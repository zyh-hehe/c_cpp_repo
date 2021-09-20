#include<iostream>
#include"circle.h"
#include"rectangle.h"
#include"shape.h"
int main(void)
{
	/*shape s;*///这行代码无法实现，因为shape类包含一个纯虚函数，是抽象类
	circle c{ 1.2 };
	shape* s = &c;//c对象上转为s类对象
    std::cout << c.getArea() << std::endl;
	std::cout << s->getArea() << std::endl;
	//上面两行代码就可以通过编译
	return 0;
}