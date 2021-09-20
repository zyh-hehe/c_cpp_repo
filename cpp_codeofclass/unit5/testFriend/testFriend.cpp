#include<iostream>
class A
{
friend class B;//将B类设置成A类的友元
private:
	int a = 1;
};
A a1;
class B
{
	int b = a1.a;//此时B类就可以访问A类的私有成员了
};
int main(void)
{
	return 0;
}