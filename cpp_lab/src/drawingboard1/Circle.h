#pragma once
#include"Shape.h"

class Circle :public Shape {
private:
	static int CountOfCircle;
	double radius{ 10.0 };
	Point* CircleCenter;
public:
	Circle();
	Circle(int, int, double, color_t, color_t, bool);
	Circle(int, int, int, int, color_t, color_t, bool);
	Circle(Circle*);
	Circle& operator=(const Circle&);
	double getRadius()const;
	void setRadius(double);
	double getArea()const override;
	static int getCountOfCircle();
	Point* getCircleCenter()const;
	void draw()override;
	void WriteToFile(ofstream& output)override;
	bool operator==(Shape*&)const override;
	bool operator>=(Shape*&)const override;
	bool operator<=(Shape*&)const override;
	bool operator!=(Shape*&)const override;
	bool operator>(Shape*&)const override;
	bool operator<(Shape*&)const override;
	Point& operator[](int)override;
	~Circle()override;
};
