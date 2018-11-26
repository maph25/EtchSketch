/*
 * TeraTerm.c
 *
 *  Created on: Nov 26, 2018
 *      Author: Andy
 */
#include "UART.h"
#include "TeraTerm.h"

uint8 positionColumn;
uint8 positionRow;

void TeraTerm_paint_init(){
	UART_put_string(UART_0,"\033[2J"); /*Clear screen*/
	UART_put_string(UART_0,"\033[0;37;44m"); /*Text in white and background in blue */
	UART_put_string(UART_0,"\033[0;24H");/*Start position*/
	UART_put_char(UART_0, '*'); /*Prints starting point of etch sketch*/
	positionColumn = LOWCOLUMN;
	positionRow = LOWROW;
}

void TeraTerm_draw(){
	uint8 flag;
	uint8 mailbox;
	flag = UART_flag_return();
	mailbox = UART_mailbox_return();
	while(flag == TRUE){
		switch(mailbox){
			case UP:{
				positionRow = positionRow + ONE;
				if(positionRow > TOPROW)
					positionRow = TOPROW;
			}
				break;
			case DOWN:{
				positionRow = positionRow - ONE;
				if(positionRow < LOWROW)
					positionRow = LOWROW;

			}
				break;
			case RIGHT:
				positionColumn = positionColumn + ONE;
				if(positionColumn > TOPCOLUMN)
					positionColumn = TOPCOLUMN;
				break;
			case LEFT:
				positionColumn = positionColumn - ONE;
				if(positionColumn < LOWCOLUMN)
					positionColumn = LOWCOLUMN;
				break;
			case ENTER:
				TeraTerm_paint_init();
				break;
			default:
				break;
			}

	}

	UART_put_string(UART_0,"\033[2J"); /*Clear screen*/
	UART_put_string(UART_0,"\033[0;37;44m"); /*Text in white and background in blue */
	UART_put_string(UART_0,"\033[positionColumn;positionColumnH");/*Start position*/
	UART_put_char(UART_0, '*'); /*Prints starting point of etch sketch*/

}
