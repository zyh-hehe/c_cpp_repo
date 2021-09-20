#include<iostream>
using namespace std;
int main(void)
{
	int a, b;
	cin >> a >> b;
	//下面是一种简单的通过条件判断来处理异常的写法
	//if (0 == b)
	//{
	//	cout << "b不能为0！";
	//	exit(a);
	//}
	//cout << (a / b) << endl;
	//return 0;

	//下面是通过踹扔抓三连鞭来进行异常处理的写法
	try
	{
		if (0 == b)
		{
			throw b;
			exit(0);
		}
		cout << a / b;
	}
	catch (int e)
	{
		cout << "b不能为:"<<e;
	}
}