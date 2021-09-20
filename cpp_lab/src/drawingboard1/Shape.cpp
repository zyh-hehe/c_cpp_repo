#include"Shape.h"

Shape::Shape() {
	BorderColor = new Color(BLACK);
	FilledColor = new Color(RED);
	bool isFilled{ false };
}

Shape::Shape(color_t BorderColor_,color_t FilledColor_,bool isFilled_){
	BorderColor = new Color(BorderColor_);
	FilledColor = new Color(FilledColor_);
	this->isFilled = isFilled_;
}

Shape::Shape(Shape& shape_) {
	BorderColor = new Color(shape_.getBorderColor());
	FilledColor = new Color(shape_.getFilledColor());
	this->isFilled = shape_.isFilled;
}

bool Shape::getIsFilled()const {
	return this->isFilled;
}

void Shape::setIsFilled(bool isFilled_) {
	this->isFilled = isFilled_;
}

color_t Shape::getBorderColor()const {
	return this->BorderColor->getColor();
}

Color& Shape::getBorderColor1() {
	return *(this->BorderColor);
}

Color& Shape::getFilledColor1() {
	return *(this->FilledColor);
}

color_t Shape::getFilledColor()const {
	return this->FilledColor->getColor();
}

void Shape::setBorderColor(color_t BorderColor_) {
	this->BorderColor = new Color(BorderColor_);
}

void Shape::setBorderColor(int hxRGB_) {
	this->BorderColor = new Color(hxRGB_);
}

void Shape::setBorderColor(int x_,int y_) {
	this->BorderColor = new Color(x_, y_);
}

void Shape::setFilledColor(color_t FilledColor_) {
	this->FilledColor = new Color(FilledColor_);
}

void Shape::setFilledColor(int hxRGB_) {
	this->FilledColor = new Color(hxRGB_);
}

void Shape::setFilledColor(int x_, int y_) {
	this->FilledColor = new Color(x_, y_);
}

Shape::~Shape() {
	delete BorderColor, FilledColor;
	BorderColor = nullptr;
	FilledColor = nullptr;
}