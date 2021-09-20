#include"Person.h"
int Person::count = 0;
Person::Person() :Person("zyh-hehe","4008208820","4001234567") {};
Person::Person(std::string name, std::string phone1, std::string phone2) {
	this->name = new std::string(name);
	phonelist.push_back(phone1);
	phonelist.push_back(phone2);
	count++;
}
Person::Person(const Person& p) {
	this->name = new std::string(*(p.name));
	phonelist.push_back(p.phonelist[0]);
	phonelist.push_back(p.phonelist[1]);
	count++;
}
int Person::getCount(void) {
	return this->count;
}

std::string Person::getName() {
	return *(this->name);
}
void Person::setName(std::string name) {
	this->name = new std::string(name);
}
Person::~Person() {
	count--;
	delete name;
	name = nullptr;
}

int readCount(Person& p) {
	return p.getCount();
}

std::string Person::getPerson() {
	return *name + ' ' + phonelist[0] + ' ' + phonelist[1];
}