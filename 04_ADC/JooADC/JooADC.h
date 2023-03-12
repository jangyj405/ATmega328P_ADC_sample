
#ifndef JOOADC_H_
#define JOOADC_H_

enum Reference{
	AREF = 0,
	AVCC = 1,
	INTV = 3	
};

void init_ADC(unsigned char channel,unsigned char ref, unsigned char adps);
int read_ADC(void);

#endif /* JOOADC_H_ */
