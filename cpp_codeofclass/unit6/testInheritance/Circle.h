#pragma once
#include<iostream>
#include "Shape.h"
class circle: public shape
{
private:
	double radius;
public:
	circle() : circle(1.0) {/*Ĭ�Ϲ��캯����ʹ����ί�й���*/}
	circle (double radius) { this->radius = radius; }
	circle(double radius, Color color, bool isFilled)
		: shape(color, isFilled)  { this->radius = radius; }
	//����и���ֵ����⣺�����shape�Ĺ��캯��������Ƕ������Ͳ��������ã�Ϊɶ��
	//���⣬û���ˣ�����һ������
	double getRadius() const { return radius; }
	double getArea() const { return radius * radius * 3.14; }
	void setRadius(double radius) { this->radius = radius; }
};
