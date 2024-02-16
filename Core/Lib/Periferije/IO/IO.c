/*
 * IO.c
 *
 *  Created on: Feb 1, 2024
 *      Author: User
 */

#include "../../Periferije/IO/IO.h"

uint8_t const CINC=7;
volatile uint8_t counter = 0;

static void
portB_init();
static void
portA_init();

void
io ()
{
  portB_init ();
  portA_init();
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

static void
portA_init()
{
	RCC-> AHB2ENR |= (0b1 << 0);

	GPIOA->MODER &= ~(0b11 << 2 * CINC);
	GPIOA->OSPEEDR &= ~(0b11 << 2 * CINC); //low speed
	GPIOA->PUPDR &= ~(0b11 << 2 *CINC);
	GPIOA->PUPDR |= (0b10 << 2*CINC);
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

bool
IO_cinc()
{
	if(!(GPIOA->IDR & (0b1 << CINC)))
		counter++;
	else
		counter=0;
	if(counter>64000)
		return true;
	return false;
}
