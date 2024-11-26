/**
 * SPDX-FileCopyrightText: 2023 Espressif Systems (Shanghai) CO LTD
 *
 *  SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include <stdint.h>
#include "soc/soc.h"
#ifdef __cplusplus
extern "C" {
#endif

/** RTCLOCKCALI_LP_CALI_TIMER_REG register
 *  need_des
 */
#define RTCLOCKCALI_LP_CALI_TIMER_REG (DR_REG_RTCLOCKCALI_BASE + 0x0)
/** RTCLOCKCALI_TIMER_TARGET : R/W; bitpos: [29:0]; default: 4095;
 *  need_des
 */
#define RTCLOCKCALI_TIMER_TARGET    0x3FFFFFFFU
#define RTCLOCKCALI_TIMER_TARGET_M  (RTCLOCKCALI_TIMER_TARGET_V << RTCLOCKCALI_TIMER_TARGET_S)
#define RTCLOCKCALI_TIMER_TARGET_V  0x3FFFFFFFU
#define RTCLOCKCALI_TIMER_TARGET_S  0
/** RTCLOCKCALI_TIMER_STOP : WT; bitpos: [30]; default: 0;
 *  need_des
 */
#define RTCLOCKCALI_TIMER_STOP    (BIT(30))
#define RTCLOCKCALI_TIMER_STOP_M  (RTCLOCKCALI_TIMER_STOP_V << RTCLOCKCALI_TIMER_STOP_S)
#define RTCLOCKCALI_TIMER_STOP_V  0x00000001U
#define RTCLOCKCALI_TIMER_STOP_S  30
/** RTCLOCKCALI_TIMER_START : WT; bitpos: [31]; default: 0;
 *  need_des
 */
#define RTCLOCKCALI_TIMER_START    (BIT(31))
#define RTCLOCKCALI_TIMER_START_M  (RTCLOCKCALI_TIMER_START_V << RTCLOCKCALI_TIMER_START_S)
#define RTCLOCKCALI_TIMER_START_V  0x00000001U
#define RTCLOCKCALI_TIMER_START_S  31

/** RTCLOCKCALI_RTCCALICFG_SLOW_REG register
 *  RTC calibration configure register
 */
#define RTCLOCKCALI_RTCCALICFG_SLOW_REG (DR_REG_RTCLOCKCALI_BASE + 0x4)
/** RTCLOCKCALI_RTC_CALI_START_CYCLING_SLOW : R/W; bitpos: [12]; default: 1;
 *  0: one-shot frequency calculation,1: periodic frequency calculation,
 */
#define RTCLOCKCALI_RTC_CALI_START_CYCLING_SLOW    (BIT(12))
#define RTCLOCKCALI_RTC_CALI_START_CYCLING_SLOW_M  (RTCLOCKCALI_RTC_CALI_START_CYCLING_SLOW_V << RTCLOCKCALI_RTC_CALI_START_CYCLING_SLOW_S)
#define RTCLOCKCALI_RTC_CALI_START_CYCLING_SLOW_V  0x00000001U
#define RTCLOCKCALI_RTC_CALI_START_CYCLING_SLOW_S  12
/** RTCLOCKCALI_RTC_CALI_CLK_SEL_SLOW : R/W; bitpos: [14:13]; default: 0;
 *  0:rtc slow clock. 1:clk_8m, 2:xtal_32k.
 */
#define RTCLOCKCALI_RTC_CALI_CLK_SEL_SLOW    0x00000003U
#define RTCLOCKCALI_RTC_CALI_CLK_SEL_SLOW_M  (RTCLOCKCALI_RTC_CALI_CLK_SEL_SLOW_V << RTCLOCKCALI_RTC_CALI_CLK_SEL_SLOW_S)
#define RTCLOCKCALI_RTC_CALI_CLK_SEL_SLOW_V  0x00000003U
#define RTCLOCKCALI_RTC_CALI_CLK_SEL_SLOW_S  13
/** RTCLOCKCALI_RTC_CALI_RDY_SLOW : RO; bitpos: [15]; default: 0;
 *  indicate one-shot frequency calculation is done.
 */
#define RTCLOCKCALI_RTC_CALI_RDY_SLOW    (BIT(15))
#define RTCLOCKCALI_RTC_CALI_RDY_SLOW_M  (RTCLOCKCALI_RTC_CALI_RDY_SLOW_V << RTCLOCKCALI_RTC_CALI_RDY_SLOW_S)
#define RTCLOCKCALI_RTC_CALI_RDY_SLOW_V  0x00000001U
#define RTCLOCKCALI_RTC_CALI_RDY_SLOW_S  15
/** RTCLOCKCALI_RTC_CALI_MAX_SLOW : R/W; bitpos: [30:16]; default: 1;
 *  Configure the time to calculate RTC slow clock's frequency.
 */
#define RTCLOCKCALI_RTC_CALI_MAX_SLOW    0x00007FFFU
#define RTCLOCKCALI_RTC_CALI_MAX_SLOW_M  (RTCLOCKCALI_RTC_CALI_MAX_SLOW_V << RTCLOCKCALI_RTC_CALI_MAX_SLOW_S)
#define RTCLOCKCALI_RTC_CALI_MAX_SLOW_V  0x00007FFFU
#define RTCLOCKCALI_RTC_CALI_MAX_SLOW_S  16
/** RTCLOCKCALI_RTC_CALI_START_SLOW : R/W; bitpos: [31]; default: 0;
 *  Set this bit to start one-shot frequency calculation.
 */
#define RTCLOCKCALI_RTC_CALI_START_SLOW    (BIT(31))
#define RTCLOCKCALI_RTC_CALI_START_SLOW_M  (RTCLOCKCALI_RTC_CALI_START_SLOW_V << RTCLOCKCALI_RTC_CALI_START_SLOW_S)
#define RTCLOCKCALI_RTC_CALI_START_SLOW_V  0x00000001U
#define RTCLOCKCALI_RTC_CALI_START_SLOW_S  31

/** RTCLOCKCALI_RTCCALICFG_FAST_REG register
 *  RTC calibration configure register
 */
#define RTCLOCKCALI_RTCCALICFG_FAST_REG (DR_REG_RTCLOCKCALI_BASE + 0x8)
/** RTCLOCKCALI_FOSC_DIV_NUM : R/W; bitpos: [11:4]; default: 0;
 *  fosc clock divider number
 */
#define RTCLOCKCALI_FOSC_DIV_NUM    0x000000FFU
#define RTCLOCKCALI_FOSC_DIV_NUM_M  (RTCLOCKCALI_FOSC_DIV_NUM_V << RTCLOCKCALI_FOSC_DIV_NUM_S)
#define RTCLOCKCALI_FOSC_DIV_NUM_V  0x000000FFU
#define RTCLOCKCALI_FOSC_DIV_NUM_S  4
/** RTCLOCKCALI_RTC_CALI_START_CYCLING_FAST : R/W; bitpos: [12]; default: 1;
 *  0: one-shot frequency calculation,1: periodic frequency calculation,
 */
#define RTCLOCKCALI_RTC_CALI_START_CYCLING_FAST    (BIT(12))
#define RTCLOCKCALI_RTC_CALI_START_CYCLING_FAST_M  (RTCLOCKCALI_RTC_CALI_START_CYCLING_FAST_V << RTCLOCKCALI_RTC_CALI_START_CYCLING_FAST_S)
#define RTCLOCKCALI_RTC_CALI_START_CYCLING_FAST_V  0x00000001U
#define RTCLOCKCALI_RTC_CALI_START_CYCLING_FAST_S  12
/** RTCLOCKCALI_RTC_CALI_CLK_SEL_FAST : R/W; bitpos: [14:13]; default: 0;
 *  0:rtc slow clock. 1:clk_8m, 2:xtal_32k.
 */
#define RTCLOCKCALI_RTC_CALI_CLK_SEL_FAST    0x00000003U
#define RTCLOCKCALI_RTC_CALI_CLK_SEL_FAST_M  (RTCLOCKCALI_RTC_CALI_CLK_SEL_FAST_V << RTCLOCKCALI_RTC_CALI_CLK_SEL_FAST_S)
#define RTCLOCKCALI_RTC_CALI_CLK_SEL_FAST_V  0x00000003U
#define RTCLOCKCALI_RTC_CALI_CLK_SEL_FAST_S  13
/** RTCLOCKCALI_RTC_CALI_RDY_FAST : RO; bitpos: [15]; default: 0;
 *  indicate one-shot frequency calculation is done.
 */
#define RTCLOCKCALI_RTC_CALI_RDY_FAST    (BIT(15))
#define RTCLOCKCALI_RTC_CALI_RDY_FAST_M  (RTCLOCKCALI_RTC_CALI_RDY_FAST_V << RTCLOCKCALI_RTC_CALI_RDY_FAST_S)
#define RTCLOCKCALI_RTC_CALI_RDY_FAST_V  0x00000001U
#define RTCLOCKCALI_RTC_CALI_RDY_FAST_S  15
/** RTCLOCKCALI_RTC_CALI_MAX_FAST : R/W; bitpos: [30:16]; default: 1;
 *  Configure the time to calculate RTC slow clock's frequency.
 */
#define RTCLOCKCALI_RTC_CALI_MAX_FAST    0x00007FFFU
#define RTCLOCKCALI_RTC_CALI_MAX_FAST_M  (RTCLOCKCALI_RTC_CALI_MAX_FAST_V << RTCLOCKCALI_RTC_CALI_MAX_FAST_S)
#define RTCLOCKCALI_RTC_CALI_MAX_FAST_V  0x00007FFFU
#define RTCLOCKCALI_RTC_CALI_MAX_FAST_S  16
/** RTCLOCKCALI_RTC_CALI_START_FAST : R/W; bitpos: [31]; default: 0;
 *  Set this bit to start one-shot frequency calculation.
 */
#define RTCLOCKCALI_RTC_CALI_START_FAST    (BIT(31))
#define RTCLOCKCALI_RTC_CALI_START_FAST_M  (RTCLOCKCALI_RTC_CALI_START_FAST_V << RTCLOCKCALI_RTC_CALI_START_FAST_S)
#define RTCLOCKCALI_RTC_CALI_START_FAST_V  0x00000001U
#define RTCLOCKCALI_RTC_CALI_START_FAST_S  31

/** RTCLOCKCALI_RTCCALICFG1_SLOW_REG register
 *  RTC calibration configure1 register
 */
#define RTCLOCKCALI_RTCCALICFG1_SLOW_REG (DR_REG_RTCLOCKCALI_BASE + 0xc)
/** RTCLOCKCALI_RTC_CALI_CYCLING_DATA_VLD_SLOW : RO; bitpos: [0]; default: 0;
 *  indicate periodic frequency calculation is done.
 */
#define RTCLOCKCALI_RTC_CALI_CYCLING_DATA_VLD_SLOW    (BIT(0))
#define RTCLOCKCALI_RTC_CALI_CYCLING_DATA_VLD_SLOW_M  (RTCLOCKCALI_RTC_CALI_CYCLING_DATA_VLD_SLOW_V << RTCLOCKCALI_RTC_CALI_CYCLING_DATA_VLD_SLOW_S)
#define RTCLOCKCALI_RTC_CALI_CYCLING_DATA_VLD_SLOW_V  0x00000001U
#define RTCLOCKCALI_RTC_CALI_CYCLING_DATA_VLD_SLOW_S  0
/** RTCLOCKCALI_RTC_CALI_VALUE_SLOW : RO; bitpos: [31:7]; default: 0;
 *  When one-shot or periodic frequency calculation is done, read this value to
 *  calculate RTC slow clock's frequency.
 */
#define RTCLOCKCALI_RTC_CALI_VALUE_SLOW    0x01FFFFFFU
#define RTCLOCKCALI_RTC_CALI_VALUE_SLOW_M  (RTCLOCKCALI_RTC_CALI_VALUE_SLOW_V << RTCLOCKCALI_RTC_CALI_VALUE_SLOW_S)
#define RTCLOCKCALI_RTC_CALI_VALUE_SLOW_V  0x01FFFFFFU
#define RTCLOCKCALI_RTC_CALI_VALUE_SLOW_S  7

/** RTCLOCKCALI_RTCCALICFG1_FAST_REG register
 *  RTC calibration configure1 register
 */
#define RTCLOCKCALI_RTCCALICFG1_FAST_REG (DR_REG_RTCLOCKCALI_BASE + 0x10)
/** RTCLOCKCALI_RTC_CALI_CYCLING_DATA_VLD_FAST : RO; bitpos: [0]; default: 0;
 *  indicate periodic frequency calculation is done.
 */
#define RTCLOCKCALI_RTC_CALI_CYCLING_DATA_VLD_FAST    (BIT(0))
#define RTCLOCKCALI_RTC_CALI_CYCLING_DATA_VLD_FAST_M  (RTCLOCKCALI_RTC_CALI_CYCLING_DATA_VLD_FAST_V << RTCLOCKCALI_RTC_CALI_CYCLING_DATA_VLD_FAST_S)
#define RTCLOCKCALI_RTC_CALI_CYCLING_DATA_VLD_FAST_V  0x00000001U
#define RTCLOCKCALI_RTC_CALI_CYCLING_DATA_VLD_FAST_S  0
/** RTCLOCKCALI_RTC_CALI_VALUE_FAST : RO; bitpos: [31:7]; default: 0;
 *  When one-shot or periodic frequency calculation is done, read this value to
 *  calculate RTC slow clock's frequency.
 */
#define RTCLOCKCALI_RTC_CALI_VALUE_FAST    0x01FFFFFFU
#define RTCLOCKCALI_RTC_CALI_VALUE_FAST_M  (RTCLOCKCALI_RTC_CALI_VALUE_FAST_V << RTCLOCKCALI_RTC_CALI_VALUE_FAST_S)
#define RTCLOCKCALI_RTC_CALI_VALUE_FAST_V  0x01FFFFFFU
#define RTCLOCKCALI_RTC_CALI_VALUE_FAST_S  7

/** RTCLOCKCALI_RTCCALICFG2_REG register
 *  Timer group calibration register
 */
#define RTCLOCKCALI_RTCCALICFG2_REG (DR_REG_RTCLOCKCALI_BASE + 0x14)
/** RTCLOCKCALI_RTC_CALI_TIMEOUT : RO; bitpos: [0]; default: 0;
 *  RTC calibration timeout indicator
 */
#define RTCLOCKCALI_RTC_CALI_TIMEOUT    (BIT(0))
#define RTCLOCKCALI_RTC_CALI_TIMEOUT_M  (RTCLOCKCALI_RTC_CALI_TIMEOUT_V << RTCLOCKCALI_RTC_CALI_TIMEOUT_S)
#define RTCLOCKCALI_RTC_CALI_TIMEOUT_V  0x00000001U
#define RTCLOCKCALI_RTC_CALI_TIMEOUT_S  0
/** RTCLOCKCALI_RTC_CALI_TIMEOUT_RST_CNT : R/W; bitpos: [6:3]; default: 3;
 *  Cycles that release calibration timeout reset
 */
#define RTCLOCKCALI_RTC_CALI_TIMEOUT_RST_CNT    0x0000000FU
#define RTCLOCKCALI_RTC_CALI_TIMEOUT_RST_CNT_M  (RTCLOCKCALI_RTC_CALI_TIMEOUT_RST_CNT_V << RTCLOCKCALI_RTC_CALI_TIMEOUT_RST_CNT_S)
#define RTCLOCKCALI_RTC_CALI_TIMEOUT_RST_CNT_V  0x0000000FU
#define RTCLOCKCALI_RTC_CALI_TIMEOUT_RST_CNT_S  3
/** RTCLOCKCALI_RTC_CALI_TIMEOUT_THRES : R/W; bitpos: [31:7]; default: 33554431;
 *  Threshold value for the RTC calibration timer. If the calibration timer's value
 *  exceeds this threshold, a timeout is triggered.
 */
#define RTCLOCKCALI_RTC_CALI_TIMEOUT_THRES    0x01FFFFFFU
#define RTCLOCKCALI_RTC_CALI_TIMEOUT_THRES_M  (RTCLOCKCALI_RTC_CALI_TIMEOUT_THRES_V << RTCLOCKCALI_RTC_CALI_TIMEOUT_THRES_S)
#define RTCLOCKCALI_RTC_CALI_TIMEOUT_THRES_V  0x01FFFFFFU
#define RTCLOCKCALI_RTC_CALI_TIMEOUT_THRES_S  7

/** RTCLOCKCALI_DFREQ_HIGH_LIMIT_SLOW_REG register
 *  RTC slow clock dfreq high limit.
 */
#define RTCLOCKCALI_DFREQ_HIGH_LIMIT_SLOW_REG (DR_REG_RTCLOCKCALI_BASE + 0x18)
/** RTCLOCKCALI_COARSE_LIMIT_DIFF_SLOW : R/W; bitpos: [7:0]; default: 16;
 *  When rtc_cali_value upper/lower than reg_high/low_limit +/-
 *  reg_coarse_limit_diff,the step of dfreq,will use reg_coarse_step.
 */
#define RTCLOCKCALI_COARSE_LIMIT_DIFF_SLOW    0x000000FFU
#define RTCLOCKCALI_COARSE_LIMIT_DIFF_SLOW_M  (RTCLOCKCALI_COARSE_LIMIT_DIFF_SLOW_V << RTCLOCKCALI_COARSE_LIMIT_DIFF_SLOW_S)
#define RTCLOCKCALI_COARSE_LIMIT_DIFF_SLOW_V  0x000000FFU
#define RTCLOCKCALI_COARSE_LIMIT_DIFF_SLOW_S  0
/** RTCLOCKCALI_HIGH_LIMIT_SLOW : R/W; bitpos: [31:8]; default: 267;
 *  when rtc_cali_value upper than reg_high_limit,frequency of osc will  increase .
 */
#define RTCLOCKCALI_HIGH_LIMIT_SLOW    0x00FFFFFFU
#define RTCLOCKCALI_HIGH_LIMIT_SLOW_M  (RTCLOCKCALI_HIGH_LIMIT_SLOW_V << RTCLOCKCALI_HIGH_LIMIT_SLOW_S)
#define RTCLOCKCALI_HIGH_LIMIT_SLOW_V  0x00FFFFFFU
#define RTCLOCKCALI_HIGH_LIMIT_SLOW_S  8

/** RTCLOCKCALI_DFREQ_LOW_LIMIT_SLOW_REG register
 *  RTC slow clock dfreq low limit.
 */
#define RTCLOCKCALI_DFREQ_LOW_LIMIT_SLOW_REG (DR_REG_RTCLOCKCALI_BASE + 0x1c)
/** RTCLOCKCALI_LOW_LIMIT_SLOW : R/W; bitpos: [31:8]; default: 266;
 *  when rtc_cali_value lower than reg_low_limit,frequency of osc will  decrease .
 */
#define RTCLOCKCALI_LOW_LIMIT_SLOW    0x00FFFFFFU
#define RTCLOCKCALI_LOW_LIMIT_SLOW_M  (RTCLOCKCALI_LOW_LIMIT_SLOW_V << RTCLOCKCALI_LOW_LIMIT_SLOW_S)
#define RTCLOCKCALI_LOW_LIMIT_SLOW_V  0x00FFFFFFU
#define RTCLOCKCALI_LOW_LIMIT_SLOW_S  8

/** RTCLOCKCALI_DFREQ_HIGH_LIMIT_FAST_REG register
 *  RTC fast clock dfreq high limit.
 */
#define RTCLOCKCALI_DFREQ_HIGH_LIMIT_FAST_REG (DR_REG_RTCLOCKCALI_BASE + 0x20)
/** RTCLOCKCALI_COARSE_LIMIT_DIFF_FAST : R/W; bitpos: [7:0]; default: 16;
 *  When rtc_cali_value upper/lower than reg_high/low_limit +/-
 *  reg_coarse_limit_diff,the step of dfreq,will use reg_coarse_step.
 */
#define RTCLOCKCALI_COARSE_LIMIT_DIFF_FAST    0x000000FFU
#define RTCLOCKCALI_COARSE_LIMIT_DIFF_FAST_M  (RTCLOCKCALI_COARSE_LIMIT_DIFF_FAST_V << RTCLOCKCALI_COARSE_LIMIT_DIFF_FAST_S)
#define RTCLOCKCALI_COARSE_LIMIT_DIFF_FAST_V  0x000000FFU
#define RTCLOCKCALI_COARSE_LIMIT_DIFF_FAST_S  0
/** RTCLOCKCALI_HIGH_LIMIT_FAST : R/W; bitpos: [31:8]; default: 267;
 *  when rtc_cali_value upper than reg_high_limit,frequency of osc will  increase .
 */
#define RTCLOCKCALI_HIGH_LIMIT_FAST    0x00FFFFFFU
#define RTCLOCKCALI_HIGH_LIMIT_FAST_M  (RTCLOCKCALI_HIGH_LIMIT_FAST_V << RTCLOCKCALI_HIGH_LIMIT_FAST_S)
#define RTCLOCKCALI_HIGH_LIMIT_FAST_V  0x00FFFFFFU
#define RTCLOCKCALI_HIGH_LIMIT_FAST_S  8

/** RTCLOCKCALI_DFREQ_LOW_LIMIT_FAST_REG register
 *  RTC fast clock dfreq low limit.
 */
#define RTCLOCKCALI_DFREQ_LOW_LIMIT_FAST_REG (DR_REG_RTCLOCKCALI_BASE + 0x24)
/** RTCLOCKCALI_LOW_LIMIT_FAST : R/W; bitpos: [31:8]; default: 266;
 *  when rtc_cali_value lower than reg_low_limit,frequency of osc will  decrease .
 */
#define RTCLOCKCALI_LOW_LIMIT_FAST    0x00FFFFFFU
#define RTCLOCKCALI_LOW_LIMIT_FAST_M  (RTCLOCKCALI_LOW_LIMIT_FAST_V << RTCLOCKCALI_LOW_LIMIT_FAST_S)
#define RTCLOCKCALI_LOW_LIMIT_FAST_V  0x00FFFFFFU
#define RTCLOCKCALI_LOW_LIMIT_FAST_S  8

/** RTCLOCKCALI_DFREQ_CONF2_REG register
 *  RTC DFREQ CONF2
 */
#define RTCLOCKCALI_DFREQ_CONF2_REG (DR_REG_RTCLOCKCALI_BASE + 0x28)
/** RTCLOCKCALI_DREQ_UPDATE : WT; bitpos: [0]; default: 0;
 *  need_des
 */
#define RTCLOCKCALI_DREQ_UPDATE    (BIT(0))
#define RTCLOCKCALI_DREQ_UPDATE_M  (RTCLOCKCALI_DREQ_UPDATE_V << RTCLOCKCALI_DREQ_UPDATE_S)
#define RTCLOCKCALI_DREQ_UPDATE_V  0x00000001U
#define RTCLOCKCALI_DREQ_UPDATE_S  0
/** RTCLOCKCALI_DREQ_INIT_32K : WT; bitpos: [2]; default: 0;
 *  Initialize the value of 32K OSC dfreq setting.
 */
#define RTCLOCKCALI_DREQ_INIT_32K    (BIT(2))
#define RTCLOCKCALI_DREQ_INIT_32K_M  (RTCLOCKCALI_DREQ_INIT_32K_V << RTCLOCKCALI_DREQ_INIT_32K_S)
#define RTCLOCKCALI_DREQ_INIT_32K_V  0x00000001U
#define RTCLOCKCALI_DREQ_INIT_32K_S  2
/** RTCLOCKCALI_DREQ_INIT_FOSC : WT; bitpos: [3]; default: 0;
 *  Initialize the value of FOSC  dfreq setting.
 */
#define RTCLOCKCALI_DREQ_INIT_FOSC    (BIT(3))
#define RTCLOCKCALI_DREQ_INIT_FOSC_M  (RTCLOCKCALI_DREQ_INIT_FOSC_V << RTCLOCKCALI_DREQ_INIT_FOSC_S)
#define RTCLOCKCALI_DREQ_INIT_FOSC_V  0x00000001U
#define RTCLOCKCALI_DREQ_INIT_FOSC_S  3
/** RTCLOCKCALI_DREQ_INIT_SOSC : WT; bitpos: [4]; default: 0;
 *  Initialize the value of SOSC  dfreq setting.
 */
#define RTCLOCKCALI_DREQ_INIT_SOSC    (BIT(4))
#define RTCLOCKCALI_DREQ_INIT_SOSC_M  (RTCLOCKCALI_DREQ_INIT_SOSC_V << RTCLOCKCALI_DREQ_INIT_SOSC_S)
#define RTCLOCKCALI_DREQ_INIT_SOSC_V  0x00000001U
#define RTCLOCKCALI_DREQ_INIT_SOSC_S  4
/** RTCLOCKCALI_32K_DFREQ_SEL : R/W; bitpos: [5]; default: 0;
 *  1:Frequency of 32k controlled by calibration module.0:Frequency of 32k controlled
 *  by register from system-register bank
 */
#define RTCLOCKCALI_32K_DFREQ_SEL    (BIT(5))
#define RTCLOCKCALI_32K_DFREQ_SEL_M  (RTCLOCKCALI_32K_DFREQ_SEL_V << RTCLOCKCALI_32K_DFREQ_SEL_S)
#define RTCLOCKCALI_32K_DFREQ_SEL_V  0x00000001U
#define RTCLOCKCALI_32K_DFREQ_SEL_S  5
/** RTCLOCKCALI_FOSC_DFREQ_SEL : R/W; bitpos: [6]; default: 0;
 *  1:Frequency of FOSC controlled by calibration module.0:Frequency of FOSC controlled
 *  by register from system-register bank
 */
#define RTCLOCKCALI_FOSC_DFREQ_SEL    (BIT(6))
#define RTCLOCKCALI_FOSC_DFREQ_SEL_M  (RTCLOCKCALI_FOSC_DFREQ_SEL_V << RTCLOCKCALI_FOSC_DFREQ_SEL_S)
#define RTCLOCKCALI_FOSC_DFREQ_SEL_V  0x00000001U
#define RTCLOCKCALI_FOSC_DFREQ_SEL_S  6
/** RTCLOCKCALI_SOSC_DFREQ_SEL : R/W; bitpos: [7]; default: 0;
 *  1:Frequency of SOSC controlled by calibration module.0:Frequency of SOSC controlled
 *  by register from system-register bank
 */
#define RTCLOCKCALI_SOSC_DFREQ_SEL    (BIT(7))
#define RTCLOCKCALI_SOSC_DFREQ_SEL_M  (RTCLOCKCALI_SOSC_DFREQ_SEL_V << RTCLOCKCALI_SOSC_DFREQ_SEL_S)
#define RTCLOCKCALI_SOSC_DFREQ_SEL_V  0x00000001U
#define RTCLOCKCALI_SOSC_DFREQ_SEL_S  7
/** RTCLOCKCALI_FINE_STEP : R/W; bitpos: [15:8]; default: 1;
 *  Frequency fine step.
 */
#define RTCLOCKCALI_FINE_STEP    0x000000FFU
#define RTCLOCKCALI_FINE_STEP_M  (RTCLOCKCALI_FINE_STEP_V << RTCLOCKCALI_FINE_STEP_S)
#define RTCLOCKCALI_FINE_STEP_V  0x000000FFU
#define RTCLOCKCALI_FINE_STEP_S  8
/** RTCLOCKCALI_COARSE_STEP_FAST : R/W; bitpos: [23:16]; default: 8;
 *  Frequency coarse step,use to decrease calibration time.
 */
#define RTCLOCKCALI_COARSE_STEP_FAST    0x000000FFU
#define RTCLOCKCALI_COARSE_STEP_FAST_M  (RTCLOCKCALI_COARSE_STEP_FAST_V << RTCLOCKCALI_COARSE_STEP_FAST_S)
#define RTCLOCKCALI_COARSE_STEP_FAST_V  0x000000FFU
#define RTCLOCKCALI_COARSE_STEP_FAST_S  16
/** RTCLOCKCALI_COARSE_STEP_SLOW : R/W; bitpos: [31:24]; default: 8;
 *  Frequency coarse step,use to decrease calibration time.
 */
#define RTCLOCKCALI_COARSE_STEP_SLOW    0x000000FFU
#define RTCLOCKCALI_COARSE_STEP_SLOW_M  (RTCLOCKCALI_COARSE_STEP_SLOW_V << RTCLOCKCALI_COARSE_STEP_SLOW_S)
#define RTCLOCKCALI_COARSE_STEP_SLOW_V  0x000000FFU
#define RTCLOCKCALI_COARSE_STEP_SLOW_S  24

/** RTCLOCKCALI_CALI_EN_REG register
 *  Configure register.
 */
#define RTCLOCKCALI_CALI_EN_REG (DR_REG_RTCLOCKCALI_BASE + 0x2c)
/** RTCLOCKCALI_CALI_EN_32K : R/W; bitpos: [0]; default: 1;
 *  need_des
 */
#define RTCLOCKCALI_CALI_EN_32K    (BIT(0))
#define RTCLOCKCALI_CALI_EN_32K_M  (RTCLOCKCALI_CALI_EN_32K_V << RTCLOCKCALI_CALI_EN_32K_S)
#define RTCLOCKCALI_CALI_EN_32K_V  0x00000001U
#define RTCLOCKCALI_CALI_EN_32K_S  0
/** RTCLOCKCALI_CALI_EN_FOSC : R/W; bitpos: [1]; default: 0;
 *  need_des
 */
#define RTCLOCKCALI_CALI_EN_FOSC    (BIT(1))
#define RTCLOCKCALI_CALI_EN_FOSC_M  (RTCLOCKCALI_CALI_EN_FOSC_V << RTCLOCKCALI_CALI_EN_FOSC_S)
#define RTCLOCKCALI_CALI_EN_FOSC_V  0x00000001U
#define RTCLOCKCALI_CALI_EN_FOSC_S  1
/** RTCLOCKCALI_CALI_EN_SOSC : R/W; bitpos: [2]; default: 0;
 *  need_des
 */
#define RTCLOCKCALI_CALI_EN_SOSC    (BIT(2))
#define RTCLOCKCALI_CALI_EN_SOSC_M  (RTCLOCKCALI_CALI_EN_SOSC_V << RTCLOCKCALI_CALI_EN_SOSC_S)
#define RTCLOCKCALI_CALI_EN_SOSC_V  0x00000001U
#define RTCLOCKCALI_CALI_EN_SOSC_S  2

/** RTCLOCKCALI_DFREQ_VALUE_REG register
 *  Configure register.
 */
#define RTCLOCKCALI_DFREQ_VALUE_REG (DR_REG_RTCLOCKCALI_BASE + 0x30)
/** RTCLOCKCALI_DREQ_32K : RO; bitpos: [11:2]; default: 172;
 *  The value of dfreq num of 32k.
 */
#define RTCLOCKCALI_DREQ_32K    0x000003FFU
#define RTCLOCKCALI_DREQ_32K_M  (RTCLOCKCALI_DREQ_32K_V << RTCLOCKCALI_DREQ_32K_S)
#define RTCLOCKCALI_DREQ_32K_V  0x000003FFU
#define RTCLOCKCALI_DREQ_32K_S  2
/** RTCLOCKCALI_DREQ_FOSC : RO; bitpos: [21:12]; default: 172;
 *  The value of dfreq num of FOSC.
 */
#define RTCLOCKCALI_DREQ_FOSC    0x000003FFU
#define RTCLOCKCALI_DREQ_FOSC_M  (RTCLOCKCALI_DREQ_FOSC_V << RTCLOCKCALI_DREQ_FOSC_S)
#define RTCLOCKCALI_DREQ_FOSC_V  0x000003FFU
#define RTCLOCKCALI_DREQ_FOSC_S  12
/** RTCLOCKCALI_DREQ_SOSC : RO; bitpos: [31:22]; default: 172;
 *  The value of dfreq num of SOSC.
 */
#define RTCLOCKCALI_DREQ_SOSC    0x000003FFU
#define RTCLOCKCALI_DREQ_SOSC_M  (RTCLOCKCALI_DREQ_SOSC_V << RTCLOCKCALI_DREQ_SOSC_S)
#define RTCLOCKCALI_DREQ_SOSC_V  0x000003FFU
#define RTCLOCKCALI_DREQ_SOSC_S  22

/** RTCLOCKCALI_BYPASS_REG register
 *  Configure register.
 */
#define RTCLOCKCALI_BYPASS_REG (DR_REG_RTCLOCKCALI_BASE + 0x34)
/** RTCLOCKCALI_HP_SLEEP_AUTOCALI : R/W; bitpos: [30]; default: 0;
 *  1:Chip begin to calibrating,when into hp_sleep.0:Disable this function.
 */
#define RTCLOCKCALI_HP_SLEEP_AUTOCALI    (BIT(30))
#define RTCLOCKCALI_HP_SLEEP_AUTOCALI_M  (RTCLOCKCALI_HP_SLEEP_AUTOCALI_V << RTCLOCKCALI_HP_SLEEP_AUTOCALI_S)
#define RTCLOCKCALI_HP_SLEEP_AUTOCALI_V  0x00000001U
#define RTCLOCKCALI_HP_SLEEP_AUTOCALI_S  30
/** RTCLOCKCALI_LP_SLEEP_AUTOCALI : R/W; bitpos: [31]; default: 0;
 *  1:Chip begin to calibrating,when into lp_sleep.0:Disable this function.
 */
#define RTCLOCKCALI_LP_SLEEP_AUTOCALI    (BIT(31))
#define RTCLOCKCALI_LP_SLEEP_AUTOCALI_M  (RTCLOCKCALI_LP_SLEEP_AUTOCALI_V << RTCLOCKCALI_LP_SLEEP_AUTOCALI_S)
#define RTCLOCKCALI_LP_SLEEP_AUTOCALI_V  0x00000001U
#define RTCLOCKCALI_LP_SLEEP_AUTOCALI_S  31

/** RTCLOCKCALI_INT_RAW_REG register
 *  Configure register.
 */
#define RTCLOCKCALI_INT_RAW_REG (DR_REG_RTCLOCKCALI_BASE + 0x38)
/** RTCLOCKCALI_XTAL_TIMEOUT_INT_RAW : R/WTC/SS; bitpos: [29]; default: 0;
 *  Indicate the xtal timeout  once happened .
 */
#define RTCLOCKCALI_XTAL_TIMEOUT_INT_RAW    (BIT(29))
#define RTCLOCKCALI_XTAL_TIMEOUT_INT_RAW_M  (RTCLOCKCALI_XTAL_TIMEOUT_INT_RAW_V << RTCLOCKCALI_XTAL_TIMEOUT_INT_RAW_S)
#define RTCLOCKCALI_XTAL_TIMEOUT_INT_RAW_V  0x00000001U
#define RTCLOCKCALI_XTAL_TIMEOUT_INT_RAW_S  29
/** RTCLOCKCALI_CALI_TIMEOUT_INT_RAW : R/WTC/SS; bitpos: [30]; default: 0;
 *  Indicate the calibration timeout  once happened .
 */
#define RTCLOCKCALI_CALI_TIMEOUT_INT_RAW    (BIT(30))
#define RTCLOCKCALI_CALI_TIMEOUT_INT_RAW_M  (RTCLOCKCALI_CALI_TIMEOUT_INT_RAW_V << RTCLOCKCALI_CALI_TIMEOUT_INT_RAW_S)
#define RTCLOCKCALI_CALI_TIMEOUT_INT_RAW_V  0x00000001U
#define RTCLOCKCALI_CALI_TIMEOUT_INT_RAW_S  30
/** RTCLOCKCALI_CALI_DONE_INT_RAW : R/WTC/SS; bitpos: [31]; default: 0;
 *  Indicate the finish of once calibration .
 */
#define RTCLOCKCALI_CALI_DONE_INT_RAW    (BIT(31))
#define RTCLOCKCALI_CALI_DONE_INT_RAW_M  (RTCLOCKCALI_CALI_DONE_INT_RAW_V << RTCLOCKCALI_CALI_DONE_INT_RAW_S)
#define RTCLOCKCALI_CALI_DONE_INT_RAW_V  0x00000001U
#define RTCLOCKCALI_CALI_DONE_INT_RAW_S  31

/** RTCLOCKCALI_INT_ST_REG register
 *  Interrupt state register.
 */
#define RTCLOCKCALI_INT_ST_REG (DR_REG_RTCLOCKCALI_BASE + 0x3c)
/** RTCLOCKCALI_XTAL_TIMEOUT_INT_ST : RO; bitpos: [29]; default: 0;
 *  Interrupt state register.
 */
#define RTCLOCKCALI_XTAL_TIMEOUT_INT_ST    (BIT(29))
#define RTCLOCKCALI_XTAL_TIMEOUT_INT_ST_M  (RTCLOCKCALI_XTAL_TIMEOUT_INT_ST_V << RTCLOCKCALI_XTAL_TIMEOUT_INT_ST_S)
#define RTCLOCKCALI_XTAL_TIMEOUT_INT_ST_V  0x00000001U
#define RTCLOCKCALI_XTAL_TIMEOUT_INT_ST_S  29
/** RTCLOCKCALI_CALI_TIMEOUT_INT_ST : RO; bitpos: [30]; default: 0;
 *  Interrupt state register.
 */
#define RTCLOCKCALI_CALI_TIMEOUT_INT_ST    (BIT(30))
#define RTCLOCKCALI_CALI_TIMEOUT_INT_ST_M  (RTCLOCKCALI_CALI_TIMEOUT_INT_ST_V << RTCLOCKCALI_CALI_TIMEOUT_INT_ST_S)
#define RTCLOCKCALI_CALI_TIMEOUT_INT_ST_V  0x00000001U
#define RTCLOCKCALI_CALI_TIMEOUT_INT_ST_S  30
/** RTCLOCKCALI_CALI_DONE_INT_ST : RO; bitpos: [31]; default: 0;
 *  Interrupt state register.
 */
#define RTCLOCKCALI_CALI_DONE_INT_ST    (BIT(31))
#define RTCLOCKCALI_CALI_DONE_INT_ST_M  (RTCLOCKCALI_CALI_DONE_INT_ST_V << RTCLOCKCALI_CALI_DONE_INT_ST_S)
#define RTCLOCKCALI_CALI_DONE_INT_ST_V  0x00000001U
#define RTCLOCKCALI_CALI_DONE_INT_ST_S  31

/** RTCLOCKCALI_INT_ENA_REG register
 *  Configure register.
 */
#define RTCLOCKCALI_INT_ENA_REG (DR_REG_RTCLOCKCALI_BASE + 0x40)
/** RTCLOCKCALI_XTAL_TIMEOUT_INT_ENA : R/W; bitpos: [29]; default: 0;
 *  Interrupt enable signal.
 */
#define RTCLOCKCALI_XTAL_TIMEOUT_INT_ENA    (BIT(29))
#define RTCLOCKCALI_XTAL_TIMEOUT_INT_ENA_M  (RTCLOCKCALI_XTAL_TIMEOUT_INT_ENA_V << RTCLOCKCALI_XTAL_TIMEOUT_INT_ENA_S)
#define RTCLOCKCALI_XTAL_TIMEOUT_INT_ENA_V  0x00000001U
#define RTCLOCKCALI_XTAL_TIMEOUT_INT_ENA_S  29
/** RTCLOCKCALI_CALI_TIMEOUT_INT_ENA : R/W; bitpos: [30]; default: 0;
 *  Interrupt enable signal.
 */
#define RTCLOCKCALI_CALI_TIMEOUT_INT_ENA    (BIT(30))
#define RTCLOCKCALI_CALI_TIMEOUT_INT_ENA_M  (RTCLOCKCALI_CALI_TIMEOUT_INT_ENA_V << RTCLOCKCALI_CALI_TIMEOUT_INT_ENA_S)
#define RTCLOCKCALI_CALI_TIMEOUT_INT_ENA_V  0x00000001U
#define RTCLOCKCALI_CALI_TIMEOUT_INT_ENA_S  30
/** RTCLOCKCALI_CALI_DONE_INT_ENA : R/W; bitpos: [31]; default: 0;
 *  Interrupt enable signal.
 */
#define RTCLOCKCALI_CALI_DONE_INT_ENA    (BIT(31))
#define RTCLOCKCALI_CALI_DONE_INT_ENA_M  (RTCLOCKCALI_CALI_DONE_INT_ENA_V << RTCLOCKCALI_CALI_DONE_INT_ENA_S)
#define RTCLOCKCALI_CALI_DONE_INT_ENA_V  0x00000001U
#define RTCLOCKCALI_CALI_DONE_INT_ENA_S  31

/** RTCLOCKCALI_INT_CLR_REG register
 *  Configure register.
 */
#define RTCLOCKCALI_INT_CLR_REG (DR_REG_RTCLOCKCALI_BASE + 0x44)
/** RTCLOCKCALI_XTAL_TIMEOUT_INT_CLR : WT; bitpos: [29]; default: 0;
 *  interrupt clear signal.
 */
#define RTCLOCKCALI_XTAL_TIMEOUT_INT_CLR    (BIT(29))
#define RTCLOCKCALI_XTAL_TIMEOUT_INT_CLR_M  (RTCLOCKCALI_XTAL_TIMEOUT_INT_CLR_V << RTCLOCKCALI_XTAL_TIMEOUT_INT_CLR_S)
#define RTCLOCKCALI_XTAL_TIMEOUT_INT_CLR_V  0x00000001U
#define RTCLOCKCALI_XTAL_TIMEOUT_INT_CLR_S  29
/** RTCLOCKCALI_CALI_TIMEOUT_INT_CLR : WT; bitpos: [30]; default: 0;
 *  interrupt clear signal.
 */
#define RTCLOCKCALI_CALI_TIMEOUT_INT_CLR    (BIT(30))
#define RTCLOCKCALI_CALI_TIMEOUT_INT_CLR_M  (RTCLOCKCALI_CALI_TIMEOUT_INT_CLR_V << RTCLOCKCALI_CALI_TIMEOUT_INT_CLR_S)
#define RTCLOCKCALI_CALI_TIMEOUT_INT_CLR_V  0x00000001U
#define RTCLOCKCALI_CALI_TIMEOUT_INT_CLR_S  30
/** RTCLOCKCALI_CALI_DONE_INT_CLR : WT; bitpos: [31]; default: 0;
 *  interrupt clear signal.
 */
#define RTCLOCKCALI_CALI_DONE_INT_CLR    (BIT(31))
#define RTCLOCKCALI_CALI_DONE_INT_CLR_M  (RTCLOCKCALI_CALI_DONE_INT_CLR_V << RTCLOCKCALI_CALI_DONE_INT_CLR_S)
#define RTCLOCKCALI_CALI_DONE_INT_CLR_V  0x00000001U
#define RTCLOCKCALI_CALI_DONE_INT_CLR_S  31

/** RTCLOCKCALI_TIMEOUT_REG register
 *  Configure register.
 */
#define RTCLOCKCALI_TIMEOUT_REG (DR_REG_RTCLOCKCALI_BASE + 0x48)
/** RTCLOCKCALI_TIMEOUT_TARGET : R/W; bitpos: [29:0]; default: 0;
 *  use to setting max calibration time .
 */
#define RTCLOCKCALI_TIMEOUT_TARGET    0x3FFFFFFFU
#define RTCLOCKCALI_TIMEOUT_TARGET_M  (RTCLOCKCALI_TIMEOUT_TARGET_V << RTCLOCKCALI_TIMEOUT_TARGET_S)
#define RTCLOCKCALI_TIMEOUT_TARGET_V  0x3FFFFFFFU
#define RTCLOCKCALI_TIMEOUT_TARGET_S  0
/** RTCLOCKCALI_TIMEOUT_EN : R/W; bitpos: [31]; default: 0;
 *  use to enable calibration time-out function ,the calibration force stopping,when
 *  timeout.
 */
#define RTCLOCKCALI_TIMEOUT_EN    (BIT(31))
#define RTCLOCKCALI_TIMEOUT_EN_M  (RTCLOCKCALI_TIMEOUT_EN_V << RTCLOCKCALI_TIMEOUT_EN_S)
#define RTCLOCKCALI_TIMEOUT_EN_V  0x00000001U
#define RTCLOCKCALI_TIMEOUT_EN_S  31

/** RTCLOCKCALI_XTAL_TIMEOUT_REG register
 *  Configure register.
 */
#define RTCLOCKCALI_XTAL_TIMEOUT_REG (DR_REG_RTCLOCKCALI_BASE + 0x4c)
/** RTCLOCKCALI_XTAL_TIMEOUT_CNT_TARGET : R/W; bitpos: [29:14]; default: 65535;
 *  use to setting max xtal monitor time .
 */
#define RTCLOCKCALI_XTAL_TIMEOUT_CNT_TARGET    0x0000FFFFU
#define RTCLOCKCALI_XTAL_TIMEOUT_CNT_TARGET_M  (RTCLOCKCALI_XTAL_TIMEOUT_CNT_TARGET_V << RTCLOCKCALI_XTAL_TIMEOUT_CNT_TARGET_S)
#define RTCLOCKCALI_XTAL_TIMEOUT_CNT_TARGET_V  0x0000FFFFU
#define RTCLOCKCALI_XTAL_TIMEOUT_CNT_TARGET_S  14
/** RTCLOCKCALI_XTAL_TIMEOUT_CNT_STOP : WT; bitpos: [30]; default: 0;
 *  use to stop XTAL time-out function ,timeout happened when xtal invalid.
 */
#define RTCLOCKCALI_XTAL_TIMEOUT_CNT_STOP    (BIT(30))
#define RTCLOCKCALI_XTAL_TIMEOUT_CNT_STOP_M  (RTCLOCKCALI_XTAL_TIMEOUT_CNT_STOP_V << RTCLOCKCALI_XTAL_TIMEOUT_CNT_STOP_S)
#define RTCLOCKCALI_XTAL_TIMEOUT_CNT_STOP_V  0x00000001U
#define RTCLOCKCALI_XTAL_TIMEOUT_CNT_STOP_S  30
/** RTCLOCKCALI_XTAL_TIMEOUT_CNT_START : WT; bitpos: [31]; default: 0;
 *  use to start XTAL time-out function ,timeout happened when xtal invalid.
 */
#define RTCLOCKCALI_XTAL_TIMEOUT_CNT_START    (BIT(31))
#define RTCLOCKCALI_XTAL_TIMEOUT_CNT_START_M  (RTCLOCKCALI_XTAL_TIMEOUT_CNT_START_V << RTCLOCKCALI_XTAL_TIMEOUT_CNT_START_S)
#define RTCLOCKCALI_XTAL_TIMEOUT_CNT_START_V  0x00000001U
#define RTCLOCKCALI_XTAL_TIMEOUT_CNT_START_S  31

/** RTCLOCKCALI_DATE_REG register
 *  Configure register.
 */
#define RTCLOCKCALI_DATE_REG (DR_REG_RTCLOCKCALI_BASE + 0x3fc)
/** RTCLOCKCALI_RTCLOCKCALI_DATE : R/W; bitpos: [30:0]; default: 35660384;
 *  need_des
 */
#define RTCLOCKCALI_RTCLOCKCALI_DATE    0x7FFFFFFFU
#define RTCLOCKCALI_RTCLOCKCALI_DATE_M  (RTCLOCKCALI_RTCLOCKCALI_DATE_V << RTCLOCKCALI_RTCLOCKCALI_DATE_S)
#define RTCLOCKCALI_RTCLOCKCALI_DATE_V  0x7FFFFFFFU
#define RTCLOCKCALI_RTCLOCKCALI_DATE_S  0
/** RTCLOCKCALI_CLK_EN : R/W; bitpos: [31]; default: 0;
 *  need_des
 */
#define RTCLOCKCALI_CLK_EN    (BIT(31))
#define RTCLOCKCALI_CLK_EN_M  (RTCLOCKCALI_CLK_EN_V << RTCLOCKCALI_CLK_EN_S)
#define RTCLOCKCALI_CLK_EN_V  0x00000001U
#define RTCLOCKCALI_CLK_EN_S  31

#ifdef __cplusplus
}
#endif