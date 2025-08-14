#ifndef PORT_H
#define PORT_H
   
#include"Port_Register.h"

typedef enum
{
	PORT_ANALOG = 0,
	PORT_GPIO   = 1,
	PORT_ALT2   = 2,
	PORT_ALT3,
	PORT_ALT4,
	PORT_ALT5,
	PORT_ALT6,
	PORT_ALT7
}PORT_MUX_Type;

typedef enum
{
	INTERRUPT_STATUS_FLAF_DISABLE = 0,
	ISF_flag_DMA_rising_edge = 1,
	ISF_flag_DMA_falling_edge = 2 ,
	ISF_flag_DMA_either_edge = 3,
	ISF_flag_Interrup_low = 8,
	ISF_flag_Interrup_rising_edge = 9,
	ISF_flag_Interrup_falling_edge = 10,
	ISF_flag_Interrup_either_edge = 11,
	ISF_flag_Interrup_high = 12
}PORT_IRQC_Type;


#define PULL_DOWN 0
#define PULL_UP 1
#define DISABLE_PULL 2

void Port_Pin_Configure(PORT_Type *Portx, PORT_MUX_Type Muxn, unsigned char NumberPin);
void Port_Pin_Input_Configure(PORT_Type *Portx, unsigned char  PULL_x, unsigned char NumberPin);
void Port_Pin_Interrupt_Configure(PORT_Type *Portx,	PORT_IRQC_Type IRQCn, unsigned char NumberPin);
void Port_Pin_ISF_Clear(PORT_Type *Portx, unsigned char NumberPin);
unsigned int Port_Pin_ISF_Get(PORT_Type *Portx, unsigned char NumberPin);
#endif