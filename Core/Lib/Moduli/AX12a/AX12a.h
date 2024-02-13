/*
 * AX12a.h
 *
 *  Created on: Feb 2, 2024
 *      Author: User
 */

#ifndef LIB_MODULI_AX12A_AX12A_H_
#define LIB_MODULI_AX12A_AX12A_H_

#include <stdint.h>
#include <stdbool.h>

#define PRAVO 570
#define LEVO 711
#define DESNO 439

void
ax_angle_move (uint8_t id, uint16_t angle, uint16_t speed);

void
ax_speed_move (uint8_t id, bool Status);

void
xl_led (uint8_t id, uint8_t LEDColor);

#endif /* LIB_MODULI_AX12A_AX12A_H_ */
