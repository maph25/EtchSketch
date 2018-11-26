/*	\file
	\brief
		This project shows how works the emulation of a VT 100 in teraterm.
	\author J. Luis Pizano Escalante, luispizano@iteso.mx
	\date	27/07/2015
	\todo
		To implement the UART_init function
 */

#include <UART.h>/**UART device driver*/
#include "MK64F12.h" /* include peripheral declarations */
#include "NVIC.h"/**NVIC device driver*/
#include "stdio.h"


/**This is mail box to received the information from the serial port*/
extern UART_MailBoxType UART0_MailBox;

int main(void)
{
	/**Enables the clock of PortB in order to configures TX and RX of UART peripheral*/
	SIM->SCGC5 = SIM_SCGC5_PORTB_MASK;
	/**Configures the pin control register of pin16 in PortB as UART RX*/
	PORTB->PCR[16] = PORT_PCR_MUX(3);
	/**Configures the pin control register of pin16 in PortB as UART TX*/
	PORTB->PCR[17] = PORT_PCR_MUX(3);
	/**Configures UART 0 to transmit/receive at 11520 bauds with a 21 MHz of clock core*/
	UART_init (UART_0,  21000000, BD_115200);
		//printf("UART is configured");

	NVIC_enableInterruptAndPriotity(UART0_IRQ, PRIORITY_10);

	UART_interruptEnable(UART_0);
	/**Enables the UART 0 interrupt in the NVIC*/

		/**Enables interrupts*/
	EnableInterrupts;
    while(1) {

    }
    return 0 ;
}
