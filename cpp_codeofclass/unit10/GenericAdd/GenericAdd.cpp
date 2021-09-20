#include<iostream>
using namespace std;
template <typename T, typename S>
S add(T x1, S x2) {
	return (x1 + x2);
}
template double add(int, double);
int main(void) {
	int a = 1;
	double b = 2.1;
	printf("%lf\n", add(a,b));
	return 0;
}