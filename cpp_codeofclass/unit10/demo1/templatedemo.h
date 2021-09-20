#pragma once
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

template <typename T>
T& add(T op1, T op2) {
	T op3 = op1 + op2;
	return op3;
}

template <typename T>
T* reverse(T a[], int length) {
	for (int i{ 0 }, j{ length - 1 }; i <= j; i++, j--) {
		T temp{ a[i] };
		a[i] = a[j];
		a[j] = temp;
	}
	return a;
}

template <typename T>
void print(T a[], int length) {
	for (int i{ 0 }; i < length; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

template <typename T = int>
class Array {
private:
	T* a;
	int length;
public:
	Array() = delete;
	Array(T* a_, int length_) {
		this->a = a_;
		this->length = length_;
	}
	T sum() {
		T temp{ 0 };
		for (int i{ 0 }; i < length; i++) {
			temp += a[i];
		}
		return temp;
	}
	T* reverse() {
		for (int i{ 0 }, j{ length - 1 }; i <= j; i++, j--) {
			T temp{ a[i] };
			a[i] = a[j];
			a[j] = temp;
		}
		return a;
	}
	void print() {
		for (int i{ 0 }; i < length; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
	int seek(T key) {
		for (int i = 0; i < length - 1; i++) {
			if (key == a[i])
				return i;
		}
		return -1;
	}
};
