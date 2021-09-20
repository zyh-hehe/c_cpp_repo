#pragma once
#include<string>
#include<iostream>
#include<cmath>//这个是数学计算的库
#include<istream>
#include<ostream>
using namespace std;
class Vec2D
{
private:
	double x_;
	double y_;
public:
	Vec2D();
	Vec2D(double x, double y);
	
	// 将向量转化为字符串显示
	std::string toString();
	
	// 向量加法
	Vec2D add(Vec2D secondVec2D);
	Vec2D add(double number);
	Vec2D operator+(const Vec2D& secondVec2D);//这里传引用参数是为了减少传参的开销
	Vec2D operator+(const double number);//double类型参数传不传引用开销差不多，const是为了保证这个传进来的参数不被改变
	Vec2D& operator +=(double x);//+=的实现结果是本身被加了，改变了原对象，所以传回来的是引用类型
	Vec2D& operator += (const Vec2D& secondVec2D);
	
	// 向量减法
	Vec2D subtract(Vec2D secondVec2D);//当然也可以不传引用，只是开销大一点
	Vec2D subtract(double numble);//当然也可以不const，只是可能会改变number的值，所以为了保证安全这类函数最好还是const
	Vec2D operator-(const Vec2D& secondVec2D);
	Vec2D operator-(const double number);
	Vec2D& operator -=(double x);//同+=
	Vec2D& operator -= (const Vec2D& secondVec2D);
	
	// 向量点乘
	double dot(Vec2D secondVec2D);//点乘结果是一个数，不是向量，高中数学别给忘了
	double operator*(const Vec2D& secondVec2D);
	
	// 向量数乘
	Vec2D multiply(double x);
	Vec2D& operator *= (double x);//同+=
	friend Vec2D operator*(double x, Vec2D vec2d);
	//这里解释一下这个friend声明：由于一个向量是前面乘了一个数还是在后面乘，结果都是一样的；
	//但是一个数乘以一个向量，比如2.0*v2，这个乘号是没有办法在这里重载的，所以要声明成友元函数，
	//即这个函数不属于这个类，这样才可以在重载时传入两个参数，第一个是一个数，第二个是一个向量对象
	
	// 向量取负
	Vec2D negative();
	Vec2D operator - (void);//这里写的和之前+=这些有点不一样，这两个取负函数只是单纯的取负，没有把该对象本身变负，所以返回一个临时Vec2D对象
	
	// 向量自增
	Vec2D& increase();
	Vec2D& operator ++();
	Vec2D    operator ++(int dummy);
	//这个++的重载是后置++，而这里的形参dummy只是作为一个标识符/占位符，
	//其实并没有参加函数逻辑本体，所以在调用时也不需要真的传进去
	//而为什么后置++运算符没有传回一个引用呢？
	//这是因为后置++运算符是在执行完后再自增，逻辑和最原始的(int)++是一样的
	//所以返回的实际上是没有自增的原对象，执行完后再自增
	
	// 向量自减
	Vec2D& decrease();
	Vec2D& operator --();
	Vec2D    operator --(int dummy);//同上
	
	// 读取和修改某个元素的值
	double& at(int x);//x如果传进0，就返回x_的值，1就返回y_的值
	double& operator [](int x);//这里之所以传回来引用类型是为了把这个函数返回值从一个不可修改的纯右值变为左值引用，可以进行修改
	
	// 计算向量模长
	double magnitude();
	operator double();//类型转换运算符（如double）的返回值即为函数本身，所以不需要写返回值类型

	// 计算向量方向
	double direction();
	
	// 比较两个向量
	int compareTo(Vec2D secondVec2D);//相等返回0，小了返回-1，大了返回1

	//重载流提取/输出运算符
	friend ostream& operator<<(ostream& os, const Vec2D& vec2d);//流提取运算符是只读类型，所以声明成const
	friend istream& operator>>(istream& is, Vec2D& vec2d);//由于流输入运算符是要改变类内值的，所以得传入引用类型
	//这里之所以声明成友元函数，是因为如果声明成类内函数，调用的时候就要写成vec2d<<cout这样子，
	//很奇怪，所以声明成友元函数,以便接收两个参数，第一个是i/o流，第二个是Vec2D
};

