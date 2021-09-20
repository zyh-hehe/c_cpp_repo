#pragma once
#include<iostream>
#include "shape.h"
class rectangle : public shape
{
private:
	double height;
	double width;
public:
	rectangle();
	rectangle(double height, double width);
	rectangle(double height, double width, Color color, bool isFilled);
	double getHeight() const;
	double getWidth()  const;
	double getArea() const;
	void setHeight(double height);
	void setWidth(double width);
};

