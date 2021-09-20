#pragma once
#include<iostream>
#include "Shape.h"
class rectangle : public shape
{
private:
	double height;
	double width;
public:
	rectangle():rectangle(1.0,1.0) {/*默认构造函数，使用了委托构造*/ }
	rectangle(double height,double width) 
	{
		this->height = height;
		this->width = width;
	}
	rectangle(double height, double width, Color color, bool isFilled)
		//: shape(color, isFilled)
	{
		this->height = height;
		this->width = width;
		shape(color, isFilled);
		//这儿有个奇怪的问题：如果把shape的构造函数放在函数体里，它就不会起作用，为啥呢
		//啊这，没事了，在下一讲讲了
	}
	double getHeight() const { return height; }
	double getWidth()  const { return width; }
	double getArea() const { return width * height; }
	void setHeight(double height) { this->height = height; }
	void setWidth(double width) { this->width = width; }
};
