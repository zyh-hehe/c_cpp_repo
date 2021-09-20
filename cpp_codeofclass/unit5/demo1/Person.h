#pragma once
#include<iostream>
#include<string>
#include<vector>
class Person {
private:
	static int count;
	std::string* name;
	std::vector<std::string> phonelist;
public:
	friend class fPerson;
	Person();
	Person(std::string name,std::string phone1,std::string phone2);
	Person(const Person&);
	int getCount(void); 
	static int sgetCount(void) {
		return count;
	}
	std::string getName();
	void setName(std::string name);
	~Person();
	friend int readCount(Person&);
	std::string getPerson();
	std::vector<std::string> getPhonelist() {
		return this->phonelist;
	}
};

class fPerson {
public:
	fPerson() = default;
	int freadCount(Person& p) {
		return p.getCount();
	}
};

