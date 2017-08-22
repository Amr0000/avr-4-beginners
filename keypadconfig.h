/*
 * keypad.c
 *
 * Created: 17/08/2017 3:03:00 PM
 *  Author: Amr
 */ 

#ifndef KEYPADCONFIG_H_
#define KEYPADCONFIG_H_

	#define F_CPU	8000000UL
	#include <avr/io.h>
	#include <util/delay.h>

/**************************************************************************/
#include <stdint.h>
/**************************************************************************/


/**************************************************************************/
#define ROW0			4
#define ROW0_DDR		DDRD
#define ROW0_PORT		PORTD

#define ROW1			5
#define ROW1_DDR		DDRD
#define ROW1_PORT		PORTD

#define ROW2			6
#define ROW2_DDR		DDRD
#define ROW2_PORT		PORTD

#define ROW3			7
#define ROW3_DDR		DDRD
#define ROW3_PORT		PORTD

#define LINE0			0
#define LINE0_DDR		DDRD
#define LINE0_PIN		PIND
#define LINE0_PULLUP	PORTD

#define LINE1			1
#define LINE1_DDR		DDRD
#define LINE1_PIN		PIND
#define LINE1_PULLUP	PORTD

#define LINE2			2
#define LINE2_DDR		DDRD
#define LINE2_PIN		PIND
#define LINE2_PULLUP	PORTD

#define LINE3			3
#define LINE3_DDR		DDRD
#define LINE3_PIN		PIND
#define LINE3_PULLUP	PORTD


#endif /* KEYPADCONFIG_H_ */