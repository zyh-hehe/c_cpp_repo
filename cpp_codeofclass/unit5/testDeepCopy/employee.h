#pragma once
#include<iostream>
#include<string>
#include "Date.h"
enum class Gender { male, female, };
class employee
{
private:
	string name;
	Gender gender;
	Date* birthday;
public:
	static int NumberOfEmployee;
	employee();
	employee(string name, Gender gender, Date birthday);
	string getName();
	Gender getGender();
	Date* getBirthday();
	void setName(string name);
	void setGender(Gender gender);
	void setBirthday(Date birthday);
	string EmployeeToString();
	~employee();
	employee(const employee& s);//重载拷贝构造函数以实现深拷贝
	employee& operator=(const employee& s);//重载赋值运算符以实现深拷贝
};
