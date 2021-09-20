#include<iostream>
#include<deque>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<string>
using namespace std;

int main(void) {
	map<int, string> m1;
	m1[1809] = "zyh-hehe";
	m1[1810] = "abc";
	m1[2059] = "cba";
	m1[1234] = "void1";
	m1[4321] = "void2";
	auto it1 = m1.begin();
	for (int i = 0; i < 7; i++, it1++) {
		cout << it1->first << ' ' << (*it1).second << endl;
	}
	long int a;
	while (1) {
		cout << "please input a number:";
		cin >> a;
		if (0 == a)
			break;
		auto it2 = m1.find(a);
		if (m1.end() == it2)
			cout << "student " << a << " does not exist!" << endl;
		else
			cout << "student " << a <<" \'s name: "<< it2->second << endl;
	}
	return 0;
}