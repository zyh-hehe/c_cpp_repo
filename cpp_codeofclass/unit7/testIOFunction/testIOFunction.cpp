#include<iostream>
#include<filesystem>
#include<fstream>
#include<array>
#include<string>
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
namespace fs = std::filesystem;
using std::string;
using std::array;
int main(void)
{
	fs::path p{R"(339.txt)"};
	ifstream input{ p };
	if (input.fail())//也可以写成 !input
	{
		cout << "文件没能正常打开" << endl;
		//std::exit(2);//这样写的话如果打开失败就会结束程序
		std::abort();//如果打开失败就直接中止程序
	}
	constexpr int SIZE = 1024;
	array<char, SIZE>buf;//buf是一个对象
	//尝试istream::getline()
	while (!input.eof())
	{
		input.getline(&buf[0], SIZE, '#');//参数列表：char*(存放数据的区域),int(区域大小),char(读取分隔符，默认为空格).这里的第一个参数必须这样写,不能写成buf，因为buf是一个对象，而不是原生数组
		cout << &buf[0] << endl;
	}
	//尝试std::getline()
	input.close();//首先要关闭原文件，因为上一轮读取已经将文件读取完了
	input.open(p);//再重新打开文件
	string name{ " " };
	while (input.eof() != true)
	{
		std::getline(input, name, '#');//参数列表：ifstream,string,char(读取分隔符，默认为空格).
		cout << name << endl;
	}
	fs::path p1{ R"(io.txt)" };
	ofstream o (p1);
	if (!o)
	{
		cout << "文件没能正常打开" << endl;
		//std::exit(2);//这样写的话如果打开失败就会结束程序
		std::abort();//如果打开失败就直接中止程序
	}
	for(int i=0;i<5;i++)
	    o.put('a'+i);
	o.close();
	ifstream i (p1);
	array <char, 5>output1;
	if (!i)
	{
		cout << "文件没能正常打开" << endl;
		//std::exit(2);//这样写的话如果打开失败就会结束程序
		std::abort();//如果打开失败就直接中止程序
	}
	for (int j = 0; j < 5; j++)
	{
		output1[j] =static_cast<char>( i.get());//第一种get函数的重载，返回的是ascii值
		cout << output1[j] << '#'<<endl;
	}
	i.close();
	i.open(p1);
	for (int j = 0; j < 5; j++)
	{
		i.get(output1[j]);//第二种get函数的重载，返回的其实是一个ifstream&，不必了解
		cout << output1[j] << '#' << endl;
	}
	cout.flush();//flush函数的这种用法老崔没说清楚，我也不知道这行代码有什么用
	cout << "啊这" << std::flush;//这里的flush据说可以当做endl使用，我也不知道什么意思
	cout << "啊这" << endl;
	return 0;
}