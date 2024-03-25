/*
 * LCD_4bit_h_file.h
 *
 * This is header file
 *  Author: Arif Anik, MTE'17
 */ 

#ifndef LCD_4BIT_H_FILE_H_
#define LCD_4BIT_H_FILE_H_

#define F_CPU 8000000UL					/* Define CPU Frequency e.g. here its 8MHz */
#include <avr/io.h>						/* Include AVR std. library file */
#include <util/delay.h>					/* Include inbuilt defined Delay header file */
#include <stdio.h>
#include <string.h>

#define LCD_Dir DDRD					/* Define LCD data port direction */
#define LCD_Port PORTD					/* Define LCD data port */
#define RS PD2							/* Define Register Select (data reg./command reg.) signal pin */
#define EN PD3 							/* Define Enable signal pin */

void LCD_Init (void);
void LCD_Char( unsigned char data );
void LCD_String (char *str);
void LCD_String_xy (char row, char pos, char *str);
void LCD_Clear();
void LCD_Set_Cursor(char a, char b);
void LCD_Shift_R();
void LCD_Shift_L();
void LCD_Decimal_xy(char row, char pos, uint8_t i);

#endif 


/* LCD_4BIT_H_FILE_H_ */

