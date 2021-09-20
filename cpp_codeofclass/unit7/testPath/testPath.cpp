#include<iostream>
#include<filesystem>
#include<string>
namespace fs = std::filesystem;
using std::string;
int main(void)
{
	fs::path p1{ "D:/Study/大一下/c++/cpp_codeofclass/unit7/testPath/hello.txt" };
	//把hello.txt去掉，就成为一个目录，运行会有不同
	fs::path p2{ "d:\\学习\\大一下\\c++\\代码\\unit7\\testPath\\hello.txt" };//这种不推荐
	fs::path p3{ R"(d:\学习\大一下\c++\代码\unit7\testPath\hello.txt)" };
	//std::cout  <<"file separator is :" << fs::path::preferred_separator << std::endl;
	//输出分隔符，得到值92，是ASCII码
	if (fs::is_regular_file(p1))//判断p1是否为常规文件
		std::cout << p1 << "' s size is " << fs::file_size(p1) << std::endl;
	//输出hello.txt的大小，aloha， world！是13个字节
	else if (fs::is_directory(p1))//判断p1是否为一个目录
	{
		std::cout << "p1 is a directory , it includes:" << std::endl;
		for (auto e : fs::directory_iterator(p1))//这个是一个类，输出估计也是path类
			std::cout << e.path() << std::endl;
	}
	else if (fs::exists(p1))//判断p1是否存在
		std::cout << p1 << " is a special file !" << std::endl;
	else
		std::cout << p1 << " does not exist !" << std::endl;
	return 0;
}