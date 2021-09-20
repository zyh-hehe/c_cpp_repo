#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;

class A
{
public:
	 virtual string to_string() { return "A"; }
};

class B : public A
{
public:
	string to_string() override { return "B"; }
};

class C : public B
{
public:
	string to_string() override { return "C"; }
};

void print(A* o)
{
	cout << o->to_string() << endl;
}

void print(A& o)
{
	cout << o.to_string() << endl;
}

int main(void)
{
	A a;
	B b;
	C c;
	A* pa = &a;
	A* pb = &b;
	A* pc = &c;
	print(pa);
	print(pb);
	print(pc);
	print(a);
	print(b);
	print(c);
}