#include<iostream>
#include<filesystem>
#include<string>
namespace fs = std::filesystem;
using std::string;
using std::cout, std::endl;
int main(void)
{
	fs::path p1{ "D:/Study/��һ��/c++/cpp_codeofclass/unit7/testPathQuery/1.txt" };
	if (fs::is_empty(p1))//ע�⣡�������ж�·���Ƿ�Ϊ�գ������ж�·���Ƿ���ڣ�
		cout << "path " << p1 << "is empty !";
    if (!fs::exists(p1))//������ж�p1�Ƿ����!
	{
		std::cout << p1 << " does not exist ! !" << std::endl;
		std::exit(0);//�˳�����
	}
	cout << "root_name( ):" << p1.root_name() << endl;//��Ŀ¼�����֣�����D��
	cout << "root_path( ):" << p1.root_path() << endl;//��Ŀ¼��·������d:/
	cout << "relative_path( ):" << p1.relative_path() << endl;//�ļ������·��
	cout << "parent_path( ):" << p1.parent_path() << endl;
	//�ļ��ĸ�·������testPathQuery�ļ��е�·��
	cout << "filename( ):" << p1.filename() << endl; //�ļ���
	cout << "stem( ):" << p1.stem() << endl;//�ļ��ĸ�Ŀ¼����testPathQuery�ļ���
	cout << "extension( ):" << p1.extension() << endl;//�ļ���չ������cpp
	return 0;
}