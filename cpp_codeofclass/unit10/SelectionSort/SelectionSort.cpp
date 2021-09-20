#include<iostream>
#include<array>
void selectionsort(double list[] , std::size_t size) {//这里不需要传引用，是因为传进来的参数是一个指针
	for (int i = 0; i < size - 1; i++){
		double min = list[i];
		int index = i;
		for (int j = i + 1; j < size; j++) {
			if (min >= list[j]){
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

