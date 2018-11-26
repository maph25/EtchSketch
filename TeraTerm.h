/*
 * TeraTerm.h
 *
 *  Created on: Nov 26, 2018
 *      Author: Andy
 */

#ifndef TERATERM_H_
#define TERATERM_H_

#define UP 0x1D
#define DOWN 0x1B
#define RIGHT 0x23
#define LEFT 0x1C
#define ENTER 0x5A
#define TOPROW 0u
#define LOWROW 24u
#define LOWCOLUMN 0u
#define TOPCOLUMN 80u
#define ONE 1u

void TeraTerm_paint_init();
void TeraTerm_draw();

#endif /* TERATERM_H_ */
