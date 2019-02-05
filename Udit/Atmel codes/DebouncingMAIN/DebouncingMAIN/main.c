/*
 * Debounce.c.c
 *
 * Created: 31-10-2018 15:15:20
 * Author : TIDU
 */ 

#define F_CPU 10000000UL 
#include <avr/io.h>
#include <util/delay.h>
int debounce(int last_state)
{
	int current_state=((PIND &(1<<PIND7))>>PIND7);
	if(current_state != last_state)
	{
		_delay_ms(5);
		current_state=(PIND &(1<<PIND7))>>PIND7;
	}
	return(current_state);
}

int main(void)
{  
   DDRB |=1<<PINB3;
   DDRD &= ~(1<<PIND7);
   PORTB|=(1<<PINB3);
   PORTD|= (1<<PIND7);
   int last_state= 1;
   int but_state;
    /* Replace with your application code */
    while (1) 
    {
		but_state=debounce(last_state);
		if(but_state==0 && last_state==1)
		{
			PORTB^=(1<< PINB3);
			
		}
		last_state=but_state;
    }
}
