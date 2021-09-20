#include<iostream>
#include<string>
#include"Date.h"
#include"employee.h"
int employee::NumberOfEmployee;
int main(void)
{
	employee e1;
	std::cout << e1.EmployeeToString() << std::endl;
	std::cout << "number of employee = " << employee::NumberOfEmployee << std::endl;
	{
		employee e2{ "Alan",Gender::famale,Date{1991,1,2} };
		std::cout << e2.EmployeeToString() << std::endl;
		std::cout << "number of employee = " << employee::NumberOfEmployee << std::endl;
	}
	std::cout << "number of employee = " << employee::NumberOfEmployee << std::endl;
	return 0;
}