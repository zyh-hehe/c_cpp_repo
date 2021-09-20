#include<iostream>

using namespace std;

int gcd(int r1, int r2) {
	if (r2 == 0 || r1 == 0)
		throw 0;
	return 0 != (r1 % r2) ? gcd(r2, r1 % r2) : r2;
}

int main(void) {
	int a, b;
	cin >> a >> b;
	try {
		cout << gcd(a, b) << endl;
	}
	catch (int r2) {
		cout << "r²»ÄÜÎª " << r2 << " !" << endl;
	}
	return 0;
}

