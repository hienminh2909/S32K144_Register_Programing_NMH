#ifndef PCC_H
#define PCC_H

#include"Pcc_Registers.h"

typedef enum {
    PCC_PORTA = PCC_PORTA_OFFSET,
    PCC_PORTB = PCC_PORTB_OFFSET,
    PCC_PORTC = PCC_PORTC_OFFSET,
    PCC_PORTD = PCC_PORTD_OFFSET,
    PCC_PORTE = PCC_PORTE_OFFSET
} PCC_PortName;

#define DISABLE_CLK 0
#define ENABLE_CLK  1

void Port_Clock(PCC_PortName Portx, unsigned char state);



#endif