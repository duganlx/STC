#include <uart8051.h>
#include <reg51.h>

void initCom(void)
{
	SCON=0x50; 	//0101_0000: 设置为工作方式1
	TMOD=0x20; 	//0010_0000: 设置计数器工作方式2
	PCON=0x80; 	//1000_0000: 波特率加倍 
	TH1=0xF3;  	//1111_0011: 计数器初始值设置,注意波特率是4800的
	TL1 =0xF3;	//1111_0011
	ES = 1;    	//关闭接收中断
	EA = 1;		//打开总中断
	TR1 = 1;	//打开计数器
}

void UART_putchar(char ch)
{
	SBUF = ch;
	while(!TI);
	TI = 0;
	return;
}

char UART_getkey(void)
{
	char DATA;
	
	while(!RI);
	DATA = SBUF;
	RI = 0;
	return DATA;
}