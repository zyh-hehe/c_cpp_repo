#include<iostream>
#include"circle.h"
#include"rectangle.h"
#include"shape.h"
int main(void)
{
	/*shape s;*///���д����޷�ʵ�֣���Ϊshape�����һ�����麯�����ǳ�����
	circle c{ 1.2 };
	shape* s = &c;//c������תΪs�����
    std::cout << c.getArea() << std::endl;
	std::cout << s->getArea() << std::endl;
	//�������д���Ϳ���ͨ������
	return 0;
}