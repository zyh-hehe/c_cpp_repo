#pragma once
#include"Pager.h"
#include"Traveler.h"

class BusinessTraveler :public Traveler {
private:
	Pager PagerOfBusinessTraveler{ "4001234567" };
public:
	BusinessTraveler();

	BusinessTraveler(string& NameOfBusinessTraveler_);

	BusinessTraveler(string& NameOfBusinessTraveler_, string& NumberOfPagerOfBusinessTraveler_);

	BusinessTraveler(BusinessTraveler& businesstraveler_);

	string BusinessTravelerToString()const;

	void setPagerOfBusinessTraveler(const Pager& pager_);

	BusinessTraveler& operator=(const BusinessTraveler& bt_);
};