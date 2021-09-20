#include"Color.h"

Color::Color() = default;

Color::Color(color_t color_) {
	this->color = color_;
}

Color::Color(int hxRGB_) {
	this->color = static_cast<color_t>(hxRGB_);
}

Color::Color(int x_, int y_) {
	this->color = getpixel(x_, y_);
}

void Color::setColor(color_t color_) {
	this->color = color_;
}

void Color::setColor(int hxRGB_) {
	this->color = static_cast<color_t>(hxRGB_);
}

void Color::setColor(int x_, int y_) {
	this->color = getpixel(x_, y_);
}

color_t Color::getColor()const {
	return this->color;
}

bool Color::operator==(Color seccolor)const {
	if (this->color == seccolor.color)
		return true;
	else
		return false;
}

bool Color::operator!=(Color& seccolor)const {
	if (this->color == seccolor.color)
		return false;
	else
		return true;
}

int Color::operator[](int index)const {
	if (0 == index)
		return EGEGET_R(this->color);
	else if (1 == index)
		return EGEGET_G(this->color);
	else if (2 == index)
		return EGEGET_B(this->color);
	else
		throw std::out_of_range("index is out of range!");
}

Color Color::operator++(int dummy) {
	Color temp{ *this };
	int r= EGEGET_R(this->color);
	int g= EGEGET_G(this->color);
	int b= EGEGET_B(this->color);
	if (r < 255)
		r++;
	if (g < 255)
		g++;
	if (b < 255)
		b++;
	color_t c = EGERGB(r, g, b);
	*this = Color(c);
	return temp;
}

Color& Color::operator++() {
	int r = EGEGET_R(this->color);
	int g = EGEGET_G(this->color);
	int b = EGEGET_B(this->color);
	if (r < 255)
		r++;
	if (g < 255)
		g++;
	if (b < 255)
		b++;
	color_t c = EGERGB(r, g, b);
	*this = Color(c);
	return *this;
}

Color Color::operator--(int dummy) {
	Color temp{ *this };
	int r = EGEGET_R(this->color);
	int g = EGEGET_G(this->color);
	int b = EGEGET_B(this->color);
	if (r > 0)
		r--;
	if (g > 0)
		g--;
	if (b > 0)
		b--;
	color_t c = EGERGB(r, g, b);
	*this = Color(c);
	return temp;
}

Color& Color::operator--() {
	int r = EGEGET_R(this->color);
	int g = EGEGET_G(this->color);
	int b = EGEGET_B(this->color);
	if (r > 0)
		r--;
	if (g > 0)
		g--;
	if (b > 0)
		b--;
	color_t c = EGERGB(r, g, b);
	*this = Color(c);
	return *this;
}

