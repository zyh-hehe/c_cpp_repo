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
		cout << "�ļ�û�гɹ���" << endl;
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
		input.get(x);//����������д��ִ�н�����ϴ޵���Ƶ��һ������֪��Ϊʲô
		cout << x;
	}
	return 0;
}