#include <reg51.h>
#include "key4x4.h"
void main()
{
	char tem;
	tem=WaitGetKey();
	P2=tem;
}