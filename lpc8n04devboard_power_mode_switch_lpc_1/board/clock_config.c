/*
 * Copyright 2018,2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/*
 * How to set up clock using clock driver functions:
 *
 * 1. Setup clock sources.
 *
 * 2. Set up all dividers.
 *
 * 3. Set up all selectors to provide selected clocks.
 */

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Clocks v7.0
processor: LPC8N04
package_id: LPC8N04FHI24
mcu_data: ksdk2_0
processor_version: 0.7.1
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

#include "fsl_power.h"
#include "fsl_clock.h"
#include "clock_config.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* System clock frequency. */
extern uint32_t SystemCoreClock;

/*******************************************************************************
 ************************ BOARD_InitBootClocks function ************************
 ******************************************************************************/
void BOARD_InitBootClocks(void)
{
    BOARD_BootClockSFRO500kHz();
}

/*******************************************************************************
 ******************* Configuration BOARD_BootClockSFRO8MHz *********************
 ******************************************************************************/
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!Configuration
name: BOARD_BootClockSFRO8MHz
outputs:
- {id: Analog_Peripheral_clock.outFreq, value: 2 MHz}
- {id: PMU_clock.outFreq, value: 32.768 kHz}
- {id: Peripheral_clock.outFreq, value: 8 MHz}
- {id: System_clock.outFreq, value: 8 MHz}
- {id: Wakeup_clock.outFreq, value: 32.768 kHz}
settings:
- {id: SYSCON.SYSCLKDIV.scale, value: '1', locked: true}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/*******************************************************************************
 * Variables for BOARD_BootClockSFRO8MHz configuration
 ******************************************************************************/
/*******************************************************************************
 * Code for BOARD_BootClockSFRO8MHz configuration
 ******************************************************************************/
void BOARD_BootClockSFRO8MHz(void)
{
    /*!< Set up the clock sources */
    CLOCK_SetSysClkDiv(kCLOCK_SysClkFreq8MHZ); /*!< Set SYSCLKDIV */
    CLOCK_SetClkDivider(kCLOCK_DivSspClk, 0U); /*!< Set SSPCLKDIV */
    CLOCK_Select(kWDT_Clk_From_Sfro);          /*!< set WDT from SFRO */
    CLOCK_SetClkDivider(kCLOCK_DivWdtClk, 0U); /*!< Set WDTCLKDIV */
    CLOCKOUT_Enable(0);                        /*!< disable CLOCKOUT */
    /*!< Set SystemCoreClock variable. */
    SystemCoreClock = BOARD_BOOTCLOCKSFRO8MHZ_CORE_CLOCK;
}

/*******************************************************************************
 ******************* Configuration BOARD_BootClockSFRO4MHz *********************
 ******************************************************************************/
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!Configuration
name: BOARD_BootClockSFRO4MHz
outputs:
- {id: Analog_Peripheral_clock.outFreq, value: 2 MHz}
- {id: PMU_clock.outFreq, value: 32.768 kHz}
- {id: Peripheral_clock.outFreq, value: 4 MHz}
- {id: System_clock.outFreq, value: 4 MHz}
- {id: Wakeup_clock.outFreq, value: 32.768 kHz}
settings:
- {id: SYSCON.SYSCLKDIV.scale, value: '2', locked: true}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/*******************************************************************************
 * Variables for BOARD_BootClockSFRO4MHz configuration
 ******************************************************************************/
/*******************************************************************************
 * Code for BOARD_BootClockSFRO4MHz configuration
 ******************************************************************************/
void BOARD_BootClockSFRO4MHz(void)
{
    /*!< Set up the clock sources */
    CLOCK_SetSysClkDiv(kCLOCK_SysClkFreq4MHZ); /*!< Set SYSCLKDIV */
    CLOCK_SetClkDivider(kCLOCK_DivSspClk, 0U); /*!< Set SSPCLKDIV */
    CLOCK_Select(kWDT_Clk_From_Sfro);          /*!< set WDT from SFRO */
    CLOCK_SetClkDivider(kCLOCK_DivWdtClk, 0U); /*!< Set WDTCLKDIV */
    CLOCKOUT_Enable(0);                        /*!< disable CLOCKOUT */
    /*!< Set SystemCoreClock variable. */
    SystemCoreClock = BOARD_BOOTCLOCKSFRO4MHZ_CORE_CLOCK;
}

/*******************************************************************************
 ******************* Configuration BOARD_BootClockSFRO2MHz *********************
 ******************************************************************************/
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!Configuration
name: BOARD_BootClockSFRO2MHz
outputs:
- {id: Analog_Peripheral_clock.outFreq, value: 2 MHz}
- {id: PMU_clock.outFreq, value: 32.768 kHz}
- {id: Peripheral_clock.outFreq, value: 2 MHz}
- {id: System_clock.outFreq, value: 2 MHz}
- {id: Wakeup_clock.outFreq, value: 32.768 kHz}
settings:
- {id: SYSCON.SYSCLKDIV.scale, value: '4', locked: true}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/*******************************************************************************
 * Variables for BOARD_BootClockSFRO2MHz configuration
 ******************************************************************************/
/*******************************************************************************
 * Code for BOARD_BootClockSFRO2MHz configuration
 ******************************************************************************/
void BOARD_BootClockSFRO2MHz(void)
{
    /*!< Set up the clock sources */
    CLOCK_SetSysClkDiv(kCLOCK_SysClkFreq2MHZ); /*!< Set SYSCLKDIV */
    CLOCK_SetClkDivider(kCLOCK_DivSspClk, 0U); /*!< Set SSPCLKDIV */
    CLOCK_Select(kWDT_Clk_From_Sfro);          /*!< set WDT from SFRO */
    CLOCK_SetClkDivider(kCLOCK_DivWdtClk, 0U); /*!< Set WDTCLKDIV */
    CLOCKOUT_Enable(0);                        /*!< disable CLOCKOUT */
    /*!< Set SystemCoreClock variable. */
    SystemCoreClock = BOARD_BOOTCLOCKSFRO2MHZ_CORE_CLOCK;
}

/*******************************************************************************
 ******************* Configuration BOARD_BootClockSFRO1MHz *********************
 ******************************************************************************/
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!Configuration
name: BOARD_BootClockSFRO1MHz
outputs:
- {id: Analog_Peripheral_clock.outFreq, value: 2 MHz}
- {id: PMU_clock.outFreq, value: 32.768 kHz}
- {id: Peripheral_clock.outFreq, value: 1 MHz}
- {id: System_clock.outFreq, value: 1 MHz}
- {id: Wakeup_clock.outFreq, value: 32.768 kHz}
settings:
- {id: SYSCON.SYSCLKDIV.scale, value: '8', locked: true}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/*******************************************************************************
 * Variables for BOARD_BootClockSFRO1MHz configuration
 ******************************************************************************/
/*******************************************************************************
 * Code for BOARD_BootClockSFRO1MHz configuration
 ******************************************************************************/
void BOARD_BootClockSFRO1MHz(void)
{
    /*!< Set up the clock sources */
    CLOCK_SetSysClkDiv(kCLOCK_SysClkFreq1MHZ); /*!< Set SYSCLKDIV */
    CLOCK_SetClkDivider(kCLOCK_DivSspClk, 0U); /*!< Set SSPCLKDIV */
    CLOCK_Select(kWDT_Clk_From_Sfro);          /*!< set WDT from SFRO */
    CLOCK_SetClkDivider(kCLOCK_DivWdtClk, 0U); /*!< Set WDTCLKDIV */
    CLOCKOUT_Enable(0);                        /*!< disable CLOCKOUT */
    /*!< Set SystemCoreClock variable. */
    SystemCoreClock = BOARD_BOOTCLOCKSFRO1MHZ_CORE_CLOCK;
}

/*******************************************************************************
 ****************** Configuration BOARD_BootClockSFRO500kHz ********************
 ******************************************************************************/
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!Configuration
name: BOARD_BootClockSFRO500kHz
called_from_default_init: true
outputs:
- {id: Analog_Peripheral_clock.outFreq, value: 2 MHz}
- {id: PMU_clock.outFreq, value: 32.768 kHz}
- {id: Peripheral_clock.outFreq, value: 500 kHz}
- {id: System_clock.outFreq, value: 500 kHz}
- {id: Wakeup_clock.outFreq, value: 32.768 kHz}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/*******************************************************************************
 * Variables for BOARD_BootClockSFRO500kHz configuration
 ******************************************************************************/
/*******************************************************************************
 * Code for BOARD_BootClockSFRO500kHz configuration
 ******************************************************************************/
void BOARD_BootClockSFRO500kHz(void)
{
    /*!< Set up the clock sources */
    CLOCK_SetSysClkDiv(kCLOCK_SysClkFreq500KHZ); /*!< Set SYSCLKDIV */
    CLOCK_SetClkDivider(kCLOCK_DivSspClk, 0U);   /*!< Set SSPCLKDIV */
    CLOCK_Select(kWDT_Clk_From_Sfro);            /*!< set WDT from SFRO */
    CLOCK_SetClkDivider(kCLOCK_DivWdtClk, 0U);   /*!< Set WDTCLKDIV */
    CLOCKOUT_Enable(0);                          /*!< disable CLOCKOUT */
    /*!< Set SystemCoreClock variable. */
    SystemCoreClock = BOARD_BOOTCLOCKSFRO500KHZ_CORE_CLOCK;
}

/*******************************************************************************
 ****************** Configuration BOARD_BootClockSFRO250kHz ********************
 ******************************************************************************/
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!Configuration
name: BOARD_BootClockSFRO250kHz
outputs:
- {id: Analog_Peripheral_clock.outFreq, value: 2 MHz}
- {id: PMU_clock.outFreq, value: 32.768 kHz}
- {id: Peripheral_clock.outFreq, value: 250 kHz}
- {id: System_clock.outFreq, value: 250 kHz}
- {id: Wakeup_clock.outFreq, value: 32.768 kHz}
settings:
- {id: SYSCON.SYSCLKDIV.scale, value: '32', locked: true}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/*******************************************************************************
 * Variables for BOARD_BootClockSFRO250kHz configuration
 ******************************************************************************/
/*******************************************************************************
 * Code for BOARD_BootClockSFRO250kHz configuration
 ******************************************************************************/
void BOARD_BootClockSFRO250kHz(void)
{
    /*!< Set up the clock sources */
    CLOCK_SetSysClkDiv(kCLOCK_SysClkFreq250KHZ); /*!< Set SYSCLKDIV */
    CLOCK_SetClkDivider(kCLOCK_DivSspClk, 0U);   /*!< Set SSPCLKDIV */
    CLOCK_Select(kWDT_Clk_From_Sfro);            /*!< set WDT from SFRO */
    CLOCK_SetClkDivider(kCLOCK_DivWdtClk, 0U);   /*!< Set WDTCLKDIV */
    CLOCKOUT_Enable(0);                          /*!< disable CLOCKOUT */
    /*!< Set SystemCoreClock variable. */
    SystemCoreClock = BOARD_BOOTCLOCKSFRO250KHZ_CORE_CLOCK;
}

/*******************************************************************************
 ****************** Configuration BOARD_BootClockSFRO125kHz ********************
 ******************************************************************************/
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!Configuration
name: BOARD_BootClockSFRO125kHz
outputs:
- {id: Analog_Peripheral_clock.outFreq, value: 2 MHz}
- {id: PMU_clock.outFreq, value: 32.768 kHz}
- {id: Peripheral_clock.outFreq, value: 125 kHz}
- {id: System_clock.outFreq, value: 125 kHz}
- {id: Wakeup_clock.outFreq, value: 32.768 kHz}
settings:
- {id: SYSCON.SYSCLKDIV.scale, value: '64', locked: true}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/*******************************************************************************
 * Variables for BOARD_BootClockSFRO125kHz configuration
 ******************************************************************************/
/*******************************************************************************
 * Code for BOARD_BootClockSFRO125kHz configuration
 ******************************************************************************/
void BOARD_BootClockSFRO125kHz(void)
{
    /*!< Set up the clock sources */
    CLOCK_SetSysClkDiv(kCLOCK_SysClkFreq125KHZ); /*!< Set SYSCLKDIV */
    CLOCK_SetClkDivider(kCLOCK_DivSspClk, 0U);   /*!< Set SSPCLKDIV */
    CLOCK_Select(kWDT_Clk_From_Sfro);            /*!< set WDT from SFRO */
    CLOCK_SetClkDivider(kCLOCK_DivWdtClk, 0U);   /*!< Set WDTCLKDIV */
    CLOCKOUT_Enable(0);                          /*!< disable CLOCKOUT */
    /*!< Set SystemCoreClock variable. */
    SystemCoreClock = BOARD_BOOTCLOCKSFRO125KHZ_CORE_CLOCK;
}

/*******************************************************************************
 ****************** Configuration BOARD_BootClockSFRO62500Hz *******************
 ******************************************************************************/
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!Configuration
name: BOARD_BootClockSFRO62500Hz
outputs:
- {id: Analog_Peripheral_clock.outFreq, value: 2 MHz}
- {id: PMU_clock.outFreq, value: 32.768 kHz}
- {id: Peripheral_clock.outFreq, value: 62.5 kHz}
- {id: System_clock.outFreq, value: 62.5 kHz}
- {id: Wakeup_clock.outFreq, value: 32.768 kHz}
settings:
- {id: SYSCON.SYSCLKDIV.scale, value: '128', locked: true}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/*******************************************************************************
 * Variables for BOARD_BootClockSFRO62500Hz configuration
 ******************************************************************************/
/*******************************************************************************
 * Code for BOARD_BootClockSFRO62500Hz configuration
 ******************************************************************************/
void BOARD_BootClockSFRO62500Hz(void)
{
    /*!< Set up the clock sources */
    CLOCK_SetSysClkDiv(kCLOCK_SysClkFreq62500HZ); /*!< Set SYSCLKDIV */
    CLOCK_SetClkDivider(kCLOCK_DivSspClk, 0U);    /*!< Set SSPCLKDIV */
    CLOCK_Select(kWDT_Clk_From_Sfro);             /*!< set WDT from SFRO */
    CLOCK_SetClkDivider(kCLOCK_DivWdtClk, 0U);    /*!< Set WDTCLKDIV */
    CLOCKOUT_Enable(0);                           /*!< disable CLOCKOUT */
    /*!< Set SystemCoreClock variable. */
    SystemCoreClock = BOARD_BOOTCLOCKSFRO62500HZ_CORE_CLOCK;
}
