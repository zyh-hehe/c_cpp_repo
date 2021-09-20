#include <stdio.h>
#include"graphics.h"
#include"struct.SHAPE.h"

//这个结构体数组的声明在mainfunction.cpp里，所以用外部变量引入
extern unsigned int count;
extern SHAPE shape[10000];
extern unsigned int polycount;

SHAPE* readfile(void);
void clearandredraw(void);

//这是询问是否读取已有画板的函数
int choice_whetherreadFile(char choice_readFile)
{
	while (is_run())
	{
		if (choice_readFile == 'q')
			closegraph();
		else if (choice_readFile == '1')
		{
			setviewport(0, 30, 1000, 1000);
			setfillcolor(WHITE);
			clearviewport();
			setviewport(0, 0, 10000, 10000);
			//以上这一段执行的目的是清除部分屏幕
			if (readfile() == NULL)//如果没读取到原文件，就提示读取失败
			{
				xyprintf(0, 0, "欢迎来到米奇妙妙屋画板3.0！");
				xyprintf(0, 30, "原有画板不存在,读取失败！");
				line(0, 125, 12800, 130);
				return 0;
			}
			else//如果读取成功，就显示已经读取
			{
				clearandredraw();
				xyprintf(0, 0, "欢迎来到米奇妙妙屋画板3.0！");
				xyprintf(0, 30, "已经读取了已有的画板文件哦");
				line(0, 125, 12800, 130);
				return 1;//返回1代表读取成功
			}
		}

		else if (choice_readFile == '2')
		{
			setviewport(0, 30, 1000, 1000);
			setfillcolor(WHITE);
			clearviewport();
			setviewport(0, 0, 10000, 10000);
			//以上这一段执行的目的是清除部分屏幕
			xyprintf(0, 0, "欢迎来到米奇妙妙屋画板3.0！");
			xyprintf(0, 30, "没有读取已有的画板文件哦");
			line(0, 125, 12800, 130);
			return 0;
		}
		else
			choice_readFile = getch();
	}
	return 0;
}

//这是在用户读取文件后询问是否要重画的函数
void redraw(int return_choice_whetherbegindraw)
{
	char choice_whetherredraw;
	if (return_choice_whetherbegindraw)
	{
		xyprintf(0, 60, "那你要重画吗？");
		xyprintf(0, 90, "按下1是重画，按下2是不重画");
		line(0, 125, 12800, 130);
		while (is_run())
		{
			choice_whetherredraw = getch();
			if (choice_whetherredraw == '1')
			{
				setviewport(0, 30, 10000, 10000);
				setfillcolor(WHITE);
				clearviewport();
				setviewport(0, 0, 10000, 10000);
				count = 1;//重画了就把图形个数重置
				polycount = 1;
				//以上这一段执行的目的是清除部分屏幕
				xyprintf(0, 0, "欢迎来到米奇妙妙屋画板3.0！");
				xyprintf(0, 30, "欢迎进入米奇妙妙屋！");
				line(0, 125, 12800, 130);
				break;
			}
			else if (choice_whetherredraw == '2')
				break;
		}
	}
}

//这是询问是否开始作画的函数
void choice_whetherbegindraw(char choice_begindraw)
{
	while (is_run())
	{
		switch (choice_begindraw)
		{
		case '1':
			setviewport(0, 0, 10000, 10000);
			break;
		case '2':
			setviewport(0, 30, 10000, 10000);
			setfillcolor(WHITE);
			clearviewport();
			setviewport(0, 0, 10000, 10000);
			xyprintf(0, 0, "欢迎来到米奇妙妙屋画板3.0！");
			xyprintf(0, 30, "已经清除了屏幕哦");
			//没啥好说的，就清个屏
			xyprintf(0, 60, "按下1是开始画画，按下2是清除屏幕（好像没什么用），按下q是退出");
			line(0, 125, 12800, 130);
			count = 1;
			polycount = 1;//清屏了就把图形个数重置
			choice_begindraw = getch();
			break;
		case'q':
			closegraph();
			break;
		default:
			choice_begindraw = getch();
		}
		if (choice_begindraw == '1')
			break;
	}
}