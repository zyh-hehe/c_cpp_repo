#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;

class A
{
public:
	string to_string() { return "A"; }
};

class B : public A
{
public:
	string to_string() { return "B"; }
};

class C : public B
{
public:
	string to_string() { return "C"; }
};

void print(A a)
{
	cout << a.to_string() << endl;
}

void print(B a)
{
	cout << a.to_string() << endl;
}

void print(C a)
{
	cout << a.to_string() << endl;
}
//上段注释代码取消注释前后，输出不同
int main(void)
{
	A a;
	B b;
	C c;
	print(a);
	print(b);
	print(c);
	return 0;
}