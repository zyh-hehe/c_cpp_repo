#include <stdio.h>
#include"graphics.h"
#include"struct.SHAPE.h"

//这个结构体数组的声明在mainfunction.cpp里，所以用外部变量引入
extern  SHAPE shape[10000];
extern unsigned int count;

//这是选择无填充图形颜色的函数
//这个函数在选择颜色时会把填充色和线条色一起调整好，这是为了方便实现代码复用，不用再写一个选填充色的函数
void choosecolor(void)
{
	xyprintf(0, 90, "你要啥颜色呢？1.黑色 2.红色 3.绿色 4.蓝色 5.青色");
	char color;
	while (is_run())
	{
		color = getch();
		if (color == '1')
		{
			//这是将所选颜色标红
			setcolor(RED);
			xyprintf(210, 90, "1.黑色");
			//根据输入将填充色和线条色设置好
			setcolor(BLACK);
			setfillcolor(BLACK);
			shape[count].color = 1;
			break;
		}
		else if (color == '2')
		{
			//这是将所选颜色标红
			setcolor(RED);
			xyprintf(315, 90, "2.红色");
			//根据输入将填充色和线条色设置好
			setfillcolor(RED);
			shape[count].color = 2;
			break;
		}
		else if (color == '3')
		{
			//这是将所选颜色标红
			setcolor(RED);
			xyprintf(420, 90, "3.绿色");
			setcolor(GREEN);
			setfillcolor(GREEN);
			shape[count].color = 3;
			break;
		}
		else if (color == '4')
		{
			//这是将所选颜色标红
			setcolor(RED);
			xyprintf(525, 90, "4.蓝色");
			//根据输入将填充色和线条色设置好
			setcolor(BLUE);
			setfillcolor(BLUE);
			shape[count].color = 4;
			break;
		}
		else if (color == '5')
		{
			//这是将所选颜色标红
			setcolor(RED);
			xyprintf(630, 90, "5.青色");
			//根据输入将填充色和线条色设置好
			setcolor(CYAN);
			setfillcolor(CYAN);
			shape[count].color = 5;
			break;
		}
	}
}

