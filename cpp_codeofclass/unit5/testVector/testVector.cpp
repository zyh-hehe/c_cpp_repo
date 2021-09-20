#include<iostream>
#include<vector>
#include<string>
#include"helper.h"//这个头文件是从老崔的博客上down下来的 
using std::string;
using std::vector;
int main(void)
{
	vector <string> v1 { "hello" , "world" , "welcome" , "to" , "c++" };
	PRINT(v1);
	v1.erase(v1.end()-1);
	/*根据我的推测，这个erase函数大概的实现原理应该是把size-1，
	再把原本的最后一个元素设置成0*/
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
	//上面这行代码会报错，说明不能将存储了不同类型数据的vector类交换
	return 0;
}