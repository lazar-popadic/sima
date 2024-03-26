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

#define PRAVO 511 //512 //570
#define LEVO 651  //653 //711
#define LEVOPP 582 //583 //641
#define LEVOPP1 546 //547 //605
#define DESNO 380 //381 //439
#define DESNOPP 446 //447  //505
#define DESNOPP1 478 //479  //537

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
