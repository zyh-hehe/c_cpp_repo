#include<iostream>
using namespace std;
int main(void)
{
	int a, b;
	cin >> a >> b;
	//������һ�ּ򵥵�ͨ�������ж��������쳣��д��
	//if (0 == b)
	//{
	//	cout << "b����Ϊ0��";
	//	exit(a);
	//}
	//cout << (a / b) << endl;
	//return 0;

	//������ͨ������ץ�������������쳣�����д��
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
		cout << "b����Ϊ:"<<e;
	}
}