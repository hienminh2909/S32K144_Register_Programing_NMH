//#include"Gpio_Register.h"
#include"Pcc_Registers.h"
//#include"Port_Register.h"
#include"Nvic.h"
#include"Gpio.h"
#include"Port.h"
#define NVIC_ISER_1			(*(volatile unsigned int*)(0xE000E100u + 4*1))
volatile int unsigned state =0;

int main()
{
	/*Step 1: Interrupt Set Enable Register */
	NVIC_IRQ_Enable(PORTC_IRQn);
	//NVIC_ISER_1 |= (1U<<29U);
	
	/*------------------------*/
	/*    config button       */
	/*------------------------*/
	
	/* Step 1: Enable clock for Port C */
	PCC_PORT->C |= (1U<<30U);
	
	/* Step 2: Configure Pin 12 of Port C is GPIO */
	//PORTC->PCR[12] |= (1U<<8U);
	Port_Pin_Configure(PORTC, PORT_GPIO,12);
	
	/* Step 3: set rising-edge interrupt */
	//PORTC->PCR[12] |= (9U<<16U);
	Port_Pin_Interrupt_Configure(PORTC, ISF_flag_Interrup_rising_edge, 12);
	Port_Pin_Input_Configure(PORTC, PULL_DOWN,12);
	/* Step 3: Configure Pin 12 of Port C is input */
	//GPIOC->PDDR &= ~(1U<<12U);
  Gpio_ConfigType Button_LED = {
		 .base = GPIOC,
		 .GPIO_PinMode = INPUT,
		 .GPIO_PinNumber = 12
	};
	Gpio_Init(&Button_LED);
	
	/*------------------------*/
	/*    config led green      */
	/*------------------------*/
		/* Step 1: Enable clock for Port D */
	PCC_PORT->D |= (1U<<30U);
	
	/* Step 2: Configure Pin 15,16,0 of Port D is GPIO */
	//PORTD->PCR[16] |= (1U<<8U);
	//PORTD->PCR[15] |= (1U<<8U);
	//PORTD->PCR[0] |= (1U<<8U);
	Port_Pin_Control(PORTD, PORT_GPIO,0);
	Port_Pin_Control(PORTD, PORT_GPIO,15);
	Port_Pin_Control(PORTD, PORT_GPIO,16);
	
	/* Step 3: Configure Pin 16,15,0 of Port D is output */
	//GPIOD->PDDR |= ((1U<<16U)|(1U<<15U)|(1U));
	//GPIOD->PDOR |= (1U<<15U); //den red tat
	//GPIOD->PDOR |= (1U); //den blue tat
	//GPIOD->PDOR &= ~(1U<<16U); //den green sang
	Gpio_ConfigType Red_LED = {
		 .base = GPIOD,
		 .GPIO_PinMode = OUTPUT,
		 .GPIO_PinNumber = 15
	};
	
	Gpio_ConfigType Green_LED = {
		 .base = GPIOD,
		 .GPIO_PinMode = OUTPUT,
		 .GPIO_PinNumber = 16
	};
	
	Gpio_ConfigType Blue_LED = {
		 .base = GPIOD,
		 .GPIO_PinMode = OUTPUT,
		 .GPIO_PinNumber = 0
	};
	
	Gpio_Init(&Red_LED);
	Gpio_Init(&Green_LED);
	Gpio_Init(&Blue_LED);
	state =0;

	while(1)
	{
      
			
		
	}
}

void PORTC_IRQHandler(void)
{
	//if(PORTC->PCR[12] & (1U<<24U)){
	if(Port_Pin_ISF_Get(PORTC,12)){	
	  //PORTC->PCR[12] |= (1U<<24U);
		Port_Pin_ISF_Clear(PORTC,12);
		state++;
		if(state >=3)
		{
			state=0;
		}
		else
		{
			// ko thuc hien task
		}
		
		if(state ==0 )
			{
				//GPIOD->PDOR &= ~(1U<<16U); //den green sang
				//GPIOD->PDOR |= (1U<<15U); //den red tat
	      //GPIOD->PDOR |= (1U); //den blue tat
				Gpio_ResetOutputPin(GPIOD,16);
				Gpio_SetOutputPin(GPIOD,15);
				Gpio_SetOutputPin(GPIOD,0);
				
			}
			else if(state ==1 )
			{
				//GPIOD->PDOR |= (1U<<16U); //den green tat
				//GPIOD->PDOR &= ~(1U<<15U); //den red sang
	      //GPIOD->PDOR |= (1U); //den blue tat
		    Gpio_SetOutputPin(GPIOD,16);
				Gpio_ResetOutputPin(GPIOD,15);
				Gpio_SetOutputPin(GPIOD,0);
			}
			else if(state ==2 )
			{
				//GPIOD->PDOR |= (1U<<16U); //den green tat
				//GPIOD->PDOR |= (1U<<15U); //den red tat
	      //GPIOD->PDOR &= ~1U; //den blue sang
				Gpio_SetOutputPin(GPIOD,16);
				Gpio_SetOutputPin(GPIOD,15);
				Gpio_ResetOutputPin(GPIOD,0); 
			}
			else
			{
				// khong thuc hien task 
			}
		
	}
	
}
