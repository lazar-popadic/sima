/*
 * Senzor.c
 *
 *  Created on: Feb 15, 2024
 *      Author: User
 */

#include "../Lib/Moduli/Senzor/Senzor.h"
#include "stm32l4xx.h"
#include "../Lib/Periferije/IO/IO.h"

static void
sensor_IO_init();

//portC
uint8_t infra_1 = 1;

void
sensor_Init()
{
sensor_IO_init();
}

void
sensor_IO_init()
{
	RCC->AHB2ENR |= (0b1 << 1); //takt za gpioB

	GPIOB-> MODER &= ~(0b11 << 2* infra_1);  //PB1
}

bool
sensor_JedanJedini()
{
	if(GPIOB->IDR & (0b1<<infra_1))
		return true;
	return false;
}
