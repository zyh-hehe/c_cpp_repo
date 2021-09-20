#include <stdio.h>
#include"graphics.h"
#include<stdbool.h>
#include"struct.SHAPE.h"

void drawbar(void);
void drawcircle(void);
void drawline(void);
void drawtriangle(void);
void clearandredraw(void);
void choose_whetherfill(void);
void draw_poly(void);//这里的draw_poly不是drawpoly,这样命名是防止和EGE自带的画多边形的函数重名
void savefile(SHAPE*);

//这个结构体数组的声明在mainfunction.cpp里，所以用外部变量引入
extern unsigned int count;
extern SHAPE shape[10000];
extern unsigned int polycount;

//以下是用来画画的函数，可以理解为这是画画程序的主函数
void draw(void)
{
	while (is_run())
	{
		flushkey();//清空键盘缓存，防止出现由于按多次而出现bug
		//打印一段提示，告诉用户已经画了多少个图形
		xyprintf(900, 0, "你已经画了%d个图形了", count - 1);
		xyprintf(900, 30, "你已经画了%d个多边形了", polycount - 1);

		char choice_drawwhat;//首先获取输入，检测用户需求
		choice_drawwhat = getch();
		switch (choice_drawwhat)
		{
		case'q':
			if (count != 1)
			{
	          xyprintf(0, 90, "你要保存你画的画吗？按下1是保存，按下2是不保存");
			  char whethersave;
			  whethersave = getch();
			  if (whethersave == '1')
				savefile(shape);
			}
			closegraph();
		case '1':
			shape[count].type = 1;//如果选择了长方形，就把类型的值记为1
			choose_whetherfill();//选择是否填充
			drawbar();
			count++;//图形数加一
			break;
		case'2':
			shape[count].type = 2;//如果选择了圆，就把类型的值记为2
			choose_whetherfill();//选择是否填充
			drawcircle();
			count++;//图形数加一
			break;
		case '3':
			shape[count].type = 3;//如果选择了三角形，就把类型的值记为3
			choose_whetherfill();//选择是否填充
			drawtriangle();
			count++;//图形数加一
			break;
		case'4':
			shape[count].type = 4;//如果选择了线，就把类型的值记为4
			drawline();
			count++;//图形数加一
			break;
		case'5':
			shape[count].type = 5;//如果选择了多边形，就把类型的值记为5
			choose_whetherfill();//选择是否填充
			draw_poly();
			count++;//图形数加一
			polycount++;//多边形数加一
			break;
		case'6':
			//这里我直接清除整个屏幕再重新打印，反正也不麻烦，对吧
			cleardevice();
			xyprintf(0, 0, "欢迎来到米奇妙妙屋画板3.0，画图时鼠标操作请不要太快！！!");
			xyprintf(0, 30, "接下来，你要画个啥呢？");
			xyprintf(0, 60, "按下:1.长方形 2.圆  3.三角形 4.线  5.多边形  6.清除屏幕 c.撤回一步 q.退出。");
			line(0, 125, 12800, 130);
			//数据全部清零
			count = 1;
			polycount = 1;
			break;
		case 'c':
			//这是撤回一步的操作
			//如果是多边形，多边形的个数减一
			if (shape[count-1].type == 5)
			{
				if (polycount > 1)//防止出现非负数
					polycount--;
			}
			//图形数减一
			if (count > 1)//防止出现非负数
				count--;
			clearandredraw();//执行重画操作
			xyprintf(0, 0, "欢迎来到米奇妙妙屋画板3.0，画图时鼠标操作请不要太快！！!");
			xyprintf(0, 30, "接下来，你要画个啥呢？");
			xyprintf(0, 60, "按下:1.长方形 2.圆  3.三角形 4.线  5.多边形  6.清除屏幕 c.撤回一步 q.退出。");
			line(0, 125, 12800, 130);
			break;
		}
	}
}
