#pragma once
class Pager {
private:
	string NumberOfPager;
public:
	Pager() = delete;

	Pager(string NumberOfPager_);

	Pager(Pager& pager_);

	string getNumberOfPager()const;

	void setNumberOfPager(string& NumberOfPager_);
};