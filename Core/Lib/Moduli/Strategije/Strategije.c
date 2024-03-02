/*
 * Strategije.c
 *
 *  Created on: Feb 16, 2024
 *      Author: User
 */

#include "../Lib/Moduli/Strategije/Strategije.h"
#include "main.h"
#include "../Lib/Moduli/AX12a/AX12a.h"

volatile uint8_t tactic_state = 0;
extern volatile bool interrupted;
extern volatile uint8_t sensors_case_timer;

static void
interrupted_func (uint8_t AX_Pogonski);

void tactic_yellow_2(uint8_t AX_Pogonski, uint8_t AX_Zakretni) {
	switch (tactic_state) {
	case 0:
		if (IO_cinc()) {
			tactic_state++;
		}
		break;

	case 1:
		TajmerDelay(200);
		ax_angle_move(AX_Zakretni, LEVOPP, 200);
		TajmerDelay(200);
		ax_wheel_mode(AX_Pogonski);
		TajmerDelay(200);
		ax_angle_move(AX_Pogonski, 0, 1023);
		TajmerDelay(200);
		ax_angle_move(AX_Zakretni, PRAVO, 200);

		tactic_state++;
		break;

	case 2:
		sensors_case_timer = SENSOR_JJ;

		if(interrupted)
		{
			tactic_state = 2;
			interrupted_func(AX_Pogonski);
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(250);
			tactic_state++;
		}

		break;
	case 3:
		sensors_case_timer = SENSOR_JJ;


		if (interrupted) {
			tactic_state = 3;
			interrupted_func(AX_Pogonski);


		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(250);
			tactic_state++;
		}
		break;
	case 4:
		sensors_case_timer = SENSOR_JJ;


		if (interrupted) {
			tactic_state = 4;
			interrupted_func(AX_Pogonski);


		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(250);
			tactic_state++;
		}
		break;
	case 5:
		sensors_case_timer = SENSOR_JJ;


		if (interrupted) {
			tactic_state = 5;
			interrupted_func(AX_Pogonski);


		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(250);
			tactic_state++;
		}
		break;
	case 6:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			tactic_state = 6;
			interrupted_func(AX_Pogonski);


		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(250);
			tactic_state++;
		}
		break;
	case 7:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			tactic_state = 7;
			interrupted_func(AX_Pogonski);


		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(250);
			tactic_state++;
		}
	case 8:
			sensors_case_timer = SENSOR_JJ;

			if (interrupted) {
				tactic_state = 8;
				interrupted_func(AX_Pogonski);


			} else {
				ax_wheel_mode(AX_Pogonski);
				TajmerDelay(100);
				ax_angle_move(AX_Pogonski, 0, 1023);

				TajmerDelay(250);
				tactic_state++;
			}
	case 9:
			sensors_case_timer = SENSOR_JJ;

			if (interrupted) {
				tactic_state = 9;
				interrupted_func(AX_Pogonski);


			} else {
				ax_wheel_mode(AX_Pogonski);
				TajmerDelay(100);
				ax_angle_move(AX_Pogonski, 0, 1023);

				TajmerDelay(250);
				tactic_state++;
			}
	case 10:
			sensors_case_timer = SENSOR_JJ;

			if (interrupted) {
				tactic_state = 10;
				interrupted_func(AX_Pogonski);


			} else {
				ax_wheel_mode(AX_Pogonski);
				TajmerDelay(100);
				ax_angle_move(AX_Pogonski, 0, 1023);

				TajmerDelay(250);
				tactic_state++;
			}
	case 11:
			sensors_case_timer = SENSOR_JJ;

			if (interrupted) {
				tactic_state = 11;
				interrupted_func(AX_Pogonski);


			} else {
				ax_wheel_mode(AX_Pogonski);
				TajmerDelay(100);
				ax_angle_move(AX_Pogonski, 0, 1023);

				TajmerDelay(250);
				tactic_state++;
			}
	case 12:
			sensors_case_timer = SENSOR_JJ;

			if (interrupted) {
				tactic_state = 12;
				interrupted_func(AX_Pogonski);


			} else {
				ax_wheel_mode(AX_Pogonski);
				TajmerDelay(100);
				ax_angle_move(AX_Pogonski, 0, 1023);

				TajmerDelay(250);
				tactic_state++;
			}
		break;
	case 13:
		ax_angle_move(AX_Pogonski, 0, 0);
		break;
	default:
		break;
	}
}

static void
interrupted_func (uint8_t AX_Pogonski)
{
	TajmerDelay(200);
    ax_angle_move(AX_Pogonski, 0, 0);
    TajmerDelay(500);
//	TajmerDelay(200);
//	ax_angle_move(AX_Pogonski + 1, DESNO, 300);
//	TajmerDelay(200);
//	ax_angle_move(AX_Pogonski + 1, PRAVO, 300);
//	TajmerDelay(500);
//	ax_angle_move(AX_Pogonski + 1, LEVO, 300);
//	TajmerDelay(200);
//	ax_angle_move(AX_Pogonski + 1, PRAVO, 300);
//    TajmerDelay(200);
}
