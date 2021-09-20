#include<iostream>
#include"employee.h"
#include<string>
using std::string;
employee::employee() :employee("John", Gender::male, Date()) {/*默认构造函数，使用了委托构造*/ }
employee::employee(string name, Gender gender, Date birthday)
{
	this->name = name;
	this->gender = gender;
	this->birthday = new Date(birthday);
	NumberOfEmployee++;
}
string employee::getName() { return name; }
Gender employee::getGender() { return gender; }
Date* employee::getBirthday() { return birthday; }
void employee::setName(string name) { this->name = name; }
void employee::setGender(Gender gender) { this->gender = gender; }
void employee::setBirthday(Date birthday) {this->birthday = &birthday; }
string employee::EmployeeToString()
{
	return (name + "\t"
		+ (gender == Gender::male ? string("male") : string("female")) + "\t"
		+ birthday->DateToString());
}
employee::~employee() {
	NumberOfEmployee--;
		delete birthday;
		birthday = nullptr;
		std::cout << "有一个堆区指针被释放了" <<std:: endl;
		//这里要特别注意：不能释放一个已经被释放掉的指针！！！
		//在浅拷贝的情况下，被拷贝过去的是一个地址，即把新的对象中的指针直接改成了拷贝对象的指针。
		//之后在执行析构函数时，由于新对象先被析构，指针也随之释放掉了，
		//那这个拷贝对象的指针就是个被释放掉的指针，释放这样一个野指针会导致程序崩溃！
}
employee::employee(const employee& s)
{
	this->birthday = new Date{*(s.birthday)};
	this->gender = s.gender;
	this->name = s.name;
	NumberOfEmployee++;
}
employee& employee::operator=(const employee& s) {
	*(this->birthday) = *(s.birthday);
	this->gender = s.gender;
	this->name = s.name;
	NumberOfEmployee++;
	return *this;
}