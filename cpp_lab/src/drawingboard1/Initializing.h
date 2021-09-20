#pragma once
#include<graphics.h>
#include<vector>
#include"Circle.h"
#include"Rectangle.h"
#include"Triangle.h"

using std::vector;

class Initializing {
private:
	int width{ 2560 };
	int height{ 1080 };
	color_t backcolor{ 0xFCFCFC };
public:
	Initializing();
	Initializing(int, int);
	void setBackcolor(color_t);
	color_t getBackcolor()const;
	int getWidth()const;
	int getHeight()const;
	void setWidth(int);
	void setHeight(int);
};