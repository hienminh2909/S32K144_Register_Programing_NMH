#include"Port.h"

void Port_Pin_Configure(PORT_Type *Portx, PORT_MUX_Type Muxn, unsigned char NumberPin)
{
	  Portx->PCR[NumberPin] &= ~(0x3U<<8U);  //clear Mux
	  Portx->PCR[NumberPin] |=  ((unsigned int)Muxn<<8U);
}

void Port_Pin_Input_Configure(PORT_Type *Portx, unsigned char  PULL_x, unsigned char NumberPin)
{
	if(PULL_x == DISABLE_PULL)
	{
	  Portx->PCR[NumberPin] &= (~2U);	
	}
	else if(PULL_x == PULL_DOWN)
	{
		 Portx->PCR[NumberPin] |= (1U<1U);
		 Portx->PCR[NumberPin] &= (~1U);	
	}
	else if(PULL_x == PULL_UP)
	{
		 Portx->PCR[NumberPin] |= (1U<1U);
		 Portx->PCR[NumberPin] |= (1U);
	}
	else
	{
		return;
	}
}

void Port_Pin_Interrupt_Configure(PORT_Type *Portx,	PORT_IRQC_Type IRQCn, unsigned char NumberPin)
{
	   Portx->PCR[NumberPin] &= ~(0xFU << 16U);   //clear 4 bit
	   Portx->PCR[NumberPin] |= ((unsigned int)IRQCn << 16U);
	  
}


void Port_Pin_ISF_Clear(PORT_Type *Portx, unsigned char NumberPin)
{ 
	   Portx->PCR[NumberPin] |= (1U<<24U);
}

unsigned int Port_Pin_ISF_Get(PORT_Type *Portx, unsigned char NumberPin)
{
	  unsigned int state = ((Portx->PCR[NumberPin]>>24U) & 1U);
	  return state;
	
}
