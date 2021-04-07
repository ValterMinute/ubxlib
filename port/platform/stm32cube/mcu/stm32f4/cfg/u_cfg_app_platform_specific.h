/*
 * Copyright 2020 u-blox Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _U_CFG_APP_PLATFORM_SPECIFIC_H_
#define _U_CFG_APP_PLATFORM_SPECIFIC_H_

/* Only bring in #includes specifically related to running applications. */

#include "u_runner.h"

/** @file
 * @brief This header file contains configuration information for
 * an STM32F4 platform that is fed in at application level.  You should
 * override these values as necessary for your particular platform.
 * Note that the pin numbers used below should be those of the MCU: if you
 * are using an MCU inside a u-blox module the IO pin numbering for
 * the module is likely different to that from the MCU: check the data
 * sheet for the module to determine the mapping.
 */

/* ----------------------------------------------------------------
 * COMPILE-TIME MACROS FOR A BLE/WIFI MODULE ON STM32F4: UART/USART
 * -------------------------------------------------------------- */

/** UART HW block with a connected short range module.
 * Note: make sure that the corresponding U_CFG_UARTx_AVAILABLE
 * for this UART is set to 1 in u_cfg_hw_platform_specific.h
 */
#ifndef U_CFG_APP_SHORT_RANGE_UART
# define U_CFG_APP_SHORT_RANGE_UART        3 // UART3
#endif

/** Short range module role.
 * Central: 1
 * Peripheral: 2
 */
#ifndef U_CFG_APP_SHORT_RANGE_ROLE
# define U_CFG_APP_SHORT_RANGE_ROLE        2
#endif

/* ----------------------------------------------------------------
 * COMPILE-TIME MACROS FOR A BLE/WIFI MODULE ON STM32F4: PINS
 * -------------------------------------------------------------- */

/** Tx pin for UART connected to short range module.
 * -1 is used where there is no such connection.
 */
#ifndef U_CFG_APP_PIN_SHORT_RANGE_TXD
# define U_CFG_APP_PIN_SHORT_RANGE_TXD   0x38 // UART3 TX, PD_8 or D1 on a C030 board
#endif

/** Rx pin for UART connected to short range module.
 * -1 is used where there is no such connection.
 */
#ifndef U_CFG_APP_PIN_SHORT_RANGE_RXD
# define U_CFG_APP_PIN_SHORT_RANGE_RXD   0x39 // UART3 RX, PD_9 or D0 on a C030 board
#endif

/** CTS pin for UART connected to short range module.
 * -1 is used where there is no such connection.
 */
#ifndef U_CFG_APP_PIN_SHORT_RANGE_CTS
# define U_CFG_APP_PIN_SHORT_RANGE_CTS   0x3b // UART3 CTS, PD_11 or D2 on a C030 board
#endif

/** RTS pin for UART connected to short range module.
 * -1 is used where there is no such connection.
 */
#ifndef U_CFG_APP_PIN_SHORT_RANGE_RTS
# define U_CFG_APP_PIN_SHORT_RANGE_RTS   0x1e // UART3 RTS, PB_14 or D3 on a C030 board
#endif

/* ----------------------------------------------------------------
 * COMPILE-TIME MACROS FOR A CELLULAR MODULE ON STM32F4: UART/USART
 * -------------------------------------------------------------- */

#ifndef U_CFG_APP_CELL_UART
/** The UART/USART to use when talking to the cellular module,
 * a number between 1 and 8, though note that only USARTs 1, 2, 3
 * and 6 are capable of HW flow control.  If you change this
 * number you will also need to make sure that the corresponding
 * U_CFG_HW_UARTx_AVAILABLE define in u_cfg_hw_platform_specific.h
 * is set to 1.
 * For a C030-R412M board this HAS to be 1 as that's the UART
 * HW block that is wired INSIDE the STM32F437VG chip to
 * the correct alternate functions for the Tx/Rx/RTS/CTS pins
 * below (see table 12 of the STM32F437VG data sheet).
 * For a C030-U201 board this HAS to be 2 for the same reasons.
 */
# define U_CFG_APP_CELL_UART                           1
#endif

/* ----------------------------------------------------------------
 * COMPILE-TIME MACROS FOR A CELLULAR MODULE ON STM32F4: PINS
 * -------------------------------------------------------------- */

/** The pins defined below are correct for the u-blox C030-R412M
 * board.  If you are using a C030-U201 board or any other board
 * you should configure the values yourself.
 * Note: on an STM32F4 chip the pin numbering has the bank number
 * in the upper nibble and the pin number in the lower nibble, so
 * pin 15, also known as PA_15, has the value 0x0f and pin 16,
 * also known as PB_0, has value 0x10, etc.
 */

#ifndef U_CFG_APP_PIN_C030_ENABLE_3V3
/** On the u-blox C030 boards it is necessary to enable
 * power to the 3.3V rail of the Arduino interface
 * by setting this pin to an open drain output and to high.
 * If you are not running on a u-blox C030 board then
 * override this pin to -1.
 */
# define U_CFG_APP_PIN_C030_ENABLE_3V3   0x40 // AKA PE_0
#endif

#ifndef U_CFG_APP_PIN_CELL_RESET
/** The pin that is connect to the cellular module's
 * reset pin.  Pin 0x15, AKA PB_5, is used on the
 * u-blox C030 boards.
 * If you are not running on a u-blox C030 board then
 * you may override this pin as required.
 */
# define U_CFG_APP_PIN_CELL_RESET    0x15 // AKA PB_5
#endif

#ifndef U_CFG_APP_PIN_CELL_ENABLE_POWER
/** The STM32F4 GPIO output that enables power to the
 * cellular module. -1 because there is no such
 * facility on a C030 board.
 */
# define U_CFG_APP_PIN_CELL_ENABLE_POWER      -1
#endif

#ifndef U_CFG_APP_PIN_CELL_PWR_ON
/** The STM32F4 GPIO output that that is connected to the
 * PWR_ON pin of the cellular module.  For the u-blox
 * C030 boards this is 0x4e, AKA PE_14.
 */
# define U_CFG_APP_PIN_CELL_PWR_ON     0x4e // AKA PE_14
#endif

#ifndef U_CFG_APP_PIN_CELL_VINT
/** The STM32F4 GPIO input that is connected to the VInt
 * pin of the cellular module. -1 is used where there
 * is no such connection. For the u-blox C030 boards
 * this is not connected.
 */
# define U_CFG_APP_PIN_CELL_VINT      -1
#endif

#ifndef U_CFG_APP_PIN_CELL_TXD
/** The STM32F4 GPIO output pin that sends UART data to
 * the cellular module.
 * For the u-blox C030-R412M board this must
 * be 0x09, AKA PA_9.
 * For the u-blox C030-U201 board this must be
 * 0x35, AKA PD_5.
 */
# define U_CFG_APP_PIN_CELL_TXD       0x09 // AKA PA_9
#endif

#ifndef U_CFG_APP_PIN_CELL_RXD
/** The STM32F4 GPIO input pin that receives UART data
 * from the cellular module.
 * For the u-blox C030-R412M board this must be
 * 0x0a, AKA PA_10.
 * For the u-blox C030-U201 board this must be
 * 0x36, AKA PD_6.
 */
# define U_CFG_APP_PIN_CELL_RXD       0x0a // AKA PA_10
#endif

#ifndef U_CFG_APP_PIN_CELL_CTS
/** The STM32F4 GPIO input pin that the cellular modem
 * will use to indicate that data can be sent to it.
 * -1 is used where there is no such connection.
 * For the u-blox C030-R412M board this must be
 * 0x0b, AKA PA_11.
 * For the u-blox C030-U201 board this must be
 * 0x33, AKA PD_3.
 */
# define U_CFG_APP_PIN_CELL_CTS       0x0b // AKA PA_11
#endif

#ifndef U_CFG_APP_PIN_CELL_RTS
/** The STM32F4 GPIO output pin that tells the cellular
 * modem that it can send more data to the STM32F4 UART.
 * -1 is used where there is no such connection.
 * For the u-blox C030-R412M board this must be
 * 0x0c, AKA PA_12.
 * For the u-blox C030-U201 board this must be
 * 0x34, AKA PD_4.
 */
# define U_CFG_APP_PIN_CELL_RTS       0x0c // AKA PA_12
#endif

/* ----------------------------------------------------------------
 * COMPILE-TIME MACROS FOR A GNSS MODULE ON STM32F4: MISC
 * -------------------------------------------------------------- */

#ifndef U_CFG_APP_GNSS_UART
/** The UART HW block to use inside the STM32F4 chip to talk to a
 * GNSS module.
 */
# define U_CFG_APP_GNSS_UART                  -1
#endif

/* ----------------------------------------------------------------
 * COMPILE-TIME MACROS FOR A GNSS MODULE ON STM32F4: PINS
 * -------------------------------------------------------------- */

#ifndef U_CFG_APP_PIN_GNSS_EN
/** The STM32F4 GPIO output that that is connected to the GNSSEN
 * pin of the GNSS module.
 */
# define U_CFG_APP_PIN_GNSS_EN               -1
#endif

#ifndef U_CFG_APP_PIN_GNSS_TXD
/** The STM32F4 GPIO output pin that sends UART data to the
 * GNSS module.
 */
# define U_CFG_APP_PIN_GNSS_TXD              -1
#endif

#ifndef U_CFG_APP_PIN_GNSS_RXD
/** The STM32F4 GPIO input pin that receives UART data from the
 * GNSS module.
 */
# define U_CFG_APP_PIN_GNSS_RXD              -1
#endif

#ifndef U_CFG_APP_PIN_GNSS_CTS
/** The STM32F4 GPIO input pin that the GNSS module will use to
 * indicate that data can be sent to it.  -1 should be used where
 * there is no such connection.
 */
# define U_CFG_APP_PIN_GNSS_CTS              -1
#endif

#ifndef U_CFG_APP_PIN_GNSS_RTS
/** The STM32F4 GPIO output pin that tells the GNSS module
 * that it can send more data to the host processor.  -1 should
 * be used where there is no such connection.
 */
# define U_CFG_APP_PIN_GNSS_RTS              -1
#endif

#endif // _U_CFG_APP_PLATFORM_SPECIFIC_H_

// End of file
