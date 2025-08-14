#include"Pcc.h"

void Port_Clock(PCC_PortName Portx, unsigned char state)
{
	 volatile unsigned int *Pcc_Reg = (volatile unsigned int*)(PCC_BASE + Portx);
	 if(state == DISABLE_CLK)
	 {
		   *Pcc_Reg &= ~(PCC_CLK_ENABLE_MASK);
	 }
	 else if(state == ENABLE_CLK)
	 {
		   *Pcc_Reg |= (PCC_CLK_ENABLE_MASK);
	 }
	 else return;
	
}