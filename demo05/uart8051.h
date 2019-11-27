#ifndef _COM_H_
#define _COM_H_

/*
初始化
*/
void initCom(void);

/*
发送数据
*/
void comSendChar(unsigned char ch);

/*
接收数据
*/
unsigned char comGetChar(void);

#endif