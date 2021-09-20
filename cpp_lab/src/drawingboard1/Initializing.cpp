#include"Initializing.h"
#include<array>
using std::array;

 Initializing::Initializing() {
	initgraph(1920, 1080);
	setfont(30, 0, "¿¬Ìå");
	setbkcolor(this->backcolor);
	setcolor(BLACK);
	setlinewidth(1.0);
	line(300, 0, 300, 2560);
}

Initializing::Initializing(int height_, int width_) {
	this->height = height_;
	this->width = width_;
	initgraph(this->height, this->width);
	setfont(30, 0, "¿¬Ìå");
	setbkcolor(this->backcolor);
	setlinewidth(5);
	line(300, 0, 300, 2560);
}

void Initializing::setBackcolor(color_t backcolor_) {
	this->backcolor = backcolor_;
	setbkcolor(this->backcolor);
}

color_t Initializing::getBackcolor() const{
	return this->backcolor;
}

void Initializing::setHeight(int height_) {
	this->height = height_;
}

void Initializing::setWidth(int width_) {
	this->width = width_;
}

int Initializing::getHeight()const {
	return this->height;
}

int Initializing::getWidth()const {
	return this->width;
}