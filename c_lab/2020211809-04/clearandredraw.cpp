#include <stdio.h>
#include"graphics.h"
#include"struct.SHAPE.h"

void clearandredraw(void);
void redraw_color();

//这个结构体数组的声明在mainfunction.cpp里，所以用外部变量引入
extern  SHAPE shape[10000];
extern unsigned int count;
int j;//这个j变量在下面两个函数里都用到了，所以写成全局变量，作用是判断循环次数和何时结束

//撤回逻辑是清屏之后重画图形至倒数第二个
void clearandredraw(void)
{
	cleardevice();
	//接下来的循环时用来重画图形的
	for (j = 1; j < count; j++)
	{
		if (shape[j].type == 1)//识别该图形的类型
		{
			redraw_color();//这个函数在下面，是用来识别该图形的颜色
			//重画
			if (shape[j].fill == true)
			{
				redraw_color();//这个函数在下面，是用来识别该图形的颜色
				bar(shape[j].x1, shape[j].y1, shape[j].x2, shape[j].y2);
			}
			else
			{
				line(shape[j].x1, shape[j].y1, shape[j].x2, shape[j].y1);
				line(shape[j].x1, shape[j].y1, shape[j].x1, shape[j].y2);
				line(shape[j].x1, shape[j].y2, shape[j].x2, shape[j].y2);
				line(shape[j].x2, shape[j].y2, shape[j].x2, shape[j].y1);
			}
		}
		else if (shape[j].type == 2)//识别该图形的类型
		{
			redraw_color();//这个函数在下面，是用来识别该图形的颜色
			//重画
			if (shape[j].fill == true)
				fillellipse(shape[j].centerx, shape[j].centery, shape[j].radius, shape[j].radius);
			else
				circle(shape[j].centerx, shape[j].centery, shape[j].radius);
		}
		else if (shape[j].type == 3)//识别该图形的类型
		{
			redraw_color();
			//将获取的坐标写入下面这个临时数组，然后画3个边的多边形
			int pt[8] =
			{
				shape[j].x1,shape[j].y1,
				shape[j].x2,shape[j].y2,
				shape[j].x3,shape[j].y3,
				shape[j].x1,shape[j].y1,
			};
			//重画
			if (shape[j].fill == true)
				fillpoly(4, pt);
			else
				drawpoly(4, pt);
		}
		else if (shape[j].type == 4)//识别该图形的类型
		{
			redraw_color();//这个函数在下面，是用来识别该图形的颜色
			//重画
			line(shape[j].x1, shape[j].y1, shape[j].x2, shape[j].y2);
		}
		else if (shape[j].type == 5)//识别该图形的类型
		{
			redraw_color();//这个函数在下面，是用来识别该图形的颜色
			int l;
			int m;
			int polypt[42];
			for (l = 0, m = 0; m < shape[j].side; l = l + 2, m = m + 1)
			{
				polypt[l] = shape[j].point[m][0];
				polypt[l + 1] = shape[j].point[m][1];
			}
			polypt[(2 * shape[j].side)] = shape[j].point[0][0];
			polypt[(2 * shape[j].side) + 1] = shape[j].point[0][1];
			//重画
			setviewport(0, 125, 10000, 10000);
			if (shape[j].fill)
				fillpoly(shape[j].side + 1, polypt);
			else
				drawpoly(shape[j].side + 1, polypt);
			setviewport(0, 0, 10000, 10000);
		}
	}
	//将颜色设置回来
	setcolor(BLACK);
	setfillcolor(WHITE);
}

void redraw_color(void)//根据对应数据设置颜色
{
	switch (shape[j].color)
	{
	case 1:
		setfillcolor(BLACK);
		setcolor(BLACK);
		break;
	case 2:
		setfillcolor(RED);
		setcolor(RED);
		break;
	case 3:
		setcolor(GREEN);
		setfillcolor(GREEN);
		break;
	case 4:
		setfillcolor(BLUE);
		setcolor(BLUE);
		break;
	case 5:
		setfillcolor(CYAN);
		setcolor(CYAN);
		break;
	}
}
