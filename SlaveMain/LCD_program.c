/*
 * LCD_program.c
 *
 *  Created on: Mar 12, 2021
 *      Author: kh
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Common.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_Cfg.h"

#include "avr/delay.h"


static void HAL_LCD_voidWriteData(uint8_t Copy_u8Data);



void HAL_LCD_voidReadData(uint8_t *Copy_u8value){

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */

	MCAL_DIO_voidSetPinValue(LCD_RS_PIN , DIO_HIGH); /*0 write Command */

	MCAL_DIO_voidSetPinValue(LCD_RW_PIN , DIO_HIGH); /*0 read */
	_delay_ms(20);

    MCAL_DIO_voidGetPortValue(LCD_DATA_PORT,Copy_u8value);
    _delay_ms(20);
	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_HIGH); /*Enable is high */

	_delay_ms(20);

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */

}
void HAL_LCD_voidWriteCommand(uint8_t Copy_u8Command)
{
#if(LCD_BIT_MODE == MODE_8_BIT)

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */

	MCAL_DIO_voidSetPinValue(LCD_RS_PIN , DIO_LOW); /*0 write Command */

	MCAL_DIO_voidSetPinValue(LCD_RW_PIN , DIO_LOW); /*0 write */

	MCAL_DIO_voidSetPortValue(LCD_DATA_PORT , Copy_u8Command);

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_HIGH); /*Enable is high */

	_delay_ms(2);

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */
#elif(LCD_BIT_MODE == MODE_4_BIT)

		//MCAL_DIO_voidSetPinDirection(2,0,1);
		//MCAL_DIO_voidSetPinValue(2 , 0 , 1);

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */

	MCAL_DIO_voidSetPinValue(LCD_RS_PIN , DIO_LOW); /*0 write Command */

	MCAL_DIO_voidSetPinValue(LCD_RW_PIN , DIO_LOW); /*0 write */

	LCD_DATA_PORT_REG = (Copy_u8Command & 0xF0) | (LCD_DATA_PORT_REG & 0x0F) ;

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_HIGH); /*Enable is high */

	_delay_ms(2);

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */

	_delay_ms(2);

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */

	MCAL_DIO_voidSetPinValue(LCD_RS_PIN , DIO_LOW); /*0 write Command */

	MCAL_DIO_voidSetPinValue(LCD_RW_PIN , DIO_LOW); /*0 write */

	LCD_DATA_PORT_REG = (Copy_u8Command << 4) | (LCD_DATA_PORT_REG & 0x0F) ;

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_HIGH); /*Enable is high */

	_delay_ms(2);

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */

	_delay_ms(2);

#endif

}

void HAL_LCD_voidWriteData(uint8_t Copy_u8Data)
{
#if(LCD_BIT_MODE == MODE_8_BIT)
	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */

	MCAL_DIO_voidSetPinValue(LCD_RS_PIN , DIO_HIGH); /*0 write Data */

	MCAL_DIO_voidSetPinValue(LCD_RW_PIN , DIO_LOW); /*0 write */

	MCAL_DIO_voidSetPortValue(LCD_DATA_PORT , Copy_u8Data);

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_HIGH); /*Enable is high */

	_delay_ms(2);

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */

#elif(LCD_BIT_MODE == MODE_4_BIT)

	//MCAL_DIO_voidSetPinDirection(2,0,1);
	//MCAL_DIO_voidSetPinValue(2 , 0 , 1);
	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */

	MCAL_DIO_voidSetPinValue(LCD_RS_PIN , DIO_HIGH); /*0 write Command */

	MCAL_DIO_voidSetPinValue(LCD_RW_PIN , DIO_LOW); /*0 write */

	LCD_DATA_PORT_REG = (Copy_u8Data & 0xF0) | (LCD_DATA_PORT_REG & 0x0F) ;

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_HIGH); /*Enable is high */

	_delay_ms(2);

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */

	_delay_ms(2);

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */

	MCAL_DIO_voidSetPinValue(LCD_RS_PIN , DIO_HIGH); /*0 write Command */

	MCAL_DIO_voidSetPinValue(LCD_RW_PIN , DIO_LOW); /*0 write */

	LCD_DATA_PORT_REG = (Copy_u8Data << 4) | (LCD_DATA_PORT_REG & 0x0F) ;

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_HIGH); /*Enable is high */

	_delay_ms(2);

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */

	_delay_ms(2);
#endif

}


void HAL_LCD_Init(void)
{
#if(LCD_BIT_MODE == MODE_8_BIT)
	MCAL_DIO_voidSetPinDirection(LCD_E_PIN , DIO_OUTPUT);
	MCAL_DIO_voidSetPinDirection(LCD_RS_PIN , DIO_OUTPUT);
	MCAL_DIO_voidSetPinDirection(LCD_RW_PIN , DIO_OUTPUT);

	MCAL_DIO_voidSetPortDirection(LCD_DATA_PORT , DIO_PORT_OUTPUT);

	_delay_ms(30);

	HAL_LCD_voidWriteCommand(0b00111100); // 00(8bits or 4bits)(1 line or 2 lines)(font)00

	_delay_ms(2);

	HAL_LCD_voidWriteCommand(0x00001100); //0b00001DCB

	_delay_ms(2);

	HAL_LCD_voidWriteCommand(0b00000001);

	_delay_ms(2);
#elif(LCD_BIT_MODE == MODE_4_BIT)

	MCAL_DIO_voidSetPinDirection(LCD_E_PIN , DIO_OUTPUT);
	MCAL_DIO_voidSetPinDirection(LCD_RS_PIN , DIO_OUTPUT);
	MCAL_DIO_voidSetPinDirection(LCD_RW_PIN , DIO_OUTPUT);

	LCD_DATA_DIR_REG = (LCD_DATA_DIR_REG & 0x0F) | 0xF0 ;

	_delay_ms(30);

	HAL_LCD_voidWriteCommand(0x33); //0b00(1100)00

	_delay_ms(2);

	HAL_LCD_voidWriteCommand(0x32);

	_delay_ms(2);

	HAL_LCD_voidWriteCommand(0b00101100);

	_delay_ms(2);

	HAL_LCD_voidWriteCommand(0b00001111);

	_delay_ms(2);

	HAL_LCD_voidWriteCommand(0b00000001);

	_delay_ms(2);




#endif

}

void HAL_LCD_voidClr(uint8_t Copy_u8Rowc , uint8_t Copy_u8Colc,uint8_t Copy_u8BacktoRow , uint8_t Copy_u8BacktoCol){
	HAL_LCD_voidMoveCursor(Copy_u8Rowc,Copy_u8Colc);
	HAL_LCD_voidWriteCharacter(7);
	HAL_LCD_voidMoveCursor(Copy_u8BacktoRow ,Copy_u8BacktoCol);

}
void HAL_LCD_voidWriteCharacter(uint8_t Copy_u8Character)
{
	HAL_LCD_voidWriteData(Copy_u8Character);
}

void HAL_LCD_voidWriteString(uint8_t arr[])
{
	uint8_t Loop = 0 ;

	while(arr[Loop] != NULL_CHAR)
	{
		HAL_LCD_voidWriteData(arr[Loop]);
		Loop++ ;
	}
}

void HAL_LCD_voidMoveCursor(uint8_t Copy_u8Row , uint8_t Copy_u8Col)
{
	/*if(Copy_u8Row == 0)
	{
		HAL_LCD_voidWriteCommand( 128 + Copy_u8Col);
	}
	else if(Copy_u8Row == 1)
	{
		HAL_LCD_voidWriteCommand( 128 + 0x40 + Copy_u8Col); //128 = 0x80 = 0b10000000
	}*/

	HAL_LCD_voidWriteCommand( 128 + (0x40 * Copy_u8Row) + Copy_u8Col);
}
void HAL_LCD_SpecialChar(uint8_t arr[] , uint8_t Copy_BlockNum ,  uint8_t Copy_Row , uint8_t Copy_Col)
{
	uint8_t Loop;

	HAL_LCD_voidWriteCommand(0x40+(0x08*Copy_BlockNum));
	for(Loop = 0 ; Loop < 8 ; Loop++)
	{
	HAL_LCD_voidWriteData(arr[Loop]);
	}


	HAL_LCD_voidMoveCursor(Copy_Row , Copy_Col);
}

void HAL_LCD_voidShiftCursor(uint8_t numofTimes,uint8_t Copy_u8Row){
	HAL_LCD_voidWriteCommand(0x80+(0x01*numofTimes)+(0x40 * Copy_u8Row));

}

