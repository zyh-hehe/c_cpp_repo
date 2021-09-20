#include"circle.h"
circle::circle() : circle(1.0) {/*Ĭ�Ϲ��캯����ʹ����ί�й���*/ }
circle::circle(double radius) { this->radius = radius; }
circle::circle(double radius, Color color, bool isFilled)
	: shape(color, isFilled) {
	this->radius = radius;
}
//����и���ֵ����⣺�����shape�Ĺ��캯��������Ƕ������Ͳ��������ã�Ϊɶ��
//���⣬û���ˣ�����һ������
double circle::getRadius() const { return radius; }
double circle::getArea() const { return radius * radius * 3.14; }
void circle::setRadius(double radius) { this->radius = radius; }