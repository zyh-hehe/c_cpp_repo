#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
#include<list>
#include<string>
using namespace std;

int main(void) {
	string s;
	deque<int> d;
	list<int> l1, l2;
	while (1) {
		std::getline(cin, s);
		string numbers{ "0123456789 -+" };
		string operators{ "-" };
		size_t pos = 0, pos1 = 0;
		size_t posofc = s.find_first_not_of(numbers, pos);
		size_t posofo = s.find_last_of(operators);
		if ("-" == s||s.empty())
			break;
        else if (posofo == s.size() - 1) {
			while (1) {
				s.erase(s.end() - 1);
				if (s.empty())
					break;
				if (*(s.end() - 1) != '-')
					break;
			}
			if ("-" == s || s.empty())
				break;
			size_t posofc = s.find_first_not_of(numbers, pos);
			if (posofc == 0)
				break;
			else if (posofc != string::npos) {
				s = s.substr(pos, posofc - 1);
				while (1) {
					size_t pos1 = s.find(' ', pos);
					if (string::npos == pos1) {
						if (0 == stoi(s.substr(pos)) % 2)
							d.push_back(stoi(s.substr(pos)));
						else
							d.push_front(stoi(s.substr(pos)));
						break;
					}
					else {
						if (0 == stoi(s.substr(pos, pos1)) % 2)
							d.push_back(stoi(s.substr(pos, pos1)));
						else
							d.push_front(stoi(s.substr(pos, pos1)));
						pos = pos1 + 1;
					}
					pos = pos1 + 1;
				}
				break;
			}
			while (1) {
				if (s.empty())
					continue;
				size_t pos1 = s.find(' ', pos);
				if (string::npos == pos1) {
					if (0 == stoi(s.substr(pos)) % 2)
						d.push_back(stoi(s.substr(pos)));
					else
						d.push_front(stoi(s.substr(pos)));
					break;
				}
				else {
					if (0 == stoi(s.substr(pos, pos1)) % 2)
						d.push_back(stoi(s.substr(pos, pos1)));
					else
						d.push_front(stoi(s.substr(pos, pos1)));
					pos = pos1 + 1;
				}
				pos = pos1 + 1;
			}
			break;
		}
		if (posofc == 0)
			break;
        else if (posofc != string::npos) {
			s = s.substr(pos, posofc - 1);
			while (1) {
				size_t pos1 = s.find(' ', pos);
				if (string::npos == pos1) {
					if (0 == stoi(s.substr(pos)) % 2)
						d.push_back(stoi(s.substr(pos)));
					else
						d.push_front(stoi(s.substr(pos)));
					break;
				}
				else {
					if (0 == stoi(s.substr(pos, pos1)) % 2)
						d.push_back(stoi(s.substr(pos, pos1)));
					else
						d.push_front(stoi(s.substr(pos, pos1)));
					pos = pos1 + 1;
				}
				pos = pos1 + 1;
			}
			break;
		}
		while (1) {
			if (s.empty())
				continue;
			size_t pos1 = s.find(' ', pos);
			if (string::npos == pos1) {
				if (0 == stoi(s.substr(pos)) % 2)
					d.push_back(stoi(s.substr(pos)));
				else
					d.push_front(stoi(s.substr(pos)));
				break;
			}
			else {
				if (0 == stoi(s.substr(pos, pos1)) % 2)
					d.push_back(stoi(s.substr(pos, pos1)));
				else
					d.push_front(stoi(s.substr(pos, pos1)));
				pos = pos1 + 1;
			}
			pos = pos1 + 1;
		}
	}
	std::reverse(d.begin(), d.end());
	for (deque<int>::iterator it1 = d.begin(); it1 != d.end(); it1++)
		l1.push_front(*it1);
	deque<int>::iterator it1 = d.begin();
	list<int>::iterator it2 = l1.begin();
	for (; it1 != d.end() && it2 != l1.end(); it1++, it2++)
		l2.push_back((*it1) * (*it2));
	list<int>::iterator it3 = l2.begin();
	list<int>::iterator it4 = l2.end();
	int count = l2.size();
	//for (auto x : d)
	//	cout << x << " ";
	//cout << endl;
	//for (auto x : l1)
	//	cout << x << " ";
	//cout << endl;
	for (; it3 != l2.end(); it3++) {
		cout << *it3 << ((--count) > 0 ? " " : "");
	}
	return 0;
}