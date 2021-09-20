#include<iostream>
#include<iomanip>
#include<array>
#include"GenericSort.h"
double a[]{ 9.0,8.0,7.0,6.0,5.0,4.0,3.0,2.0,1.0 };
std::array b{ 9.0,8.0,7.0,6.0,5.0,4.0,3.0,2.0,1.0 };//需要c++17才能不明确类型和大小
int main(void) {
	for (auto x : a) {
		std::cout << std::setprecision(1) << std::fixed << x << "  ";
	}
	std::cout << "\n";
	selectionsort(a, sizeof(a) / sizeof(a[0]));
	for (auto x : a) {
		std::cout << std::setprecision(1) << std::fixed << x << "  ";
	}
	std::cout << "\n";

	for (auto x : b) {
		std::cout << std::setprecision(1) << std::fixed << x << "  ";
	}
	std::cout << "\n";
	selectionsort(b);
	for (auto x : b) {
		std::cout << std::setprecision(1) << std::fixed << x << "  ";
	}
	std::cout << "\n";
}