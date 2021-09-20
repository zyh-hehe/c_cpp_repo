#pragma once
template <typename T>
class stack {
private:
	int size{ 0 };
	T elements[100]{};
public:
	stack();
	bool empty();
	T peek();
	T pop();
	T push(T value);
	int getSize();
};

template <typename T>
stack<T>::stack() {
	int size = 0;
	for (auto& x : elements) {
		x = 0;
	}
}

template <typename T>
bool stack<T>::empty() {
	return (size == 0);
}

template <typename T>
T stack<T>::peek() {
	return elements[size - 1];
}

template <typename T>
T stack<T>::pop() {
	T temp = peek();
	size -= 1;
	return temp;
}

template <typename T>
T stack<T>::push(T value) {
	size += 1;
	elements[size-1] = value;
	return value;
}

template <typename T>
int stack<T>::getSize() {
	return size;
}