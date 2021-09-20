#include <iostream>
using namespace std;
#include<string>
#include<ostream>
#include<istream>
#include <iostream>
#include <cstdlib>
#include <limits>
#include<exception>
#include<stdexcept>

class MyComplex {
private:
	double RealPart{ 1 };
	double ImagePart{ 1 };
public:
	MyComplex();

	MyComplex(double, double);

	string toString();

	MyComplex operator+(const MyComplex&);

	MyComplex operator-(const MyComplex&);
	
	MyComplex operator*(const MyComplex&);

	MyComplex operator/(MyComplex&);

	MyComplex& operator+=(const MyComplex&);

	double& operator[](int);

	MyComplex& operator++();

	MyComplex operator++(int);

	friend ostream& operator<<(ostream&, MyComplex);

	MyComplex& operator=(const MyComplex&);

	friend istream& operator>>(istream&, MyComplex&);
};

MyComplex::MyComplex() = default;

MyComplex::MyComplex(double RealPart_, double ImagePart_) {
	this->RealPart = RealPart_;
	this->ImagePart = ImagePart_;
}

string MyComplex::toString() {
	if (0 > this->ImagePart)
		return std::to_string(this->RealPart) + std::to_string(this->ImagePart) + 'i';
	else
		return std::to_string(this->RealPart) + '+' + std::to_string(this->ImagePart) + 'i';
}

MyComplex MyComplex::operator+(const MyComplex & mycomplex2_) {
	return MyComplex(this->RealPart + mycomplex2_.RealPart, this->ImagePart + mycomplex2_.ImagePart);
}

MyComplex MyComplex::operator-(const MyComplex & mycomplex2_) {
	return MyComplex(this->RealPart - mycomplex2_.RealPart, this->ImagePart - mycomplex2_.ImagePart);
}

MyComplex MyComplex::operator*(const MyComplex& mycomplex2_) {
	double r_ = this->RealPart * mycomplex2_.RealPart - this->ImagePart * mycomplex2_.ImagePart;
	double i_ = this->ImagePart * mycomplex2_.RealPart + this->RealPart * mycomplex2_.ImagePart;
	return MyComplex(r_, i_);
}

MyComplex MyComplex::operator/(MyComplex& mycomplex2_) {
	if (mycomplex2_[0] == 0 && mycomplex2_[1] == 0) {
		throw runtime_error("Divisor is 0");
	}
	double cd = mycomplex2_[0] * mycomplex2_[0] + mycomplex2_[1] * mycomplex2_[1];
	double r_ = this->RealPart * mycomplex2_.RealPart + this->ImagePart * mycomplex2_.ImagePart;
	double i_ = this->ImagePart * mycomplex2_.RealPart - this->RealPart * mycomplex2_.ImagePart;
	return MyComplex(r_ / cd, i_ / cd);
}

MyComplex& MyComplex::operator+=(const MyComplex & mycomplex2_) {
	*this = this->operator+(mycomplex2_);
	return *this;
}

double& MyComplex::operator[](int x_) {
	if (0 == x_)
		return this->RealPart;
	else if (1 == x_)
		return this->ImagePart;
	else {
		std::cout << "error!\n";
		std::exit(0);
	}
}

MyComplex& MyComplex::operator++() {
	*this = MyComplex(this->RealPart + 1, this->ImagePart + 1);
	return *this;
}

MyComplex MyComplex::operator++(int dummy) {
	MyComplex temp{ *this };
	*this = MyComplex(this->RealPart + 1, this->ImagePart + 1);
	return temp;
}

ostream& operator<<(ostream & os, MyComplex mycomplex_) {
	os << '(' << noshowpos << mycomplex_[0] << showpos << mycomplex_[1] << "i)";
	return os;
}

MyComplex& MyComplex::operator=(const MyComplex & mycomplex_) {
	this->RealPart = mycomplex_.RealPart;
	this->ImagePart = mycomplex_.ImagePart;
	return *this;
}

istream& operator>>(istream & is, MyComplex & mycomplex_) {
	double r_, i_;
	cin >> r_ >> i_;
	mycomplex_.RealPart = r_;
	mycomplex_.ImagePart = i_;
	return is;
}

int main() {
	MyComplex z1, z2;
	std::cin >> z1;
	std::cin >> z2;
	try {
		std::cout << "z1 + z2 = " << z1 + z2 << std::endl;
		std::cout << "z1 - z2 + z1 = " << z1 - z2 + z1 << std::endl;
		std::cout << "z1 * z2 - z1 = " << z1 * z2 - z1 << std::endl;
		if (z2[0] != 0 || z2[1] != 0)
			std::cout << "z1 / z2 + z1 = ";
		std::cout << z1 / z2 + z1 << std::endl;
		if (z1[0] != 0 || z1[1] != 0)
			std::cout << "z2 - z1 / z1 = ";  // 本语句不可与下一句放在一起
		// 否则异常时的输出信息依赖于系统库实现
		std::cout << z2 - z1 / z1 << std::endl;
		std::cout << "Finished";
	}
	catch (exception& e) {  // catch父类异常类型，也可以捕获子类异常
		std::cout << e.what()
			<< std::endl;  // what()函数将存放在异常对象中的信息取出来
		std::cout << "Unexpected Error";
	}

	// GCC及VC编译器在调试模式下会暂停，便于查看运行结果
#if (defined(__DEBUG__) || defined(_DEBUG))
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
#endif
	return 0;
}