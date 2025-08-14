#define SCG_BASE 0x40064000

int main(){
	volatile unsigned int* SCG_SPLLCSR = (volatile unsigned int*)(SCG_BASE + 0x600);
	*SCG_SPLLCSR &= ~(1U);
	
	volatile unsigned int* SCG_SPLLDIV = (volatile unsigned int*)(SCG_BASE + 0x604);
	*SCG_SPLLDIV |= ((5U<<8U)|(2U));
	
	volatile unsigned int* SCG_SPLLCFG = (volatile unsigned int*)(SCG_BASE + 0x608);
	*SCG_SPLLCFG |= (4U<<8U);
	*SCG_SPLLCFG |=  (8U<<16U);
	*SCG_SPLLCFG |= (1U);
	
	*SCG_SPLLCSR &= ~(1U<<23U);
	
	*SCG_SPLLCSR |= (1U);
	
}
