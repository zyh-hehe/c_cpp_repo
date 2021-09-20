#include<string>
#include"Pager.h"
using std::string;
Pager::Pager(string NumberOfPager_) {
		this->NumberOfPager = NumberOfPager_;
	}

Pager::Pager(Pager& pager_) {
		this->NumberOfPager = pager_.getNumberOfPager();
	}

string Pager::getNumberOfPager()const {
	return this->NumberOfPager;
}

void Pager::setNumberOfPager(string& NumberOfPager_) {
	this->NumberOfPager = NumberOfPager_;
}