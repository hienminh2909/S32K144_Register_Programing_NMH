#include"Nvic.h"


void NVIC_IRQ_Enable(IRQn_Type IRQn)
{
   	  unsigned int regs_Index = IRQn/32;
	    unsigned int bits_Index = IRQn%32;
	
	    NVIC_ISER->IQRn[regs_Index] = (1U<<bits_Index);
}

void NVIC_IRQ_Disable(IRQn_Type IRQn)
{
	   unsigned int regs_Index = IRQn/32;
	   unsigned int bits_Index = IRQn%32;
	
	   NVIC_ICER->IQRn[regs_Index] = (1U<<bits_Index);
}

void NVIC_IRQ_SetPending(IRQn_Type IRQn)
{
	   unsigned int regs_Index = IRQn/32;
	   unsigned int bits_Index = IRQn%32;
	   NVIC_ISPR->IQRn[regs_Index] = (1U<<bits_Index);
}

void NVIC_IRQ_ClearPending(IRQn_Type IRQn)
{
	   unsigned int regs_Index = IRQn/32;
	   unsigned int bits_Index = IRQn%32;
	   NVIC_ISPR->IQRn[regs_Index] &= ~(1U<<bits_Index);
}

unsigned int NVIC_IRQ_GetPending(IRQn_Type IRQn)
{
	 
	 unsigned int regs_Index = IRQn/32;
	 unsigned int bits_Index = IRQn%32;
	 unsigned int tmp        = (NVIC_ISPR->IQRn[regs_Index]);
	 unsigned int state      = (tmp>>bits_Index)&0x00000001U;
	 return state;
	 
}

void NVIC_IRQ_SetPriority(IRQn_Type IRQn, unsigned int priority)
{   
	 unsigned int regs_Index = IRQn/4;
	 unsigned int bits_Index = (IRQn%4)*8;
	 NVIC_IPR->PRIn[regs_Index] &= ~(255U<<bits_Index); // xoa 8bit ve 0  
	 NVIC_IPR->PRIn[regs_Index] |= (priority << bits_Index); // set priority
	 
}

unsigned int NVIC_IRQ_GetPriority(IRQn_Type IRQn)
{
	  unsigned int regs_Index = IRQn/4;
	  unsigned int bits_Index = (IRQn%4)*8;
	  unsigned int tmp        = (NVIC_IPR->PRIn[regs_Index]);
	  unsigned int state      = (tmp>>bits_Index)&0x00000001U;
	  return state;
	
}


unsigned int NVIC_IRQ_GetActive(IRQn_Type IRQn)
{
	  unsigned int regs_Index = IRQn/32;
	  unsigned int bits_Index = IRQn%32;
	  unsigned int tmp        = (NVIC_IABR->IQRn[regs_Index]);
	  unsigned int state      = (tmp>>bits_Index)&0x00000001U;
	  return state;
	
}
