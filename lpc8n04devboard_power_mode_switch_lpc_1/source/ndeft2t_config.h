/*
 * Copyright 2019 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __NDEFT2T_CONFIG_H_
#define __NDEFT2T_CONFIG_H_

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/**
 * NDEFT2T MOD does interrupt handling by itself. So, the below callback shall be defined, to get notified on the NFC
 * field status. Refer @ref nfcIntHandling_anchor "NFC Interrupt Handling" for more details.
 * @note The value set @b must have the same signature as #pNdeft2t_FieldStatus_Cb_t.
 * @note This must be set to the name of a function, not a pointer to a function: no dereference will be made!
 */
//#define NDEFT2T_FIELD_STATUS_CB NDEFT2T_FieldStatus_Cb

/**
 * The below callback shall be defined, for the application to get notified on the presence of a valid NDEF Message in
 * shared memory. Refer @ref nfcIntHandling_anchor "NFC Interrupt Handling" for more details.
 * @note The value set @b must have the same signatures as #pNdeft2t_MsgAvailable_Cb_t.
 * @note This must be set to the name of a function, not a pointer to a function: no dereference will be made!
 */
//#define NDEFT2T_MSG_AVAILABLE_CB NDEFT2T_MsgAvailable_Cb

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void NDEFT2T_FieldStatus_Cb(bool status);
void NDEFT2T_MsgAvailable_Cb(void);

#endif /** @} */
