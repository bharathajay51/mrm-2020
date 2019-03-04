






/*
 * PWMFinal.c
 *
 * Created: 04-11-2018 12:41:44
 * Author : TIDU
 */ 

#define  F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    TCCR0|= (1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00) ;// WG00:1 is set to fast PWM mode, COM01 is set to non-inverted PWM mode, CS00 is set to no prescalling
	DDRB|=1<<PINB3; // OCR0( Output Compare Register for timer 0) is linked to Pin 3 of port b.
	int i; 
	
     while (1) 
    {
	for(i=0; i<=255; i++)
	{ 
		OCR0=i;
		_delay_ms(10);
    }
	_delay_ms(500);
	for(i=255; i>=0; i--)
	{
		OCR0=i;
		_delay_ms(10);
	}	
	_delay_ms(500);
   
	}
}




