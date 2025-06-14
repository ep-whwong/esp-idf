# SPDX-FileCopyrightText: 2022-2025 Espressif Systems (Shanghai) CO LTD
# SPDX-License-Identifier: Unlicense OR CC0-1.0
import http.server
import logging
import multiprocessing
import os
import socket
import ssl
from typing import Callable

import pexpect
import pytest
from common_test_methods import get_env_config_variable
from common_test_methods import get_host_ip4_by_dest_ip
from pytest_embedded import Dut
from pytest_embedded_idf.utils import idf_parametrize
from RangeHTTPServer import RangeRequestHandler


def https_request_handler() -> Callable[..., http.server.BaseHTTPRequestHandler]:
    """
    Returns a request handler class that handles broken pipe exception
    """

    class RequestHandler(RangeRequestHandler):
        protocol_version = 'HTTP/1.1'

        def finish(self) -> None:
            try:
                if not self.wfile.closed:
                    self.wfile.flush()
                    self.wfile.close()
            except socket.error:
                pass
            self.rfile.close()

        def handle(self) -> None:
            try:
                RangeRequestHandler.handle(self)
            except socket.error:
                pass

        def do_GET(self) -> None:
            self.close_connection = True
            self.send_response(200)
            self.end_headers()

    return RequestHandler


def start_https_server(server_file: str, key_file: str, server_ip: str, server_port: int) -> None:
    requestHandler = https_request_handler()
    httpd = http.server.HTTPServer((server_ip, server_port), requestHandler)

    ssl_context = ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER)
    ssl_context.load_cert_chain(certfile=server_file, keyfile=key_file)

    httpd.socket = ssl_context.wrap_socket(httpd.socket, server_side=True)
    httpd.serve_forever()


@pytest.mark.ethernet
@pytest.mark.parametrize(
    'config',
    [
        'cli_ses_tkt',
    ],
    indirect=True,
)
@pytest.mark.parametrize('erase_nvs', ['y'], indirect=True)
@idf_parametrize('target', ['esp32'], indirect=['target'])
def test_examples_protocol_https_request_cli_session_tickets(dut: Dut) -> None:
    logging.info('Testing for "esp_tls client session tickets"')

    # check and log bin size
    binary_file = os.path.join(dut.app.binary_path, 'https_request.bin')
    bin_size = os.path.getsize(binary_file)
    logging.info('https_request_bin_size : {}KB'.format(bin_size // 1024))
    # start https server
    server_port = 8070
    server_file = os.path.join(os.path.dirname(__file__), 'main', 'local_server_cert.pem')
    key_file = os.path.join(os.path.dirname(__file__), 'main', 'local_server_key.pem')
    thread1 = multiprocessing.Process(target=start_https_server, args=(server_file, key_file, '0.0.0.0', server_port))
    thread1.daemon = True
    thread1.start()
    logging.info('The server started on localhost:{}'.format(server_port))
    try:
        # start test
        dut.expect('Loaded app from partition at offset', timeout=30)
        try:
            ip_address = dut.expect(r'IPv4 address: (\d+\.\d+\.\d+\.\d+)[^\d]', timeout=60)[1].decode()
            print('Connected to AP/Ethernet with IP: {}'.format(ip_address))
        except pexpect.exceptions.TIMEOUT:
            raise ValueError('ENV_TEST_FAILURE: Cannot connect to AP')
        host_ip = get_host_ip4_by_dest_ip(ip_address)

        dut.expect('Start https_request example', timeout=30)
        print('writing to device: {}'.format('https://' + host_ip + ':' + str(server_port)))
        dut.write('https://' + host_ip + ':' + str(server_port))
        logging.info('Testing for "https_request using saved session"')

        # Check for connection using already saved client session
        try:
            dut.expect('https_request to local server', timeout=30)
            dut.expect(
                ['Connection established...', 'Reading HTTP response...', 'HTTP/1.1 200 OK', 'connection closed'],
                expect_all=True,
            )
        except Exception:
            logging.info('Failed to connect to local https server"')
            raise

        try:
            dut.expect('https_request using saved client session', timeout=20)
            dut.expect(
                ['Connection established...', 'Reading HTTP response...', 'HTTP/1.1 200 OK', 'connection closed'],
                expect_all=True,
            )
        except Exception:
            logging.info('Failed the test for "https_request using saved client session"')
            raise

        logging.info('Passed the test for "https_request using saved client session"')
    finally:
        thread1.terminate()


@pytest.mark.ethernet
@pytest.mark.parametrize(
    'config',
    [
        'ssldyn_tls1_3',
        'ssldyn_tls1_3_only',
    ],
    indirect=True,
)
@pytest.mark.parametrize('erase_nvs', ['y'], indirect=True)
@idf_parametrize('target', ['esp32'], indirect=['target'])
def test_examples_protocol_https_request_dynamic_buffers_tls1_3(dut: Dut) -> None:
    # Check for tls 1.3 connection using crt bundle with mbedtls dynamic resource enabled
    # check and log bin size
    binary_file = os.path.join(dut.app.binary_path, 'https_request.bin')
    bin_size = os.path.getsize(binary_file)
    logging.info('https_request_bin_size : {}KB'.format(bin_size // 1024))
    # start https server
    server_port = 8070
    server_file = os.path.join(os.path.dirname(__file__), 'main', 'local_server_cert.pem')
    key_file = os.path.join(os.path.dirname(__file__), 'main', 'local_server_key.pem')
    thread1 = multiprocessing.Process(target=start_https_server, args=(server_file, key_file, '0.0.0.0', server_port))
    thread1.daemon = True
    thread1.start()
    logging.info('The server started on localhost:{}'.format(server_port))

    dut.expect('Loaded app from partition at offset', timeout=30)
    try:
        try:
            ip_address = dut.expect(r'IPv4 address: (\d+\.\d+\.\d+\.\d+)[^\d]', timeout=60)[1].decode()
            print('Connected to AP/Ethernet with IP: {}'.format(ip_address))
            host_ip = get_host_ip4_by_dest_ip(ip_address)
            dut.expect('Start https_request example', timeout=30)
            print('writing to device: {}'.format('https://' + host_ip + ':' + str(server_port)))
            dut.write('https://' + host_ip + ':' + str(server_port))
        except pexpect.exceptions.TIMEOUT:
            raise ValueError('ENV_TEST_FAILURE: Cannot connect to AP/Ethernet')
        # Check for connection using already saved client session
        try:
            dut.expect('https_request to local server', timeout=30)
            dut.expect(
                ['Connection established...', 'Reading HTTP response...', 'HTTP/1.1 200 OK', 'connection closed'],
                expect_all=True,
            )
        except Exception:
            logging.info('Failed to connect to local https server"')
            raise

        try:
            dut.expect('https_request using saved client session', timeout=20)
            dut.expect(
                ['Connection established...', 'Reading HTTP response...', 'HTTP/1.1 200 OK', 'connection closed'],
                expect_all=True,
            )
        except Exception:
            logging.info('Failed the test for "https_request using saved client session"')
            raise
        # only check if one connection is established
        logging.info('Testing for "https_request using crt bundle" with mbedtls dynamic resource enabled')
        try:
            dut.expect('https_request using crt bundle', timeout=30)
            dut.expect(
                [
                    'Connection established...',
                    'Reading HTTP response...',
                    'HTTP/1.1 200 OK',
                    'TLS 1.3',
                    'connection closed',
                ],
                expect_all=True,
            )
        except Exception:
            logging.info(
                'Failed the test for "https_request using crt bundle" with TLS 1.3 '
                'when mbedtls dynamic resource was enabled'
            )
            raise
        logging.info(
            'Passed the test for "https_request using crt bundle" with TLS 1.3 when '
            'mbedtls dynamic resource was enabled'
        )
    finally:
        thread1.terminate()


@pytest.mark.ethernet
@pytest.mark.parametrize(
    'config',
    [
        'ssldyn',
    ],
    indirect=True,
)
@pytest.mark.parametrize('erase_nvs', ['y'], indirect=True)
@idf_parametrize('target', ['esp32'], indirect=['target'])
def test_examples_protocol_https_request_dynamic_buffers(dut: Dut) -> None:
    # Check for connection using crt bundle with mbedtls dynamic resource enabled
    # check and log bin size
    binary_file = os.path.join(dut.app.binary_path, 'https_request.bin')
    bin_size = os.path.getsize(binary_file)
    logging.info('https_request_bin_size : {}KB'.format(bin_size // 1024))

    dut.expect('Loaded app from partition at offset', timeout=30)
    try:
        ip_address = dut.expect(r'IPv4 address: (\d+\.\d+\.\d+\.\d+)[^\d]', timeout=60)[1].decode()
        print('Connected to AP/Ethernet with IP: {}'.format(ip_address))
    except pexpect.exceptions.TIMEOUT:
        raise ValueError('ENV_TEST_FAILURE: Cannot connect to AP/Ethernet')

    # only check if one connection is established
    logging.info('Testing for "https_request using crt bundle" with mbedtls dynamic resource enabled')
    try:
        dut.expect('https_request using crt bundle', timeout=30)
        dut.expect(
            ['Connection established...', 'Reading HTTP response...', 'HTTP/1.1 200 OK', 'connection closed'],
            expect_all=True,
        )
    except Exception:
        logging.info('Failed the test for "https_request using crt bundle" when mbedtls dynamic resource was enabled')
        raise
    logging.info('Passed the test for "https_request using crt bundle" when mbedtls dynamic resource was enabled')


@pytest.mark.ethernet
@pytest.mark.parametrize('erase_nvs', ['y'], indirect=True)
@idf_parametrize('target', ['esp32'], indirect=['target'])
def test_examples_protocol_https_request(dut: Dut) -> None:
    """
    steps: |
      1. join AP
      2. establish TLS connection to www.howsmyssl.com:443 with multiple
         certificate verification options
      3. send http request
    """
    # check and log bin size
    binary_file = os.path.join(dut.app.binary_path, 'https_request.bin')
    bin_size = os.path.getsize(binary_file)
    logging.info('https_request_bin_size : {}KB'.format(bin_size // 1024))
    logging.info('Starting https_request simple test app')

    dut.expect('Loaded app from partition at offset', timeout=30)
    try:
        ip_address = dut.expect(r'IPv4 address: (\d+\.\d+\.\d+\.\d+)[^\d]', timeout=60)[1].decode()
        print('Connected to AP/Ethernet with IP: {}'.format(ip_address))
    except pexpect.exceptions.TIMEOUT:
        raise ValueError('ENV_TEST_FAILURE: Cannot connect to AP/Ethernet')

    # Check for connection using crt bundle
    logging.info('Testing for "https_request using crt bundle"')
    try:
        dut.expect('https_request using crt bundle', timeout=30)
        dut.expect(
            [
                'Certificate validated',
                'Connection established...',
                'Reading HTTP response...',
                'HTTP/1.1 200 OK',
                'connection closed',
            ],
            expect_all=True,
        )
    except Exception:
        logging.info('Failed the test for "https_request using crt bundle"')
        raise
    logging.info('Passed the test for "https_request using crt bundle"')

    # Check for connection using cacert_buf
    logging.info('Testing for "https_request using cacert_buf"')
    try:
        dut.expect('https_request using cacert_buf', timeout=20)
        dut.expect(
            ['Connection established...', 'Reading HTTP response...', 'HTTP/1.1 200 OK', 'connection closed'],
            expect_all=True,
        )
    except Exception:
        logging.info('Passed the test for "https_request using cacert_buf"')
        raise
    logging.info('Passed the test for "https_request using cacert_buf"')

    # Check for connection using global ca_store
    logging.info('Testing for "https_request using global ca_store"')
    try:
        dut.expect('https_request using global ca_store', timeout=20)
        dut.expect(
            ['Connection established...', 'Reading HTTP response...', 'HTTP/1.1 200 OK', 'connection closed'],
            expect_all=True,
        )
    except Exception:
        logging.info('Failed the test for "https_request using global ca_store"')
        raise
    logging.info('Passed the test for "https_request using global ca_store"')

    # Check for connection using specified server supported ciphersuites
    logging.info('Testing for "https_request using server supported ciphersuites"')
    try:
        dut.expect('https_request using server supported ciphersuites', timeout=20)
        dut.expect(
            ['Connection established...', 'Reading HTTP response...', 'HTTP/1.1 200 OK', 'connection closed'],
            expect_all=True,
        )
    except Exception:
        logging.info('Failed the test for "https_request using server supported ciphersuites"')
        raise
    logging.info('Passed the test for "https_request using server supported ciphersuites"')

    # Check for connection using specified server unsupported ciphersuites
    logging.info('Testing for "https_request using server unsupported ciphersuites"')
    try:
        dut.expect('https_request using server unsupported ciphersuites', timeout=20)
        dut.expect('Connection failed...', timeout=30)
    except Exception:
        logging.info('Failed the test for "https_request using server unsupported ciphersuites"')
        raise
    logging.info('Passed the test for "https_request using server unsupported ciphersuites"')


@pytest.mark.wifi_ap
@pytest.mark.xtal_26mhz
@pytest.mark.parametrize(
    'config, baud',
    [
        ('esp32c2_rom_mbedtls', '74880'),
    ],
    indirect=True,
)
@idf_parametrize('target', ['esp32c2'], indirect=['target'])
def test_examples_protocol_https_request_rom_impl(dut: Dut) -> None:
    # Connect to AP
    if dut.app.sdkconfig.get('EXAMPLE_WIFI_SSID_PWD_FROM_STDIN') is True:
        dut.expect('Please input ssid password:')
        env_name = 'wifi_ap'
        ap_ssid = get_env_config_variable(env_name, 'ap_ssid')
        ap_password = get_env_config_variable(env_name, 'ap_password')
        dut.write(f'{ap_ssid} {ap_password}')
    # check and log bin size
    binary_file = os.path.join(dut.app.binary_path, 'https_request.bin')
    bin_size = os.path.getsize(binary_file)
    logging.info('https_request_bin_size : {}KB'.format(bin_size // 1024))
    logging.info('Starting https_request simple test app')

    try:
        ip_address = dut.expect(r'IPv4 address: (\d+\.\d+\.\d+\.\d+)[^\d]', timeout=60)[1].decode()
        print('Connected to AP/Ethernet with IP: {}'.format(ip_address))
    except pexpect.exceptions.TIMEOUT:
        raise ValueError('ENV_TEST_FAILURE: Cannot connect to AP/Ethernet')

    # Check for connection using crt bundle
    logging.info('Testing for "https_request using crt bundle"')
    try:
        dut.expect('https_request using crt bundle', timeout=30)
        dut.expect(
            [
                'Certificate validated',
                'Connection established...',
                'Reading HTTP response...',
                'HTTP/1.1 200 OK',
                'connection closed',
            ],
            expect_all=True,
        )
    except Exception:
        logging.info('Failed the test for "https_request using crt bundle"')
        raise
    logging.info('Passed the test for "https_request using crt bundle"')

    # Check for connection using cacert_buf
    logging.info('Testing for "https_request using cacert_buf"')
    try:
        dut.expect('https_request using cacert_buf', timeout=20)
        dut.expect(
            ['Connection established...', 'Reading HTTP response...', 'HTTP/1.1 200 OK', 'connection closed'],
            expect_all=True,
        )
    except Exception:
        logging.info('Passed the test for "https_request using cacert_buf"')
        raise
    logging.info('Passed the test for "https_request using cacert_buf"')

    # Check for connection using global ca_store
    logging.info('Testing for "https_request using global ca_store"')
    try:
        dut.expect('https_request using global ca_store', timeout=20)
        dut.expect(
            ['Connection established...', 'Reading HTTP response...', 'HTTP/1.1 200 OK', 'connection closed'],
            expect_all=True,
        )
    except Exception:
        logging.info('Failed the test for "https_request using global ca_store"')
        raise
    logging.info('Passed the test for "https_request using global ca_store"')

    # Check for connection using specified server supported ciphersuites
    logging.info('Testing for "https_request using server supported ciphersuites"')
    try:
        dut.expect('https_request using server supported ciphersuites', timeout=20)
        dut.expect(
            ['Connection established...', 'Reading HTTP response...', 'HTTP/1.1 200 OK', 'connection closed'],
            expect_all=True,
        )
    except Exception:
        logging.info('Failed the test for "https_request using server supported ciphersuites"')
        raise
    logging.info('Passed the test for "https_request using server supported ciphersuites"')

    # Check for connection using specified server unsupported ciphersuites
    logging.info('Testing for "https_request using server unsupported ciphersuites"')
    try:
        dut.expect('https_request using server unsupported ciphersuites', timeout=20)
        dut.expect('Connection failed...', timeout=30)
    except Exception:
        logging.info('Failed the test for "https_request using server unsupported ciphersuites"')
        raise
    logging.info('Passed the test for "https_request using server unsupported ciphersuites"')
