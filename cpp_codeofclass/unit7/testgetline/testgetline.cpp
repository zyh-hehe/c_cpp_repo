#include<iostream>
#include<filesystem>
#include<fstream>
#include<string>
using namespace std;
namespace fs = std::filesystem;
int main(void) {
	fs::path p{ "test.txt" };
	ofstream output{ p,ios::trunc };
	output << "100 100 100" << endl;
	output.close();
	ifstream input{ p };
	string a;
	std::getline(input, a);
	cout << a.find(' ') << endl;
	cout << a.find(' ', 4);
	cout << a.substr(0, 3) << "    \'aaaaa" << endl;
	cout << a.substr(4, 6) << endl;
}