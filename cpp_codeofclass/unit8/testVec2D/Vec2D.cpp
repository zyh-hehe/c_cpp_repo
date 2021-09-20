#include "Vec2D.h"

Vec2D::Vec2D () { 
	x_ = 0.0; 
	y_ = 0.0; 
}

Vec2D::Vec2D(double x,double y) {
	x_ = x;
	y_ = y;
}

// ������ת��Ϊ�ַ�����ʾ
std::string Vec2D::toString() {
	return std::string("(" + std::to_string(x_)+","+std::to_string(y_)+")");
}

// �����ӷ�
Vec2D Vec2D::add(Vec2D secondVec2D) {
	return Vec2D(x_+secondVec2D.x_,y_+secondVec2D.y_);
}

Vec2D Vec2D::add(double number) {
	return Vec2D(x_ + number, y_ + number);
}

Vec2D Vec2D::operator+(const double number) {
	return this->add(number);//ֱ�ӵ���ԭ�к���
}

Vec2D Vec2D::operator+(const Vec2D& secondVec2D) {
	return this->add(secondVec2D);//ֱ�ӵ���ԭ�к���
}

Vec2D& Vec2D::operator +=(double x) {
	*this = this->add(x);//ֱ�ӵ���ԭ�к���
	/*��һ��ʵ�ַ�ʽ
	x_+=x;
	y_+=y;
	*/
	return *this;//���ص����Լ�
}

Vec2D& Vec2D::operator += (const Vec2D& secondVec2D) {
	*this = this->operator+(secondVec2D);//ֱ�ӵ���ԭ�к���
	return *this;//���ص����Լ�
}

// ��������
Vec2D Vec2D::subtract(Vec2D secondVec2D) {
	return Vec2D(x_ - secondVec2D.x_, y_ - secondVec2D.y_);
}

Vec2D Vec2D::subtract(double number) {
	return Vec2D(x_ - number, y_ - number);//������ʱ����
}

Vec2D Vec2D::operator-(const double number) {
	return this->subtract(number);//ֱ�ӵ���ԭ�к���
}

Vec2D Vec2D::operator-(const Vec2D& secondVec2D) {
	return this->subtract(secondVec2D);//ֱ�ӵ���ԭ�к���
}

Vec2D& Vec2D::operator -=(double x) {
	*this = this->subtract(x);//ֱ�ӵ���ԭ�к���
	return *this;//���ص����Լ�
}

Vec2D& Vec2D::operator -= (const Vec2D& secondVec2D) {
	*this = this->operator-(secondVec2D);
	return *this;
}

// �������
double Vec2D::dot(Vec2D secondVec2D) {
	return (x_* secondVec2D.x_+y_* secondVec2D.y_);
}

double Vec2D::operator*(const Vec2D& secondVec2D) {
	return this->dot(secondVec2D);
}

// ��������
Vec2D Vec2D::multiply(double x) {
	return Vec2D(this->x_*x,this->y_*x);
}

Vec2D operator*(double x,Vec2D vec2d) {
	return vec2d.multiply(x);
}//���������������ʱ��Ҫ��friend������ʵ�ֵ�ʱ����Ϊһ�����ⲿ����ͨ������д�Ϳ�����

Vec2D& Vec2D::operator *= (double x) {
	*this = this->multiply(x);
	return *this;
}

// ����ȡ��
Vec2D Vec2D::negative() {
	return Vec2D(-x_,-y_);//ֻ����ԭ����ĸ�ֵ������һ����ʱ���󷵻ػ�ȥ��û�иı�ԭ�����ֵ
}

Vec2D Vec2D::operator - (void) {
	return Vec2D(-(this->x_), -(this->y_));//ֻ����ԭ����ĸ�ֵ������һ����ʱ���󷵻ػ�ȥ��û�иı�ԭ�����ֵ
}

// ��������
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
	this->y_++;//����������ͺͷ��ص�temp�޹���
	return temp;//���ص���ԭ����Ŀ���
}

// �����Լ�
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

// ��ȡ���޸�ĳ��Ԫ�ص�ֵ
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

// ��������ģ��
double Vec2D::magnitude() {
	return sqrt(pow(x_,2)+pow(y_,2));//sqrt��������ƽ������pow��������������������һ�����ݵĵ������ڶ����Ǵ���
}

Vec2D::operator double() {
	return this->magnitude();
}

// ������������
double Vec2D::direction() {
	return atan(x_/y_);//atan�����������Ǻ���arctanֵ��
}

// �Ƚ���������
int Vec2D::compareTo(Vec2D secondVec2D) {
	double m1 = this->magnitude();
	double m2 = secondVec2D.magnitude();
	if (abs(m1-m2) < 1e-10)//��������������ֱ���еȣ�����Ҫ�����������С��һ����С�������ж��������
		return 0;
	else
		return m1 > m2 ? 1 : -1;
}

//��������ȡ/��������
ostream& operator<< (ostream& os, const Vec2D& vec2d) {
	os << "(" << vec2d.x_ << "," <<vec2d.y_<< ")" << endl;
	//os <<vec2d[0]<< vec2d[1] << endl;
	//����ע�͵������д�����const Vec2D&�Ĳ��������޷����õ�
	//ȥ��const�Ϳ���ʹ�ã��������Ļ�ԭ����һ�����޷�ʹ����
	//������Ϊvec2d[]�����������ط��ص����������ͣ�����const����
	//�����ȥ��const��x_��y_����private���ͳ�Ա���޷��������ȡ
	return os;
}

istream& operator>>(istream& is, Vec2D& vec2d) {
	is >> vec2d[0] >> vec2d[1];//����Ϳ������������ͣ�ԭ�����
	return is;
}



