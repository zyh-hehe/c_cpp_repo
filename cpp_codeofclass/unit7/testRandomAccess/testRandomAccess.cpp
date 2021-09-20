#include<iostream>
#include<fstream>
#include<filesystem>
#include<array>
using namespace std;
namespace fs = filesystem;
int main(void)
{
	fs::path p1{ "test.dat" };
	fstream file{ p1,ios::out | ios::in | ios::trunc };
	auto x{ 12LL }, y{ 24LL };
	file.write(reinterpret_cast<char*>(&x), sizeof(long long int));
	file.write(reinterpret_cast<char*>(&y), sizeof(long long int));
	char str[]{ "hello,world" };
	file.write(str, sizeof(str));
	char buf[100]{ 0 };
	//�ƶ���ĳ��λ�á�seekg/seekp()���������غ�������һ�����ؽ���һ�����������ƶ���ĳ������λ��
	//�ڶ������ؽ���������������һ����ƫ����������Ϊ�������ڶ�����һ����־λ
	//��־λ�����֣�std::ios::beg(��ʼλ)��std::ios::end(ĩβλ)��std::ios::cur(��ǰλ)
	//������tellg/tellp()������ȡ��ǰָ���ľ���λ��
	//g����������ʱʹ�ã�p���������ʱʹ��
	file.seekg(16, std::ios::beg);
	file.read( buf,5 );
	cout << buf << endl;
	return 0;
}