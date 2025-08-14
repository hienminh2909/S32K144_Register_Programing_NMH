#define SCG_BASE 0x40064000

int main(){
   volatile unsigned int *SCG_SOSCDIV = ( volatile unsigned int*)(SCG_BASE+ 0x104);
	 *SCG_SOSCDIV |= ((2U<<8U) | 4U); 
	 
	 volatile unsigned int *SCG_SOSCCFG = ( volatile unsigned int*)(SCG_BASE+ 0x108);
	 *SCG_SOSCCFG |=  ((1U<<2)|(1U<<3));
	 
	 volatile unsigned int *SCG_SOSCSR = ( volatile unsigned int*)(SCG_BASE+ 0x100);
	 *SCG_SOSCSR &= ~(1U<<23);
	 *SCG_SOSCSR |= 1U;
	 
	
	while(1)
	 {
		 
		 
	 }

}
