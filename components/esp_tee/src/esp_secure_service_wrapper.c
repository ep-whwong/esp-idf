/*
 * SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <stdarg.h>

#include "esp_err.h"
#include "esp_efuse.h"
#include "esp_random.h"

#include "hal/sha_types.h"
#include "hal/sha_hal.h"
#include "hal/mmu_types.h"
#include "hal/wdt_hal.h"

#include "soc/soc_caps.h"

#include "esp_tee.h"
#include "secure_service_num.h"

/* ---------------------------------------------- Interrupts ------------------------------------------------- */

void IRAM_ATTR __wrap_esp_rom_route_intr_matrix(int cpu_no, uint32_t model_num, uint32_t intr_num)
{
    esp_tee_service_call(4, SS_ESP_ROM_ROUTE_INTR_MATRIX, cpu_no, model_num, intr_num);
}

/* ---------------------------------------------- eFuse ------------------------------------------------- */

uint32_t __wrap_efuse_hal_chip_revision(void)
{
    return esp_tee_service_call(1, SS_EFUSE_HAL_CHIP_REVISION);
}

uint32_t __wrap_efuse_hal_get_chip_ver_pkg(void)
{
    return esp_tee_service_call(1, SS_EFUSE_HAL_GET_CHIP_VER_PKG);
}

bool __wrap_efuse_hal_get_disable_wafer_version_major(void)
{
    return esp_tee_service_call(1, SS_EFUSE_HAL_GET_DISABLE_WAFER_VERSION_MAJOR);
}

void __wrap_efuse_hal_get_mac(uint8_t *mac)
{
    esp_tee_service_call(2, SS_EFUSE_HAL_GET_MAC, mac);
}

bool __wrap_esp_efuse_check_secure_version(uint32_t secure_version)
{
    return esp_tee_service_call(4, SS_ESP_EFUSE_CHECK_SECURE_VERSION, secure_version);
}

esp_err_t __wrap_esp_efuse_read_field_blob(const esp_efuse_desc_t *field[], void *dst, size_t dst_size_bits)
{
    return esp_tee_service_call(4, SS_ESP_EFUSE_READ_FIELD_BLOB, (uint32_t)field, (uint32_t)dst, (uint32_t)dst_size_bits);
}

bool __wrap_esp_flash_encryption_enabled(void)
{
    return esp_tee_service_call(1, SS_ESP_FLASH_ENCRYPTION_ENABLED);
}

/* ---------------------------------------------- RTC_WDT ------------------------------------------------- */

void __wrap_wdt_hal_init(wdt_hal_context_t *hal, wdt_inst_t wdt_inst, uint32_t prescaler, bool enable_intr)
{
    esp_tee_service_call(5, SS_WDT_HAL_INIT, hal, wdt_inst, prescaler, enable_intr);
}

void __wrap_wdt_hal_deinit(wdt_hal_context_t *hal)
{
    esp_tee_service_call(2, SS_WDT_HAL_DEINIT, hal);
}

/* ---------------------------------------------- AES ------------------------------------------------- */

typedef struct {
    uint8_t key_bytes;
    volatile uint8_t key_in_hardware; /* This variable is used for fault injection checks, so marked volatile to avoid optimisation */
    uint8_t key[32];
} esp_aes_context;

int __wrap_esp_aes_intr_alloc(void)
{
    return esp_tee_service_call(1, SS_ESP_AES_INTR_ALLOC);
}

int __wrap_esp_aes_crypt_cbc(esp_aes_context *ctx,
                             int mode,
                             size_t length,
                             unsigned char iv[16],
                             const unsigned char *input,
                             unsigned char *output)
{
    return esp_tee_service_call(7, SS_ESP_AES_CRYPT_CBC, ctx, mode, length, iv, input, output);
}

int __wrap_esp_aes_crypt_cfb128(esp_aes_context *ctx,
                                int mode,
                                size_t length,
                                size_t *iv_off,
                                unsigned char iv[16],
                                const unsigned char *input,
                                unsigned char *output)
{
    return esp_tee_service_call(8, SS_ESP_AES_CRYPT_CFB128, (uint32_t)ctx,
                                mode, length, iv_off, iv, (uint32_t)input, (uint32_t)output);
}

int __wrap_esp_aes_crypt_cfb8(esp_aes_context *ctx,
                              int mode,
                              size_t length,
                              unsigned char iv[16],
                              const unsigned char *input,
                              unsigned char *output)
{
    return esp_tee_service_call(7, SS_ESP_AES_CRYPT_CFB8, ctx,
                                mode, length, iv, input, output);
}

int __wrap_esp_aes_crypt_ctr(esp_aes_context *ctx,
                             size_t length,
                             size_t *nc_off,
                             unsigned char nonce_counter[16],
                             unsigned char stream_block[16],
                             const unsigned char *input,
                             unsigned char *output)
{
    return esp_tee_service_call(8, SS_ESP_AES_CRYPT_CTR, ctx, length, nc_off, nonce_counter, stream_block, input, output);
}

int __wrap_esp_aes_crypt_ecb(esp_aes_context *ctx,
                             int mode,
                             const unsigned char input[16],
                             unsigned char output[16])
{
    return esp_tee_service_call(5, SS_ESP_AES_CRYPT_ECB,
                                (uint32_t)ctx, (uint32_t)mode,
                                (uint32_t)input, (uint32_t)output);
}

int __wrap_esp_aes_crypt_ofb(esp_aes_context *ctx,
                             size_t length,
                             size_t *iv_off,
                             unsigned char iv[16],
                             const unsigned char *input,
                             unsigned char *output)
{
    return esp_tee_service_call(7, SS_ESP_AES_CRYPT_OFB, (uint32_t)ctx, length,
                                iv_off, iv, (uint32_t)input, (uint32_t)output);
}

/* ---------------------------------------------- SHA ------------------------------------------------- */

typedef enum {
    ESP_SHA1_STATE_INIT,
    ESP_SHA1_STATE_IN_PROCESS
} esp_sha1_state;

typedef enum {
    ESP_SHA256_STATE_INIT,
    ESP_SHA256_STATE_IN_PROCESS
} esp_sha256_state;

typedef enum {
    ESP_SHA512_STATE_INIT,
    ESP_SHA512_STATE_IN_PROCESS
} esp_sha512_state;

typedef struct {
    uint32_t total[2];          /*!< number of bytes processed  */
    uint32_t state[5];          /*!< intermediate digest state  */
    unsigned char buffer[64];   /*!< data block being processed */
    int first_block;            /*!< if first then true else false */
    esp_sha_type mode;
    esp_sha1_state sha_state;
} esp_sha1_context;

typedef struct {
    uint32_t total[2];          /*!< number of bytes processed  */
    uint32_t state[8];          /*!< intermediate digest state  */
    unsigned char buffer[64];   /*!< data block being processed */
    int first_block;           /*!< if first then true, else false */
    esp_sha_type mode;
    esp_sha256_state sha_state;
} esp_sha256_context;

typedef struct {
    uint64_t total[2];          /*!< number of bytes processed  */
    uint64_t state[8];          /*!< intermediate digest state  */
    unsigned char buffer[128];  /*!< data block being processed */
    int first_block;
    esp_sha_type mode;
    uint32_t t_val;             /*!< t_val for 512/t mode */
    esp_sha512_state sha_state;
} esp_sha512_context;

void __wrap_esp_sha(esp_sha_type sha_type, const unsigned char *input, size_t ilen, unsigned char *output)
{
    esp_tee_service_call(5, SS_ESP_SHA,
                         (uint32_t)sha_type, (uint32_t)input,
                         (uint32_t)ilen, (uint32_t)output);
}

int __wrap_esp_sha_dma(esp_sha_type sha_type, const void *input, uint32_t ilen,
                       const void *buf, uint32_t buf_len, bool is_first_block)
{
    return esp_tee_service_call(7, SS_ESP_SHA_DMA, sha_type, input, ilen, buf, buf_len, is_first_block);
}

void __wrap_esp_sha_read_digest_state(esp_sha_type sha_type, void *digest_state)
{
    esp_tee_service_call(3, SS_ESP_SHA_READ_DIGEST_STATE, sha_type, digest_state);
}

void __wrap_esp_sha_write_digest_state(esp_sha_type sha_type, void *digest_state)
{
    esp_tee_service_call(3, SS_ESP_SHA_WRITE_DIGEST_STATE, sha_type, digest_state);
}

/* ---------------------------------------------- MMU HAL ------------------------------------------------- */

void IRAM_ATTR __wrap_mmu_hal_map_region(uint32_t mmu_id, mmu_target_t mem_type, uint32_t vaddr, uint32_t paddr, uint32_t len, uint32_t *out_len)
{
    esp_tee_service_call(7, SS_MMU_HAL_MAP_REGION, mmu_id, mem_type, vaddr, paddr, len, out_len);
}

void IRAM_ATTR __wrap_mmu_hal_unmap_region(uint32_t mmu_id, uint32_t vaddr, uint32_t len)
{
    esp_tee_service_call(4, SS_MMU_HAL_UNMAP_REGION, mmu_id, vaddr, len);
}

bool IRAM_ATTR __wrap_mmu_hal_vaddr_to_paddr(uint32_t mmu_id, uint32_t vaddr, uint32_t *out_paddr, mmu_target_t *out_target)
{
    return esp_tee_service_call(5, SS_MMU_HAL_VADDR_TO_PADDR, mmu_id, vaddr, out_paddr, out_target);
}

bool IRAM_ATTR __wrap_mmu_hal_paddr_to_vaddr(uint32_t mmu_id, uint32_t paddr, mmu_target_t target, mmu_vaddr_t type, uint32_t *out_vaddr)
{
    return esp_tee_service_call(6, SS_MMU_HAL_PADDR_TO_VADDR, mmu_id, paddr, target, type, out_vaddr);
}