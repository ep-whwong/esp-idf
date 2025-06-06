/*
 * SPDX-FileCopyrightText: 2021-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include "esp_err.h"
#include "ulp_common.h"
#include "esp_intr_alloc.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    ULP_RISCV_WAKEUP_SOURCE_TIMER,
    ULP_RISCV_WAKEUP_SOURCE_GPIO,
} ulp_riscv_wakeup_source_t;

/**
 * @brief ULP riscv init parameters
 *
 */
typedef struct {
    ulp_riscv_wakeup_source_t wakeup_source; /*!< ULP wakeup source */
} ulp_riscv_cfg_t;

#define ULP_RISCV_DEFAULT_CONFIG()                      \
    {                                                   \
        .wakeup_source = ULP_RISCV_WAKEUP_SOURCE_TIMER, \
    }

/* ULP RISC-V interrupt signals for the main CPU */
#if (CONFIG_IDF_TARGET_ESP32S2 || CONFIG_IDF_TARGET_ESP32S3)
#define ULP_RISCV_SW_INT    (BIT(13))   // Corresponds to RTC_CNTL_COCPU_INT_ST_M interrupt status bit
#define ULP_RISCV_TRAP_INT  (BIT(17))   // Corresponds to RTC_CNTL_COCPU_TRAP_INT_ST_M interrupt status bit
#else
#error "ULP_RISCV_SW_INT and ULP_RISCV_TRAP_INT are undefined. Please check soc/rtc_cntl_reg.h for the correct bitmap on your target SoC."
#endif /* (CONFIG_IDF_TARGET_ESP32S2 || CONFIG_IDF_TARGET_ESP32S3) */

/**
 * @brief Register ULP signal ISR
 *
 * @note The ISR routine will only be active if the main CPU is not in deepsleep
 *
 * @param fn    ISR callback function
 * @param arg   ISR callback function arguments
 * @param mask  Bit mask to enable the required ULP RISC-V interrupt signals
 * @return
 *      - ESP_OK on success
 *      - ESP_ERR_INVALID_ARG if callback function is NULL or if the interrupt bits are invalid
 *      - ESP_ERR_NO_MEM if heap memory cannot be allocated for the interrupt
 *      - other errors returned by esp_intr_alloc
 */
esp_err_t ulp_riscv_isr_register(intr_handler_t fn, void *arg, uint32_t mask);

/**
 * @brief Deregister ULP signal ISR
 *
 * @param fn    ISR callback function
 * @param arg   ISR callback function arguments
 * @param mask  Bit mask to enable the required ULP RISC-V interrupt signals
 * @return
 *      - ESP_OK on success
 *      - ESP_ERR_INVALID_ARG if callback function is NULL or if the interrupt bits are invalid
 *      - ESP_ERR_INVALID_STATE if a handler matching both callback function and its arguments isn't registered
 */
esp_err_t ulp_riscv_isr_deregister(intr_handler_t fn, void *arg, uint32_t mask);

/**
 * @brief Configure the ULP and run the program loaded into RTC memory
 *
 * @param cfg pointer to the config struct
 * @return  ESP_OK on success
 */
esp_err_t ulp_riscv_config_and_run(ulp_riscv_cfg_t* cfg);

/**
 * @brief Configure the ULP with default settings
 *        and run the program loaded into RTC memory
 *
 * @return  ESP_OK on success
 */
esp_err_t ulp_riscv_run(void);

/**
 * @brief Load ULP-RISC-V program binary into RTC memory
 *
 * Different than ULP FSM, the binary program has no special format, it is the ELF
 * file generated by RISC-V toolchain converted to binary format using objcopy.
 *
 * Linker script in components/ulp/ld/ulp_riscv.ld produces ELF files which
 * correspond to this format. This linker script produces binaries with load_addr == 0.
 *
 * @param program_binary pointer to program binary
 * @param program_size_bytes size of the program binary
 * @return
 *      - ESP_OK on success
 *      - ESP_ERR_INVALID_SIZE if program_size_bytes is more than 8KiB
 */
esp_err_t ulp_riscv_load_binary(const uint8_t* program_binary, size_t program_size_bytes);

/**
 * @brief Stop the ULP timer
 *
 * @note This will stop the ULP from waking up if halted, but will not abort any program
 *       currently executing on the ULP.
 */
void ulp_riscv_timer_stop(void);

/**
 * @brief Resumes the ULP timer
 *
 * @note This will resume an already configured timer, but does no other configuration
 *
 */
void ulp_riscv_timer_resume(void);

/**
 * @brief Halts the program currently running on the ULP-RISC-V
 *
 * @note  Program will restart at the next ULP timer trigger if timer is still running.
 *        If you want to stop the ULP from waking up then call ulp_riscv_timer_stop() first.
 */
void ulp_riscv_halt(void);

/**
 * @brief Resets the ULP-RISC-V core from the main CPU
 *
 * @note This will reset the ULP core from the main CPU. It is intended to be used when the
 *       ULP is in a bad state and cannot run as intended due to a corrupt firmware or any other reason.
 *       The main core can reset the ULP core with this API and then re-initialize the ULP.
 */
void ulp_riscv_reset(void);

#ifdef __cplusplus
}
#endif
