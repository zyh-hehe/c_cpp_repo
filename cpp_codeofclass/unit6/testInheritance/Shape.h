#pragma once
#include<iostream>
#include<array>
#include<string>
using namespace std::string_literals;//可以使用“”s
using std::string;
using std::array;
enum class Color{  white,black,yellow,red,blue,green,cyan,orange,purple, };
class shape
{
private:
	Color color{ Color::black };
	bool isFilled{ false };
public:
	shape() = default;
	shape(Color color, bool isFilled)
	{
		this->color = color;
		this->isFilled = isFilled;
		std::cout << "shape的有参构造函数被调用了" << std::endl;
	}
	Color getColor() { return color; }
	bool getwhetherFilled() { return isFilled; }
	void setColor(Color color) { this->color = color; }
	void setwhetherFilled(bool isFilled) { this->isFilled = isFilled; }
	string shapetostring()
	{
		array <string, 9> c
		{ "white"s,"black"s,"yellow"s,"red"s,"blue"s,"green"s,"cyan"s,"orange"s,"purple"s };
		return "shape:    " + c[static_cast<int>(color)] + "\t"
			+ (isFilled == true ? "filled" : "not filled");
	}
};
