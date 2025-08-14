#include"Gpio.h"



void Gpio_Init(const Gpio_ConfigType* ConfigPtr){
	if(ConfigPtr->GPIO_PinMode == 1)
	{
		ConfigPtr->base->PDDR |= (1<<(ConfigPtr->GPIO_PinNumber));		
  }
	else if(ConfigPtr->GPIO_PinMode == 0)
	{
				ConfigPtr->base->PDDR &= ~(1<<(ConfigPtr->GPIO_PinNumber));		
	}
}


void Gpio_WriteToOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber, unsigned char value)
{
  if(value ==1)
	{
	   pGPIOx->PDOR |= (1<<PinNumber);
	}
	else
	{
		 pGPIOx->PDOR &= ~(1<<PinNumber);
	}
}

void Gpio_SetOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber)
{
	pGPIOx->PDOR |= (1<<PinNumber);
}

void Gpio_ResetOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber)
{
  pGPIOx->PDOR &= ~(1<<PinNumber);	
}

void Gpio_ToggleOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber)
{
	pGPIOx->PDOR ^= (1<<PinNumber);
}

unsigned char GPIO_ReadFromInputPin(GPIO_Type *pGPIOx, unsigned char PinNumber)
{
	unsigned char value;
	value = ((pGPIOx->PDIR)>>PinNumber)&1;
	return value;
	
}





