#define  F_CPU 16000000L /*Hz¼³Á¤*/
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	char pattern1 = 0b01010101;
	char pattern2 = 0b10101010;
	DDRB = 0xff; //0b11111111
	PORTB = pattern1;
	_delay_ms(500);
	while(1)
	{
		if((PORTB >> 7) == 0){
			PORTB = pattern2;
			_delay_ms(500);
		}
		else{
			PORTB = pattern1; 
			_delay_ms(500);
		}
	}
			
}