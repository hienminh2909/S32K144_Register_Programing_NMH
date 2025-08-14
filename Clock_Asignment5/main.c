#define SCG_BASE 0x40064000

int main()
{
   volatile unsigned int* SCG_RCCR = (volatile unsigned int*) (SCG_BASE + 0x14);
	//	lua chon SPPL Source: 0110
	*SCG_RCCR |= (6U<<24U); //set bit 1,2
	*SCG_RCCR &= ~(9U<<24U); // reset bit 0,3
	// DIV CORE = 4;
	*SCG_RCCR &= ~(15U<<16U); // reset :0000
	*SCG_RCCR |= (3U<<16U); // set :0011
	// DIV BUS = 2;
	*SCG_RCCR &= ~(15U<<4U); // reset :0000
	*SCG_RCCR |= (1U<<4U); // reset :0001
	//DIV SLOW = 4;
		*SCG_RCCR &= ~(15U); // reset :0000
	*SCG_RCCR |= (3U); // set :0011
	
	 volatile unsigned int* SCG_SPLLCSR = (volatile unsigned int*) (SCG_BASE + 0x600);
	*SCG_SPLLCSR &= ~(1U); // disable SPLL
	
	 volatile unsigned int* SCG_SPLLCFG = (volatile unsigned int*) (SCG_BASE + 0x608);
	*SCG_SPLLCFG |= 1U ; // FIRC(48Mhz) input SPLL =0;
	*SCG_SPLLCFG |= (4U<<8U); //PREDIV = 5+1 (0b100); 
	*SCG_SPLLCFG &= (3U<<8U); //PREDIV = 5+1 (0b100);
	*SCG_SPLLCFG |= (8U<<16U); //MULT = 24+16 (0b01000); 
	*SCG_SPLLCFG &= ~(23U<<16U); //MULT = 24+16 (0b01000); =>  VCO_CLK = FIRC(48Mhz)/(5+1) * (24+16) =320Mhz
	                                                     //=> SPLL_CLK = VCO/2 = 320/2 =160;
	
	*SCG_SPLLCSR &= ~(1U<<23U); //unlock CSR SPLL
	*SCG_SPLLCSR |= (1U); // enable SPLL
	 
	
}
