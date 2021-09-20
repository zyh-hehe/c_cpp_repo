#pragma once
#include<iostream>
#include "Shape.h"
class rectangle : public shape
{
private:
	double height;
	double width;
public:
	rectangle():rectangle(1.0,1.0) {/*Ĭ�Ϲ��캯����ʹ����ί�й���*/ }
	rectangle(double height,double width) 
	{
		this->height = height;
		this->width = width;
	}
	rectangle(double height, double width, Color color, bool isFilled)
		//: shape(color, isFilled)
	{
		this->height = height;
		this->width = width;
		shape(color, isFilled);
		//����и���ֵ����⣺�����shape�Ĺ��캯�����ں���������Ͳ��������ã�Ϊɶ��
		//���⣬û���ˣ�����һ������
	}
	double getHeight() const { return height; }
	double getWidth()  const { return width; }
	double getArea() const { return width * height; }
	void setHeight(double height) { this->height = height; }
	void setWidth(double width) { this->width = width; }
};
