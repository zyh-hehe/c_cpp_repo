#include<iostream>
#include<fstream>
#include<filesystem>
#include<array>
namespace fs = std::filesystem;
using namespace std;
int main(void)
{
	fs::path p1{ "array.dat" };//dat类型文件也可以用记事本打开
	fstream bio1{ p1,ios::out | ios::app };
	if (!bio1)
	{
		cout << "输出流未能成功打开！" << endl;
		exit(2);
	}
	array a1{ 97,42,63 };
	streamsize size =sizeof(a1[0]) * a1.size();//这个size变量实际上是一个long int类型的数,值为12
	bio1.write(reinterpret_cast<char*>(&a1[0]), size);//reinterpret_cast是类型转换，可以将地址转化为一个整数或者另一个类型的地址
	bio1.close();
	bio1.open(p1,ios::in);
	if (!bio1)
	{
		cout << "输入流未能成功打开！" << endl;
		exit(2);
	}
	auto x{ 0 };
	bio1.read(reinterpret_cast<char*>(&x), sizeof(x));
	cout << x << endl;
	bio1.close();
	fs::path p2{ "string.dat" };
	fstream bio2(p2, ios::out | ios::binary | ios::trunc);
	char s[]{ 'a','b','c' };
	bio2.write(s, sizeof(s));
	int b = 98;
	bio2.write(reinterpret_cast<char*>(&b), sizeof(int));//这行会报错，因为read或write函数接收的第一个参数应该是char*类型的
	return 0;
}
