#include<iostream>
#include<filesystem>
#include<string>
namespace fs = std::filesystem;
using std::string;
int main(void)
{
	fs::path p1{ "D:/Study/��һ��/c++/cpp_codeofclass/unit7/testPath/hello.txt" };
	//��hello.txtȥ�����ͳ�Ϊһ��Ŀ¼�����л��в�ͬ
	fs::path p2{ "d:\\ѧϰ\\��һ��\\c++\\����\\unit7\\testPath\\hello.txt" };//���ֲ��Ƽ�
	fs::path p3{ R"(d:\ѧϰ\��һ��\c++\����\unit7\testPath\hello.txt)" };
	//std::cout  <<"file separator is :" << fs::path::preferred_separator << std::endl;
	//����ָ������õ�ֵ92����ASCII��
	if (fs::is_regular_file(p1))//�ж�p1�Ƿ�Ϊ�����ļ�
		std::cout << p1 << "' s size is " << fs::file_size(p1) << std::endl;
	//���hello.txt�Ĵ�С��aloha�� world����13���ֽ�
	else if (fs::is_directory(p1))//�ж�p1�Ƿ�Ϊһ��Ŀ¼
	{
		std::cout << "p1 is a directory , it includes:" << std::endl;
		for (auto e : fs::directory_iterator(p1))//�����һ���࣬�������Ҳ��path��
			std::cout << e.path() << std::endl;
	}
	else if (fs::exists(p1))//�ж�p1�Ƿ����
		std::cout << p1 << " is a special file !" << std::endl;
	else
		std::cout << p1 << " does not exist !" << std::endl;
	return 0;
}