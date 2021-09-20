#include <stdio.h>
#include"graphics.h"
#include<stdbool.h>
#include"struct.SHAPE.h"

//这个结构体数组的声明在mainfunction.cpp里，所以用外部变量引入
extern  SHAPE shape[10000];
extern unsigned int count;
char whetherfill;//这个获取值用于处理bool类型的fill的值

void choose_whetherfill(void)
{
	xyprintf(0, 90, "你要填充吗？按1是填充，按2是不填充");//询问是否要填充
	while (is_run())//这个循环确保只有在获取到正确值时才能进行下一步
	{
		whetherfill = getch();//获取键盘输入值

		if (whetherfill == '1')//如果输入是1，就把true写到对应的结构体数组里，代表要填充；
		{
			shape[count].fill = true;
			break;
		}
		else if (whetherfill == '2')//如果输入是2，就把false写到对应的结构体数组里，代表不填充；
		{
			shape[count].fill = false;
			break;
		}
	}
}