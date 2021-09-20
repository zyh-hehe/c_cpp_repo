#pragma once
#include<iostream>
#include<graphics.h>
#include<string>
#include<array>
#include<fstream>
#include<filesystem>
#include<vector>
#include<cmath>
#include<stdexcept>
#include"Color.h"
#include"Point.h"

using std::ifstream;
using std::ofstream;
using std::ios;

namespace fs = std::filesystem;

class Shape{
private:
	Color* BorderColor;
	Color* FilledColor;
	bool isFilled{ true };
public:
	Shape();
	Shape(color_t, color_t, bool);
	Shape(Shape&);
	color_t getBorderColor()const;
	Color& getBorderColor1();
	Color& getFilledColor1();
	color_t getFilledColor()const;
	bool getIsFilled()const;
	void setIsFilled(bool);
	void setBorderColor(color_t);
	void setBorderColor(int);
	void setBorderColor(int, int);
	void setFilledColor(color_t);
	void setFilledColor(int);
	void setFilledColor(int, int);
	virtual ~Shape();
	virtual void draw() = 0;
	virtual double getArea()const = 0;
	virtual Point& operator[](int) = 0;
	virtual bool operator==(Shape*&)const = 0;
	virtual bool operator>=(Shape*&)const = 0;
	virtual bool operator<=(Shape*&)const = 0;
	virtual bool operator!=(Shape*&)const = 0;
	virtual bool operator<(Shape*&)const = 0;
	virtual bool operator>(Shape*&)const = 0;
	virtual void WriteToFile(ofstream& output) = 0;
};