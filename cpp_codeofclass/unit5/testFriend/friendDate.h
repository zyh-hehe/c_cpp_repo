#pragma once
#include<iostream>
#include<string>
using std::string;
class Date
{
private:
	int year, month, date;
public:
	Date() : Date(2002, 1, 1)  {/*默认构造函数，使用了委托构造*/} 
	Date(int year,int month,int date)
	{
		this->year = year;
		this->month = month;
		this->date = date;
	}
	int getYear() { return year ; }
	int getMonth() { return month ; }
	int getDate() { return date ; }
	void setDate(int date) { this->date = date ; }
	void setMonth(int month) { this->month = month ; }
	void setYear(int year) { this->year = year ; }
	string DateToString()
	{
		return (std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(date));
	}
};
