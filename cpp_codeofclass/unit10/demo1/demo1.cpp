#include"templatedemo.h"
#include<ostream>

class hehe {
public:
	double haha = 1.0;
	hehe(double a) {
		this->haha = a;
	}
	friend std::ostream& operator<<(std::ostream&, hehe&);
};

std::ostream& operator<<(std::ostream& o, hehe& hehe_) {
	o << hehe_.haha;
	return o;
}

int main(void) {
	int a{ 11 }, b{ 12 };
	cout << add(a, b) << endl;
	int arr[5]{ 0,1,2,3,4 };
	print(arr, 5);
	reverse(arr, 5);
	print(arr, 5);
	cout << sizeof(arr)/sizeof(arr[0]) << endl;
	double arr1[4]{ 0.4,2.1,4.2,1.3 };
	print(arr1, 4);
	reverse(arr1, 4);
	print(arr1, 4);
	hehe arr2[5]{ 1.1,2.2,3.3,4.4,5.5 };
	print(arr2, 5);
	reverse(arr2, 5);
	print(arr2, 5);
	Array<int> arr3{ arr,5 };
	arr3.print();
	arr3.reverse();
	arr3.print();
	cout << arr3.sum() << endl;
	cout << arr3.seek(3) << endl;
	cout << arr3.seek(10) << endl;
	return 0;
}