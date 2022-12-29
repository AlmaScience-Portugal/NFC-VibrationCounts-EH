/*
 * AlmaScience CoLAB
 * All rights reserved.
 * Developed by @Felisberto Perreira & @Shubham Das
 *
 */

#include "board.h"
#include "fsl_common.h"
#include "fsl_power.h"
#include "fsl_gpio.h"
#include "pin_mux.h"
#include "clock_config.h"

//For NFC
#include "fsl_nfc.h"
#include "ndeft2t.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DEMO_WAKEUP_PIN_NUMBER 0U
#define DEMO_WAKE_UP_PIN_IRQ   PIO0_IRQn

//For NFC
#define LPC_NFC    RFIDNFC
//#define LPC_EEPROM EEPROM


int vibrations = 0;
char vibCount[50] ;


/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void BOARD_InitLedDisplay(void);
void BOARD_LedDisplay(uint32_t num);
void BOARD_IOCON_SetPin(uint32_t pin, uint32_t func);
void BOARD_EnableDeepSleepIRQ(void);

//For NFC
void NFC_IRQHandler(void);


/** NFC peripheral instance buffer */
uint32_t instance[NDEFT2T_INSTANCE_SIZE / 4];

/** Buffer for NDEF messages */
uint32_t buffer[NFC_SHARED_MEM_BYTE_SIZE / 4 - 1];

/*******************************************************************************
 * Code
 ******************************************************************************/

void BOARD_IOCON_SetPin(uint32_t pin, uint32_t func)
{
    IOCON->PIO[0][pin] = func;
}

void BOARD_EnableDeepSleepIRQ(void)
{
    SYSCON->STARTAPRP0 |= 1 << DEMO_WAKEUP_PIN_NUMBER;
    SYSCON->STARTERP0 |= 1 << DEMO_WAKEUP_PIN_NUMBER;
}
void PIO0_IRQHandler(void)
{
    /* Change state of switch. */
    if ((GPIO_PortGetInterruptsFlags(GPIO) & (1 << DEMO_WAKEUP_PIN_NUMBER)) &&
        (GPIO_PortReadMaskedInterrupts(GPIO) & (1 << DEMO_WAKEUP_PIN_NUMBER)))
    {
    	GPIO_PortDisableInterrupts(GPIO, 1 << DEMO_WAKEUP_PIN_NUMBER);
    }
    /* clear the interrupt status */
    GPIO_PortClearInterruptFlags(GPIO, 1U << DEMO_WAKEUP_PIN_NUMBER);
}

void DEMO_PreEnterLowPower(void)
{
	BOARD_EnableDeepSleepIRQ();
    BOARD_IOCON_SetPin(DEMO_WAKEUP_PIN_NUMBER, IOCON_PIO_FUNC(0));
    GPIO_PortEnableInterrupts(GPIO, 1U << DEMO_WAKEUP_PIN_NUMBER);
}


void NFC_IRQHandler(void)
{
    NDEFT2T_IRQHandler(LPC_NFC);
}

/*!
 * @brief Main function
 */

int main(void)
{
    /* Init board hardware. */
    BOARD_InitPins();
    BOARD_InitBootClocks();
    CLOCK_SetSysClkDiv(kCLOCK_SysClkFreq4MHZ);
    SystemCoreClockUpdate();

    /* Init NFC peripheral */
  	NDEFT2T_Init(LPC_NFC);


    while (1)
    {
        /* prepare to enter low power mode */
        DEMO_PreEnterLowPower();

        GPIO_PortClearInterruptFlags(GPIO, 0xFFFU);
        EnableIRQ(DEMO_WAKE_UP_PIN_IRQ);

        ++vibrations; //Counting vibrations



        /* Create an NDEF message */
		NDEFT2T_CreateMessage(&instance, (uint8_t *)&buffer, sizeof(buffer), true);

		/* Create a TEXT type record */
		NDEFT2T_CREATE_RECORD_INFO_T record;
		record.pString     = (uint8_t *)"en";
		record.shortRecord = true;
		NDEFT2T_CreateTextRecord(&instance, &record);

		/* Copy record payload to message buffer */
		int j = snprintf (vibCount, 50, "The number of Vibrations = %d", vibrations);
		NDEFT2T_WriteRecordPayload(&instance, vibCount, strlen(vibCount));

		/* Finalize the record header */
		NDEFT2T_CommitRecord(&instance);

		/* Finalize the message header */
		NDEFT2T_CommitMessage(LPC_NFC, &instance);

		POWER_EnterDeepSleep();

    }


}



