#include<reg51.h>

data unsigned char cLed _at_ 0x20;

void init()
{
	IT0=1;
	EX0=1;
	EA=1;
}

void main()
{
	cLed = 0xfe;
	P2=cLed;
	init();
	while(1);
}

void I0() interrupt 0
{
  # pragma asm
	MOV A, 20H
	RL A
	MOV 20H, A
  # pragma endasm
  P2=cLed;
}
