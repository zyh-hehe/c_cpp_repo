#pragma once
#include<iostream>
#include<array>
void selectionsort(double[], std::size_t);
//模板函数和它的声明需要放在一起，都要放在一个头文件里
template <int N>
void selectionsort(std::array<double, N>& list) {//这里需要传一个引用，因为array是一个对象，如果不传引用的话会导致实参没有发生变化
	constexpr int size = N;
	for (int i = 0; i < size - 1; i++) {
		double min = list[i];
		int index = i;
		for (int j = i + 1; j < size; j++) {
			if (min >= list[j]) {
				min = list[j];
				index = j;
			}
		}
		if (index != i) {
			list[index] = list[i];
			list[i] = min;
		}
	}
}
