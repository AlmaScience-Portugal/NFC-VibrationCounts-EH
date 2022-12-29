/*
 * Copyright 2018 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _BOARD_H_
#define _BOARD_H_

#include "fsl_common.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief The board name */
#define BOARD_NAME "LPC8N04DEVBOARD"

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*! @brief Define the port interrupt number for the board switches */
#ifndef BOARD_USER_BUTTON_GPIO
#define BOARD_USER_BUTTON_GPIO GPIO
#endif
#ifndef BOARD_USER_BUTTON_GPIO_PIN
#define BOARD_USER_BUTTON_GPIO_PIN (0U)
#endif
#define BOARD_USER_BUTTON_IRQ         PIO0_IRQn
#define BOARD_USER_BUTTON_IRQ_HANDLER PIO0_IRQHandler
#define BOARD_USER_BUTTON_NAME        "S2"

/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * @brief Show number on the LED matrix
 *
 * This is a blocking function to show a number on the LED matrix for some time.
 * This function re-configures the IO pins, so when it is used, the peripherals
 * such as I2C, SPI should not be used.
 *
 * @param num The number to show, valid range is 0 ~ 9, if input number is larger
 * than 9, then 9 is shown.
 * @param duration The duration to show the number. If set to 0, the number is shown forever.
 * @param forceInit Set true to initialize LED pins forcefully.
 */
void BOARD_LedMatrixShowNumber(uint8_t num, uint32_t duration, bool forceInit);
void BOARD_InitLedMatrix(void);
#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* _BOARD_H_ */
