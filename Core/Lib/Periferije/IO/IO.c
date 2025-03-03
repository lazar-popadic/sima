/*
 * IO.c
 *
 *  Created on: Feb 1, 2024
 *      Author: User
 */

#include "../../Periferije/IO/IO.h"
#include "main.h"

uint8_t const CINC=7;
uint8_t const PREKIDAC_TAKTIKE_2=9;
uint8_t const PREKIDAC_TAKTIKE_3=10;
uint8_t const PREKIDAC_TAKTIKE_4=11;
volatile uint8_t counter = 0;

static void
portC_init();
static void
portB_init();
static void
portA_init();

void
io ()
 {
	portC_init();
	portB_init();
	portA_init();
}

static void
portC_init()
{
	RCC->AHB2ENR |= (0b1 << 2);
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

	GPIOA->MODER &= ~(0b11 << 2 * PREKIDAC_TAKTIKE_2);
	GPIOA->OSPEEDR &= ~(0b11 << 2 * PREKIDAC_TAKTIKE_2); //low speed
	GPIOA->PUPDR &= ~(0b11 << 2 * PREKIDAC_TAKTIKE_2);
	GPIOA->PUPDR |= (0b10 << 2 * PREKIDAC_TAKTIKE_2);

	GPIOA->MODER &= ~(0b11 << 2 * PREKIDAC_TAKTIKE_3);
	GPIOA->OSPEEDR &= ~(0b11 << 2 * PREKIDAC_TAKTIKE_3); //low speed
	GPIOA->PUPDR &= ~(0b11 << 2 * PREKIDAC_TAKTIKE_3);
	GPIOA->PUPDR |= (0b10 << 2 * PREKIDAC_TAKTIKE_3);

	GPIOA->MODER &= ~(0b11 << 2 * PREKIDAC_TAKTIKE_4);
	GPIOA->OSPEEDR &= ~(0b11 << 2 * PREKIDAC_TAKTIKE_4); //low speed
	GPIOA->PUPDR &= ~(0b11 << 2 * PREKIDAC_TAKTIKE_4);
	GPIOA->PUPDR |= (0b10 << 2*PREKIDAC_TAKTIKE_4);
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
	if(counter)
		return true;
	return false;
}

void
Taktika_SIMA_DRUGI_2()
{
	if(!(GPIOA->IDR & (0b1 << PREKIDAC_TAKTIKE_2)))
			tactic_blue_2(ID_SIMA2_POGONSKI, ID_SIMA2_ZAKRETNI);
		else
			tactic_yellow_2(ID_SIMA2_POGONSKI, ID_SIMA2_ZAKRETNI);
}

void
Taktika_SIMA_TRECI_3()
{
	if(!(GPIOA->IDR & (0b1 << PREKIDAC_TAKTIKE_3)))
          tactic_blue_3(ID_SIMA3_POGONSKI, ID_SIMA3_ZAKRETNI);
		else
           tactic_yellow_3(ID_SIMA3_POGONSKI, ID_SIMA3_ZAKRETNI);
}

void
Taktika_SIMA_CETVRTI_4()
{
	if(!(GPIOA->IDR & (0b1 << PREKIDAC_TAKTIKE_4)))
          tactic_blue_1(ID_SIMA4_POGONSKI, ID_SIMA4_ZAKRETNI);
		else
          tactic_yellow_1(ID_SIMA4_POGONSKI, ID_SIMA4_ZAKRETNI);
}
