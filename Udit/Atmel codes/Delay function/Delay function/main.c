/*
 * Delay function.c
 *
 * Created: 17-01-2019 15:49:57
 * Author : TIDU
 */ 
#define F_CPU 1000000L
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{   DDRB|=(1<<PINB3);
	PORTB&=~(1<<PINB3);
	
 
    while (1) 
    {
		PORTB^=(1<<PINB3);
		T_delay_ms(1000);
}
}
void T_delay_ms(int k)
{
	long double t=k*5.8;
	long double i=0;
	while(i<t)
	{
		i++;
	}
}

