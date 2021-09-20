#include<iostream>
#include<filesystem>
#include<string>
using std::cout;
using std::cin;
using std::endl;
namespace fs = std::filesystem;
int main(void)
{
	fs::path p1{ R"(d:/学习/大一下)" };
	fs::path p2{ R"(d:/学习/大一下)" };
	fs::path p3{ "" };
	p1.append(R"(c++)");
	p1 /= R"(代码)";
	cout << p1 << endl;
	//append和/=不需要手动添加/
	p2.concat(R"(/c++)");
	p2+= R"(/代码)";
	cout << p2 << endl;
	//concat和+=符号需要手动加入/
	p3 = p3 / R"(d:/学习/大一下)" / R"(c++)" / R"(代码)";
	cout << p3 << endl;
	return 0;
}