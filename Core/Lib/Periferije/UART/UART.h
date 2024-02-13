/*
 * UART.h
 *
 *  Created on: Feb 2, 2024
 *      Author: User
 */

#ifndef LIB_PERIFERIJE_UART_UART_H_
#define LIB_PERIFERIJE_UART_UART_H_

#include <stdint.h>		//za tip uint
#include <stdbool.h>
#include "stm32l4xx.h"

void
UART_init ();

void
UART_send_byte (uint8_t data);

void
UART_write (uint8_t data);

uint8_t
UART_read ();

bool
UART_is_empty ();

#endif /* LIB_PERIFERIJE_UART_UART_H_ */
