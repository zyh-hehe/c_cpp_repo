#include<iostream>
#include<string>
#include"Date.h"
#include"employee.h"
int employee::NumberOfEmployee;
int main(void)
{
	employee e1;
	std::cout << e1.EmployeeToString() << std::endl;
	employee e2{ "Alan",Gender::female,Date{1991,1,2} };
	std::cout << e2.EmployeeToString() << std::endl;
	employee e3{ e1 };
	std::cout << e3.EmployeeToString() << std::endl;
	std::cout << "Now there are " << employee::NumberOfEmployee << " employees" << std::endl;
	*(e3.getBirthday())= Date{ 2001,1,2 };
	std::cout << e3.EmployeeToString() << std::endl;
	employee e4{ "Alan",Gender::female,Date{1991,1,2} };
	std::cout << e4.EmployeeToString() << std::endl;
	std::cout << "Now there are " << employee::NumberOfEmployee << " employees" << std::endl;
	e4 = e3;
	std::cout << "Now there are " << employee::NumberOfEmployee << " employees" << std::endl;
	std::cout << e4.EmployeeToString() << std::endl;
	std::cout << "Now there are " << employee::NumberOfEmployee << " employees" << std::endl;
	//std::cin.get();
	return 0;
}