#define SCG_BASE 0x40064000
#define SMC_BASE 0x4007E000
#define SIM_BASE 0x40048000
int main()
{
   volatile unsigned int* SCG_RCCR = (volatile unsigned int*) (SCG_BASE + 0x14);
	// FIRC clock source 
   *SCG_RCCR |= (3U<<24U);
   *SCG_RCCR &= ~(12U<<24);	
	
	volatile unsigned int* SCG_HCCR = (volatile unsigned int*) (SCG_BASE + 0x1C);
	// FIRC clock source 
	*SCG_HCCR |= (3U<<24U);
  *SCG_HCCR &= ~(12U<<24); 
	
	volatile unsigned int* SMC_PMPROT = (volatile unsigned int*) (SMC_BASE + 0x8);
	//Allow HSRUN
  *SMC_PMPROT |= (1U<<7U);
	
	volatile unsigned int* SMC_PMCTR = (volatile unsigned int*) (SMC_BASE + 0xC);
	// HSRUN Mode
  *SMC_PMCTR |= (3U<<5U);
	
	//Chuyen FIRC -> SPLL clock source: 0110 =112Mhz
	*SCG_HCCR |= (6U<<24); //set bit 1,2
	*SCG_HCCR &= ~(9U<<24);// clear bit 0,3
	
	// DIVCORE =2 = 0001
	*SCG_HCCR |= (1U<<16U);
	*SCG_HCCR &= ~(14U<<16U);
	// DIVBUS = 2 = 0001
	*SCG_HCCR &= ~(15U<<4U); //Reset tat ca cac bit
	*SCG_HCCR |= (1U<<4U);// set bit 0 len 1
	// DIVSLOW = 4 = 0011
	*SCG_HCCR &= ~(15U); //Reset tat ca cac bit
	*SCG_HCCR |= (3U);// set bit 0,1 len 1
	
	 volatile unsigned int* SCG_SPLLCSR = (volatile unsigned int*) (SCG_BASE + 0x600);
	*SCG_SPLLCSR &= ~(1U); // disable SPLL
	
	volatile unsigned int* SCG_SPLLCFG = (volatile unsigned int*) (SCG_BASE + 0x608);
	*SCG_SPLLCFG |= 1U ; // FIRC(48Mhz) input SPLL =0;
	*SCG_SPLLCFG |= (4U<<8U); //PREDIV = 5+1 (0b100); 
	*SCG_SPLLCFG &= ~(3U<<8U); //PREDIV = 5+1 (0b100);
	*SCG_SPLLCFG |= (24U<<16U); //MULT = 40+16 (0b11000); 
	*SCG_SPLLCFG &= ~(7U<<16U); //MULT = 40+16 (0b11100); =>  VCO_CLK = FIRC(48Mhz)/(5+1) * (40+16) =448Mhz
	                                                     //=> SPLL_CLK = VCO/2 = 448/2 =224;
	
	*SCG_SPLLCSR &= ~(1U<<23U); //unlock CSR SPLL
	*SCG_SPLLCSR |= (1U); // enable SPLL
	
	volatile unsigned int *PCC_PORTB =(volatile unsigned int*)(0x40065000u + 0x128);
	 *PCC_PORTB |= (1<<30);
	
	volatile unsigned int* PORTB_PCR5 = (volatile unsigned int*)(0x4004A000+0x14);
	*PORTB_PCR5 &= ~(2U<<8U);
	*PORTB_PCR5 |= (5U<<8U);
	 volatile unsigned int* SCG_SPLLDIV = (volatile unsigned int*)(SCG_BASE+0x604);
	 *SCG_SPLLDIV |= (5U<<8U);
	 *SCG_SPLLDIV &= ~(2U<<8U);
	 
   volatile unsigned int* SIM_CHIPCTL = (volatile unsigned int*)(SIM_BASE+0x4);
   *SIM_CHIPCTL |= (8U<<4U);  // SPLL_DIV2_CLK
	 *SIM_CHIPCTL &= ~(7U<<4U);
	 
	 *SIM_CHIPCTL |= (6U<<8U); // CLK_DIV7
	 *SIM_CHIPCTL &= ~(1U<<8U);
	 
	 *SIM_CHIPCTL |= (1U<<11U); // Enable CLK_OUT
}
