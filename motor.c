#include "motor.h"

void power_on_motor(){
       DDRD|=((1<<PD0)|(1<<PD1)|(1<<PD2));
	   PORTD^=(1<<PD2);
//Rotates Motor in Antilockwise
		PORTD |= (1<<PD0); //00000001
		_delay_ms(4000);

		//Stops Motor
		PORTD &=~ (1<<PD0); //00000000
		_delay_ms(4000);

		//Rotates Motor in Clockwise
		PORTD |= (1<<PD1); //00000010
		_delay_ms(4000);

		//Stops Motor
		PORTD |= ((1<<PD0)|(1<<PD1));//00000011
		_delay_ms(4000);
		PORTD&=~((1<<PD0)|(1<<PD1)|(1<<PD2));
}		