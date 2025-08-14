#ifndef Pcc_REGISTER_H
#define Pcc_REGISTER_H

#define PCC_BASE   (0x40065000)

#define PCC_PORT_BASE  (PCC_BASE + 0x124)
#define PCC_PORTA_OFFSET   0x124
#define PCC_PORTB_OFFSET   0x128
#define PCC_PORTC_OFFSET   0x12C
#define PCC_PORTD_OFFSET   0x130
#define PCC_PORTE_OFFSET   0x134

typedef struct{
	volatile unsigned int A;
	volatile unsigned int B;
	volatile unsigned int C;
	volatile unsigned int D;
	volatile unsigned int E;
}PCC_PORT_Type;
\
#define PCC_PORT ((PCC_PORT_Type *)PCC_PORT_BASE)

// Bit dinh nghia
#define PCC_CLK_ENABLE_MASK   (1U << 30)




#endif
