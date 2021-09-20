#pragma once
template <typename T = char, int N = 100>//默认类为char，数组大小为100
class stack {
private:
	int size{ 0 };
	T elements[N]{};
public:
	stack();
	bool empty();
	T peek();
	T pop();
	T push(T value);
	int getSize();
};

template <typename T, int N>
stack<T,N>::stack() {
	int size = 0;
	for (auto& x : elements) {
		x = 0;
	}
}

template <typename T, int N>
bool stack<T,N>::empty() {
	return (size == 0);
}

template <typename T, int N>
T stack<T,N>::peek() {
	return elements[size - 1];
}

template <typename T, int N>
T stack<T,N>::pop() {
	T temp = peek();
	size -= 1;
	return temp;
}

template <typename T, int N>
T stack<T,N>::push(T value) {
	size += 1;
	elements[size - 1] = value;
	return value;
}

template <typename T, int N>
int stack<T,N>::getSize() {
	return size;
}
