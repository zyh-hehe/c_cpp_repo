#pragma once
#include<iostream>
#include<array>

//模板函数和它的声明需要放在一起，都要放在一个头文件里
template <typename T>
void selectionsort(T list[], const std::size_t size) {//这里不需要传引用，是因为传进来的参数是一个指针
	for (int i = 0; i < size - 1; i++) {
		T min = list[i];
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

//模板函数和它的声明需要放在一起，都挺要放在一个头文件里
template <typename T,int N>
void selectionsort(std::array<T, N>& list) {//这里需要传一个引用，因为array是一个对象，如果不传引用的话会导致实参没有发生变化
	constexpr int size = N;
	for (int i = 0; i < size - 1; i++) {
		T min = list[i];
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
