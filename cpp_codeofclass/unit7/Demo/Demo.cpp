#include <fstream>
#include<filesystem>
#include <iostream>
using namespace std;
namespace fs = std::filesystem;
int main() {
	fs::path p1{ "out.txt" };
	fs::path p2{ "in.txt" };
	ofstream out(p1);
	ifstream in(p2);
	if (in)
		cout << "in.txt exists" << endl;
	else
		cout << "in.txt does not exist" << endl;
	in.close();
	out.close();
	return 0;
}


