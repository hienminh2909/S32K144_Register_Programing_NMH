#ifndef PORT_REGISTER_H
#define PORT_REGISTER_H

#define PORTA_BASE 0x40049000
#define PORTB_BASE 0x4004A000
#define PORTC_BASE 0x4004B000
#define PORTD_BASE 0x4004C000
#define PORTE_BASE 0x4004D000

typedef struct{
   volatile unsigned int PCR[32];
	 volatile unsigned int GPCLR;
	 volatile unsigned int GPCHR;
	 volatile unsigned int GICLR;
	 volatile unsigned int GICHR;
	 volatile unsigned int ISFR;
	 volatile unsigned int DFER;
	 volatile unsigned int DFCR;
	 volatile unsigned int DFWR;
} PORT_Type;

#define PORTA ((PORT_Type *)PORTA_BASE)
#define PORTB ((PORT_Type *)PORTB_BASE)
#define PORTC ((PORT_Type *)PORTC_BASE)
#define PORTD ((PORT_Type *)PORTD_BASE)
#define PORTE ((PORT_Type *)PORTE_BASE)

#endif
