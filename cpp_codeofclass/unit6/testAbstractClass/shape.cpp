#include"shape.h"
shape::shape() = default;
shape::shape(Color color, bool isFilled)
{
	this->color = color;
	this->isFilled = isFilled;
	std::cout << "shape���вι��캯����������" << std::endl;
}
Color shape::getColor() { return color; }
bool shape::getwhetherFilled() { return isFilled; }
void shape::setColor(Color color) { this->color = color; }
void shape::setwhetherFilled(bool isFilled) { this->isFilled = isFilled; }
string shape::shapetostring()
{
	array <string, 9> c
	{ "white"s,"black"s,"yellow"s,"red"s,"blue"s,"green"s,"cyan"s,"orange"s,"purple"s };
	return "shape:    " + c[static_cast<int>(color)] + "\t"
		+ (isFilled == true ? "filled" : "not filled");
}