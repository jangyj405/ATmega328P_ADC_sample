#include <avr/io.h>

void init_ADC(unsigned char channel,unsigned char ref, unsigned char adps){
	ADMUX |= ref << REFS0;
	
	ADCSRA |= adps;
	ADCSRA |= 1 << ADEN;
	ADCSRA |= 1 << ADATE;
	
	ADMUX = (ADMUX & 0xE0) | channel;
	ADCSRA |= 1 << ADSC;
}

int read_ADC(void){
	while(!(ADCSRA & (0x01 << ADIF)));
	return ADC;
}
