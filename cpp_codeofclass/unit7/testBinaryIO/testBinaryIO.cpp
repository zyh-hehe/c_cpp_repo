#include<iostream>
#include<fstream>
#include<filesystem>
#include<array>
namespace fs = std::filesystem;
using namespace std;
int main(void)
{
	fs::path p1{ "array.dat" };//dat�����ļ�Ҳ�����ü��±���
	fstream bio1{ p1,ios::out | ios::app };
	if (!bio1)
	{
		cout << "�����δ�ܳɹ��򿪣�" << endl;
		exit(2);
	}
	array a1{ 97,42,63 };
	streamsize size =sizeof(a1[0]) * a1.size();//���size����ʵ������һ��long int���͵���,ֵΪ12
	bio1.write(reinterpret_cast<char*>(&a1[0]), size);//reinterpret_cast������ת�������Խ���ַת��Ϊһ������������һ�����͵ĵ�ַ
	bio1.close();
	bio1.open(p1,ios::in);
	if (!bio1)
	{
		cout << "������δ�ܳɹ��򿪣�" << endl;
		exit(2);
	}
	auto x{ 0 };
	bio1.read(reinterpret_cast<char*>(&x), sizeof(x));
	cout << x << endl;
	bio1.close();
	fs::path p2{ "string.dat" };
	fstream bio2(p2, ios::out | ios::binary | ios::trunc);
	char s[]{ 'a','b','c' };
	bio2.write(s, sizeof(s));
	int b = 98;
	bio2.write(reinterpret_cast<char*>(&b), sizeof(int));//���лᱨ����Ϊread��write�������յĵ�һ������Ӧ����char*���͵�
	return 0;
}
