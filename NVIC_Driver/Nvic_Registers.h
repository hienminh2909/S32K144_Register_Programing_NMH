#ifndef NVIC_REGISTERS_H
#define NVIC_REGISTERS_H
   
#define NVIC_ISER_BASE (0xE000E100)	 
#define NVIC_ICER_BASE (0xE000E180)	
#define NVIC_ISPR_BASE (0xE000E200)	
#define NVIC_ICPR_BASE (0xE000E280)	
#define NVIC_IABR_BASE (0xE000E300)	
#define NVIC_IPR_BASE  (0xE000E400)	



typedef struct{
	volatile unsigned int IQRn[8];
}NVIC_Reg_Type;

//Interrupt Set-enable Registers
#define NVIC_ISER ((NVIC_Reg_Type*) NVIC_ISER_BASE)

//Interrupt Clear-enable Registers
#define NVIC_ICER ((NVIC_Reg_Type*) NVIC_ICER_BASE)


//Interrupt Set-pending Registers
#define NVIC_ISPR ((NVIC_Reg_Type*) NVIC_ISPR_BASE)

//Interrupt Clear-pending Registers
#define NVIC_ICPR ((NVIC_Reg_Type*) NVIC_ICPR_BASE)

//Interrupt Active Bit Registers
#define NVIC_IABR ((NVIC_Reg_Type*) NVIC_IABR_BASE)


typedef struct{
	volatile unsigned int PRIn[60];
}NVIC_Reg_Type1;

#define NVIC_IPR ((NVIC_Reg_Type1*) NVIC_IPR_BASE)
#define NVIC_STIR      (0xE000EF00)	

#endif

