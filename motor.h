#ifndef _dc_motor_
#define _dc_motor_
#define F_CPU 8000000UL // 16MHz clock speed
#include <avr/io.h>
#include <util/delay.h>

#define motor_pins_DIR DDRD
#define motor_pins_value PORTD

void power_on_motor(void);


#endif