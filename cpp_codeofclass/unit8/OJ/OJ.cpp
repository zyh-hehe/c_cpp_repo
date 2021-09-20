#include <iostream>
#include<algorithm>
#include<array>
using namespace std;

bool cmp(int a, int b) {
	return a < b;
}

int main(void) {
	int a[10]{ 9,8,7,6,5,4,3,2,1,0 };
	int* p = find(a, a+10, 4);
	if (((p - a) != 10) && (*p == 4))
		cout << (p - a + 1);
	return 0;
}