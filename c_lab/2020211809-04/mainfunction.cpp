#include <stdio.h>
#include"graphics.h"
#include"struct.SHAPE.h"
//声明部分，这里将每一个函数用到的变量直接跟在了该函数后面，是为了方便阅读
void initialsettings(void);
int choice_whetherreadFile(char);
char choice_readFile;
void choice_whetherbegindraw(char);
char choice_begindraw;
void draw(void);
void redraw(int);

unsigned int count = 1;//非负整型变量count用于计算已经画了多少个非多边形图形
SHAPE shape[10000];//定义了一个可以放10000个图形数据的SHAPE类型结构体数组
unsigned int polycount = 1;//非负整型变量polycount用于计算已经画了多少个多边形

//主函数部分
int main(void)
{
	//初始化设置字体大小颜色和画板背景色,这个函数在initialsettingsfunction.cpp里
	initialsettings();

	//以下为第一次屏幕的输出内容，引导用户选择是否读取已有画板
	xyprintf(0, 0, "欢迎来到米奇妙妙屋画板3.0，请先按shift关闭输入法！");
	xyprintf(0, 30, "你是否要读取已有的画板文件？");
	xyprintf(0, 60, "按下1是读取已有画板文件，按下2是不读取已有画板文件，按下q是退出");
	line(0, 125, 12800, 130);

	choice_readFile = getch();
	redraw(choice_whetherreadFile(choice_readFile));
	/*将choice_readFile这个值传给choice_whetherreadFile函数，
	再将其的返回值传给redraw函数。这两个函数都在menu.cpp里*/

	//以下为第二次屏幕的输出内容，引导用户选择是否开始作画
	xyprintf(0, 60, "接下来，你要开始画画吗？");
	xyprintf(0, 90, "按下1是开始画画，按下2是清除屏幕（好像没什么用），按下q是退出");
	line(0, 125, 12800, 130);

	choice_begindraw = getch();
	choice_whetherbegindraw(choice_begindraw);
	//将choice_begindraw的值传给choice_whetherbegindraw函数。这个函数也在menu.cpp里

	//以下为第三次屏幕的输出内容，引导用户选择画什么，这一段会一直显示
	xyprintf(0, 0, "欢迎来到米奇妙妙屋画板3.0，画图时鼠标操作请不要太快！！!");
	xyprintf(0, 30, "                                              ");
	xyprintf(0, 30, "接下来，你要画个啥呢？");
	xyprintf(0, 60, "按下:1.长方形 2.圆  3.三角形 4.线  5.多边形  6.清除屏幕 c.撤回一步 q.退出。");
	xyprintf(0, 90, "                                                                 ");
	line(0, 125, 12800, 130);
	//接下来可以开始画画了，这个函数在choosedrawwhat.cpp里
	//以上实现的只是一个前端提示的功能，主要用来画图的函数都在draw()函数里
	draw();
}