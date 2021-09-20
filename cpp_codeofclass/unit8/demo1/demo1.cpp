#include"MyComplex.h"

int main(void) {
	MyComplex mc1(-2, -2);
	std::cout << mc1 << std::endl;
	mc1++;
	std::cout << mc1 << std::endl;
	MyComplex mc2 = mc1++;
	MyComplex mc3 = ++mc1;
	std::cout << mc1 << std::endl;
	std::cout << mc2 << std::endl;
	std::cout << mc3 << ' ' << mc3[0] << ' ' << mc3[1] << std::endl;
	std::cin.get();
	std::cout << mc3[2] << std::endl;
	return 0;
}