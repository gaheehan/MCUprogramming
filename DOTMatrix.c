/*
 * GccApplication10.c
 *
 * Created: 2022-12-23 오후 3:59:22
 * Author : 21
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	char pattern1 = 0x01, pattern2 = 0x01;
	DDRF = 0xff; //행
	DDRC = 0xff; //열
	
	//PORTF = 0xff;
    //PORTC = 0x00;
	
    while (1) 
    {
		PORTF = pattern1;
		PORTC = ~pattern2;
		pattern1 = pattern1 << 1;
		if(pattern1 == 0x00){
			pattern1 = 0x01;
			pattern2 = pattern2 <<1;
			if(pattern2 == 0x00)
			    pattern2 = 0x01;
		}
		_delay_ms(100);
    }
	
	return 0;
}

