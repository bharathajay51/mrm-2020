//*************SET joystix X at channel 1 and Y at channel 2;     codes X at reads from channel 2 and Y at channel 1;
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
	int X;
	int Y;
	uint16_t bitval;
	int joyval;
	uint16_t Tenbit;
	uint8_t lv;
	uint8_t joyval1;
	uint8_t joyval2;

int main(void)

{
	DDRB|= (1<<PINB3);
	DDRD|=(1<<PIND7);
	DDRB|=(1<<PINB0);
	DDRB|=(1<<PINB1);
	   TCCR0 |= 1<<WGM00 | 1<<WGM01 | 1<<COM01 | 1<<CS00;
	TCCR2|=1<<WGM20| 1<<WGM21| 1<<COM21| 1<<CS20;

	
	/* Replace with your application code */
	while (1)
	{
		ADC_initialise();
		
		X=(ADC_channel(2));
		
		
		//_delay_ms(2);
		
		ADC_initialise();
		 Y=(ADC_channel(1));
		 
		 drive(X,Y);
			
	}
	}



void ADC_initialise(void)
{
	ADMUX=(1<<REFS0)|(1<<ADLAR);
	ADCSRA=(1<<ADEN)|(1<<ADPS2);
	//MCUCR=(1<<SM0);
	
}

int ADC_channel(int channel)
{
	channel &= 0b00000111;
	ADMUX|=channel;
	ADCSRA|=(1<<ADSC);
	while((ADCSRA & (1<<ADSC)))
	
	//_delay_ms (10);
	ADCSRA|=(1<<ADIF);
	 lv=ADCL;
	Tenbit=ADCH<<6|lv>>2;
	
		 joyval	=(ADCH-128);
	return(joyval);
}


int drive(int X,int Y)
{
	
	if(abs(X)<=30)
	{
		X=0;
	}
	if(abs(Y)<=30)
	{
		Y=0;
	}
	
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
			PORTB=(0<<PINB0)|(0<<PINB1);
		}
	}
	
	if (X <= 0 && Y >= 0) // Second Quad
	{
		int level = X + Y;
		if (level == 0)
		{   
			OCR2=abs(Y);
			OCR0=0;
			PORTB=(0<<PINB0)|(0<<PINB1);
		}
		if (level > 0)
		{
			OCR0=abs(level);
			OCR2=abs(Y);
			PORTB=(0<<PINB0)|(0<<PINB1);

		}
		if (level < 0)
		{
			OCR0=abs(level);
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
	return 0;
}

