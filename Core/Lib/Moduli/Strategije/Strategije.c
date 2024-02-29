/*
 * Strategije.c
 *
 *  Created on: Feb 16, 2024
 *      Author: User
 */

#include "../Lib/Moduli/Strategije/Strategije.h"
#include "main.h"
#include "../Lib/Moduli/AX12a/AX12a.h"

uint8_t tactic_state = 0;
uint8_t last_tactic_state = 0;

void tactic_yellow_2() {
	switch (tactic_state) {
	case 0:
		if (IO_cinc()) {
			tactic_state++;
		}
		break;

	case 1:
		ax_angle_move(6, LEVOPP, 200);
		TajmerDelay(200);
		ax_wheel_mode(5);
		TajmerDelay(500);
		ax_angle_move(5, 0, 1023);
		TajmerDelay(100);
		ax_angle_move(6, PRAVO, 200);

		tactic_state++;
		break;

	case 2:
		TajmerDelay(500);
		tactic_state++;
		break;
	case 3:
		TajmerDelay(500);
		tactic_state++;
		break;
	case 4:
		TajmerDelay(500);
		tactic_state++;
		break;
	case 5:
		TajmerDelay(500);
		tactic_state++;
		break;
	case 6:
		TajmerDelay(500);
		tactic_state++;
		break;
	case 7:
		TajmerDelay(500);
		tactic_state++;
		break;
	case 8:
		ax_angle_move(5, 0, 0);
		break;
	default:
		break;
	}
}


