#include "Gpio_Register.h"
#include "Gpio.h"
#include "Port_Register.h"
#include "Pcc_Registers.h"

int main()
{
	
	PCC_PORT->D |= (1U<<30U);

	PORTD->PCR16 |= (1U<<8U);
	
  /*
	GPIOD->PDDR |= (1U<<16U);
	GPIOD->PDOR |= (1U<<16U);
	*/
	Gpio_ConfigType LedPin = {
		.base = GPIOD,
		.GPIO_PinNumber = 16,
		.GPIO_PinMode = OUTPUT
		
	};
	
	Gpio_Init(&LedPin);
	Gpio_SetOutputPin(GPIOD,16);
	
	while(1)
	{
		
		for(int i = 0; i < 600000; i++);
		
		//GPIOD->PDOR ^=(1U<<16U);
		Gpio_ToggleOutputPin(GPIOD,16);
		
	}

}



