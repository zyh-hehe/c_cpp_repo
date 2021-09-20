#pragma once
#include<iostream>
#include "Shape.h"
class circle: public shape
{
private:
	double radius;
public:
	circle() : circle(1.0) {/*默认构造函数，使用了委托构造*/}
	circle (double radius) { this->radius = radius; }
	circle(double radius, Color color, bool isFilled)
		: shape(color, isFilled)  { this->radius = radius; }
	//这儿有个奇怪的问题：如果把shape的构造函数放在内嵌体里，它就不会起作用，为啥呢
	//啊这，没事了，在下一讲讲了
	double getRadius() const { return radius; }
	double getArea() const { return radius * radius * 3.14; }
	void setRadius(double radius) { this->radius = radius; }
};
