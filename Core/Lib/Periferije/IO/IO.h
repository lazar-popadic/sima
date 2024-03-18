/*
 * IO.h
 *
 *  Created on: Feb 1, 2024
 *      Author: User
 */

#ifndef LIB_PERIFERIJE_IO_IO_H_
#define LIB_PERIFERIJE_IO_IO_H_

#include "stdbool.h"
#include "stm32l4xx.h"

void
io ();
void
io_led (bool status);

bool
IO_cinc();
void
Taktika_SIMA_DRUGI_2();
void
Taktika_SIMA_TRECI_3();
void
Taktika_SIMA_CETVRTI_4();

#endif /* LIB_PERIFERIJE_IO_IO_H_ */
