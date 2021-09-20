#include<iostream>
#include<ctime>
#include"twoclass.h"
using std::cout;

//class father {
//private:
//public:
//	int a{ 0 };
//	father() = default;
//	virtual void vfprint(int i) {
//		a = i;
//	}
//	void ifprint(int i) {
//		a = i;
//	}
//};
//
//class son :public father {
//private:
//public:
//	int b{ 0 };
//	son() = default;
//	void vfprint(int i)override {
//		b = i;
//	}
//};

int main(void) {
	clock_t start1, start2, end1, end2;
	double duration1, duration2;
	son* s1 = new son();
	father* f1=dynamic_cast<father*>(s1);

	start1 = clock();
	for(int i=0;i< 1000000000;i++)
		f1->vfprint(i);
	s1->a = s1->b;
	end1 = clock();
	duration1 = (double)(static_cast<double>(end1) - static_cast<double>(start1)) / CLK_TCK;
	cout << "invoking virtual function \"vfprint()\" for 1000000000 times takes " << duration1 << " seconds!\n";

	start2 = clock();
	for (int i = 0; i < 1000000000; i++)
		f1->ifprint(i);
	s1->a = s1->b;
	end2 = clock();
	duration2 = (double)(static_cast<double>(end2) - static_cast<double>(start2)) / CLK_TCK;
	cout << "invoking non-virtual function \"ifprint()\" for 1000000000 times takes " << duration2 << " seconds!\n";

	return 0;
}