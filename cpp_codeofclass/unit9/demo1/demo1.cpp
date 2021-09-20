#include<iostream>
#include<Windows.h>
#include<new>
#include<stdexcept>
#include<string>
using namespace std;

class MyBadAlloc :public bad_alloc {
private:
public:
	MyBadAlloc() = default;
	const char* what()const override {
		return "MyBadAlloc : bad allocation";
	}
};
void f() {
	try {
		while (1)
			auto* p = new long long int[100000000];
	}
	catch (bad_alloc& b) {
			cout << b.what() << endl;
			throw/* MyBadAlloc()*/;
	}
	while(1)
		auto* p = new long long int[10000000];
	throw 0;
}

int main(void) {
	try {
		f();
	}
	catch (MyBadAlloc& b) {
		cout << b.what() << endl;
	}
	catch (bad_alloc& b) {
		cout << b.what() << endl;
	}
	catch (int b) {
		cout << b << endl;
	}
	return 0;
}