#include<reg51.h>

unsigned int nTimerCount;
sbit P1_0 = P1^0;
sbit P1_1 = P1^1;

/**
* ��ʱ
*/
void delayMS(unsigned int n)
{
	nTimerCount = n;
	while(nTimerCount!=0);
}

/**
* ��ʼ��
*/
void initTimer()
{
	/*
	�����ж�
	*/
	ET0 = 1;
	ET1 = 1;
	EA = 1;
	
	/*
	T1: GATE=0; C/T=0; M1=1; M0=0; ģʽ1
	T0: GATE=0; C/T=0; M1=0; M0=1; ģʽ2
	*/
	TMOD = 0x21; //0010_0001
	TH0 = (65536-1000)/256;  //us
	TL0 = (65536-1000)%256; 
	TL1 = 256-100;
	TH1 = 256-100;
	
	/*
	������ʱ
	*/
	TR0 = 1;
	TR1 = 1;
	
	nTimerCount = 0;
	P1_0 = 0;
	P1_1 = 1;
	P2 = 0x05;
}

/**
* ��ʱ/������0(T0) �жϷ������
*/
void Timer0 () interrupt 1
{
	TH0 = (65536-1000)/256;  //us
	TL0 = (65536-1000)%256; 
	
	if(nTimerCount > 0)
		nTimerCount--;
}

/**
* ��ʱ/������1(T1) �жϷ������
*/
void Timer1 () interrupt 3
{
	P1_0 = ~P1_0;
	P1_1 = ~P1_1;
}

void main()
{
	initTimer();
	while(1)
	{
		delayMS(500);
		P2 = ~P2;
	}
}
