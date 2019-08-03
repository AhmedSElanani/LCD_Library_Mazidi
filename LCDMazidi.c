#include "LCDMazidi.h"


void lcd_init ()
{
	#if (LCD_MODE==4)
	LCD_DDDR = 0xFF;
	LCD_CDDR = 0xFF;
	LCD_CPRT &= ~(1<<LCD_EN);
	lcdCommand(0x33);
	lcdCommand(0x32);
	lcdCommand(0x28);
	lcdCommand(0x0E);
	lcdCommand(0x01);
	_delay_us(2000);
	lcdCommand(0x06);
	#endif
	
	#if (LCD_MODE==8)
	LCD_DDDR = 0xFF;
	LCD_CDDR = 0xFF;
	LCD_CPRT &= ~(1<<LCD_EN);
	_delay_us(2000);
	lcdCommand(0x38);
	lcdCommand(0x0E);
	lcdCommand(0x01);
	_delay_us(2000);
	lcdCommand(0x06);
	#endif
}

void lcdCommand (unsigned char cmnd)
{
	#if (LCD_MODE==4)
	LCD_DPRT = cmnd & 0xF0 ;
	LCD_CPRT &= ~(1<<LCD_RS);
	LCD_CPRT &= ~(1<<LCD_RW);
	LCD_CPRT |= (1<<LCD_EN);
	_delay_us(1);
	LCD_CPRT &= ~(1<<LCD_EN);
	_delay_us(100);
	LCD_DPRT = cmnd<<4;
	LCD_CPRT |= (1<<LCD_EN);
	_delay_us(1);
	LCD_CPRT &=~(1<<LCD_EN);
	_delay_us(100);
	#endif

	#if (LCD_MODE==8)
	LCD_DPRT = cmnd;
	LCD_CPRT &= ~(1<<LCD_RS);
	LCD_CPRT &= ~(1<<LCD_RW);
	LCD_CPRT |= (1<<LCD_EN);
	_delay_us(1);
	LCD_CPRT &= ~(1<<LCD_EN);
	_delay_us(100);
	#endif
}

void lcdData (unsigned char data)
{
	#if (LCD_MODE==4)
	LCD_DPRT = data & 0xF0 ;
	LCD_CPRT |= (1<<LCD_RS);
	LCD_CPRT &= ~(1<<LCD_RW);
	LCD_CPRT |= (1<<LCD_EN);
	_delay_us(1);
	LCD_CPRT &= ~(1<<LCD_EN);
	LCD_DPRT = (data<<4);
	LCD_CPRT |= (1<<LCD_EN);
	_delay_us(1);
	LCD_CPRT &= ~(1<<LCD_EN);
	_delay_us(100);
	#endif
	
	#if (LCD_MODE==8)
	LCD_DPRT = data ;
	LCD_CPRT |= (1<<LCD_RS);
	LCD_CPRT &= ~(1<<LCD_RW);
	LCD_CPRT |= (1<<LCD_EN);
	_delay_us(1);
	LCD_CPRT &= ~(1<<LCD_EN);
	_delay_us(100);
	#endif
}

void lcd_gotoxy (unsigned char x,unsigned char y)
{
	#if (LCD_MODE==4)
	unsigned char firstcharAdr [] = {0x80,0xC0,0x94,0xD4};
	lcdCommand( firstcharAdr[y-1] + x - 1 );
	_delay_us(100);
	#endif
	
	#if (LCD_MODE==8)
	unsigned char firstcharAdr [] = {0x80,0xC0,0x94,0xD4};
	lcdCommand( firstcharAdr[y-1] + x - 1 );
	_delay_us(100);
	#endif
}

void lcd_print (char *str)
{
	#if (LCD_MODE==4)
	unsigned char i = 0;
	while (str[i] !=0)
	{
		lcdData(str[i++]);
	}
	#endif
	
	#if (LCD_MODE==8)
	unsigned char i = 0;
	while (str[i] !=0)
	{
		lcdData(str[i++]);
	}
	#endif
}

void LCD_clear(void)
{
	lcdCommand(0x01); 
}
