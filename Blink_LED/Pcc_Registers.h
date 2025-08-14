#ifndef Pcc_REGISTER_H
#define Pcc_REGISTER_H

#define PCC_BASE   (0x40065000)
#define PCC_PORTBASE  (PCC_BASE + 0x124)

typedef struct{
	volatile unsigned int A;
	volatile unsigned int B;
	volatile unsigned int C;
	volatile unsigned int D;
	volatile unsigned int E;
}PCC_Type;

#define PCC_PORT ((PCC_Type *)PCC_PORTBASE)


#endif
