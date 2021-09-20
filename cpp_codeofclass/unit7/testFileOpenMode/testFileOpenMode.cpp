#include<iostream>
#include<filesystem>
#include<fstream>
using namespace std;
namespace fs = filesystem;
int main(void)
{
	fs::path p1{ "339.txt" }, p2{ "339(2).txt" };
	ofstream out1{ p1,ios::out | ios::app };//app模式表示在文件末尾追加输出流内容；
	ofstream out2{ p2,ios::out | ios::trunc };//trunc模式表示清除原文件内容，重新输出
	char c;
	while (!std::cin.get(c).eof())//在按下ctrl+z时，cin.get(c).eof()为真。这个eof输入的键位和系统有关
	{
		out1.put(c); 
		out2.put(c);
	}
	out1.close();
	out2.close();
	ifstream in1{ p1,ios::in };
	ifstream in2{ p2,ios::in | ios::ate };//ate模式表示打开文件时将光标移到文件末尾
	cout << p1;
	while (!in1.get(c).eof())
		cout << c;
	cout << p2 << endl;
	while (!in2.get(c).eof())//因为打开时光标移到了文件末尾，所以一开始就会为真
		cout << c;
	cout << endl;
	return 0;
}