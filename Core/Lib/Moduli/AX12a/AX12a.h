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

#define PRAVO 570 //165.3 AX -> 0 robot
#define LEVO 711  //206.19 AX ->
#define DESNO 439 //127.31 AX ->

void
ax_angle_move (uint8_t id, uint16_t angle, uint16_t speed);

void
ax_wheel_mode(uint8_t id);

void
ax_joint_mode(uint8_t id);

void
xl_angle_move (uint8_t id, uint16_t angle);

#endif /* LIB_MODULI_AX12A_AX12A_H_ */
