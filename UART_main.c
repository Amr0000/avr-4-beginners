/*
 * UART_AMR.c
 * 
 * Created: 15/08/2017 09:58:37 
 *  Author: Amr Ahmed
 */ 

#include <avr/io.h>
#include "uart.h"
 unsigned char ARR[]="HELLO WORLD";


int main(void)
{
	uart_init();

    while(1)
    {
		
        //data=uart_receive();
		uart_transmit_str(ARR); 
		_delay_ms(500);
	    uart_transmit(13); //the ascii code for new line
		_delay_ms(500);
    }
}