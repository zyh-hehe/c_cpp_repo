#include<iostream>
#include<vector>
using namespace std;
class Animal {
public:
	Animal() {
		cout << "Animal" << endl;
	}
	virtual void speak()=0;
};

class Dog : public Animal {
public:
	Dog() {
		cout << "Dog" << endl;
	}
	void speak() {
		cout << "wang" << endl;
	}
};

class Cat :public Animal {
public:
	Cat() {
		cout << "Cat" << endl;
	}
	void speak() {
		cout << "miao" << endl;
	}
};

int main(void) {
	vector<Animal*> v;
	int a;
	cin >> a;
	for (int i = 0; i < a; i++) {
		Dog d;
		v.push_back(&d);
		Cat c;
		v.push_back(&c);
	}
	for (int i = 0; i < 2 * a; i++) {
		v[i]->speak();
	}
	return 0;
}
