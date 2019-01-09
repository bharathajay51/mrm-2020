/*
 * MotorCode.c
 *
 * Created: 09-01-2019 23:36:44
 * Author : TIDU
 */ 
#define F_CPU 1000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
int joylevel1;
int joylevel2;


uint16_t Ten_bit_val;



int main(void)
{
    DDRB|= (1<<PINB3);
	DDRD|=(1<<PIND7);
	DDRB|=(1<<PINB0);
	DDRB|=(1<<PINB1);
	
	TCCR0|= (1<<WGM00)| (1<<WGM01)|(1<<COM01)|(1<<CS00) ; // PWM setting for pinb3, timer 0 
	TCCR2|= (1<<WGM20)|(1<<WGM21) | (1<<COM21)| (1<<CS20) ; // PWM setting for pind7 timer 
//*************************setting up ADC*********************************	
	void ADCsetup()
	{
		ADCSRA|=(1<<ADPS2)| (0<<ADPS1) | (0<<ADPS0);
	    ADMUX|=(1<<ADLAR)|(1<<REFS0);
	    ADCSRA|=(1<<ADIE)|(1<<ADEN);
	    sei();
	    ADCSRA|= (1<<ADSC);
		
	}
	
    while (1) 
    {    
		ADCsetup(); // for joylevel1
		ADCsetup();//  for joylevel2 
		
		  // start ADC
	//**********************getting input from joystick************
		
		int X=(joylevel1-512)/2;
		int Y=(joylevel2-512)/2;
		if (X < 10 && X > -10)
		{
			X = 0;
		}
		if (Y < 10 && Y > -10)
		{
			Y = 0;
		}
//*******************starting mapping*************************

		  if (X >= 0 && Y >= 0)          // First quadrant
		  {
			  int level = X - Y;
			  if (level == 0)
			  {
				  OCR0=abs(X);
				  OCR2=0;
				  PORTB=(0<<PINB0)|(0<<PINB1);		
				  	  
			   }
			  if (level > 0)
			  {
				 
				 OCR0=abs(X);
				 OCR2=abs(X-Y);
				 PORTB=(0<<PINB0)|(1<<PINB1);
				 
			  }
			  if (level < 0)
			  {
				 OCR0=abs(Y);
				 OCR2=abs(X-Y);
				 PORTB=(0<<PINB0)|(1<<PINB1);
			  }
		  }
		  
		if (X <= 0 && Y >= 0) // Second Quad
		{
			int level = X + Y;
			if (level == 0)
			{ 
				OCR0=abs(0);
				OCR2=abs(Y);
				PORTB=(0<<PINB0)|(0<<PINB1);
			}
			if (level > 0)
			{
				OCR0=abs(Y+X);
				OCR2=abs(Y);
				PORTB=(0<<PINB0)|(0<<PINB1);

			}
			if (level < 0)
			{
					OCR0=abs(Y+X);
					OCR2=abs(X);
					PORTB=(1<<PINB0)|(0<<PINB1);
			}
		}
		
			
		if (X >= 0 && Y <= 0) // Fourth quad
		{
			int level = X + Y;
			if (level == 0)
			{ 
				OCR0=abs(0);
				OCR2=abs(Y);
				PORTB=(0<<PINB0)|(1<<PINB1);
			}
			if (level > 0)
			{
			   OCR0=abs(X+Y);
			   OCR2=abs(X);
			   PORTB=(0<<PINB0)|(1<<PINB1);

			}
			if (level < 0)
			{
				OCR0=abs(X+Y);
				OCR2=abs(Y);
				PORTB=(1<<PINB0)|(1<<PINB1);
			}
		}  
		
		
		if (X <= 0 && Y <=0) // Third quad
			{
				int level = X - Y;
				if (level == 0)
				{ 
					OCR0=abs(X);
					OCR2=abs(0);
					PORTB=(1<<PINB0)|(0<<PINB1);
				}
				if (level > 0)
				{
					
					OCR0=abs(Y);
					OCR2=abs(X-Y);
					PORTB=(1<<PINB0)|(1<<PINB1);
				}
				if (level < 0)
				{  
					OCR0=abs(X);
					OCR2=abs(X-Y);
					PORTB=(1<<PINB0)|(0<<PINB1);
					
				}
			}
		
		
		
		
    }
}


ISR(ADC_vect)
{   uint8_t  LOWval = ADCL;
	Ten_bit_val=(ADCH<<8)|(LOWval);
	
	switch(ADMUX)
	{
	 case 0xC0:
		  {
			   joylevel1=Ten_bit_val;
			   ADMUX=0xC1;
			   break;
		  }
	 case 0xC1:
	      {
			   joylevel2=Ten_bit_val;
			   ADMUX=0XC0;
			   break;
		  }
	}
	ADCSRA|= (1<<ADSC);
}



