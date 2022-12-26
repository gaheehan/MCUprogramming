/*
 * GccApplication16.c
 *
 * Created: 2022-12-26 오후 5:13:37
 * Author : 21
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <time.h>
#include <stdlib.h>

//포트 정의
#define PORT_DATA    PORTC
#define PORT_CONTROL PORTA
#define DDR_DATA     DDRC
#define DDR_CONTROL  DDRA

//제어핀번호 정의
#define RS_PIN       0
#define RW_PIN       1
#define E_PIN        2

//명령어(command) 정의
#define COMMAND_CLEAR_DISPLAY  0x01
#define COMMAND_8_BIT_MODE     0x38
#define COMMAND_4_BIT_MODE     0x28
#define COMMAND_DISPLAY_ON_OFF_BIT  2
#define COMMAND_CURSE_ON_OFF_BIT    1
#define COMMAND_BLANK_ON_OFF_BIT    0

//제어신호 핀 중, enable(E)핀에 신호 주기
void LCD_pulse_enable(void)
{
	PORT_CONTROL |= (0x01 << E_PIN);
	_delay_ms(1);
	PORT_CONTROL &= ~(0x01 << E_PIN);
	_delay_ms(1);
}

//출력할 문자를 전송
void LCD_write_data(char data)
{
	
	PORT_CONTROL |= (0x01 << RS_PIN);
	PORT_DATA = data;
	LCD_pulse_enable();
	_delay_ms(2);
}


//명령어 전송
void LCD_write_command(char command)
{
	PORT_CONTROL &= ~(0x01 << RS_PIN);
	PORT_DATA = command;
	LCD_pulse_enable();
	_delay_ms(2);
}

//LCD 모두 지우기
void LCD_clear(void)
{
	LCD_write_command(COMMAND_CLEAR_DISPLAY);
	_delay_ms(2);
}

//LCD 초기화
void LCD_init(void)
{
	_delay_ms(50);
	
	DDR_DATA = 0xff; //출력핀
	PORT_DATA = 0x00; //포트 초기화
	DDR_CONTROL |= (0x01 << RS_PIN)|(0x01 << RW_PIN)|(0x01 << E_PIN); //0b00000111
	
	PORT_CONTROL &= ~(0x01 << RW_PIN);
	LCD_write_command(COMMAND_8_BIT_MODE);
	
	char command = 0x08 | (0x01<<COMMAND_DISPLAY_ON_OFF_BIT);
	LCD_write_command(command);
	
	LCD_clear();
	
	LCD_write_command(0x06);
}

//문자열 출력
void LCD_write_string(char *string)
{
	int i;
	for(i=0;string[i];i++)
	LCD_write_data(string[i]);
}

// 커서 이동
void LCD_goto_XY(int row, int col)
{
	col %= 16;
	row %= 2;
	
	char address = (0x40*row) + col;  //커서 위치계산
	char command = 0x80 + address;    //(0x80)커서를 address로 이동시키는 명령
	
	LCD_write_command(command);
}

#define LCD_SETCGRAMMADDR  0x40

char Hn[8] = {0b00000010, 0b00000111, 0b00000010, 0b00000101, 0b00000010, 0b00000000,  0b00000010, 0b00000011};
char an[8] = {0b00010000, 0b00010000, 0b00011000, 0b00010000, 0b00010000, 0b00000000,  0b00000000, 0b00010000};
char Ka[8] = {0b00000000, 0b00000010, 0b00111010, 0b00001011, 0b00001010, 0b00001010, 0b00000010,0b00000000};
char Hee[8] = {0b00001000, 0b00011101, 0b00001001
, 0b00010101, 0b00001001, 0b00000001, 0b00011101,0b00000001};

char MODE = 4;

int main(void)
{
	LCD_init();
	LCD_write_command(LCD_SETCGRAMMADDR);
	for(int i=0; i<8; i++)
		LCD_write_data(Hn[i]);
	
	for(int j=0; j<8; j++)
		LCD_write_data(an[j]);
	
	for(int k=0; k<8; k++)
		LCD_write_data(Ka[k]);
	
	for(int z=0; z<8; z++)
		LCD_write_data(Hee[z]);
	LCD_init();
	LCD_write_data(0);
	LCD_write_data(1);
	LCD_write_data(2);
	LCD_write_data(3);
	
	return 0;
}