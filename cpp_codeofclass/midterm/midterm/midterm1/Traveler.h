#pragma once
#include<string>
using std::string;

class Traveler {
private:
	string NameOfTraveler;
public:
	Traveler() = delete;

	Traveler(string NameOfTraveler_);

	Traveler(Traveler& traveler_);

	string getNameOfTraveler()const;

	void setNameOfTraveler(string NameOfTraveler_);
};