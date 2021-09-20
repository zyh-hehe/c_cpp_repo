#include <stdio.h>
#include"graphics.h"
#include<stdbool.h>
#include<math.h>
#include"struct.SHAPE.h"

void choosecolor(void);
void get2point(void);
void restore(void);

//这个结构体数组的声明在mainfunction.cpp里，所以用外部变量引入
extern  SHAPE shape[10000];
extern unsigned int count;

//这是画长方形的函数
void drawbar(void)
{
	choosecolor();//首先选颜色
	get2point();//这个函数在下面，用来获取两个点并将点的数据写入对应的结构体数组

	if (shape[count].fill)//如果读取到的数据是要填充，就画一个填充长方形
		bar(shape[count].x1, shape[count].y1, shape[count].x2, shape[count].y2);
	else//否则，就画四根线形成一个不填充的长方形
	{
		//根据上面得到的坐标画四根线，形成一个不填充的长方形
		line(shape[count].x1, shape[count].y1, shape[count].x2, shape[count].y1);
		line(shape[count].x1, shape[count].y1, shape[count].x1, shape[count].y2);
		line(shape[count].x1, shape[count].y2, shape[count].x2, shape[count].y2);
		line(shape[count].x2, shape[count].y2, shape[count].x2, shape[count].y1);
	}
	restore();//这个函数也在下面，是为了把字体颜色和填充颜色设置回初始值
}

//这是画圆的函数
void drawcircle(void)
{
	int a;//这个a变量只是用来充当在计算半径时的中间值，在其他函数里并没有用到，所以我把它定义在了函数里做一个局部变量
	choosecolor();//首先选颜色
	get2point();//这个函数在下面，用来获取两个点并将点的数据写入对应的结构体数组

	shape[count].centerx = (shape[count].x1 + shape[count].x2) / 2;//计算圆心的X坐标
	shape[count].centery = (shape[count].y1 + shape[count].y2) / 2;//计算圆心的Y坐标
	a = (shape[count].x1 - shape[count].x2) * (shape[count].x1 - shape[count].x2) + (shape[count].y1 - shape[count].y2) * (shape[count].y1 - shape[count].y2);//勾股定理计算函数半径
	shape[count].radius = sqrt(a) / 2;//勾股定理计算半径

	if (shape[count].fill)//如果读取到的数据是要填充，就画一个填充圆
		//在EGE库里并没有画填充圆的函数，所以我只能画一个长短轴相等的椭圆形成一个圆
		fillellipse(shape[count].centerx, shape[count].centery, shape[count].radius, shape[count].radius);
	else//否则，就画一个圆
		circle(shape[count].centerx, shape[count].centery, shape[count].radius);
	restore();//这个函数也在下面，是为了把字体颜色和填充颜色设置回初始值
}

//这是画线的函数
void drawline(void)
{
	choosecolor();//首先选颜色
	get2point();//这个函数在下面，用来获取两个点并将点的数据写入对应的结构体数组
	line(shape[count].x1, shape[count].y1, shape[count].x2, shape[count].y2);
	restore();//这个函数也在下面，是为了把字体颜色和填充颜色设置回初始值
}

//这是画三角形的函数
void drawtriangle(void)
{
	choosecolor();
	//三角形的坐标确定是靠点击三次鼠标，和长方形，圆和线的点获取逻辑不同，所以要另外写下面这段来获取其坐标
	int i = 0;
	mouse_msg msg;
	for (; is_run(); delay_fps(120))
	{
		mouse_msg msg = { 0 };
		while (mousemsg())
			msg = getmouse();
		//以下是获取鼠标按下去时的坐标位置
		if (i == 0 && msg.is_left() && msg.is_down())
		{
			shape[count].x1 = msg.x;
			shape[count].y1 = msg.y;
			i++;
		}
		//以下是获取鼠标松开时的坐标位置
		else if (i == 1 && msg.is_left() && msg.is_down())
		{
			shape[count].x2 = msg.x;
			shape[count].y2 = msg.y;
			i++;
		}
		else if (i == 2 && msg.is_left() && msg.is_down())
		{
			shape[count].x3 = msg.x;
			shape[count].y3 = msg.y;
			i++;
		}
		if (i == 3)
			break;
	}

	//将获取的坐标写入下面这个临时数组，然后画3个边的多边形
	int pt[8] =
	{
		shape[count].x1,shape[count].y1,
		shape[count].x2,shape[count].y2,
		shape[count].x3,shape[count].y3,
		shape[count].x1,shape[count].y1,
	};

	if (shape[count].fill)//如果读取到的数据是填充，就画一个填充三角形
		fillpoly(4, pt);
	else//否则，就画一个不填充的三角形
		drawpoly(4, pt);
	restore();//这个函数也在下面，是为了把字体颜色和填充颜色设置回初始值
}

//这是能获取两个点坐标的函数，被用在了画长方形，线和圆的函数里
void get2point(void)
{
	int i = 0;
	mouse_msg msg;
	for (; is_run(); delay_fps(120))
	{
		mouse_msg msg = { 0 };
		while (mousemsg())
			msg = getmouse();
		//以下是获取鼠标按下去时的坐标位置
		if (i == 0 && msg.is_left() && msg.is_down())
		{
			shape[count].x1 = msg.x;
			shape[count].y1 = msg.y;
			i++;
		}
		//以下是获取鼠标松开时的坐标位置
		else if (i == 1 && msg.is_left() && msg.is_up())
		{
			shape[count].x2 = msg.x;
			shape[count].y2 = msg.y;
			i++;
		}
		//获取到两个点就可以出来了
		if (i == 2)
			break;
	}
}

//这是将颜色设置初始化的函数，以防之后输出的字体颜色花里胡哨的
void restore(void)
{
	setcolor(BLACK);
	setfillcolor(WHITE);
	//以下这行是为了覆盖掉询问颜色的那句话
	xyprintf(0, 90, "                                                                 ");
}