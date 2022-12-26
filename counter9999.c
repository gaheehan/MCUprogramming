#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#define SEGMENT_DELAY 10
//4자릿수 표현
char number[] = {0x7e, 0x60, 0x3d, 0x79, 0x63, 0x5b,0x5f, 0x72, 0x7f, 0x73};

void display_digit(int position, int n){
	PORTC |= 0x0f;
	PORTC &= (0x01 << (position - 1));
	PORTE = ~number[n];
	}
	
void display_counter(int n){
	int j;
	for(j=0;j<5;j++){
		display_digit(1, n%10);
		_delay_ms(SEGMENT_DELAY);
		display_digit(2, (n/10)%10);
		_delay_ms(SEGMENT_DELAY);
		display_digit(3, (n/100)%10);
		_delay_ms(SEGMENT_DELAY);
		display_digit(4, (n/1000)%10);
		_delay_ms(SEGMENT_DELAY);
	}
	
}

int main(void)
{  
	int i = 0;
	DDRE = 0xff;
	DDRC = 0x0f;
		
	PORTC = 0x0f;
		
	while (1){
		/*for(j=0;j<5;j++){
			display_digit(1, i%10);
			_delay_ms(SEGMENT_DELAY);
			display_digit(2, (i/10)%10);
			_delay_ms(SEGMENT_DELAY);
			display_digit(3, (i/100)%10);
			_delay_ms(SEGMENT_DELAY);
			display_digit(4, (i/1000)%10);
			_delay_ms(SEGMENT_DELAY);
		}*/
		    display_counter(i);
		    i++;			
	}
	 

return 0;
}