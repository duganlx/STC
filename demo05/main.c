#include <reg51.h>
#include <uart8051.h>

void main()
{
	initCom();
	
	while(1)
	{
		char ch=comGetChar();
		comSendChar(ch);
	}
}