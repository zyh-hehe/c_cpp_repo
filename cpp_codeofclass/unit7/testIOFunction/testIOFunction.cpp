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
	if (input.fail())//Ҳ����д�� !input
	{
		cout << "�ļ�û��������" << endl;
		//std::exit(2);//����д�Ļ������ʧ�ܾͻ��������
		std::abort();//�����ʧ�ܾ�ֱ����ֹ����
	}
	constexpr int SIZE = 1024;
	array<char, SIZE>buf;//buf��һ������
	//����istream::getline()
	while (!input.eof())
	{
		input.getline(&buf[0], SIZE, '#');//�����б�char*(������ݵ�����),int(�����С),char(��ȡ�ָ�����Ĭ��Ϊ�ո�).����ĵ�һ��������������д,����д��buf����Ϊbuf��һ�����󣬶�����ԭ������
		cout << &buf[0] << endl;
	}
	//����std::getline()
	input.close();//����Ҫ�ر�ԭ�ļ�����Ϊ��һ�ֶ�ȡ�Ѿ����ļ���ȡ����
	input.open(p);//�����´��ļ�
	string name{ " " };
	while (input.eof() != true)
	{
		std::getline(input, name, '#');//�����б�ifstream,string,char(��ȡ�ָ�����Ĭ��Ϊ�ո�).
		cout << name << endl;
	}
	fs::path p1{ R"(io.txt)" };
	ofstream o (p1);
	if (!o)
	{
		cout << "�ļ�û��������" << endl;
		//std::exit(2);//����д�Ļ������ʧ�ܾͻ��������
		std::abort();//�����ʧ�ܾ�ֱ����ֹ����
	}
	for(int i=0;i<5;i++)
	    o.put('a'+i);
	o.close();
	ifstream i (p1);
	array <char, 5>output1;
	if (!i)
	{
		cout << "�ļ�û��������" << endl;
		//std::exit(2);//����д�Ļ������ʧ�ܾͻ��������
		std::abort();//�����ʧ�ܾ�ֱ����ֹ����
	}
	for (int j = 0; j < 5; j++)
	{
		output1[j] =static_cast<char>( i.get());//��һ��get���������أ����ص���asciiֵ
		cout << output1[j] << '#'<<endl;
	}
	i.close();
	i.open(p1);
	for (int j = 0; j < 5; j++)
	{
		i.get(output1[j]);//�ڶ���get���������أ����ص���ʵ��һ��ifstream&�������˽�
		cout << output1[j] << '#' << endl;
	}
	cout.flush();//flush�����������÷��ϴ�û˵�������Ҳ��֪�����д�����ʲô��
	cout << "����" << std::flush;//�����flush��˵���Ե���endlʹ�ã���Ҳ��֪��ʲô��˼
	cout << "����" << endl;
	return 0;
}