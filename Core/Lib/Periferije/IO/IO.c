/*
 * IO.c
 *
 *  Created on: Feb 1, 2024
 *      Author: User
 */

#include "../../Periferije/IO/IO.h"

static void
portB_init();

void
io ()
{
  portB_init ();
}

static void
portB_init()
{
	RCC-> AHB2ENR |= (0b1 << 1);

	GPIOB->MODER &= ~(0b11 << 2 * 3);
	GPIOB->MODER |= (0b01 << 2 * 3);
	GPIOB->OTYPER &= ~(0b1 << 3);
	GPIOB->OSPEEDR |= (0b11 << 2 * 3);
	GPIOB->PUPDR &= ~(0b11 << 2 * 3);
}

void
io_led (bool status)
{
  if (true == status)
    {
    GPIOB->ODR |= (0b1 << 3);
    }
  else
    GPIOB->ODR &= ~(0b1 << 3);

}
