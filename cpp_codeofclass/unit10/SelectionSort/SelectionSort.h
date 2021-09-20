#pragma once
#include<iostream>
#include<array>
void selectionsort(double[], std::size_t);
//ģ�庯��������������Ҫ����һ�𣬶�Ҫ����һ��ͷ�ļ���
template <int N>
void selectionsort(std::array<double, N>& list) {//������Ҫ��һ�����ã���Ϊarray��һ����������������õĻ��ᵼ��ʵ��û�з����仯
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
