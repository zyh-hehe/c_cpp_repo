#include<iostream>
#include<filesystem>
#include<fstream>
using namespace std;
namespace fs = filesystem;
int main(void)
{
	fs::path p1{ "339.txt" }, p2{ "339(2).txt" };
	ofstream out1{ p1,ios::out | ios::app };//appģʽ��ʾ���ļ�ĩβ׷����������ݣ�
	ofstream out2{ p2,ios::out | ios::trunc };//truncģʽ��ʾ���ԭ�ļ����ݣ��������
	char c;
	while (!std::cin.get(c).eof())//�ڰ���ctrl+zʱ��cin.get(c).eof()Ϊ�档���eof����ļ�λ��ϵͳ�й�
	{
		out1.put(c); 
		out2.put(c);
	}
	out1.close();
	out2.close();
	ifstream in1{ p1,ios::in };
	ifstream in2{ p2,ios::in | ios::ate };//ateģʽ��ʾ���ļ�ʱ������Ƶ��ļ�ĩβ
	cout << p1;
	while (!in1.get(c).eof())
		cout << c;
	cout << p2 << endl;
	while (!in2.get(c).eof())//��Ϊ��ʱ����Ƶ����ļ�ĩβ������һ��ʼ�ͻ�Ϊ��
		cout << c;
	cout << endl;
	return 0;
}