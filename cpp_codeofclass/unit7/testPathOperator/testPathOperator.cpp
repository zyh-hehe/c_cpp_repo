#include<iostream>
#include<filesystem>
#include<string>
using std::cout;
using std::cin;
using std::endl;
namespace fs = std::filesystem;
int main(void)
{
	fs::path p1{ R"(d:/ѧϰ/��һ��)" };
	fs::path p2{ R"(d:/ѧϰ/��һ��)" };
	fs::path p3{ "" };
	p1.append(R"(c++)");
	p1 /= R"(����)";
	cout << p1 << endl;
	//append��/=����Ҫ�ֶ����/
	p2.concat(R"(/c++)");
	p2+= R"(/����)";
	cout << p2 << endl;
	//concat��+=������Ҫ�ֶ�����/
	p3 = p3 / R"(d:/ѧϰ/��һ��)" / R"(c++)" / R"(����)";
	cout << p3 << endl;
	return 0;
}