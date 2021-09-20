#include<stdio.h>
#include"graphics.h"
//初始化设置函数
void initialsettings(void)
{
	initgraph(-1, -1);//画板为全屏
	setbkcolor(WHITE);//画板为白色
	setcolor(BLACK);//字体是黑的
	setfont(30, 0, "黑体");//字体大小和字体类型
}