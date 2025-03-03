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
interrupted_func_stop(uint8_t AX_Pogonski);

static void
interrupted_func_right_forward_sideway(uint8_t AX_Pogonski, uint8_t AX_Zakretni);

static void
interrupted_func_right_diagonal_sideway(uint8_t AX_Pogonski, uint8_t AX_Zakretni);

static void
interrupted_func_left_forward_sideway(uint8_t AX_Pogonski, uint8_t AX_Zakretni);

static void
interrupted_func_left_diagonal_sideway(uint8_t AX_Pogonski, uint8_t AX_Zakretni);

void SIMA_homologacija (uint8_t AX_Pogonski, uint8_t AX_Zakretni)
{
	switch (tactic_state) {
	case 0:
		if (IO_cinc()) {
			timer_start_sys_time();
			tactic_state++;
		}
		break;
	case 1:
		TajmerDelay(90000); //90000  //200
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		TajmerDelay(200);
		ax_wheel_mode(AX_Pogonski);
		TajmerDelay(200);
		ax_angle_move(AX_Pogonski, 0, 512);
		TajmerDelay(200);
		ax_angle_move(AX_Pogonski, 0, 767);

		tactic_state++;
		break;

	case 2:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
			tactic_state ++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 3:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
			tactic_state ++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 4:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
			tactic_state ++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 5:
			sensors_case_timer = SENSOR_JJ;

			if (interrupted) {

				interrupted_func_stop(AX_Pogonski);
				tactic_state ++;
			} else {
				ax_wheel_mode(AX_Pogonski);
				TajmerDelay(100);
				ax_angle_move(AX_Pogonski, 0, 1023);

				TajmerDelay(150);
				tactic_state++;
			}
	case 6:
			sensors_case_timer = SENSOR_JJ;

			if (interrupted) {

				interrupted_func_stop(AX_Pogonski);
				tactic_state ++;
			} else {
				ax_wheel_mode(AX_Pogonski);
				TajmerDelay(100);
				ax_angle_move(AX_Pogonski, 0, 1023);

				TajmerDelay(150);
				tactic_state++;
			}
	case 7:
			sensors_case_timer = SENSOR_JJ;

			if (interrupted) {

				interrupted_func_stop(AX_Pogonski);
				tactic_state ++;
			} else {
				ax_wheel_mode(AX_Pogonski);
				TajmerDelay(100);
				ax_angle_move(AX_Pogonski, 0, 1023);

				TajmerDelay(150);
				tactic_state++;
			}
	case 8:
			sensors_case_timer = SENSOR_JJ;

			if (interrupted) {

				interrupted_func_stop(AX_Pogonski);
				tactic_state ++;
			} else {
				ax_wheel_mode(AX_Pogonski);
				TajmerDelay(100);
				ax_angle_move(AX_Pogonski, 0, 1023);

				TajmerDelay(150);
				tactic_state++;
			}
	case 9:
			sensors_case_timer = SENSOR_JJ;

			if (interrupted) {

				interrupted_func_stop(AX_Pogonski);
				tactic_state ++;
			} else {
				ax_wheel_mode(AX_Pogonski);
				TajmerDelay(100);
				ax_angle_move(AX_Pogonski, 0, 1023);

				TajmerDelay(150);
				tactic_state++;
			}
	case 10:
			sensors_case_timer = SENSOR_JJ;

			if (interrupted) {

				interrupted_func_stop(AX_Pogonski);
				tactic_state ++;
			} else {
				ax_wheel_mode(AX_Pogonski);
				TajmerDelay(100);
				ax_angle_move(AX_Pogonski, 0, 1023);

				TajmerDelay(150);
				tactic_state++;
			}
	}
}

void tactic_yellow_1(uint8_t AX_Pogonski, uint8_t AX_Zakretni) {
	switch (tactic_state) {
	case 0:
		if (IO_cinc()) {
			timer_start_sys_time();
			tactic_state++;
		}
		break;

	case 1:
		TajmerDelay(91000);//91000 //1200
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		TajmerDelay(500);
		ax_angle_move(AX_Zakretni, LEVOPP, 200);
		ax_angle_move(AX_Zakretni, LEVOPP, 200);
		ax_angle_move(AX_Zakretni, LEVOPP, 200);
		ax_angle_move(AX_Zakretni, LEVOPP, 200);
		TajmerDelay(200);
		ax_wheel_mode(AX_Pogonski);
		TajmerDelay(200);
		ax_angle_move(AX_Pogonski, 0, 767);
		TajmerDelay(600);
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		ax_angle_move(AX_Zakretni, PRAVO, 200);

		tactic_state++;
		break;

	case 2:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
			tactic_state++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}

		break;
	case 3:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
			tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
		break;
	case 4:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
			tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
		break;
	case 5:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
			tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
		break;
	case 6:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
			tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
		break;
	case 7:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
			tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
		break;
	case 8:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
			tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
		break;

	case 9:
		ax_angle_move(AX_Pogonski, 0, 0);
		break;
	default:
		break;
	}
}

void tactic_yellow_2(uint8_t AX_Pogonski, uint8_t AX_Zakretni) {
	switch (tactic_state) {
	case 0:
		if (IO_cinc()) {
			timer_start_sys_time();
			tactic_state++;
		}
		break;

	case 1:
		TajmerDelay(90500); //90500 //700
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		TajmerDelay(300);
		ax_angle_move(AX_Zakretni, LEVOPP1, 200);
		ax_angle_move(AX_Zakretni, LEVOPP1, 200);
		ax_angle_move(AX_Zakretni, LEVOPP1, 200);
		ax_angle_move(AX_Zakretni, LEVOPP1, 200);
		TajmerDelay(200);
		ax_wheel_mode(AX_Pogonski);
		TajmerDelay(200);
		ax_angle_move(AX_Pogonski, 0, 767);
		TajmerDelay(150);
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		ax_angle_move(AX_Zakretni, PRAVO, 200);

		tactic_state++;
		break;

	case 2:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
			tactic_state ++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}

		break;
	case 3:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
			tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
		break;
	case 4:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
						tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
		break;
	case 5:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
						tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
		break;
	case 6:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
						tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
		break;
	case 7:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
						tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 8:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
						tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 9:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
						tactic_state++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 10:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
						tactic_state++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 11:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
						tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 12:
			sensors_case_timer = SENSOR_JJ;

			if (interrupted) {
				interrupted_func_stop(AX_Pogonski);
							tactic_state++;

			} else {
				ax_wheel_mode(AX_Pogonski);
				TajmerDelay(100);
				ax_angle_move(AX_Pogonski, 0, 1023);

				TajmerDelay(150);
				tactic_state++;
			}
	case 13:
			sensors_case_timer = SENSOR_JJ;

			if (interrupted) {
				interrupted_func_stop(AX_Pogonski);
							tactic_state++;

			} else {
				ax_wheel_mode(AX_Pogonski);
				TajmerDelay(100);
				ax_angle_move(AX_Pogonski, 0, 767);

				TajmerDelay(150);
				tactic_state++;
			}

		break;
	case 14:
		ax_angle_move(AX_Pogonski, 0, 0);
		break;
	default:
		break;
	}
}

void tactic_yellow_3(uint8_t AX_Pogonski, uint8_t AX_Zakretni) {
	switch (tactic_state) {
	case 0:
		if (IO_cinc()) {
			timer_start_sys_time();
			tactic_state++;
		}
		break;

	case 1:
		TajmerDelay(90000); //90000  //200
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		TajmerDelay(200);
		ax_wheel_mode(AX_Pogonski);
		TajmerDelay(200);
		ax_angle_move(AX_Pogonski, 0, 512);
		TajmerDelay(200);
		ax_angle_move(AX_Pogonski, 0, 767);

		tactic_state++;
		break;

	case 2:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
			tactic_state ++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 3:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
			tactic_state ++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 4:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
			tactic_state ++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 5:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
			tactic_state ++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 767);
			ax_angle_move(AX_Pogonski, 0, 767);
			ax_angle_move(AX_Pogonski, 0, 767);
			ax_angle_move(AX_Pogonski, 0, 767);
			TajmerDelay(200);
			ax_angle_move(AX_Zakretni, DESNOPP, 1000);
			ax_angle_move(AX_Zakretni, DESNOPP, 1000);
			ax_angle_move(AX_Zakretni, DESNOPP, 1000);
			ax_angle_move(AX_Zakretni, DESNOPP, 1000);
			TajmerDelay(400);
			ax_angle_move(AX_Zakretni, PRAVO, 1000);
			ax_angle_move(AX_Zakretni, PRAVO, 1000);
			ax_angle_move(AX_Zakretni, PRAVO, 1000);
			ax_angle_move(AX_Zakretni, PRAVO, 1000);

			TajmerDelay(150);
			tactic_state++;
		}
	case 6:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
						tactic_state ++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 7:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
						tactic_state ++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 8:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
						tactic_state ++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 9:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
						tactic_state ++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 10:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
			tactic_state ++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 11:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
			tactic_state ++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 12:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
			tactic_state ++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 13:
			sensors_case_timer = SENSOR_JJ;

			if (interrupted) {

				interrupted_func_stop(AX_Pogonski);
				tactic_state ++;
			} else {
				ax_wheel_mode(AX_Pogonski);
				TajmerDelay(100);
				ax_angle_move(AX_Pogonski, 0, 1023);

				TajmerDelay(150);
				tactic_state++;
			}
	case 14:
				sensors_case_timer = SENSOR_JJ;

				if (interrupted) {

					interrupted_func_stop(AX_Pogonski);
					tactic_state ++;
				} else {
					ax_wheel_mode(AX_Pogonski);
					TajmerDelay(100);
					ax_angle_move(AX_Pogonski, 0, 1023);

					TajmerDelay(150);
					tactic_state++;
				}
	case 15:
		ax_angle_move(AX_Pogonski, 0, 0);
		break;
	default:
		break;
	}
}

void tactic_blue_1(uint8_t AX_Pogonski, uint8_t AX_Zakretni) {
	switch (tactic_state) {
	case 0:
		if (IO_cinc()) {
			timer_start_sys_time();
			tactic_state++;
		}
		break;

	case 1:
		TajmerDelay(91000);//91000 //1200
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		TajmerDelay(500);
		ax_angle_move(AX_Zakretni, DESNOPP, 200);
		ax_angle_move(AX_Zakretni, DESNOPP, 200);
		ax_angle_move(AX_Zakretni, DESNOPP, 200);
		ax_angle_move(AX_Zakretni, DESNOPP, 200);
		TajmerDelay(200);
		ax_wheel_mode(AX_Pogonski);
		TajmerDelay(200);
		ax_angle_move(AX_Pogonski, 0, 767);
		TajmerDelay(550);
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		ax_angle_move(AX_Zakretni, PRAVO, 200);

		tactic_state++;
		break;

	case 2:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
			tactic_state++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}

		break;
	case 3:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
			tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
		break;
	case 4:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
			tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
		break;
	case 5:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
			tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
		break;
	case 6:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
			tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
		break;
	case 7:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
			tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
		break;
	case 8:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
			tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
		break;

	case 9:
		ax_angle_move(AX_Pogonski, 0, 0);
		break;
	default:
		break;
	}
}

void tactic_blue_2(uint8_t AX_Pogonski, uint8_t AX_Zakretni) {
	switch (tactic_state) {
	case 0:
		if (IO_cinc()) {
			timer_start_sys_time();
			tactic_state++;
		}
		break;

	case 1:
		TajmerDelay(90500); //90500 //700
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		TajmerDelay(300);
		ax_angle_move(AX_Zakretni, DESNOPP, 200);
		ax_angle_move(AX_Zakretni, DESNOPP, 200);
		ax_angle_move(AX_Zakretni, DESNOPP, 200);
		ax_angle_move(AX_Zakretni, DESNOPP, 200);
		TajmerDelay(200);
		ax_wheel_mode(AX_Pogonski);
		TajmerDelay(200);
		ax_angle_move(AX_Pogonski, 0, 767);
		TajmerDelay(350);
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		ax_angle_move(AX_Zakretni, PRAVO, 200);

		tactic_state++;
		break;

	case 2:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
						tactic_state++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}

		break;
	case 3:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
						tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
		break;
	case 4:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
						tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
		break;
	case 5:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
						tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
		break;
	case 6:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
						tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
		break;
	case 7:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
						tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 8:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
						tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 9:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
						tactic_state++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 10:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
						tactic_state++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 11:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {
			interrupted_func_stop(AX_Pogonski);
						tactic_state++;

		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 12:
			sensors_case_timer = SENSOR_JJ;

			if (interrupted) {
				interrupted_func_stop(AX_Pogonski);
							tactic_state++;

			} else {
				ax_wheel_mode(AX_Pogonski);
				TajmerDelay(100);
				ax_angle_move(AX_Pogonski, 0, 1023);

				TajmerDelay(150);
				tactic_state++;
			}
	case 13:
			sensors_case_timer = SENSOR_JJ;

			if (interrupted) {
				interrupted_func_stop(AX_Pogonski);
							tactic_state++;

			} else {
				ax_wheel_mode(AX_Pogonski);
				TajmerDelay(100);
				ax_angle_move(AX_Pogonski, 0, 767);

				TajmerDelay(150);
				tactic_state++;
			}
		break;
	case 14:
		ax_angle_move(AX_Pogonski, 0, 0);
		break;
	default:
		break;
	}
}

void tactic_blue_3(uint8_t AX_Pogonski, uint8_t AX_Zakretni) {
	switch (tactic_state) {
	case 0:
		if (IO_cinc()) {
			timer_start_sys_time();
			tactic_state++;
		}
		break;

	case 1:
		TajmerDelay(90000); //90000 //200
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		ax_angle_move(AX_Zakretni, PRAVO, 200);
		TajmerDelay(200);
		ax_wheel_mode(AX_Pogonski);
		TajmerDelay(200);
		ax_angle_move(AX_Pogonski, 0, 512);
		TajmerDelay(200);
		ax_angle_move(AX_Pogonski, 0, 767);

		tactic_state++;
		break;

	case 2:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
						tactic_state ++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 3:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
						tactic_state ++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 4:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
						tactic_state ++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 5:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
						tactic_state ++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 767);
			ax_angle_move(AX_Pogonski, 0, 767);
			ax_angle_move(AX_Pogonski, 0, 767);
			ax_angle_move(AX_Pogonski, 0, 767);
			TajmerDelay(200);
			ax_angle_move(AX_Zakretni, LEVOPP, 1000);
			ax_angle_move(AX_Zakretni, LEVOPP, 1000);
			ax_angle_move(AX_Zakretni, LEVOPP, 1000);
			ax_angle_move(AX_Zakretni, LEVOPP, 1000);
			TajmerDelay(800);
			ax_angle_move(AX_Zakretni, PRAVO, 1000);
			ax_angle_move(AX_Zakretni, PRAVO, 1000);
			ax_angle_move(AX_Zakretni, PRAVO, 1000);
			ax_angle_move(AX_Zakretni, PRAVO, 1000);

			TajmerDelay(150);
			tactic_state++;
		}
	case 6:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
						tactic_state ++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 7:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
						tactic_state ++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 8:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
						tactic_state ++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 9:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
						tactic_state ++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 10:
		sensors_case_timer = SENSOR_JJ;

		if (interrupted) {

			interrupted_func_stop(AX_Pogonski);
						tactic_state ++;
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

			interrupted_func_stop(AX_Pogonski);
						tactic_state ++;
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

			interrupted_func_stop(AX_Pogonski);
						tactic_state ++;
		} else {
			ax_wheel_mode(AX_Pogonski);
			TajmerDelay(100);
			ax_angle_move(AX_Pogonski, 0, 1023);

			TajmerDelay(150);
			tactic_state++;
		}
	case 13:
			sensors_case_timer = SENSOR_JJ;

			if (interrupted) {

				interrupted_func_stop(AX_Pogonski);
							tactic_state ++;
			} else {
				ax_wheel_mode(AX_Pogonski);
				TajmerDelay(100);
				ax_angle_move(AX_Pogonski, 0, 1023);

				TajmerDelay(150);
				tactic_state++;
			}
	case 14:
				sensors_case_timer = SENSOR_JJ;

				if (interrupted) {

					interrupted_func_stop(AX_Pogonski);
								tactic_state ++;
				} else {
					ax_wheel_mode(AX_Pogonski);
					TajmerDelay(100);
					ax_angle_move(AX_Pogonski, 0, 1023);

					TajmerDelay(150);
					tactic_state++;
				}
	case 15:
		ax_angle_move(AX_Pogonski, 0, 0);
		break;
	default:
		break;
	}
}

static void interrupted_func_stop(uint8_t AX_Pogonski) {
	TajmerDelay(100);
	ax_angle_move(AX_Pogonski, 0, 255);
	ax_angle_move(AX_Pogonski, 0, 255);
	ax_angle_move(AX_Pogonski, 0, 255);
	ax_angle_move(AX_Pogonski, 0, 255);
	TajmerDelay(100);
	ax_angle_move(AX_Pogonski, 0, 127);
	ax_angle_move(AX_Pogonski, 0, 127);
	ax_angle_move(AX_Pogonski, 0, 127);
	ax_angle_move(AX_Pogonski, 0, 127);
	TajmerDelay(100);
	ax_angle_move(AX_Pogonski, 0, 0);
	ax_angle_move(AX_Pogonski, 0, 0);
	ax_angle_move(AX_Pogonski, 0, 0);
	ax_angle_move(AX_Pogonski, 0, 0);
	TajmerDelay(200);
}

static void interrupted_func_right_forward_sideway(uint8_t AX_Pogonski,
		uint8_t AX_Zakretni) {

	ax_angle_move(AX_Pogonski, 0, 767);
	TajmerDelay(200);
	ax_angle_move(AX_Zakretni, DESNO, 1000);
	ax_angle_move(AX_Zakretni, DESNO, 1000);
	ax_angle_move(AX_Zakretni, DESNO, 1000);
	ax_angle_move(AX_Zakretni, DESNO, 1000);
	TajmerDelay(300);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	TajmerDelay(200);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	TajmerDelay(300);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	TajmerDelay(750);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	TajmerDelay(300);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	TajmerDelay(200);
	ax_angle_move(AX_Zakretni, DESNO, 1000);
	ax_angle_move(AX_Zakretni, DESNO, 1000);
	ax_angle_move(AX_Zakretni, DESNO, 1000);
	ax_angle_move(AX_Zakretni, DESNO, 1000);
	TajmerDelay(300);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	TajmerDelay(200);
}

static void interrupted_func_right_diagonal_sideway(uint8_t AX_Pogonski,
		uint8_t AX_Zakretni) {
	ax_angle_move(AX_Pogonski, 0, 767);
	TajmerDelay(200);
	ax_angle_move(AX_Zakretni, DESNO, 1000);
	ax_angle_move(AX_Zakretni, DESNO, 1000);
	ax_angle_move(AX_Zakretni, DESNO, 1000);
	ax_angle_move(AX_Zakretni, DESNO, 1000);
	TajmerDelay(300);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	TajmerDelay(200);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	TajmerDelay(300);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	TajmerDelay(1250);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	TajmerDelay(300);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	TajmerDelay(500);
}

static void interrupted_func_left_forward_sideway(uint8_t AX_Pogonski,
		uint8_t AX_Zakretni) {
	ax_angle_move(AX_Pogonski, 0, 767);
	TajmerDelay(200);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	TajmerDelay(250);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	TajmerDelay(400);
	ax_angle_move(AX_Zakretni, DESNO, 1000);
	ax_angle_move(AX_Zakretni, DESNO, 1000);
	ax_angle_move(AX_Zakretni, DESNO, 1000);
	ax_angle_move(AX_Zakretni, DESNO, 1000);
	TajmerDelay(250);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	TajmerDelay(1000);
	ax_angle_move(AX_Zakretni, DESNO, 1000);
	ax_angle_move(AX_Zakretni, DESNO, 1000);
	ax_angle_move(AX_Zakretni, DESNO, 1000);
	ax_angle_move(AX_Zakretni, DESNO, 1000);
	TajmerDelay(250);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	TajmerDelay(1200);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	TajmerDelay(250);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	TajmerDelay(200);
}

static void interrupted_func_left_diagonal_sideway(uint8_t AX_Pogonski,
		uint8_t AX_Zakretni) {
	ax_angle_move(AX_Pogonski, 0, 767);
	TajmerDelay(200);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	ax_angle_move(AX_Zakretni, LEVO, 1000);
	TajmerDelay(300);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	TajmerDelay(400);
	ax_angle_move(AX_Zakretni, DESNO, 1000);
	ax_angle_move(AX_Zakretni, DESNO, 1000);
	ax_angle_move(AX_Zakretni, DESNO, 1000);
	ax_angle_move(AX_Zakretni, DESNO, 1000);
	TajmerDelay(250);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	TajmerDelay(1500);
	ax_angle_move(AX_Zakretni, DESNOPP, 1000);
	ax_angle_move(AX_Zakretni, DESNOPP, 1000);
	ax_angle_move(AX_Zakretni, DESNOPP, 1000);
	ax_angle_move(AX_Zakretni, DESNOPP, 1000);
	TajmerDelay(250);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	ax_angle_move(AX_Zakretni, PRAVO, 1000);
	TajmerDelay(500);
}
