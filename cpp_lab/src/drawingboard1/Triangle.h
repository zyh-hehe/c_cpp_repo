#pragma once
#include"Shape.h"
class Triangle :public Shape {
private:
	static int CountOfTriangle;
	Point* p1;
	Point* p2;
	Point* p3;
public:
	Triangle();
	Triangle(Point, Point, Point, color_t, color_t, bool);
	Triangle(Triangle*);
	vector<Point*> getTriPoint()const;
	static int getCountOfTriangle();
	void draw()override;
	void WriteToFile(ofstream& output)override;
	double getArea()const override;
	Triangle& operator=(const Triangle&);
	bool operator<(Shape*&)const override;
	bool operator<=(Shape*&)const override;
	bool operator>(Shape*&)const override;
	bool operator>=(Shape*&)const override;
	bool operator==(Shape*&)const override;
	bool operator!=(Shape*&)const override;
	Point& operator[](int)override;
	~Triangle();
};