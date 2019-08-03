#ifndef __LCDMAZIDI_H__
#define __LCDMAZIDI_H__

#include "LCDMazidi_Config.h"
#include <avr/io.h>
#include <util/delay.h>

//Functions prototypes
void lcdCommand (unsigned char cmnd);
void lcdData (unsigned char data);
void lcd_init (void);
void lcd_gotoxy (unsigned char x,unsigned char y);
void lcd_print (char *str);
void LCD_clear(void);

#endif
