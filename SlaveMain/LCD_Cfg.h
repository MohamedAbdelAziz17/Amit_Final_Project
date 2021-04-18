/*
 * LCD_Cfg.h
 *
 *  Created on: Mar 12, 2021
 *      Author: kh
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_
#include "AVR_DIO_REG.h"

#define LCD_DATA_PORT	DIO_PORTC

#define LCD_DATA_DIR_REG DDRC
#define LCD_DATA_PORT_REG PORTC
#define LCD_RS_PIN  	DIO_PORTB , DIO_PIN_1
#define LCD_RW_PIN  	DIO_PORTB , DIO_PIN_2
#define LCD_E_PIN  	DIO_PORTB , DIO_PIN_3




/*MODE_4_BIT
 * MODE_8_BIT*/
#define LCD_BIT_MODE  MODE_4_BIT

#endif /* LCD_CFG_H_ */
