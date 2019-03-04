/*
 * USART.cpp
 *
 * Created: 05-01-2019 00:50:47
 * Author : AYUSH
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
uint16_t a;
uint8_t l;
int  adc_0(void)
{
	ADMUX &=~(1<<MUX2)&~(1<<MUX1)&~(1<<MUX0)&~(1<<MUX3);         //ADC0;
	ADCSRA  |=(1<<ADSC);
	while ((ADCSRA&(1<<ADSC))==0b01000000)
	{
	}
	l=ADCL;
	a=(ADCH<<2)|(l>>6);
	//a=ADCH;
	return a;
}


int adc_1(void)
{
	ADMUX|=(1<<MUX0);                                 // ADC1
	ADMUX&=~(1<<MUX4)&~(1<<MUX3)&~(1<<MUX2)&~(1<<MUX1);

	uint16_t a;
	ADCSRA  |=(1<<ADSC);
	while ((ADCSRA&(1<<ADSC))==0b01000000)
	{
	}
	a=(ADCH<<2)|(l>>6);
	return a;
}

int adc_2(void)
{ADMUX|=(1<<MUX1);                                 // ADC2
	ADMUX&=~(1<<MUX4)&~(1<<MUX3)&~(1<<MUX2)&~(1<<MUX0);


	uint16_t a;
	ADCSRA  |=(1<<ADSC);
	while ((ADCSRA&(1<<ADSC))==0b01000000)
	{
	}
	a=(ADCH<<2)|(l>>6);
	return a;
}

int adc_3(void)
{
	ADMUX|=(1<<MUX1)|(1<<MUX0);                       // ADC3
	ADMUX&=~(1<<MUX4)&~(1<<MUX3)&~(1<<MUX2);

	uint16_t a;
	ADCSRA  |=(1<<ADSC);
	while ((ADCSRA&(1<<ADSC))==0b01000000)
	{
	}
	a=(ADCH<<2)|(l>>6);
	return a;
}


int adc_4(void)
{
	ADMUX|=(1<<MUX2);                                 // ADC4
	ADMUX&=~(1<<MUX4)&~(1<<MUX3)&~(1<<MUX1)&~(1<<MUX0);

	uint16_t a;
	ADCSRA  |=(1<<ADSC);
	while ((ADCSRA&(1<<ADSC))==0b01000000)
	{
	}
	a=(ADCH<<2)|(l>>6);
	return a;
}


int adc_5(void)
{
	ADMUX|=(1<<MUX0)|(1<<MUX2);                       // ADC5
	ADMUX&=~(1<<MUX4)&~(1<<MUX3)&~(1<<MUX1);

	uint16_t a;
	ADCSRA  |=(1<<ADSC);
	while ((ADCSRA&(1<<ADSC))==0b01000000)
	{
	}
	a=(ADCH<<2)|(l>>6);
	return a;
}

int adc_6(void)
{

	ADMUX|=(1<<MUX1)|(1<<MUX2);                       // ADC6
	ADMUX&=~(1<<MUX4)&~(1<<MUX3)&~(1<<MUX0);
	uint16_t a;
	ADCSRA  |=(1<<ADSC);
	while ((ADCSRA&(1<<ADSC))==0b01000000)
	{
	}
	a=(ADCH<<2)|(l>>6);
	return a;
}

int adc_7(void)
{

	ADMUX |=(1<<MUX2)|(1<<MUX1)|(1<<MUX0);            //ADC7;
	ADMUX&=~(1<<MUX4)&~(1<<MUX3);
	uint16_t a;
	ADCSRA  |=(1<<ADSC);
	while ((ADCSRA&(1<<ADSC))==0b01000000)
	{
	}
	a=(ADCH<<2)|(l>>6);
	return a;
}
void adc_int(void)
{ADCSRA |=(1<<ADEN)|(1<<ADPS1)|(1<<ADPS0);   // initialize the adc
	ADMUX  |= (1<<REFS0)|(1<<ADLAR);

}
void usart_int(void)
{
}

void send(int o,char b)
{   int count=0;
	char abc;
	int n=0;
	int r;
	while(o>0)
	{r=o%10;
		n=n*10+r;
		o=o/10;
	}
	while (!(UCSRA&(1<<UDRE)));
	UDR= 'c';
	while (!(UCSRA&(1<<UDRE)));
	UDR= 'e';
	while (!(UCSRA&(1<<UDRE)));
	UDR= 'l';
	while (!(UCSRA&(1<<UDRE)));
	UDR= 'l';
	while (!(UCSRA&(1<<UDRE)));
	UDR= b;
	while (!(UCSRA&(1<<UDRE)));
	UDR= ':';
	
	
	
	
	while(n>0)
	{if (count==1)
		{while (!(UCSRA&(1<<UDRE)));
		UDR= '\t';}
		
		
		r=n%10;
		switch(r)
		{    case 0:abc='0';
			while (!(UCSRA&(1<<UDRE)));
			UDR= abc;
			break;
			case 1:abc='1';
			while (!(UCSRA&(1<<UDRE)));
			UDR= abc;
			break;
			case 2:abc='2';
			while (!(UCSRA&(1<<UDRE)));
			UDR= abc;
			break;
			case 3:abc='3';
			while (!(UCSRA&(1<<UDRE)));
			UDR= abc;
			break;
			case 4:abc='4';
			while (!(UCSRA&(1<<UDRE)));
			UDR= abc;
			break;
			case 5:abc='5';
			while (!(UCSRA&(1<<UDRE)));
			UDR= abc;
			break;
			case 6:abc='6';
			while (!(UCSRA&(1<<UDRE)));
			UDR= abc;
			break;
			case 7:abc='7';
			while (!(UCSRA&(1<<UDRE)));
			UDR= abc;
			break;
			case 8:abc='8';
			while (!(UCSRA&(1<<UDRE)));
			UDR= abc;
			break;
			case 9:abc='9';
			while (!(UCSRA&(1<<UDRE)));
			UDR= abc;
			break;
			
			
		}
		n=n/10;
	++count;	
	}
	
	
	
	while (!(UCSRA&(1<<UDRE)));
	UDR= '-';
	while (!(UCSRA&(1<<UDRE)));
	UDR= '-';
	
	if (b=='6')
	{while (!(UCSRA&(1<<UDRE)));
		UDR= '\n';
	}
}


int main(void)
{//8 BIT OF DATA , 1 STOP BITS,NO PARITY,baud =9600 // idle high // receiver and transmitter uses same setting // stop bit high / start high 
	// for interrupt driven only 
	// when doing the initialization global interrupts should be cleared 
	
	// initialization 
	//baud rate
	// frame format 
	// enable the transmission  
	// check txc is zero before transmission 
	// Ursel to 0 in ucsrc for ubrrh writing
	 // UCSRA WHEN WRITTEN write udre to 0
	
  float o;
    cli();
    UCSRC &=~(1<<URSEL);
    unsigned int  h = 0;
    UBRRH=(unsigned char)(h>>8);
    UBRRL=(unsigned char)h;
	
	//char abc;
    
    DDRA&=~(1<<PA1);
	PORTA|=(1<<PA1);
   
    
    UCSRC |=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
    UCSRB &=~(1<<UCSZ2);
    UCSRC &=~(1<<UMSEL)& ~(1<<UPM1)& ~(1<<UPM0)&~(1<<USBS);
    UCSRB |=(1<<TXEN);
    
    sei();
    adc_int();
    while (1) 
    {
		 o =adc_0();
	    o=(o/1023)*5;
		o=o*100;
		send(o,'1');
	 o =adc_1();
		 o=(o/1023)*5;
		 o=o*100;
		 send(o,'2');
		  o =adc_2();
		  o=(o/1023)*5;
		  o=o*100;
		  send(o,'3');
		   o =adc_3();
		   o=(o/1023)*5;
		   o=o*100;
		   send(o,'4');
		   o=(o/1023)*5;
		   o=o*100;
		    o =adc_4();
			o=(o/1023)*5;
			o=o*100;
		    send(o,'5');
			 o =adc_5();
			 o=(o/1023)*5;
			 o=o*100;
			 send(o,'6');
			 // o =adc_6();
			  //send(o,'7');
			  // o =adc_7();
			  //send(o,'8');
		
		
		//while (!(UCSRA&(1<<UDRE)));
		//UDR =(c>>8);
	    //PORTD^=(1<<PD7);
		

			
			
    }
}

