#include "Person.h"
int main(void) {
	Person p1;
	std::cout << p1.getCount() << std::endl;
	Person p2("zyh-haha","15812341243","13843214321");
	std::cout << readCount(p2) << std::endl;
	Person p3(p1);
	fPerson fp;
	std::cout << fp.freadCount(p3) << std::endl;
	p3.setName("zyh-lala");
	std::cout << p1.getPerson() << std::endl;
	std::cout << p2.getPerson() << std::endl;
	std::cout << p3.getPerson() << std::endl;
	bool isInTheList1 = false;
	for (auto x : p2.getPhonelist()) {
		if (x==("15812341243")) {
			isInTheList1 = true;
		}
	}
	std::cout << std::boolalpha << isInTheList1 << std::endl;
	bool isInTheList2 = false;
	for (auto x : p2.getPhonelist()) {
		if (x==("1581234")) {
			isInTheList2 = true;
		}
	}
	std::cout << std::boolalpha << isInTheList2 << std::endl;
	return 0;
}

















