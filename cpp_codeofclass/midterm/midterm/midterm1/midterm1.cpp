#include<iostream>
#include<string>
#include"Traveler.h"
#include"Pager.h"
#include"BusinessTraveler.h"

using std::cout;
using std::cin;
using std::string;

//class Traveler {
//private:
//	string NameOfTraveler;
//public:
//	Traveler() = delete;
//	
//	Traveler(string NameOfTraveler_) {
//		this->NameOfTraveler = NameOfTraveler_;
//	}
//	
//	Traveler(Traveler& traveler_) {
//		this->NameOfTraveler = traveler_.getNameOfTraveler();
//	}
//	
//	string getNameOfTraveler()const {
//		return this->NameOfTraveler;
//	}
//	
//	void setNameOfTraveler(string NameOfTraveler_) {
//		this->NameOfTraveler = NameOfTraveler_;
//	}
//};

//class Pager {
//private:
//	string NumberOfPager;
//public:
//	Pager() = delete;
//	
//	Pager(string NumberOfPager_) {
//		this->NumberOfPager = NumberOfPager_;
//	}
//	
//	Pager(Pager& pager_) {
//		this->NumberOfPager = pager_.getNumberOfPager();
//	}
//	
//	string getNumberOfPager()const {
//		return this->NumberOfPager;
//	}
//	
//	void setNumberOfPager(string& NumberOfPager_) {
//		this->NumberOfPager = NumberOfPager_;
//	}
//};

//class BusinessTraveler :public Traveler {
//private:
//	Pager PagerOfBusinessTraveler{ "4001234567" };
//public:
//	BusinessTraveler() :Traveler("xiaoming") {};
//
//	BusinessTraveler(string& NameOfBusinessTraveler_) :Traveler(NameOfBusinessTraveler_) {};
//
//	BusinessTraveler(string& NameOfBusinessTraveler_, string& NumberOfPagerOfBusinessTraveler_)
//		:Traveler(NameOfBusinessTraveler_) {
//		this->PagerOfBusinessTraveler = Pager(NumberOfPagerOfBusinessTraveler_);
//	}
//	
//	BusinessTraveler(BusinessTraveler& businesstraveler_)
//		:Traveler(businesstraveler_.getNameOfTraveler()) {
//		this->PagerOfBusinessTraveler = Pager(businesstraveler_.PagerOfBusinessTraveler.getNumberOfPager());
//	}
//	
//	string BusinessTravelerToString()const {
//		return this->PagerOfBusinessTraveler.getNumberOfPager() + "  " + this->getNameOfTraveler();
//	}
//	
//	void setPagerOfBusinessTraveler(const Pager& pager_) {
//		this->PagerOfBusinessTraveler = pager_;
//	}
//
//	BusinessTraveler& operator=(const BusinessTraveler& bt_){
//		this->setNameOfTraveler(bt_.getNameOfTraveler());
//		this->PagerOfBusinessTraveler = Pager(bt_.PagerOfBusinessTraveler.getNumberOfPager());
//		return *this;
//	}
//};

int main(void) {
	//test the function in the class
	string name1{ "lilei" }, number1{ "123456" }, name2{ "hanmeimei" }, number2{ "654321" };
	BusinessTraveler b1{ name1,number1 };//test the constructor that takes two string arguments
	cout << b1.BusinessTravelerToString() << '\n';
	BusinessTraveler b2{ name2 }; //test the constructor that takes a string argument
	cout << b2.BusinessTravelerToString() << '\n';
	Pager p2{ number2 };//test the constructor that takes a string argument
	b2.setPagerOfBusinessTraveler(p2);
	cout << b2.BusinessTravelerToString() << '\n';
	b2 = b1; //test the overloading assignment operator function
	cout << b2.BusinessTravelerToString() << '\n';
	return 0;
}