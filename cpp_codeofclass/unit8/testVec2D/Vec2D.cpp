#include "Vec2D.h"

Vec2D::Vec2D () { 
	x_ = 0.0; 
	y_ = 0.0; 
}

Vec2D::Vec2D(double x,double y) {
	x_ = x;
	y_ = y;
}

// 将向量转化为字符串显示
std::string Vec2D::toString() {
	return std::string("(" + std::to_string(x_)+","+std::to_string(y_)+")");
}

// 向量加法
Vec2D Vec2D::add(Vec2D secondVec2D) {
	return Vec2D(x_+secondVec2D.x_,y_+secondVec2D.y_);
}

Vec2D Vec2D::add(double number) {
	return Vec2D(x_ + number, y_ + number);
}

Vec2D Vec2D::operator+(const double number) {
	return this->add(number);//直接调用原有函数
}

Vec2D Vec2D::operator+(const Vec2D& secondVec2D) {
	return this->add(secondVec2D);//直接调用原有函数
}

Vec2D& Vec2D::operator +=(double x) {
	*this = this->add(x);//直接调用原有函数
	/*另一种实现方式
	x_+=x;
	y_+=y;
	*/
	return *this;//返回的是自己
}

Vec2D& Vec2D::operator += (const Vec2D& secondVec2D) {
	*this = this->operator+(secondVec2D);//直接调用原有函数
	return *this;//返回的是自己
}

// 向量减法
Vec2D Vec2D::subtract(Vec2D secondVec2D) {
	return Vec2D(x_ - secondVec2D.x_, y_ - secondVec2D.y_);
}

Vec2D Vec2D::subtract(double number) {
	return Vec2D(x_ - number, y_ - number);//返回临时对象
}

Vec2D Vec2D::operator-(const double number) {
	return this->subtract(number);//直接调用原有函数
}

Vec2D Vec2D::operator-(const Vec2D& secondVec2D) {
	return this->subtract(secondVec2D);//直接调用原有函数
}

Vec2D& Vec2D::operator -=(double x) {
	*this = this->subtract(x);//直接调用原有函数
	return *this;//返回的是自己
}

Vec2D& Vec2D::operator -= (const Vec2D& secondVec2D) {
	*this = this->operator-(secondVec2D);
	return *this;
}

// 向量点乘
double Vec2D::dot(Vec2D secondVec2D) {
	return (x_* secondVec2D.x_+y_* secondVec2D.y_);
}

double Vec2D::operator*(const Vec2D& secondVec2D) {
	return this->dot(secondVec2D);
}

// 向量数乘
Vec2D Vec2D::multiply(double x) {
	return Vec2D(this->x_*x,this->y_*x);
}

Vec2D operator*(double x,Vec2D vec2d) {
	return vec2d.multiply(x);
}//这个函数在声明的时候要加friend，但在实现的时候作为一个类外部的普通函数来写就可以了

Vec2D& Vec2D::operator *= (double x) {
	*this = this->multiply(x);
	return *this;
}

// 向量取负
Vec2D Vec2D::negative() {
	return Vec2D(-x_,-y_);//只是用原对象的负值来构造一个临时对象返回回去，没有改变原对象的值
}

Vec2D Vec2D::operator - (void) {
	return Vec2D(-(this->x_), -(this->y_));//只是用原对象的负值来构造一个临时对象返回回去，没有改变原对象的值
}

// 向量自增
Vec2D& Vec2D::increase() {
	++x_, ++y_;
	return *this;
}

Vec2D& Vec2D::operator ++() {
	return this->increase();
}

Vec2D Vec2D::operator ++(int dummy) {
	Vec2D temp{ *this };
	this->x_++;
	this->y_++;//这里的自增就和返回的temp无关了
	return temp;//返回的是原对象的拷贝
}

// 向量自减
Vec2D& Vec2D::decrease() {
	x_--, y_--;
	return *this;
}

Vec2D& Vec2D::operator --() {
	return this->decrease();
}

Vec2D Vec2D::operator --(int dummy) {
	Vec2D temp{ *this };
	this->x_--;
	this->y_--;
	return temp;
}

// 读取或修改某个元素的值
double& Vec2D::at(int x) {
	if (0 == x)
		return x_;
	else
	    return y_;
}

double& Vec2D::operator[](int x) {
	if (1 == x)
		return y_;
	else if (0 == x)
		return x_;
	else
	{
		std::cout << "error!";
		std::exit(0);
	}
}

// 计算向量模长
double Vec2D::magnitude() {
	return sqrt(pow(x_,2)+pow(y_,2));//sqrt函数是求平方根，pow函数接受两个参数，第一个是幂的底数，第二个是次数
}

Vec2D::operator double() {
	return this->magnitude();
}

// 计算向量方向
double Vec2D::direction() {
	return atan(x_/y_);//atan函数是求反三角函数arctan值的
}

// 比较两个向量
int Vec2D::compareTo(Vec2D secondVec2D) {
	double m1 = this->magnitude();
	double m2 = secondVec2D.magnitude();
	if (abs(m1-m2) < 1e-10)//两个浮点数不能直接判等，所以要用两数相减，小于一个很小的数即判定两者相等
		return 0;
	else
		return m1 > m2 ? 1 : -1;
}

//重载流提取/输出运算符
ostream& operator<< (ostream& os, const Vec2D& vec2d) {
	os << "(" << vec2d.x_ << "," <<vec2d.y_<< ")" << endl;
	//os <<vec2d[0]<< vec2d[1] << endl;
	//上面注释掉的这行代码在const Vec2D&的参数下是无法调用的
	//去掉const就可以使用，但这样的话原来那一行又无法使用了
	//这是因为vec2d[]这个运算符重载返回的是引用类型，不是const类型
	//而如果去掉const，x_和y_都是private类型成员，无法在类外读取
	return os;
}

istream& operator>>(istream& is, Vec2D& vec2d) {
	is >> vec2d[0] >> vec2d[1];//这里就可以用这种类型，原因见上
	return is;
}



