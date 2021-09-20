#include<iostream>
int main(void){
	auto ptr{ std::cin.rdbuf() };
	auto x = std::cin.peek();
	std::cout << "x=" << x << std::endl;
	std::cout << "there is(are) " << ptr->in_avail() << " character(s) in the buffer" << std::endl;
	int count = ptr->in_avail();
	for (int i = 0; i < count; i++) {
		std::cout << i + 1 << " : " << std::cin.get() << std::endl;
	}
	return 0;
}