/*
 * GccApplication6.c
 *
 * Created: 2022-12-19 오후 2:46:11
 * Author : 21
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{	char pattern = 0b00000001;
	DDRD = 0x00; //입력포트
	DDRB = 0xff; //출력포트
	DDRF = 0xff; PORTF = 0xff; //신호발생(출력)
	
	PORTB = 0x01;
    while (1) 
    {
		if(((PIND & 0b00000010) >> 1) == 0){
			pattern = (pattern)<<1;
			_delay_ms(500);
		}
		PORTB = pattern;
	}
	
}

