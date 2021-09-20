#include"shape.h"
#include"rectangle.h"
rectangle::rectangle() :rectangle(1.0, 1.0) {/*Ĭ�Ϲ��캯����ʹ����ί�й���*/ }
rectangle::rectangle(double height, double width)
	{
		this->height = height;
		this->width = width;
	}
	rectangle::rectangle(double height, double width, Color color, bool isFilled) :
		shape(color, isFilled)
	{
		this->height = height;
		this->width = width;
	}
	double rectangle::getHeight() const { return height; }
	double rectangle::getWidth()  const { return width; }
	double rectangle::getArea() const { return width * height; }
	void rectangle::setHeight(double height) { this->height = height; }
	void rectangle::setWidth(double width) { this->width = width; }

