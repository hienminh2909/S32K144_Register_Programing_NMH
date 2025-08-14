#ifndef GPIO_REGISTER_H
#define GPIO_REGISTER_H

#define GPIOA_BASE 0x400FF000
#define GPIOB_BASE 0x400FF040
#define GPIOC_BASE 0x400FF080
#define GPIOD_BASE 0x400FF0C0
#define GPIOE_BASE 0x400FF100




//////////////////////////////////////////////
typedef struct{
	volatile unsigned int PDOR;
	volatile unsigned int PSOR;
	volatile unsigned int PCOR;
	volatile unsigned int PTOR;
	volatile unsigned int PDIR;
	volatile unsigned int PDDR;
	volatile unsigned int PIDR;
}GPIO_Type;

#define GPIOA ((GPIO_Type *)GPIOA_BASE)
#define GPIOB ((GPIO_Type *)GPIOB_BASE)
#define GPIOC ((GPIO_Type *)GPIOC_BASE)
#define GPIOD ((GPIO_Type *)GPIOD_BASE)
#define GPIOE ((GPIO_Type *)GPIOE_BASE)
///////////////////////////////////////////////

////////////////////////////////////////////////



#endif
