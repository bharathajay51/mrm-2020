/*
 * ADC(NEW DUAL  INTERRUPT FINAL).c
 *
 * Created: 16-01-2019 19:30:52
 * Author : TIDU
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>

int bitval;
int joyval;
int Tenbit;
int lv;


int main(void)
{ 
	
	TCCR0 |= (1<<WGM01) |(1<<WGM00) | (1<<COM01) | (1<<CS00); //setting PWM for pin3 port B
	TCCR2 |= (1<<WGM21) |(1<<WGM20) | (1<<COM21) | (1<<CS20);
	DDRB |= (1<<PINB3);
	DDRD |= (1<<PIND7);
	ADMUX |= (1<<REFS0)|(1<<ADLAR); // taking input voltage as reference & doing right shift to the result
	ADCSRA |= 1<<ADPS2; // prescaller set to 16
	ADCSRA |= 1<<ADEN;
	ADCSRA |= 1<<ADIE;
	ADCSRA|=1<<ADATE;
	sei();
	
	ADCSRA |= 1<<ADSC;
	while (4)
	{
	}
		
}

ISR(ADC_vect)
{  
	 bitval=ADCH;
	 lv=ADCL;
	 Tenbit=(ADCH<<6|lv>>2);
	 joyval=(ADCH-128);
	 if(abs(joyval)<=25)
	 {
		 joyval=0;
	 }
	 
		
	switch(ADMUX)
	{
		case 0x60:
		{
		OCR0=abs(joyval);
		ADMUX=0x61;
		break;	
		}
		
		case 0x61:
		{
			OCR2=abs(joyval);
			ADMUX=0x60;
			break;
		}
		
	}
	ADCSRA|=1<<ADSC;
	
}
