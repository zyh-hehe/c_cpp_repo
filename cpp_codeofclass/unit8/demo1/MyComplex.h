#pragma once
#include<iostream>
#include<string>
#include<ostream>
using std::ostream;
using std::string;
class MyComplex {
private:
	int RealPart{ 1 };
	int ImagePart{ 1 };
public:
	MyComplex();

	MyComplex(int, int);

	string toString();

	MyComplex operator+(const MyComplex&);

	MyComplex& operator+=(const MyComplex&);

	int& operator[](int);

	MyComplex& operator++();

	MyComplex operator++(int);

	friend ostream& operator<<(ostream&, MyComplex);

	MyComplex& operator=(const MyComplex&);
};