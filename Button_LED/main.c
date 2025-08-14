#include "Gpio.h"
#include "Pcc_Registers.h"
#include "Port_Register.h"
#include "Gpio_Register.h"



int main()
{
	// Button PORTC PIN12
	PCC_PORT->C |= (1U<<30U);
	PORTC->PCR12 |= ((1U<<8U) | (2U));
	PORTC->PCR12 &= ~(1U);
	//GPIOC->PDDR  &= ~(1U<<12U);
	Gpio_ConfigType ButtonPin = {
		.base = GPIOC,
		.GPIO_PinMode = INPUT,
		.GPIO_PinNumber = 12
	};
	
	//unsigned int tmp = 0; 
	
	// LED PORTD PIN16
	PCC_PORT->D |= (1U<<30U);
	PORTD->PCR16 |= (1U<<8U);	
	//GPIOD->PDDR |= (1U<<16U);
	Gpio_ConfigType LedPin = {
	   .base = GPIOD,	
		 .GPIO_PinMode = OUTPUT,
		.GPIO_PinNumber = 16
	};
	
	Gpio_Init(&ButtonPin);
	Gpio_Init(&LedPin);
	
	//unsigned int state = 0; 
	while(1)
	{
		//tmp = GPIOC->PDIR; // doc gia tri thanh ghi 
		//state = ((tmp >> 12) & 1);// doc gia tri bit 12
		if(GPIO_ReadFromInputPin(GPIOC,12) == 1){
			for(unsigned int i =0; i<4000000;i++); //Delay
			
			if(GPIO_ReadFromInputPin(GPIOC,12) == 1){
				// dao trang thai led
			   GPIOD->PDOR ^= (1U<<16U);
			}
			while(GPIO_ReadFromInputPin(GPIOC,12) == 1);
			for(unsigned int i =0; i<4000000;i++); //Delay
		}
		
		
		
	}

}
