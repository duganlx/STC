#include <reg51.h>

//以下是key4x4部分的变量定义
#define KEYPORT P1
char code Key4x4code[4][4]={'0','1','2','3','4','5','6','7',
							'8','9','.','-',' ','\b','\r','\n'};

/*
 延时
*/
void _delayms(int ms)
{
	unsigned char i;
	while(ms--)
		for(i=0;i<110;i++);
}

/*
 获取键盘的ascii码，没有键按下返回0
*/
char key4x4_getkey()
{
	unsigned char row,col;
	unsigned int tem;
    KEYPORT=0x0f;
	if(KEYPORT!=0x0f)
	{
		_delayms(30);
		KEYPORT=0x0f;
		tem=KEYPORT;
		if(tem!=0x0f)//确定有键按下
		{
			for(row=0; row<4; row++)
			{
				if((tem&0x01)==0) break;
				tem=tem>>1;
			}
			KEYPORT=0xF0;
			tem=KEYPORT;
			for(col=0; col<4; col++)
			{
				if((tem&0x10)==0) break;
				tem=tem>>1;
			}
			tem=0;
			while((tem<50)&&(KEYPORT!=0xF0))
			{
				_delayms(30);
				tem++;
			}
		  return Key4x4code[row][col];
		}
		else//干扰
			return 0;
	}
	else//没有键按下
		return 0;
}

/*
 连接输入格式化流，实现格式化流输入的关键
*/
char WaitGetKey()
{
	char tem;
	while(1)
	{
		tem=key4x4_getkey();
		if(tem!=0)
  		 return tem;
	}
} 
