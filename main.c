/*
 * GccApplication7.c
 *
 * Created: 2022-12-20 오전 9:24:30
 * Author : 21
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	int i = 0;
	char number[] = {0x7e, 0x60, 0x3d, 0x79, 0x63, 0x5b,0x5f, 0x72, 0x7f, 0x73};
	DDRE = 0xff; //출력포트	
	DDRD = 0x00; //입력포트
	DDRF = 0xff; PORTF = 0xff; //신호발생(출력)
    while (1) 
    {
		if(((PIND & 0b000010) >> 1) == 0){
			i++;
			if(i > 9)
				i=0;
			PORTE = ~number[i];
			_delay_ms(1000);
			}
		
		
		if(((PIND & 0b000100) >> 2) == 0){
			i--;
			if(i < 0)
				i = 9;
			PORTE = ~number[i];
			_delay_ms(1000);
			}
	}
	return 0;
}

