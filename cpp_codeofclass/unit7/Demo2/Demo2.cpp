#include<iostream>
#include<filesystem>
#include<fstream>
#include<array>
#include<string>
#include<iomanip>
namespace fs = std::filesystem;
using std::cout;
using std::array;
using std::endl;
using std::cin;
using std::fstream;
using std::ios;
using std::string;

class Person {
public:
	string name{ "zyh-hehe" };
	Person() = default;
};

int main(void) {
	fs::path p1{ "inout.dat" };
	fstream bio1{ p1,ios::out | ios::trunc };
	int x{ 2 };
	int x1;
	double y{ 1.1 };
	double y1;
	double y2{ 1.0 };
	array<int, 3> a{ 3,4,5 };
	int a1;
	Person zyh;
	string name{ "zyh-haha" };
	constexpr int SIZE = sizeof(a[0]) * (a.size());
	bio1.write(reinterpret_cast<char*>(&x), sizeof(x));
	bio1.write(reinterpret_cast<char*>(&y), sizeof(y));
	bio1.write(reinterpret_cast<char*>(&a[0]), SIZE);
	bio1.write(reinterpret_cast<char*>(&zyh.name[0]), sizeof(zyh.name));
	bio1.close();
	bio1.open(p1, ios::in | ios::out);
	bio1.read(reinterpret_cast<char*>(&x1), sizeof(x1));
	cout << x1 << endl;
	bio1.read(reinterpret_cast<char*>(&y1), sizeof(y1));
	cout << y1 << endl;
	for (int i = 0; i < 3; i++) {
		bio1.read(reinterpret_cast<char*>(&a1), sizeof(a1));
		cout << a1 << endl;
	}
	bio1.read(reinterpret_cast<char*>(&name[0]), sizeof(zyh.name));
	cout << name << endl;
	bio1.seekp(sizeof(int), ios::beg);
	bio1.write(reinterpret_cast<char*>(&y2), sizeof(y2));
	bio1.seekg(sizeof(int), ios::beg);
	bio1.read(reinterpret_cast<char*>(&y1), sizeof(y1));
	cout <<std::showpoint <<std::setprecision(2) << y1 << endl;
	bio1.seekg((-1) * static_cast<int>(sizeof(name) + sizeof(int) * 2),ios::end);
	cout << bio1.tellg() << endl;
	bio1.read(reinterpret_cast<char*>(&a1), sizeof(a1));
	cout << a1 << endl;
	return 0;
}


