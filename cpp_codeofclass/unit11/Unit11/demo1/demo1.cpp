#include<iostream>
#include<deque>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<string>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(void) {
	deque<int> c1;
	for (int i = 1; i <= 10; i = i + 2)
		c1.push_front(i);
	for (int i = 8; i >= 0; i = i - 2)
		c1.push_back(i);
	for (auto x : c1)
		cout << x << ' ';
	cout << endl;
	set<int> c2;
	for (auto x : c1)
		c2.insert(x);
	for (int i = 11; i < 20; i = i + 2)
		c2.insert(i);
	cout << c2.size() << endl;
	for (auto x : c2)
		cout << x << ' ';
	cout << endl;
	vector<int> v1, v2;
	for (auto x : c2)
		v1.push_back(x);
	v2 = v1;
	reverse(v2.begin(), v2.end());
	for (auto x : v2)
		cout << x << ' ';
	cout << endl;
	auto it1 = v2.begin() + 5;
	cout << "v2[5]:" << *it1 << endl;
	cout << "insert 21 before v2[5]:";
	v2.insert(it1, 21);
	for (auto x : v2)
		cout << x << ' ';
	cout << endl;
	srand((unsigned)time(NULL));
	int rv = rand() % (v1.size() - 1);
	auto it2 = v1.begin() + rv;
	cout << "v1[" << rv << "]:" << *it2 << endl;
	v1.erase(it2);
	cout << "delete v1[" << rv << "]:";
	for (auto x : v1)
		cout << x << ' ';
	cout << endl;
	cout << "v1 > v2 ? : " << (v1 > v2 ? "true" : "false") << endl;
	vector<int> v3{ 1,2,3,4,5 };
	vector<int>::iterator it3 = v3.begin();
	v3.erase(it3);
	it3 = v3.begin();
	cout << *it3 << endl;
}