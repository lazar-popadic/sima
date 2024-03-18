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
#define LEVOPP 641
#define LEVOPP1 605
#define DESNO 439 //127.31 AX ->
#define DESNOPP 505
#define DESNOPP1 537

#define ID_SIMA2_POGONSKI 5
#define ID_SIMA2_ZAKRETNI 6
#define ID_SIMA3_POGONSKI 11
#define ID_SIMA3_ZAKRETNI 8
#define ID_SIMA4_POGONSKI 13
#define ID_SIMA4_ZAKRETNI 12

void
ax_angle_move (uint8_t id, uint16_t angle, uint16_t speed);

void
ax_wheel_mode(uint8_t id);

void
ax_joint_mode(uint8_t id);

void
xl_angle_move (uint8_t id, uint16_t angle);

#endif /* LIB_MODULI_AX12A_AX12A_H_ */
