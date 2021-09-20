#include"MyComplex.h"
using std::string;

MyComplex::MyComplex() = default;

MyComplex::MyComplex(int RealPart_, int ImagePart_) {
	this->RealPart = RealPart_;
	this->ImagePart = ImagePart_;
}

string MyComplex::toString() {
	if(0>this->ImagePart)
		return std::to_string(this->RealPart) + std::to_string(this->ImagePart) + 'i';
	else 
		return std::to_string(this->RealPart) + '+' + std::to_string(this->ImagePart) + 'i';
}

MyComplex MyComplex::operator+(const MyComplex& mycomplex2_) {
	return MyComplex(this->RealPart + mycomplex2_.RealPart, this->ImagePart + mycomplex2_.ImagePart);
}

MyComplex& MyComplex::operator+=(const MyComplex& mycomplex2_) {
	*this = this->operator+(mycomplex2_);
	return *this;
}

int& MyComplex::operator[](int x_) {
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

ostream& operator<<(ostream& os, MyComplex mycomplex_) {
	os << mycomplex_.toString();
	return os;
}

MyComplex& MyComplex::operator=(const MyComplex& mycomplex_) {
	this->RealPart = mycomplex_.RealPart;
	this->ImagePart = mycomplex_.ImagePart;
	return *this;
}