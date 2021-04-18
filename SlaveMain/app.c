/*
 * app.c
 *
 *  Created on: Apr 9, 2021
 *      Author: m7mdAG
 */
/**		SLAVE MAIN		**/


#include "STD_TYPES.h"
#include "Common.h"
#include <string.h>
#include "DIO_interface.h"
#include "SPI.h"
#include "LCD_interface.h"

    uint8_t voiceCommand[20];

	/**Commands**/
	uint8_t lightsOn[10]="lights on";
	uint8_t lightsOff[11]="lights off";
	uint8_t FanOn[10]="fan on";
	uint8_t FanOff[10]="fan off";

    uint8_t i=0;
    uint8_t data;

void checkLights(void);
void checkFan(void);

int main(void){
	HAL_LCD_Init();
	SPI_Init();

	MCAL_DIO_voidSetPortDirection(DIO_PORTA,DIO_PORT_OUTPUT);


	while(1){
		data=SPI_Receive();
		/**	  code	**/
		voiceCommand[i]=data;
		i++;
		checkLights();
		checkFan();
	}
}




void checkLights(void){
	if(strcmp((char*)lightsOn,(char*)voiceCommand)==0)
	{
		MCAL_DIO_voidSetPinValue(DIO_PORTA,DIO_PIN_0,DIO_HIGH);
		MCAL_DIO_voidSetPinValue(DIO_PORTA,DIO_PIN_2,DIO_HIGH);
		MCAL_DIO_voidSetPinValue(DIO_PORTA,DIO_PIN_3,DIO_HIGH);

		HAL_LCD_voidWriteString(voiceCommand);
		memset(voiceCommand,0,strlen((char*)voiceCommand));// clear voiceCommand
		i=0;
	}
	else if(strcmp((char*)lightsOff,(char*)voiceCommand)==0)
	{
		MCAL_DIO_voidSetPinValue(DIO_PORTA,DIO_PIN_0,DIO_LOW);
		MCAL_DIO_voidSetPinValue(DIO_PORTA,DIO_PIN_2,DIO_LOW);
		MCAL_DIO_voidSetPinValue(DIO_PORTA,DIO_PIN_3,DIO_LOW);
		HAL_LCD_voidWriteString(voiceCommand);
		memset(voiceCommand,0,strlen((char*)voiceCommand));// clear voiceCommand
		i=0;
	}
	else if(data=='c')
	{
		HAL_LCD_voidWriteCommand(1);
		memset(voiceCommand,0,strlen((char*)voiceCommand));// clear voiceCommand
		i=0;
	}
	else{
	}
}

void checkFan(void){
	if(strcmp((char*)voiceCommand,(char*)FanOn)==0)
		{
			MCAL_DIO_voidSetPinValue(DIO_PORTA,DIO_PIN_1,DIO_HIGH);
			HAL_LCD_voidWriteString(voiceCommand);
			memset(voiceCommand,0,strlen((char*)voiceCommand)); // clear voiceCommand
			i=0;
		}
		else if(strcmp((char*)voiceCommand,(char*)FanOff)==0)
		{
			MCAL_DIO_voidSetPinValue(DIO_PORTA,DIO_PIN_1,DIO_LOW);
			HAL_LCD_voidWriteString(voiceCommand);
			memset(voiceCommand,0,strlen((char*)voiceCommand));// clear voiceCommand
			i=0;
		}
		else if(data=='c')
		{
			HAL_LCD_voidWriteCommand(1);
			memset(voiceCommand,0,strlen((char*)voiceCommand));// clear voiceCommand
			i=0;
		}
		else{
		}
}


