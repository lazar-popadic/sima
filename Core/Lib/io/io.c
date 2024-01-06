/*
 * io.c
 *
 *  Created on: Nov 30, 2023
 *      Author: lazar
 */

#include "io.h"
#include "stm32l432xx.h"

uint8_t led = 3; //pb3

void
io_init ()
{
  GPIOA->MODER &= (0xFFFFFFFF);
  GPIOA->MODER |= (0b01 << 0 * 2);
  GPIOA->MODER |= (0b01 << 1 * 2);
  GPIOA->MODER |= (0b01 << 2 * 2);
  GPIOA->MODER |= (0b01 << 3 * 2);
  GPIOA->MODER |= (0b01 << 4 * 2);
  GPIOA->MODER |= (0b01 << 5 * 2);
  GPIOA->MODER |= (0b01 << 6 * 2);
  GPIOA->MODER |= (0b01 << 7 * 2);

  GPIOA->ODR |= (0b1 << 0);
  GPIOA->ODR |= (0b1 << 1);
  GPIOA->ODR |= (0b1 << 2);
  GPIOA->ODR |= (0b1 << 3);
  GPIOA->ODR |= (0b1 << 4);
  GPIOA->ODR |= (0b1 << 5);
  GPIOA->ODR |= (0b1 << 6);
  GPIOA->ODR |= (0b1 << 7);

  GPIOB->MODER &= ~(0b11 << led * 2);
  GPIOB->MODER |= (0b01 << led * 2);
  GPIOB->OTYPER &= ~(0b1 << led);
  GPIOB->OSPEEDR |= (0b11 << led * 2);
  GPIOB->PUPDR &= ~(0b11 << led * 2);
}

void
led_on (bool status)
{
  if (status == true)
    GPIOB->ODR |= (0b1 << led);
  else
    GPIOB->ODR &= ~(0b1 << led);
}
