#define SCG_BASE 0x40064000

int main()
{
	volatile unsigned int* SCG_RCCR = (volatile unsigned int*)(SCG_BASE + 0x14);	
	//Chon Source Clock - SOSC : 0001
	*SCG_RCCR |= (1U<<24U); // set bit 1 
	*SCG_RCCR &= ~(7U<<25U);// clear bit 2,3,4
	
	
	*SCG_RCCR &= ~(15U<<16U); // Clock: chia 1:0000 -> clear 4bit
	
	*SCG_RCCR &= ~(15U<<4U);  // Bus: chia 2:0001 -> clear 4 bit trc
	*SCG_RCCR |= (1U<<4U);    // set bit 1
	
	*SCG_RCCR &= ~(15U);  // Flash: chia 4:0011 -> clear 4 bit trc
	*SCG_RCCR |= 3U;      // set bit 1,2
	
}
