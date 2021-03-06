/*
 * LCD_interface.h
 *
 *  Created on: Mar 12, 2021
 *      Author: kh
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define MODE_4_BIT 0
#define MODE_8_BIT 1
extern void HAL_LCD_Init(void);

extern void HAL_LCD_voidWriteCharacter(uint8_t Copy_u8Character);

extern void HAL_LCD_voidWriteString(uint8_t arr[]);

extern void HAL_LCD_voidMoveCursor(uint8_t Copy_u8Row , uint8_t Copy_u8Col);

void HAL_LCD_SpecialChar(uint8_t arr[] , uint8_t Copy_NoOfBlocks ,  uint8_t Copy_Row , uint8_t Copy_Col);
void HAL_LCD_voidClr(uint8_t Copy_u8Rowc , uint8_t Copy_u8Colc,uint8_t Copy_u8BacktoRow , uint8_t Copy_u8BacktoCol);
void HAL_LCD_voidReadData(uint8_t *Copy_u8value);

void HAL_LCD_voidWriteCommand(uint8_t Copy_u8Command);
void HAL_LCD_voidShiftCursor(uint8_t numofTimes,uint8_t Copy_u8Row);
#endif /* LCD_INTERFACE_H_ */
