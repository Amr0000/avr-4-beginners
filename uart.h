// finally my UART !!!!!!!
#ifndef _UART_H_
#define _UART_H_


#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

// uart init
void uart_init(void);

//Functions recieve data

unsigned char uart_receive (void);
 


//Functions transmit data

void uart_transmit (unsigned char data);
 


//Functions transmit string
void uart_transmit_str(unsigned char *ptr);
	
#endif