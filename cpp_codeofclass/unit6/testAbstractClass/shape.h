#pragma once
#include<iostream>
#include<string>
#include<array>
using std::string;
using std::array;
using namespace std::string_literals;
enum class Color { white, black, yellow, red, blue, green, cyan, orange, purple, };
class shape
{
private:
	Color color{ Color::black };
	bool isFilled{ false };
public:
	shape();
	shape(Color color, bool isFilled);
	Color getColor();
	bool getwhetherFilled();
	void setColor(Color color);
	void setwhetherFilled(bool isFilled);
	string shapetostring();
	virtual double getArea() const = 0;
};
