/*
 * ADC with polling.c
 *
 * Created: 16-01-2019 08:50:32
 * Author : TIDU
 */ 

#define F_CPU 1000000L
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>

int main(void)
{   TCCR0 |= 1<<WGM00 | 1<<WGM01 | 1<<COM01 | 1<<CS00;
	DDRB |= 1<<PINB3;
	
    /* Replace with your application code */
    while (1) 
    {
		ADC_initialise();
		OCR0=ADC_channel(5);	
    }
}

void ADC_initialise(void)
{
	ADMUX|=(1<<REFS0)|(1<<ADLAR);
	ADCSRA|=(1<<ADEN)|(1<<ADPS2);
	
}

int ADC_channel(int channel)
{
	channel=channel & 0b00000111;
	ADMUX|=channel;
	ADCSRA|=(1<<ADSC);
	while((ADCSRA & (1<<ADSC))==0)
	{}
    _delay_ms (10);
	ADCSRA|=(1<<ADIF);
	return(ADCL);
}+