#include "Point.h"

Point::Point() = default;

Point::Point(int x_, int y_) {
	this->x = x_, this->y = y_;
}

Point::Point(Point* p) {
	this->x = p->getX();
	this->y = p->getY();
}

int Point::getX()const {
	return this->x;
}

int Point::getY()const {
	return this->y;
}

void Point::setX(int x_) {
	this->x = x_;
}

void Point::setY(int y_) {
	this->y = y_;
}

int& Point::operator[](int index) {
	if (0 == index)
		return this->x;
	else if (1 == index)
		return this->y;
	else
		throw std::out_of_range("index is out of range!");
}

bool Point::operator==(Point& secpoint)const {
	if (this->x == secpoint[0] && this->y == secpoint[1])
		return true;
	else
		return false;
}

bool Point::operator!=(Point& secpoint)const {
	if (this->x == secpoint[0] && this->y == secpoint[1])
		return false;
	else
		return true;
}

Point Point::operator+(Point& secpoint)const {
	int x3 = (secpoint[0] + this->x) / 2;
	int y3 = (secpoint[1] + this->y) / 2;
	return Point(x3, y3);
}