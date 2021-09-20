#pragma once
#include<iostream>
#include<vector>
#include<graphics.h>
#include<stdexcept>

class Point{
private:
	int x{ 0 };
	int y{ 0 };
public:
	Point();
	Point(int, int);
	Point(Point*);
	int getX()const;
	int getY()const;
	void setX(int);
	void setY(int);
	bool operator!=(Point&)const;
	bool operator==(Point&)const;
	int& operator[](int);
	Point operator+(Point&)const;//因为我的点类坐标用的是int类型，所以这里的中点就向下取整
};

