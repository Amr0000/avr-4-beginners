#ifndef	LCDCONFIG_H_
#define LCDCONFIG_H_

//#include <stdint.h>

/***************************************************************************
The four data lines as well as the two control lines may be
implemented on any available I/O pin of any port.  These are
the connections used for this program:



**************************************************************************/
//lcd D7 pin
#define LCD_PORT_D7     	PORTB
#define LCD_DDR_D7      	DDRB
#define D7_BIT		        PB6
//lcd D6 pin
#define LCD_PORT_D6     	PORTB
#define LCD_DDR_D6          DDRB
#define D6_BIT				PB5
//lcd D5 pin
#define LCD_PORT_D5     	PORTB
#define LCD_DDR_D5      	DDRB
#define D5_BIT				PB4
//lcd D4 pin
#define LCD_PORT_D4     	PORTB
#define LCD_DDR_D4      	DDRB
#define D4_BIT				PB3
//lcd Register Select pin
#define RS_PORT				PORTB
#define RS_BIT				PB0
#define RS_DDR				DDRB
//lcd Read/write pin	
#define RW_PORT				PORTB
#define RW_BIT				PB1
#define RW_DDR				DDRB
//lcd Enable pin	
#define E_PORT				PORTB
#define E_BIT				PB2
#define E_DDR				DDRB

 
#endif // LCDCONFIG_H_