#pragma once
#include<iostream>
#include<vector>
#include<graphics.h>
using std::string;
using std::vector;
using std::array;
using std::cout;
using std::endl;

class Color {
private:
	color_t color{ 0xFFFFFF };
public:
	Color();
	Color(color_t);
	Color(int);
	Color(int, int);
	void setColor(color_t);
	void setColor(int);
	void setColor(int, int);
	color_t getColor()const;
	bool operator==(Color)const;
	bool operator!=(Color&)const;
	int operator[](int)const;
	Color operator++(int dummy);//后置++
	Color& operator++();//前置++
	Color operator--(int dummy);//后置--
	Color& operator--();//前置--
};