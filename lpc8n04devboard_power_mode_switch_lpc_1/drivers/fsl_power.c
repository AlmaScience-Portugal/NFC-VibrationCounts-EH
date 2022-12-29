/*
 * Copyright 2018, NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_power.h"
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.power_no_lib"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * brief API to read PMU register.
 *
 * param regAddr address of PMU register.
 * return register value.
 */
uint32_t POWER_ReadPmuReg(void *regAddr)
{
    /* To prevent from being optimized in release mode, use volatile keyword to decorate. */
    volatile uint32_t regValue = 0;
    uint32_t *addr             = regAddr;

    /* wait PMU access status ready */
    while (!POWER_GetPmuAccessReadyStat())
    {
    }
    /* request read */
    regValue = *addr;
    /* wait command complete */
    while (!POWER_GetPmuAccessReadyStat())
    {
    }

    /* load data from buffer */
    regValue = *addr;

    return regValue;
}

/*!
 * brief API to write PMU register.
 *
 * param regAddr address of PMU register.
 * param regValue value to write.
 * return none
 */
void POWER_WritePmuReg(void *regAddr, uint32_t regValue)
{
    /* wait PMU access status ready */
    while (!POWER_GetPmuAccessReadyStat())
    {
    }
    /* write data */
    *(uint32_t *)regAddr = regValue;
    /* wait command load into PMU finish */
    while (!POWER_GetPmuAccessReadyStat())
    {
    }
}

/*!
 * brief API to set PMU register bit.
 *
 * param regAddr address of PMU register.
 * param mask bit mask.
 * return none
 */
void POWER_SetPmuRegBit(void *regAddr, uint32_t mask)
{
    uint32_t regValue = POWER_ReadPmuReg(regAddr);

    regValue |= mask;
    POWER_WritePmuReg(regAddr, regValue);
}

/*!
 * brief API to clr PMU register bit.
 *
 * param regAddr address of PMU register.
 * param mask bit mask.
 * return none
 */
void POWER_ClrPmuRegBit(void *regAddr, uint32_t mask)
{
    uint32_t regValue = POWER_ReadPmuReg(regAddr);

    regValue &= ~mask;

    POWER_WritePmuReg(regAddr, regValue);
}

/*!
 * brief API to select power source.
 *
 * param sel power source.
 */
void POWER_SelectPowerSource(power_src_sel_t sel)
{
    switch (sel)
    {
        case kPmu_PowerSourceFromVBAT:
            POWER_SetPmuRegBit((void *)(uint32_t *)(uint32_t)(&PMU->PCON), 1UL << 17U);
            break;

        case kPmu_PowerSourceFromNFC:
            POWER_SetPmuRegBit((void *)(uint32_t *)(uint32_t)(&PMU->PCON), 1UL << 18U);
            break;

        case kPmu_PowerSourceAutoSwitch:
            POWER_SetPmuRegBit((void *)(uint32_t *)(uint32_t)(&PMU->PCON), PMU_PCON_FORCEVBAT_FORCEVNFC_MASK);
            POWER_ClrPmuRegBit((void *)(uint32_t *)(uint32_t)(&PMU->PCON), PMU_PCON_PMULPM_MASK);
            break;

        default:
            /* All cases have been listed above, the default clause should not be reached. */
            assert(false);
            break;
    }
}

/*!
 * brief API to enter sleep power mode.
 *
 * return none
 */
void POWER_EnterSleep(void)
{
    uint32_t pmsk;

    pmsk = __get_PRIMASK();
    __disable_irq();

    /* clear DPEN bit first */
    POWER_ClrPmuRegBit((void *)(uint32_t *)(uint32_t)(&PMU->PCON), PMU_PCON_DPEN_MASK);

    /* disable Deepsleep mode in the ARM-CORTEX M0+ SCR register */
    SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;

    /* make sure outstanding memory transactions complete */
    __DSB();
    /* Enter powerdown mode */
    __WFI();
    /* make sure no instruction is excuted until wake up */
    __ISB();

    __set_PRIMASK(pmsk);
}

/*!
 * brief API to enter deep sleep power mode.
 *
 * param activePart: should be a single or combine value of _power_deep_sleep_active .
 * return none
 */
void POWER_EnterDeepSleep(void)
{
    uint32_t pmsk;

    pmsk = __get_PRIMASK();
    __disable_irq();

    /* clear DPEN bit first */
    POWER_ClrPmuRegBit((void *)(uint32_t *)(uint32_t)(&PMU->PCON), PMU_PCON_DPEN_MASK);

    /* enable Deepsleep mode in the ARM-CORTEX M0+ SCR register */
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

    /* make sure outstanding memory transactions complete */
    __DSB();
    /* Enter powerdown mode */
    __WFI();
    /* make sure no instruction is excuted until wake up */
    __ISB();

    /* disable Deepsleep mode in the ARM-CORTEX M0+ SCR register */
    SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
    __set_PRIMASK(pmsk);
}

/*!
 * brief API to enter deep power down mode.
 *
 * return none
 */
void POWER_EnterDeepPowerDownMode(void)
{
    uint32_t pmsk;

    pmsk = __get_PRIMASK();
    __disable_irq();

    /* enable DPD */
    POWER_SetPmuRegBit((void *)(uint32_t *)(uint32_t)(&PMU->PCON), PMU_PCON_DPEN_MASK);

    /* enable Deepsleep mode in the ARM-CORTEX M0+ SCR register */
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

    /* make sure outstanding memory transactions complete */
    __DSB();
    /* Enter powerdown mode */
    __WFI();
    /* make sure no instruction is excuted until wake up */
    __ISB();

    /* disable Deepsleep mode in the ARM-CORTEX M0+ SCR register */
    SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
    __set_PRIMASK(pmsk);
}

void EnableDeepSleepIRQ(IRQn_Type interrupt)
{
    uint32_t intNumber = (uint32_t)interrupt;

    /* enable pin interrupt wake up in the STARTERP0 register */
    SYSCON->STARTERP0 |= 1UL << intNumber;
    /* also enable interrupt at NVIC */
    (void)EnableIRQ(interrupt);
}

void DisableDeepSleepIRQ(IRQn_Type interrupt)
{
    uint32_t intNumber = (uint32_t)interrupt;

    /* also disable interrupt at NVIC */
    (void)DisableIRQ(interrupt);
    /* disable pin interrupt wake up in the STARTERP0 register */
    SYSCON->STARTERP0 &= ~(1UL << intNumber);
}
