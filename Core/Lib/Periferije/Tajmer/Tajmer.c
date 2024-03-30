/*
 * Tajmer.c
 *
 *  Created on: Feb 1, 2024
 *      Author: User
 */

#include "../../Periferije/Tajmer/Tajmer.h"
#include "main.h"
#include "../../Moduli/Senzor/Senzor.h"

#define END_TIME 100*1000 //100 * 1000ms

static void
tim2_init ();

volatile uint32_t sys_time_ms = 0;
bool flag_delay = true;

volatile uint8_t sensors_case_timer = 0;
volatile bool interrupted = false;


void
tajmer_init()
{
 tim2_init();
}

static void
tim2_init()
{
	RCC->APB1ENR1 |= (0b1 << 0);

	TIM2-> PSC = 80-1; //80MHz -> 1MHz

	TIM2-> ARR = 1000-1; //1MHz -> 1kHz

	TIM2->CR1 &= ~((0b1 << 1) || (0b1 << 2));

	TIM2->EGR |= (0b1 << 0);

	TIM2->DIER |= (0b1 << 0);

	while (!(TIM2->SR & (0b1 << 0)));

	TIM2->SR &= ~(0b1 << 0);
	TIM2->CR1 |= (0b1 << 2);

	uint8_t const TIM2_PREKID = 28;
	NVIC->ISER[0] |= (0b1 << TIM2_PREKID);

	//TIM2->CR1 |= (0b1 << 0);
}

void
timer_start_sys_time ()
{
  TIM2->CR1 |= (0b1 << 0);	//tek ga ovo ukljucuje
}

void
timer_stop_sys_time ()
{
  TIM2->CR1 &= ~(0b1 << 0);
}

bool
timer_delay_nonblocking (uint32_t delay_ms)
{
  static uint32_t start_sys_time_ms;
  if (flag_delay == true)				//da samo jednom udje
    {
      start_sys_time_ms = sys_time_ms;
      flag_delay = false;
    }

  if (sys_time_ms <= start_sys_time_ms + delay_ms)
    return false;
  flag_delay = true;
  return true;
}

void TajmerDelay(uint32_t ms) {
	uint32_t PocVreme = sys_time_ms;
	while (sys_time_ms <= PocVreme + ms) {
		__NOP();
	}

}

void
TIM2_IRQHandler ()
{
  // poziva se svake milisekunde
  // proveri da li je stvarno TIM2 pozvao rutinu
  if ((TIM2->SR & (0b1 << 0)) == (0b1 << 0))
    {
      TIM2->SR &= ~(0b1 << 0);	// da bi sledeci put mogli da detektujemo prekid

      sys_time_ms++;

      if(sys_time_ms >= 99500) //99500 //9500
      {
    	  TajmerDelay(100);
    	  ax_angle_move(ID_SIMA2_POGONSKI, 0, 0);
//    	  ax_angle_move(ID_SIMA3_POGONSKI, 0, 0);
//    	  ax_angle_move(ID_SIMA4_POGONSKI, 0, 0);
    	  while(1);
      }
    }

  switch (sensors_case_timer) {
	case SENSOR_JJ:
		interrupted = sensor_JedanJedini();
		break;
	case SENSORS_OFF:
		  interrupted = false;
		  break;
	default:
		  interrupted = false;
		break;
    }
}
