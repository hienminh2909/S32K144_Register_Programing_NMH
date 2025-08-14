#include<stdint.h>


#define SCG_FIRCDIV      (*(volatile uint32_t*)(0x40064000+0x304))
#define SCG_FIRCCSR      (*(volatile uint32_t*)0x40064010)
	
#define PCC_BASE            0x40065000
#define PCC_PORTC           (*(volatile uint32_t *)(PCC_BASE + 0x12C))
#define PCC_LPUART1         (*(volatile uint32_t *)(PCC_BASE + 0x1AC))

#define PCC_CGC_MASK        (1u << 30u)
#define PCC_PCS_FIRCDIV2    (3u << 24u)  // Chon FIRCDIV2 l�m clock source

#define PORTC_BASE      0x4004B000
#define PORTC_PCR6      (*(volatile uint32_t *)(PORTC_BASE + 0x18))
#define PORTC_PCR7      (*(volatile uint32_t *)(PORTC_BASE + 0x1C))

#define LPUART1_BASE        0x4006B000
#define LPUART1_BAUD        (*(volatile uint32_t *)(LPUART1_BASE + 0x10))
#define LPUART1_CTRL        (*(volatile uint32_t *)(LPUART1_BASE + 0x18))
#define LPUART1_STAT        (*(volatile uint32_t *)(LPUART1_BASE + 0x14))
#define LPUART1_DATA        (*(volatile uint32_t *)(LPUART1_BASE + 0x1C))

int main(){   

    // Chn he so chia FIRCDIV2 = divide by 1 (48 MHz)
    SCG_FIRCDIV |=  (2 << 8);
	  //SCG_FIRCCSR &= ~(1u<<23u);
	  
    PCC_PORTC |= PCC_CGC_MASK;        // Enable clock cho PORTC (d�ng PC6, PC7)
    
    // Disable truoc khi chon clock
    PCC_LPUART1 &= ~PCC_CGC_MASK;
    PCC_LPUART1 |= (PCC_PCS_FIRCDIV2 | PCC_CGC_MASK);
	
	  PORTC_PCR6 = 0x00000200; // ALT2 cho LPUART1_TX
    PORTC_PCR7 = 0x00000200; // ALT2 cho LPUART1_RX
	  
	  LPUART1_CTRL &= ~((1U << 18U) | (1U << 19U));  // Enable TX (TE) v� RX (RE) // Disable TX, RX

    // Baudrate = 9600; Clock = 24MHz (FIRC DIV2)
    // SBR = 24000000 / (16 * 9600) = 156.25 ~ 156
    LPUART1_BAUD |= (15<<24) | 156;

    LPUART1_CTRL |= (1 << 18) | (1 << 19);  // Enable TX (TE) v� RX (RE)
	
	  while(1)
		{
			  while ((LPUART1_STAT & (1 << 23)) == 0);			// Wait for TDRE = 1
        LPUART1_DATA = 'A';
			
		}
}


