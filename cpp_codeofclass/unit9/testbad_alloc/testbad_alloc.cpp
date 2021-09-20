#include<iostream>
#include<Windows.h>
#include<new>
#include<stdexcept>
using namespace std;
int main(void)
{
	try {
		for (int i = 0; i < 10000; i++)
		{
			auto* p = new long long int[2000000000000];
			delete[] p;
			cout << i << " array" << endl;
			Sleep(10);
		}
	}
	catch (bad_alloc& e)
	{
		cout << e.what();
	}
	return 0;
}