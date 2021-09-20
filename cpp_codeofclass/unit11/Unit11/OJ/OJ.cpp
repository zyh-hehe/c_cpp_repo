#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(void) {
	string s;
	vector<int> v;
	std::getline(cin,s);
	string numbers{ "0123456789 -+" };
	size_t pos = 0, pos1 = 0;
	size_t posofc = s.find_first_not_of(numbers, pos);
	if (posofc != string::npos)
		s = s.substr(pos, posofc - 1);
	while (1) {
		size_t pos1 = s.find(' ', pos);
       if (string::npos == pos1) {
			v.push_back(stoi(s.substr(pos)));
			break;
		}
		v.push_back(stoi(s.substr(pos, pos1)));
		pos = pos1 + 1;
	}
	sort(v.begin(),v.end());
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
		cout << *i << endl;
	return 0;
}