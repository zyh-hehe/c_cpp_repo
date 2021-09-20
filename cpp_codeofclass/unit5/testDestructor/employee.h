#pragma once
#include<iostream>
#include<string>
#include "Date.h"
enum class Gender{male,famale,};
class employee
{
private:
	string name;
	Gender gender;
	Date* birthday;
public:
	static int NumberOfEmployee;
	employee():employee("John",Gender::male,Date()) {/*默认构造函数，使用了委托构造*/ }
	employee(string name, Gender gender, Date birthday)
	{
		this->name = name;
		this->gender = gender;
		this->birthday = new Date(birthday);
		NumberOfEmployee++;
	}
	string getName() { return name ; }
	Gender getGender() { return gender ; }
	Date getBirthday() { return *birthday; }
	void setName(string name) { this->name = name ; }
	void setGender(Gender gender) { this->gender = gender ; }
	void setBirthday(Date birthday) { *(this->birthday) = birthday ; }
	string EmployeeToString()
	{
		return (name + "\t"
			+(gender==Gender::male?string("male"):string("female"))+ "\t"
			+birthday->DateToString());
	}
	~employee() { 
		NumberOfEmployee-- ; 
		delete birthday;
		birthday = nullptr;
	}
};