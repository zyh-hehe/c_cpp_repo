#include"BusinessTraveler.h"

BusinessTraveler::BusinessTraveler() :Traveler("xiaoming") {};

BusinessTraveler::BusinessTraveler(string& NameOfBusinessTraveler_) :Traveler(NameOfBusinessTraveler_) {};

BusinessTraveler::BusinessTraveler(string& NameOfBusinessTraveler_, string& NumberOfPagerOfBusinessTraveler_)
	:Traveler(NameOfBusinessTraveler_) {
	this->PagerOfBusinessTraveler = Pager(NumberOfPagerOfBusinessTraveler_);
}

BusinessTraveler::BusinessTraveler(BusinessTraveler& businesstraveler_)
	:Traveler(businesstraveler_.getNameOfTraveler()) {
	this->PagerOfBusinessTraveler = Pager(businesstraveler_.PagerOfBusinessTraveler.getNumberOfPager());
}

string BusinessTraveler::BusinessTravelerToString()const {
		return this->PagerOfBusinessTraveler.getNumberOfPager() + "  " + this->getNameOfTraveler();
}

void BusinessTraveler::setPagerOfBusinessTraveler(const Pager& pager_) {
	this->PagerOfBusinessTraveler = pager_;
}

BusinessTraveler& BusinessTraveler::operator=(const BusinessTraveler& bt_) {
	this->setNameOfTraveler(bt_.getNameOfTraveler());
	this->PagerOfBusinessTraveler = Pager(bt_.PagerOfBusinessTraveler.getNumberOfPager());
	return *this;
}
