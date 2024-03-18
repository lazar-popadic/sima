/*
 * UART.c
 *
 *  Created on: Feb 2, 2024
 *      Author: User
 */

#include "../../Periferije/UART/UART.h"

#define MAX_BUFFER_SIZE 32

volatile static uint8_t input = 0;
volatile static uint8_t buffer[MAX_BUFFER_SIZE];
volatile static uint8_t buffer_size = 0;
volatile static uint8_t index_write = 0;
volatile static uint8_t index_read = 0;

static void
UART1_init();

void
UART_init()
{
	UART1_init();
}

static void
UART1_init()
{
	//PB6 i PB7 AF7
	RCC->APB2ENR |= (0b1 << 14); //takt na USART1
	RCC->AHB2ENR |= (0b1 << 1); //takt za gpioB

	uint8_t const TX_PIN = 6;
	uint8_t const RX_PIN = 7;

	GPIOB->MODER &= ~(0b11 << TX_PIN * 2);
	GPIOB->MODER &= ~(0b11 << RX_PIN * 2);
	GPIOB->MODER |= (0b10 << TX_PIN * 2);
	GPIOB->MODER |= (0b10 << RX_PIN * 2);

	GPIOB->OTYPER |= (0b1 << TX_PIN);
	GPIOB->PUPDR &= ~(0b11 << TX_PIN*2);
	GPIOB->PUPDR |= (0b01 << TX_PIN*2);

	uint8_t const Alt_function = 7;

	GPIOB->AFR[TX_PIN / 8] &= ~(0b1111 << (TX_PIN % 8) * 4);
	GPIOB->AFR[TX_PIN / 8] |= (Alt_function << (TX_PIN % 8) * 4);
	GPIOB->AFR[RX_PIN / 8] &= ~(0b1111 << (RX_PIN % 8) * 4);
	GPIOB->AFR[RX_PIN / 8] |= (Alt_function << (RX_PIN % 8) * 4);

     USART1->CR1 &= ~(0b1 << 12);
     USART1->CR1 &= ~(0b1 << 28); //8 bita
     USART1->CR2 &= ~(0b11 << 12); //1 stop bit

     USART1->BRR = 0; //baud 9600->546.14
     USART1->BRR |= ((546 << 4) | (14 << 0)); //115200->45.57

     USART1->CR1 |= (0b11 << 2); //tx & rx pin enable

     USART1->CR1 |= (0b1 << 5); //interrupt enable

     USART1->CR2 &= ~(0b1 << 11);
     USART1->CR2 &= ~(0b1 << 14);
     USART1->CR3 &= ~(0b1 << 1);
     USART1->CR3 &= ~(0b1 << 5);
     USART1->CR3 |= (0b1 << 3);

    uint8_t  USART1_INTERRUPT = 37;
    NVIC->ISER[USART1_INTERRUPT / 32] |= (0b1 <<  USART1_INTERRUPT % 32);

     USART1-> CR1 |= (0b1 << 0); //usart enable
}

void
UART_send_byte (uint8_t data)
{
   USART1->TDR = data; //ovako se salje, kada je  USART1->dr sa desne strane, onda se ponasa kao recieve registar

  while (!( USART1->ISR & (0b1 << 6)))
	  ;

   USART1->ISR &= ~(0b1 << 6);
}

void
UART_write (uint8_t data)
{
  if (buffer_size != MAX_BUFFER_SIZE)
    {
      buffer[index_write] = data;
      index_write = (index_write + 1) % MAX_BUFFER_SIZE;
      buffer_size++;
    }
  else
    {
      buffer[index_write] = data;
      index_write = (index_write + 1) % MAX_BUFFER_SIZE;
      index_read = (index_read + 1) % MAX_BUFFER_SIZE;
    }
}

uint8_t
UART_read ()
{
  uint8_t temp_data;

  if (buffer_size != 0)
    {
      temp_data = buffer[index_read];
      index_read = (index_read + 1) % MAX_BUFFER_SIZE;
      buffer_size--;
    }
  return temp_data;
}

bool
UART_is_empty ()
{
  if (buffer_size == 0)
    return true;
  else
    return false;
}

void
USART1_IRQHandler ()
{
  if ( USART1->ISR & (0b1 << 5))
    {
      UART_write(USART1->RDR);
    }
}
