#include<iostream>
#include<array>
using std::array;
using std::cout;
using std::cin;
using std::endl;
int main(void)
{
	array <int,4>a1;
	cin >> a1[0] >> a1[1] >> a1[2];
	cout << "a1: ";
	for (int x : a1)
		cout << x << ' ';
	cout << endl;
	array <int, 4>b1;
	cin >> b1[0] >> b1[1] >> b1[2]>>b1[3];
	cout << "b1: ";
	for (int x : b1)
		cout << x << ' ';
	cout << endl;
	a1.swap(b1);
	cout << "a1: ";
	for (int x : a1)
		cout << x << ' ';
	cout << endl;
	cout << "b1: ";
	for (int x : b1)
		cout << x << ' ';
	cout << endl;
	return 0;
}