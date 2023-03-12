#define F_CPU 16000000L
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "JooUART/JooUART.h"
#include "JooADC/JooADC.h"




/*
int main(void)
{
	int read = 0;
	char buffer[5] = {0};
		
	init_uart(9600, F_CPU, 0x01, DL8, NONE, ONE);
	init_ADC(0, AVCC, 0b0111);
	
    while (1) 
    {
		read = read_ADC();
		sprintf(buffer, "%04d", read);
		buffer[4] = '\0';
		uart_transmit_print_line(buffer);
		_delay_ms(1000);
		
    }
    return 0;
}

*/

int main(void)
{
	int read = 0;
	unsigned char adch;
	unsigned char on_off_pattern;
	DDRD = 0xFF;
	PORTD = 0x00;
	init_ADC(0, AVCC, 0b0111);
	
	while (1)
	{
		read = read_ADC();
		adch = read >> 7;
		on_off_pattern = 0;
		for(int i = 0; i<= adch; i++)
		{
			on_off_pattern |= 0x01 << i;
		}
		PORTD = on_off_pattern;
	}
	return 0;
}