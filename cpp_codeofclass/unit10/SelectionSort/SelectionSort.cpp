#include<iostream>
#include<array>
void selectionsort(double list[] , std::size_t size) {//���ﲻ��Ҫ�����ã�����Ϊ�������Ĳ�����һ��ָ��
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

