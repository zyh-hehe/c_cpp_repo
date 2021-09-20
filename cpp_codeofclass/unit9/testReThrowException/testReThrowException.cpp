#include<iostream>
#include<exception>
#include<stdexcept>
using namespace std;
void f() {
	try {
		throw logic_error("throw in f()");
	}
	catch(logic_error& e){
		cout << "catched in f()" << endl;
		cout << "exception:" << e.what() <<endl;
		throw;
	}
	catch (...) {
		cout << "yyhsb" << endl;
	}
}

int main(void){
	try {
		f();
	}
	catch (logic_error& e) {
        cout << "catched exception : " << e.what() << endl;
	}
}