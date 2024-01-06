/*
 * timer.c
 *
 *  Created on: Nov 30, 2023
 *      Author: lazar
 */

#include "timer.h"
#include "stm32l432xx.h"

#define START_TIME 90*1000
#define END_TIME 100*1000

volatile uint32_t sys_time_ms = 0;

static void
tim6_init ();

void
timer_init ()
{
  tim6_init ();
}

static void
tim6_init ()
{
  RCC->APB1ENR1 |= (0b1 << 4);
  // 80MHz -> 1kHz
  // 1) 80MHz -> 1MHz
  TIM6->PSC = 80 - 1;		// -1 jer brojimo od 0
  // 2) 1MHz -> 1kHz
  TIM6->ARR = 1000 - 1;

  TIM6->CR1 &= ~((0b1 << 1) || (0b1 << 2)); //sta generise dogadjaj | dozvola dogadjaja ILI obrnuto
  TIM6->EGR |= (0b1 << 0);	// Reinicijalizacija timera
  TIM6->DIER |= (0b1 << 0);	//dozvola prekida
  while (!(TIM6->SR & (0b1 << 0)))
    ;		//cekanje da se izvrsi reinicijalizacija

  TIM6->SR &= ~(0b1 << 0);
  TIM6->CR1 |= (0b1 << 2);

  //odabir prekidne rutine
  uint8_t const TIM6_PREKID = 54;
  NVIC->ISER[TIM6_PREKID / 32] |= (0b1 << (TIM6_PREKID % 32));

  //ne bi trebalo da je jos ukljucen
}

void
timer_start_sys_time ()
{
  TIM6->CR1 |= (0b1 << 0);	//tek ga ovo ukljucuje
}

void
TIM6_DACUNDER_IRQHandler ()
{
  // poziva se svake milisekunde
  // proveri da li je stvarno TIM6 pozvao rutinu
  if ((TIM6->SR & (0b1 << 0)) == (0b1 << 0))
    {
      TIM6->SR &= ~(0b1 << 0);	// da bi sledeci put mogli da detektujemo prekid

      sys_time_ms++;
    }
}
