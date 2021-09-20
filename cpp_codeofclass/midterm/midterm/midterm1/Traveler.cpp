#include"Traveler.h"

	Traveler::Traveler(string NameOfTraveler_) {
		this->NameOfTraveler = NameOfTraveler_;
	}

	Traveler::Traveler(Traveler& traveler_) {
		this->NameOfTraveler = traveler_.getNameOfTraveler();
	}

	string Traveler::getNameOfTraveler()const {
		return this->NameOfTraveler;
	}

	void Traveler::setNameOfTraveler(string NameOfTraveler_) {
		this->NameOfTraveler = NameOfTraveler_;
	}
