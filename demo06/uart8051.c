#include <uart8051.h>
#include <reg51.h>

void initCom(void)
{
	SCON=0x50; 	//0101_0000: ����Ϊ������ʽ1
	TMOD=0x20; 	//0010_0000: ���ü�����������ʽ2
	PCON=0x80; 	//1000_0000: �����ʼӱ� 
	TH1=0xF3;  	//1111_0011: ��������ʼֵ����,ע�Ⲩ������4800��
	TL1 =0xF3;	//1111_0011
	ES = 1;    	//�رս����ж�
	EA = 1;		//�����ж�
	TR1 = 1;	//�򿪼�����
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