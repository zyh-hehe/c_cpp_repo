#include<iostream>
class A
{
friend class B;//��B�����ó�A�����Ԫ
private:
	int a = 1;
};
A a1;
class B
{
	int b = a1.a;//��ʱB��Ϳ��Է���A���˽�г�Ա��
};
int main(void)
{
	return 0;
}