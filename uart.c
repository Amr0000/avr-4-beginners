
#include "uart.h"



void uart_init(void){
	//UART initialization
	UBRRH=0x00;
	UBRRL=0x4d; // To set the Buad rate to 9600.. get value through above formula
	UCSRB=(1<<RXCIE) | (1<<RXEN) | (1<<TXEN);
	UCSRC=(1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0) ;
	
}


unsigned char uart_receive ()
 {
 while((UCSRA&(1<<RXC)) == 0);
 // wait untill 8-bit of a character receive
 return UDR;
 }



//Functions transmit data

void uart_transmit (unsigned char data)
 {
 while (!( UCSRA & (1<<UDRE)));
 // wait for the register to free from data
 UDR = data;
 // load data in the register
 }

void uart_transmit_str(unsigned char *ptr){
	while (*ptr)
	{
		uart_transmit(*ptr++);
	}
	
	};

