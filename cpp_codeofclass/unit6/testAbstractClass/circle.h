#pragma once
#include<iostream>
#include "shape.h"
class circle : public shape
{
private:
	double radius;
public:
	circle();
	circle(double radius);
	circle(double radius, Color color, bool isFilled);
	double getRadius() const;
	double getArea() const;
	void setRadius(double radius);
};

