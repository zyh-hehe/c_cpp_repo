#include<iostream>
#include<exception>
#include<stdexcept>
using namespace std;
class student {
public:
	student() = default;
	virtual void foo() {};
};
class undergraduate :public student {};
class graduate :public student {};
int main(void)
{
	undergraduate u;
	graduate g;
	student* s1 = &u;
	student* s2 = &g;
	graduate* p = dynamic_cast<graduate*>(s2);
	long x = reinterpret_cast<long>(p);
	cout << x << endl;
	graduate* p2 = dynamic_cast<graduate*>(s1);//�����Ĵ��벻���׳��쳣
	if (p2 == nullptr)
		cout << "cast s1 to graduate* is failed!" << endl;
	else
		cout << "cast s1 to graduate* is successful" << endl;
	try {
		graduate& r1 = dynamic_cast<graduate&>(u);//ֻ��ֱ�Ӱ�һ����������ת��Ϊ��һ���������ͲŻ��׳��쳣
	}
	catch (bad_cast& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}