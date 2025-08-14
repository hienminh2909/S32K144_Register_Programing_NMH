#ifndef GPIO_H
#define GPIO_H

#include"Gpio_Register.h"

typedef struct
{
    GPIO_Type         *      base;                  /*!< Gpio base pointer.  */
    unsigned char            GPIO_PinNumber;        /*!< Pin number.*/
    unsigned char            GPIO_PinMode;          /*!< Pin_mode */
} Gpio_ConfigType;

#define OUTPUT 1
#define INPUT  0
#define HIGH   1
#define LOW    0
	
void Gpio_Init(const Gpio_ConfigType* ConfigPtr);
void Gpio_WriteToOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber, unsigned char value);
void Gpio_SetOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber);
void Gpio_ResetOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber);
void Gpio_ToggleOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber);
unsigned char GPIO_ReadFromInputPin(GPIO_Type *pGPIOx, unsigned char PinNumber);

#endif
