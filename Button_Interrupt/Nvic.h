#ifndef NVIC_H
#define NVIC_H

#include"Nvic_Registers.h"

typedef enum{
 PORTA_IRQn = 59,
 PORTB_IRQn = 60,
 PORTC_IRQn = 61,
 PORTD_IRQn = 62,
 PORTE_IRQn = 63
}IRQn_Type;

 

void NVIC_IRQ_Enable(IRQn_Type IRQn);
void NVIC_IRQ_Disable(IRQn_Type IRQn);
void NVIC_IRQ_SetPending(IRQn_Type IRQn);
void NVIC_IRQ_ClearPending(IRQn_Type IRQn);
unsigned int NVIC_IRQ_GetPending(IRQn_Type IRQn);
void NVIC_IRQ_SetPriority(IRQn_Type IRQn, unsigned int priority);
unsigned int NVIC_IRQ_GetPriority(IRQn_Type IRQn);
unsigned int NVIC_IRQ_GetActive(IRQn_Type IRQn);
#endif
