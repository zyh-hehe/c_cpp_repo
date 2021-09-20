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
	employee(const employee& s);//���ؿ������캯����ʵ�����
	employee& operator=(const employee& s);//���ظ�ֵ�������ʵ�����
};
