/*
 * Odometrija.c
 *
 *  Created on: Feb 13, 2024
 *      Author: User
 */

#include "../Lib/Moduli/Odometrija/Odometrija.h"

float x_r=0;
float y_r=0;
float Theta_r=0;
float d=61.3; // [mm]
float V_r=0;
float w_r=0;
float V_T =0; //brzina AX 1023 -> 114rpm/obrtaja u minuti -> 1.9 obrtaja u sekundi
float Theta_T=0;


//void
//GdeSam (uint8_t stanje, float ugao)
//{
//  switch (stanje) {
//	case 1: // pravo
//
//		break;
//	case 2: // skretanje
//
//		break;
//	default:
//		break;
//}
//}
