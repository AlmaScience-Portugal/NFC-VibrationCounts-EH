/*
 * Copyright 2018 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>
#include "fsl_common.h"
#include "clock_config.h"
#include "board.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define LED_ROW0_PIN 2
#define LED_ROW1_PIN 7
#define LED_ROW2_PIN 8
#define LED_ROW3_PIN 9
#define LED_ROW4_PIN 1
#define LED_ROW5_PIN 0
#define LED_ROW6_PIN 3
#define LED_COL0_PIN 6
#define LED_COL1_PIN 5
#define LED_COL2_PIN 4
#define LED_COL3_PIN 10
#define LED_COL4_PIN 11

#define LED_ROW0_PIN_MASK (1U << LED_ROW0_PIN)
#define LED_ROW1_PIN_MASK (1U << LED_ROW1_PIN)
#define LED_ROW2_PIN_MASK (1U << LED_ROW2_PIN)
#define LED_ROW3_PIN_MASK (1U << LED_ROW3_PIN)
#define LED_ROW4_PIN_MASK (1U << LED_ROW4_PIN)
#define LED_ROW5_PIN_MASK (1U << LED_ROW5_PIN)
#define LED_ROW6_PIN_MASK (1U << LED_ROW6_PIN)
#define LED_COL0_PIN_MASK (1U << LED_COL0_PIN)
#define LED_COL1_PIN_MASK (1U << LED_COL1_PIN)
#define LED_COL2_PIN_MASK (1U << LED_COL2_PIN)
#define LED_COL3_PIN_MASK (1U << LED_COL3_PIN)
#define LED_COL4_PIN_MASK (1U << LED_COL4_PIN)

/*
 * The board LED matrix is 5*7, because LED_COL_3 and LED_COL_4 are used as
 * SWD pins, so here only use the 3*5 matrix.
 */
#define LED_COL_NUM 3
#define LED_ROW_NUM 5

#define LED_COL_PIN_MASK (LED_COL0_PIN_MASK | LED_COL1_PIN_MASK | LED_COL2_PIN_MASK)
#define LED_ROW_PIN_MASK \
    (LED_ROW0_PIN_MASK | LED_ROW1_PIN_MASK | LED_ROW2_PIN_MASK | LED_ROW3_PIN_MASK | LED_ROW4_PIN_MASK)
#define LED_PIN_MASK (LED_ROW_PIN_MASK | LED_COL_PIN_MASK)

/*******************************************************************************
 * Variables
 ******************************************************************************/
static bool s_ledMatrixInited;

static const uint16_t s_colPinMask[LED_COL_NUM] = {
    (~LED_COL0_PIN_MASK) & LED_COL_PIN_MASK, /* col 0 */
    (~LED_COL1_PIN_MASK) & LED_COL_PIN_MASK, /* col 1 */
    (~LED_COL2_PIN_MASK) & LED_COL_PIN_MASK, /* col 2 */
};

static const uint16_t s_rowPinMask[10][LED_COL_NUM] = {
    /* 0 */
    {
        LED_ROW0_PIN_MASK | LED_ROW1_PIN_MASK | LED_ROW2_PIN_MASK | LED_ROW3_PIN_MASK | LED_ROW4_PIN_MASK, /* Col 0 */
        LED_ROW0_PIN_MASK | LED_ROW4_PIN_MASK,                                                             /* Col 1 */
        LED_ROW0_PIN_MASK | LED_ROW1_PIN_MASK | LED_ROW2_PIN_MASK | LED_ROW3_PIN_MASK | LED_ROW4_PIN_MASK, /* Col 2 */
    },

    /* 1 */
    {
        0,                                                                                                 /* Col 0 */
        0,                                                                                                 /* Col 1 */
        LED_ROW0_PIN_MASK | LED_ROW1_PIN_MASK | LED_ROW2_PIN_MASK | LED_ROW3_PIN_MASK | LED_ROW4_PIN_MASK, /* Col 2 */
    },

    /* 2 */
    {
        LED_ROW0_PIN_MASK | LED_ROW2_PIN_MASK | LED_ROW3_PIN_MASK | LED_ROW4_PIN_MASK, /* Col 0 */
        LED_ROW0_PIN_MASK | LED_ROW2_PIN_MASK | LED_ROW4_PIN_MASK,                     /* Col 1 */
        LED_ROW0_PIN_MASK | LED_ROW1_PIN_MASK | LED_ROW2_PIN_MASK | LED_ROW4_PIN_MASK, /* Col 2 */
    },

    /* 3 */
    {
        LED_ROW0_PIN_MASK | LED_ROW2_PIN_MASK | LED_ROW4_PIN_MASK,                                         /* Col 0 */
        LED_ROW0_PIN_MASK | LED_ROW2_PIN_MASK | LED_ROW4_PIN_MASK,                                         /* Col 1 */
        LED_ROW0_PIN_MASK | LED_ROW1_PIN_MASK | LED_ROW2_PIN_MASK | LED_ROW3_PIN_MASK | LED_ROW4_PIN_MASK, /* Col 2 */
    },

    /* 4 */
    {
        LED_ROW0_PIN_MASK | LED_ROW1_PIN_MASK | LED_ROW2_PIN_MASK,                                         /* Col 0 */
        LED_ROW2_PIN_MASK,                                                                                 /* Col 1 */
        LED_ROW0_PIN_MASK | LED_ROW1_PIN_MASK | LED_ROW2_PIN_MASK | LED_ROW3_PIN_MASK | LED_ROW4_PIN_MASK, /* Col 2 */
    },

    /* 5 */
    {
        LED_ROW0_PIN_MASK | LED_ROW1_PIN_MASK | LED_ROW2_PIN_MASK | LED_ROW4_PIN_MASK, /* Col 0 */
        LED_ROW0_PIN_MASK | LED_ROW2_PIN_MASK | LED_ROW4_PIN_MASK,                     /* Col 1 */
        LED_ROW0_PIN_MASK | LED_ROW2_PIN_MASK | LED_ROW3_PIN_MASK | LED_ROW4_PIN_MASK, /* Col 2 */
    },

    /* 6 */
    {
        LED_ROW0_PIN_MASK | LED_ROW1_PIN_MASK | LED_ROW2_PIN_MASK | LED_ROW3_PIN_MASK | LED_ROW4_PIN_MASK, /* Col 0 */
        LED_ROW0_PIN_MASK | LED_ROW2_PIN_MASK | LED_ROW4_PIN_MASK,                                         /* Col 1 */
        LED_ROW0_PIN_MASK | LED_ROW2_PIN_MASK | LED_ROW3_PIN_MASK | LED_ROW4_PIN_MASK,                     /* Col 2 */
    },

    /* 7 */
    {
        LED_ROW0_PIN_MASK,                                                                                 /* Col 0 */
        LED_ROW0_PIN_MASK,                                                                                 /* Col 1 */
        LED_ROW0_PIN_MASK | LED_ROW1_PIN_MASK | LED_ROW2_PIN_MASK | LED_ROW3_PIN_MASK | LED_ROW4_PIN_MASK, /* Col 2 */
    },

    /* 8 */
    {
        LED_ROW0_PIN_MASK | LED_ROW1_PIN_MASK | LED_ROW2_PIN_MASK | LED_ROW3_PIN_MASK | LED_ROW4_PIN_MASK, /* Col 0 */
        LED_ROW0_PIN_MASK | LED_ROW2_PIN_MASK | LED_ROW4_PIN_MASK,                                         /* Col 1 */
        LED_ROW0_PIN_MASK | LED_ROW1_PIN_MASK | LED_ROW2_PIN_MASK | LED_ROW3_PIN_MASK | LED_ROW4_PIN_MASK, /* Col 2 */
    },

    /* 9 */
    {
        LED_ROW0_PIN_MASK | LED_ROW1_PIN_MASK | LED_ROW2_PIN_MASK | LED_ROW4_PIN_MASK,                     /* Col 0 */
        LED_ROW0_PIN_MASK | LED_ROW2_PIN_MASK | LED_ROW4_PIN_MASK,                                         /* Col 1 */
        LED_ROW0_PIN_MASK | LED_ROW1_PIN_MASK | LED_ROW2_PIN_MASK | LED_ROW3_PIN_MASK | LED_ROW4_PIN_MASK, /* Col 2 */
    },
};

/*******************************************************************************
 * Code
 ******************************************************************************/

void BOARD_InitLedMatrix(void)
{
    s_ledMatrixInited = true;

    CLOCK_EnableClock(kCLOCK_Iocon);
    CLOCK_EnableClock(kCLOCK_Gpio);

    IOCON->PIO[0][LED_ROW0_PIN] = IOCON_PIO_FUNC(0);
    IOCON->PIO[0][LED_ROW1_PIN] = IOCON_PIO_FUNC(0);
    IOCON->PIO[0][LED_ROW2_PIN] = IOCON_PIO_FUNC(0);
    IOCON->PIO[0][LED_ROW3_PIN] = IOCON_PIO_FUNC(0);
    IOCON->PIO[0][LED_ROW4_PIN] = IOCON_PIO_FUNC(0);
    IOCON->PIO[0][LED_COL0_PIN] = IOCON_PIO_FUNC(0);
    IOCON->PIO[0][LED_COL1_PIN] = IOCON_PIO_FUNC(0);
    IOCON->PIO[0][LED_COL2_PIN] = IOCON_PIO_FUNC(0);

    GPIO->DIR |= LED_PIN_MASK;
    GPIO->GPIODATA[2047] = (LED_ROW_PIN_MASK & ~(LED_COL_PIN_MASK));
}

void BOARD_LedMatrixDelay(void)
{
    uint32_t systemClockFreq_kHz = SystemCoreClock / 1000;

    while (systemClockFreq_kHz--)
    {
        __NOP();
    }
}

void BOARD_LedMatrixShowNumber(uint8_t num, uint32_t duration, bool forceInit)
{
    uint32_t i;
    uint32_t inc = (duration == 0) ? 0 : 1;
    uint32_t gpioData;
    uint8_t col;

    duration = (duration == 0) ? 1 : duration;
    num      = (num > 9) ? 9 : num;

    if ((!s_ledMatrixInited) || forceInit)
    {
        BOARD_InitLedMatrix();
    }

    gpioData = GPIO->GPIODATA[2047] & ~LED_PIN_MASK;

    for (i = 0; i < duration; i += inc)
    {
        for (col = 0; col < LED_COL_NUM; col++)
        {
            GPIO->GPIODATA[2047] = gpioData | s_rowPinMask[num][col] | s_colPinMask[col];
            BOARD_LedMatrixDelay();
        }
    }
}
