#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#define SEGMENT_DELAY 50

//4자릿수 표현
char number[] = {0x7e, 0x60, 0x3d, 0x79, 0x63, 0x5b,0x5f, 0x72, 0x7f, 0x73};

void display_digit(int position, int n){
	PORTC |= 0x0f;
	PORTC &= (0x01 << (position - 1));
	PORTE = ~number[n];
	
int main(void)
{
	int i = 0;
	
	DDRE = 0xff; 
	DDRC = 0x0f; 
	
	PORTC = 0x0f;
	
	while (1)
	{
		display_digit(1,1);
		_delay_ms(SEGMENT_DELAY);
		display_digit(2,2);
		_delay_ms(SEGMENT_DELAY);
		display_digit(3,3);
		_delay_ms(SEGMENT_DELAY);
		display_digit(4,4);
		_delay_ms(SEGMENT_DELAY);
		
		
	}


}

return 0;

