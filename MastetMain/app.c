/*
 * app.c
 *
 *  Created on: Apr 9, 2021
 *      Author: m7mdAG
 */
/**		MASTER MAIN		**/


#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "SPI.h"
#include "UART.h"


int main(void){
	UART_Init();
	SPI_Init();
	uint8_t dataRecieved;

	SPI_SlaveSelect(0);
	while(1){
		dataRecieved=UART_Receive();
		SPI_Transmit(dataRecieved);


	}
}

