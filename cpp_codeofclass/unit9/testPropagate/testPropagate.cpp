#include<iostream>
using namespace std;
class e1{};
class e2{};
class e3{};

void f3() {//�ֱ�ȡ���⼸�е�ע�ͣ����������Բ��򿪵���-����-���ö�ջ�����ᷢ��ʲô��
	//throw std::exception();
	//throw e1();
	throw e2();
	//throw e3();
}

void f2() {
	try {
		f3();
		cout << "f2()" << endl;
	}
	catch (e2& e) {
		cout << "catch f3()" << endl;
	}
}

void f1() {
	try {
		f2();
		cout << "f1" << endl;
	}
	catch (e1& e) {
		cout << "catch f2()" << endl;
	}
}

int main(void) {
	try {
		f1();
		cout << "main" << endl;
	}
	catch(const std::exception& e){
		cout << "catch f1()" << endl;
	}
}
