#ifndef _COM_H_
#define _COM_H_

/*
初始化
*/
void initCom(void);

/*
发送数据
*/
void UART_putchar(char ch);

/*
接收数据
*/
char UART_getkey(void);

#endif