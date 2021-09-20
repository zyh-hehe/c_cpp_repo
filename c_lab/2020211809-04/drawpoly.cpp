#include <stdio.h>
#include "graphics.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include"struct.SHAPE.h"

//这个结构体数组的声明在mainfunction.cpp里，所以用外部变量引入
extern  SHAPE shape[10000];
extern unsigned int count;

void choosecolor(void);
void choose_whetherfill(void);
void restore(void);

void draw_poly(void)
{
	choosecolor();
	int polypt[42];//这个是一个临时数组，用于临时存入点的数据
	char side[10];//这是一个临时字符数组，用于临时储存从对话框获取的数据
	//创建一个对话框
	inputbox_getline("基于人工智能深度学习数据挖掘的多边形数据键入对话框",
		"请先输入你想要画的多边形的边数(最多20个边)。",
		side,
		sizeof(side) / sizeof(*side));

	while (is_run())
	{
		//下面这个if判断是为了确定输入值合法，即检测是否在3到20内和是否为整数
		if (atoi(side) >= 3 && atoi(side) <= 20 && (atoi(side)) - atof(side) == 0)
		{
			shape[count].side = atoi(side);//将输入值转化为整数值存入对应的结构体数组
			break;
		}

		else//如果不合法，就提示输入值非法，要求重新输入
		{
			inputbox_getline("基于人工智能深度学习数据挖掘的多边形数据键入对话框",
				"请先输入你想要画的多边形的边数(最多20个边)\n该输入值非法，请输入一个介于3到20之间的整数值！！！",
				side,
				sizeof(side) / sizeof(*side));
		}
	}
	xyprintf(300, 300, "%d", shape[count].side);//临时函数，方便我测试时看数据，没啥用

	while (is_run())
	{
		int k;//临时变量，只用于下面这个循环，目的是当读取到目标个数的坐标就结束获取
		for (k = 0; k < shape[count].side; k++)
		{
			char temppoint[15];//定义一个临时数组，用于临时储存输入
			//创建一个对话框
			inputbox_getline("基于人工智能深度学习数据挖掘的多边形数据键入对话框",
				"请逐个输入目标多边形的点坐标，形式如下\n\np.s：最小数值为1，最大数值和显示器大小有关\n\n\t\t   x,y",
				temppoint,
				sizeof(temppoint) / sizeof(*temppoint));

			char* p;//定义一个地址，用于下面的分割函数
			while (is_run())
			{
				p = strtok(temppoint, ",");//分隔符是逗号
				if (p && atoi(p) > 0 && (atoi(p)) - atof(p) == 0)//判断分割出的一段字符串是否合法
				{
					shape[count].point[k][0] = atoi(p);//如果合法，就直接写进对应的结构体数组
					p = strtok(NULL, ",");
					if (p && atoi(p) > 0 && (atoi(p)) - atof(p) == 0)
					{
						shape[count].point[k][1] = atoi(p);//如果合法，就直接写进对应的结构体数组
						xyprintf((300), (330 + 30 * k), "%d,%d", shape[count].point[k][0], shape[count].point[k][1]);//临时写的函数，方便我测试时看数据，没啥用
						break;//获取到的值合法就跳出去
					}
				}
				//如果输入值出现错误，就报错要求重输
				inputbox_getline("基于人工智能深度学习数据挖掘的多边形数据键入对话框",
					"该输入非法，请重新输入！！！！！\n请逐个输入目标多边形的点坐标，形式如下\np.s：最小数值为1，最大数值和显示器大小有关\n\n\t\t   x,y",
					temppoint,
					sizeof(temppoint) / sizeof(*temppoint));
			}
		}
		break;
	}
	int l;
	int m;//这两个变量都是临时变量，用于下面将值写入临时存点的数组中
	for (l = 0, m = 0; m < shape[count].side; l = l + 2, m = m + 1)
	{
		polypt[l] = shape[count].point[m][0];
		polypt[l + 1] = shape[count].point[m][1];
	}
	//数组的最后一个点是输入的第一个点
	polypt[(2 * shape[count].side)] = shape[count].point[0][0];
	polypt[(2 * shape[count].side) + 1] = shape[count].point[0][1];
	//接下来是画图阶段
	setviewport(0, 125, 10000, 10000);//调整视口
	if (shape[count].fill)//如果读取到的数据是要填充，就画一个填充多边形
		fillpoly(shape[count].side + 1, polypt);
	else
		drawpoly(shape[count].side + 1, polypt);//否则，就画一个不填充的多边形
	setviewport(0, 0, 10000, 10000);//将视口设置回来
	restore();//这个函数是为了把字体颜色和填充颜色设置回初始值
}