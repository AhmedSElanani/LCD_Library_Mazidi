#ifndef __LCDMAZIDICONFIG_H__
#define __LCDMAZIDICONFIG_H__

#ifndef F_CPU
#define F_CPU 1000000UL
#endif

#define LCD_MODE 4				//(4_BIT or 8_BIT)
#define LCD_DPRT PORTA
#define LCD_DDDR DDRA
#define LCD_DPIN PINA
#define LCD_CPRT PORTB
#define LCD_CDDR DDRB
#define LCD_CPIN PINB
#define LCD_RS 0
#define LCD_RW 1
#define LCD_EN 2

#endif