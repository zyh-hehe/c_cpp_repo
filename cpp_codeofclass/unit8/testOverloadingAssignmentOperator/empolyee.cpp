#include<iostream>
#include"employee.h"
#include<string>
using std::string;
employee::employee() :employee("John", Gender::male, Date()) {/*Ĭ�Ϲ��캯����ʹ����ί�й���*/ }
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
		std::cout << "��һ������ָ�뱻�ͷ���" <<std:: endl;
		//����Ҫ�ر�ע�⣺�����ͷ�һ���Ѿ����ͷŵ���ָ�룡����
		//��ǳ����������£���������ȥ����һ����ַ�������µĶ����е�ָ��ֱ�Ӹĳ��˿��������ָ�롣
		//֮����ִ����������ʱ�������¶����ȱ�������ָ��Ҳ��֮�ͷŵ��ˣ�
		//��������������ָ����Ǹ����ͷŵ���ָ�룬�ͷ�����һ��Ұָ��ᵼ�³��������
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