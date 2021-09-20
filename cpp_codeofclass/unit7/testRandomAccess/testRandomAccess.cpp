#include<iostream>
#include<fstream>
#include<filesystem>
#include<array>
using namespace std;
namespace fs = filesystem;
int main(void)
{
	fs::path p1{ "test.dat" };
	fstream file{ p1,ios::out | ios::in | ios::trunc };
	auto x{ 12LL }, y{ 24LL };
	file.write(reinterpret_cast<char*>(&x), sizeof(long long int));
	file.write(reinterpret_cast<char*>(&y), sizeof(long long int));
	char str[]{ "hello,world" };
	file.write(str, sizeof(str));
	char buf[100]{ 0 };
	//移动至某个位置。seekg/seekp()有两个重载函数，第一个重载接受一个参数，是移动至某个绝对位置
	//第二个重载接受两个参数，第一个是偏移量，可以为正负；第二个是一个标志位
	//标志位有三种，std::ios::beg(开始位)，std::ios::end(末尾位)，std::ios::cur(当前位)
	//可以用tellg/tellp()函数获取当前指到的绝对位置
	//g函数在输入时使用，p函数在输出时使用
	file.seekg(16, std::ios::beg);
	file.read( buf,5 );
	cout << buf << endl;
	return 0;
}