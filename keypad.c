/*
 * keypad.c
 *
 * Created: 17/08/2017 3:02:30 PM
 *  Author: Amr
 */ 
#include "keypad.h"
//*****************************************************************************/
//the keypad map
const uint8_t keypad_Characters[4][4] = {{'7','8','9','/'},
										 {'4','5','6','*'},
										 {'1','2','3','-'},
										 {'c','0','=','+'}};
//*****************************************************************************/


//*****************************************************************************

//*****************************************************************************

  
//*****************************************************************************
//
//! vKeypadInit.
//!
//! \param None.
//! this fuction intializes the Keypad module 4*4.
//! Keypad pins have to be defined as connected to the hardware in the keypadconfig.h
//!
//! \return None.
//
//*****************************************************************************
void 
vKeypadInit (void)
{

	// set Rows direction as output.so i'll put the token through rows
	ROW0_DDR |= (1U << ROW0);
	ROW1_DDR |= (1U << ROW1);
	ROW2_DDR |= (1U << ROW2);
	ROW3_DDR |= (1U << ROW3);
	// set Lines direction as input. so i'll read through lines
	LINE0_DDR &=~ (1U << LINE0);
	LINE1_DDR &=~ (1U << LINE1);
	LINE2_DDR &=~ (1U << LINE2);
	LINE3_DDR &=~ (1U << LINE3);
	// connect Lines to pull up.so the values will 0
	LINE0_PULLUP |= (1U << LINE0);
	LINE1_PULLUP |= (1U << LINE1);
	LINE2_PULLUP |= (1U << LINE2);
	LINE3_PULLUP |= (1U << LINE3);
}
  
//*****************************************************************************
//
//! vKeypadInit.
//!
//! \param None.
//! this fuction scan the keypad and return the mapped keypad button value in keypad_Characters array.
//!
//! \return NO_KEY_PRESSED if no button was pressed during the scan.
//! \return uint8_t keypad_Characters[row][line]
//
//*****************************************************************************

uint8_t 
ucKeypadScan(void)
{
	// loop the output on rows.
	uint8_t row,line=0;
	for (row=0 ; row <4 ; row++)
	{
		// Set all rows to high.
		ROW0_PORT |= (1U << ROW0);
		ROW1_PORT |= (1U << ROW1);
		ROW2_PORT |= (1U << ROW2);
		ROW3_PORT |= (1U << ROW3);
		// Clear the numbered row.
		switch (row)
			{
				case 0: ROW0_PORT &=~ (1U << ROW0); break;
				case 1: ROW1_PORT &=~ (1U << ROW1);	break;
				case 2: ROW2_PORT &=~ (1U << ROW2);	break;
				case 3: ROW3_PORT &=~ (1U << ROW3);	break;
				default: break;
			}
		// Check if the user has hit a keypad button
		if (ALL_LINES != 1)
			{
				// Read the input.
				if((LINE0_PIN & (1U << LINE0))==0)
				{
					line=0;
					//_delay_ms(50);
				}		
				else if ((LINE1_PIN & (1U << LINE1))==0) 	
				{
					line=1;
					//_delay_ms(50);
				}
				else if ((LINE2_PIN & (1U << LINE2))==0) 	
				{
					line=2;
					//_delay_ms(50);
				}
				else if ((LINE3_PIN & (1U << LINE3))==0) 	
				{
					line=3;
					//_delay_ms(50);
				}
				else 
				{
					;
				}
				// Wait till the user release his finger.
				while (ALL_LINES != 1);
				break;
			}
	}
	// Check if no input entered.
	if (row==4)
		{
			return NO_KEY_PRESSED;
		}
	// Return the array character.
	return keypad_Characters[row][line]; 
}