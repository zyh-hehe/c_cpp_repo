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
	graduate* p2 = dynamic_cast<graduate*>(s1);//这样的代码不会抛出异常
	if (p2 == nullptr)
		cout << "cast s1 to graduate* is failed!" << endl;
	else
		cout << "cast s1 to graduate* is successful" << endl;
	try {
		graduate& r1 = dynamic_cast<graduate&>(u);//只有直接把一个对象类型转化为另一个对象类型才会抛出异常
	}
	catch (bad_cast& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}