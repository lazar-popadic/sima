/*
 * Tajmer.h
 *
 *  Created on: Feb 1, 2024
 *      Author: User
 */

#ifndef LIB_PERIFERIJE_TAJMER_TAJMER_H_
#define LIB_PERIFERIJE_TAJMER_TAJMER_H_

#include <stdint.h>		//za tip uint
#include <stdbool.h>
#include "stm32l4xx.h"

#define SENSORS_OFF 0
#define SENSOR_JJ 1

void
tajmer_init();
void
timer_start_sys_time();
void
timer_stop_sys_time ();
void
TajmerDelay(uint32_t ms);
bool
timer_delay_nonblocking (uint32_t delay_ms);

#endif /* LIB_PERIFERIJE_TAJMER_TAJMER_H_ */
