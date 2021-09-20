#include<iostream>
#include "Shape.h"
#include"Circle.h"
#include"Rectangle.h"
int main(void)
{
	std::cout << "创建1" << std::endl;
	shape s1;
	std::cout << "创建2" << std::endl;
	circle c1;
	std::cout << "创建3" << std::endl;
	rectangle r1;
	std::cout << "创建4" << std::endl;
	shape s2{ Color::cyan,true };
	std::cout << "创建5" << std::endl;
	circle c2{ 20.0 };
	std::cout << "创建6" << std::endl;
	rectangle r2{2.0,2.0};
	std::cout << "创建7" << std::endl;
	shape s3{ s2 };
	std::cout << "创建8" << std::endl;
	circle c3{ 20.0,Color::cyan,false };
	std::cout << "创建9" << std::endl;
	rectangle r3(3.0,3.0,Color::green,true);
	std::cout << "s1." << s1.shapetostring() << std::endl;
	std::cout << "s2." << s2.shapetostring() << std::endl;
	std::cout << "s3." << s3.shapetostring() << std::endl;
	std::cout << "c1." << c1.shapetostring() << std::endl;
	std::cout << "c2." << c2.shapetostring() << std::endl;
	std::cout << "c3." << c3.shapetostring() << std::endl;
	std::cout << "r1." << r1.shapetostring() << std::endl;
	std::cout << "r2." << r2.shapetostring() << std::endl;
	std::cout << "r3." << r3.shapetostring() << std::endl;
	return 0;
}