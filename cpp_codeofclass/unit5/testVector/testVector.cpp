#include<iostream>
#include<vector>
#include<string>
#include"helper.h"//���ͷ�ļ��Ǵ��ϴ޵Ĳ�����down������ 
using std::string;
using std::vector;
int main(void)
{
	vector <string> v1 { "hello" , "world" , "welcome" , "to" , "c++" };
	PRINT(v1);
	v1.erase(v1.end()-1);
	/*�����ҵ��Ʋ⣬���erase������ŵ�ʵ��ԭ��Ӧ���ǰ�size-1��
	�ٰ�ԭ�������һ��Ԫ�����ó�0*/
	PRINT(v1);
	v1.push_back("c++!");
	PRINT(v1);
	vector <string> v2 { v1.begin() ,  v1.end() };
	PRINT(v2);
	v2.insert(v2.begin()+2, "aloha! ");
	PRINT(v2);
	vector <string> v3{ v2 };
	PRINT(v3);
	v3.swap(v1);
	std::cout << "After swap:" << std::endl;
	PRINT(v1);
	PRINT(v3 );
	v3[0] = "aloha";
	PRINT(v3);
	vector <string> v4 (4, "aloha");
	PRINT(v4);
	vector <int> v5 (5, 10);
	PRINT(v5);
	//v5.swap(v4);
	//�������д���ᱨ��˵�����ܽ��洢�˲�ͬ�������ݵ�vector�ཻ��
	return 0;
}