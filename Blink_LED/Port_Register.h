#ifndef PORT_REGISTER_H
#define PORT_REGISTER_H

#define PORTA_BASE 0x40049000
#define PORTB_BASE 0x4004A000
#define PORTC_BASE 0x4004B000
#define PORTD_BASE 0x4004C000
#define PORTE_BASE 0x4004D000

typedef struct{
   volatile unsigned int PCR0;
	 volatile unsigned int PCR1;
	 volatile unsigned int PCR2;
	 volatile unsigned int PCR3;
	 volatile unsigned int PCR4;
	 volatile unsigned int PCR5;
	 volatile unsigned int PCR6;
	 volatile unsigned int PCR7;
	 volatile unsigned int PCR8;
	 volatile unsigned int PCR9;
	 volatile unsigned int PCR10;
	 volatile unsigned int PCR11;
	 volatile unsigned int PCR12;
	 volatile unsigned int PCR13;
	 volatile unsigned int PCR14;
	 volatile unsigned int PCR15;
	 volatile unsigned int PCR16;
	 volatile unsigned int PCR17;
	 volatile unsigned int PCR18;
	 volatile unsigned int PCR19;
	 volatile unsigned int PCR20;
	 volatile unsigned int PCR21;
	 volatile unsigned int PCR22;
	 volatile unsigned int PCR23;
	 volatile unsigned int PCR24;
	 volatile unsigned int PCR25;
	 volatile unsigned int PCR26;
	 volatile unsigned int PCR27;
	 volatile unsigned int PCR28;
	 volatile unsigned int PCR29;
	 volatile unsigned int PCR30;
	 volatile unsigned int PCR31;
	 volatile unsigned int GPCLR;
	 volatile unsigned int GPCHR;
} PORT_Type;

#define PORTA ((PORT_Type *)PORTA_BASE)
#define PORTB ((PORT_Type *)PORTB_BASE)
#define PORTC ((PORT_Type *)PORTC_BASE)
#define PORTD ((PORT_Type *)PORTD_BASE)
#define PORTE ((PORT_Type *)PORTE_BASE)

#endif
