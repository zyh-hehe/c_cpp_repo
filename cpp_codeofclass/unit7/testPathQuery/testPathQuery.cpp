#include<iostream>
#include<filesystem>
#include<string>
namespace fs = std::filesystem;
using std::string;
using std::cout, std::endl;
int main(void)
{
	fs::path p1{ "D:/Study/大一下/c++/cpp_codeofclass/unit7/testPathQuery/1.txt" };
	if (fs::is_empty(p1))//注意！这行是判断路径是否为空，而非判断路径是否存在！
		cout << "path " << p1 << "is empty !";
    if (!fs::exists(p1))//这才是判断p1是否存在!
	{
		std::cout << p1 << " does not exist ! !" << std::endl;
		std::exit(0);//退出程序
	}
	cout << "root_name( ):" << p1.root_name() << endl;//根目录的名字，就是D盘
	cout << "root_path( ):" << p1.root_path() << endl;//根目录的路径，是d:/
	cout << "relative_path( ):" << p1.relative_path() << endl;//文件的相对路径
	cout << "parent_path( ):" << p1.parent_path() << endl;
	//文件的父路径，即testPathQuery文件夹的路径
	cout << "filename( ):" << p1.filename() << endl; //文件名
	cout << "stem( ):" << p1.stem() << endl;//文件的父目录，是testPathQuery文件夹
	cout << "extension( ):" << p1.extension() << endl;//文件扩展名，即cpp
	return 0;
}