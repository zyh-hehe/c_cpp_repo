#include<iostream>
#include<fstream>
#include<filesystem>
#include<string>
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::string;
namespace fs = std::filesystem;
int main(void)
{
	fs::path p{ "score.txt" };
	ifstream input{ p };
	if (input.fail() == true)
	{
		cout << "文件没有成功打开" << endl;
		return  0;
	}
	string name{ "" };
	double score{ 0.0 };
	input >> name >> score;
	cout << name << "  " << score << endl;;
	input >> name >> score;
	cout << name << "  " << score<<endl;
	char x;
	while (!input.eof())
	{
		input.get(x);//这里这样子写的执行结果和老崔的视频不一样，不知道为什么
		cout << x;
	}
	return 0;
}