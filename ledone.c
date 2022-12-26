/*
 * GccApplication1.c
 *
 * Created: 2022-12-16 오후 4:14:52
 * Author : 21
 */ 

#define  F_CPU 16000000L /*Hz설정*/
#include <avr.io.h>
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	DDRB = 0xff; //0b11111111
	
    while (1) 
    {
		PORTB = 0b00000001; //0b11111111
		_delay_ms(1000);
		PORTB = 0b00000010;
		_delay_ms(1000);
		PORTB = 0b00000100;
		_delay_ms(1000);
		PORTB = 0b00000101;
		_delay_ms(1000);
		PORTB = 0b00000111;
		_delay_ms(1000);
		PORTB = 0b00001000;
		_delay_ms(1000);
		PORTB = 0b00001001;
		_delay_ms(1000);
		PORTB = 0b00001010;
		_delay_ms(1000);
    }
}

