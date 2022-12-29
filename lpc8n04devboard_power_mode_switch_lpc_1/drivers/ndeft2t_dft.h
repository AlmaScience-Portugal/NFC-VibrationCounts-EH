/*
 * Copyright (c) 2014-2016, Freescale Semiconductor, Inc.
 * Copyright 2017-2019 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @defgroup MODS_LPC8Nxx_NDEFT2T_DFT Diversity Settings
 * @ingroup MODS_LPC8Nxx_NDEFT2T
 * These 'defines' capture the diversity settings of the module. The displayed values refer to the default settings.
 * To override the default settings, place the defines with their desired values in the application ndeft2t_config.h
 * header file: the compiler will pick up your defines before parsing this file.
 *
 * @{
 */

#ifndef __NDEFT2T_DFT_H_
#define __NDEFT2T_DFT_H_

#include "ndeft2t_config.h"

/**
 * Set this flag to '1' to enable message header length correction and '0' to disable. When set to '1', it allows the
 * message to be created even if the argument 'shortMessage' in #NDEFT2T_CreateMessage API was set wrongly by the
 * caller.
 * When set to '0' the message creation will fail and an error will be returned.
 */
#if !defined(NDEFT2T_MESSAGE_HEADER_LENGTH_CORRECTION)
#define NDEFT2T_MESSAGE_HEADER_LENGTH_CORRECTION 1
#endif

/**
 * Set this flag to '1' to enable @ref colDetDesc_anchor "Shared memory access collision detection" and '0' to disable.
 */
#if !defined(NDEFT2T_COLLISION_DETECTION)
#define NDEFT2T_COLLISION_DETECTION 0
#endif

/**
 * Number of tries for writing NDEF message into shared memory in case of
 * @ref colDetDesc_anchor "Shared memory access collision detection".
 */
#if !defined(NDEFT2T_WRITE_TRIES)
#define NDEFT2T_WRITE_TRIES 1
#endif

/**
 * Number of tries for reading NDEF message from shared memory in case of
 * @ref colDetDesc_anchor "Shared memory access collision detection".
 */
#if !defined(NDEFT2T_READ_TRIES)
#define NDEFT2T_READ_TRIES 1
#endif

#endif /** @} */
