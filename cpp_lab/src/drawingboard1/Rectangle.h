#pragma once
#include"Shape.h"

class cRectangle:public Shape {
private:
	static int CountOfRectangle;
	Point* p1;
	Point* p2;
	Point* p3;
	Point* p4;
public:
	cRectangle();
	cRectangle(int, int, int, int, color_t, color_t, bool);
	cRectangle(cRectangle*);
	vector<Point*> getRecPoint();
	static int getCountOfRectangle();
	void draw()override;
	void WriteToFile(ofstream& output)override;
	double getArea()const override;
	cRectangle& operator=(const cRectangle&);
	bool operator<(Shape*&)const override;
	bool operator<=(Shape*&)const override;
	bool operator>(Shape*&)const override;
	bool operator>=(Shape*&)const override;
	bool operator==(Shape*&)const override;
	bool operator!=(Shape*&)const override;
	Point& operator[](int)override;
	~cRectangle();
};
