#include<iostream>
using namespace std;
//void foo() { }  //如果这一行不注释掉，就会导致重定义。因为noexcept不能作为区分重载函数的标识符（与之相反，const作为标识符时可以区分重载函数）
void foo () noexcept { throw 1; }
void tao() noexcept(1) {}
void zen() noexcept(1-1){}
int main(void)
{
	cout << "foo() noexcept:" << noexcept(foo()) << endl
		//<< "foo():" << noexcept(foo()) << endl
		<< "tao() noexcept(1):" << noexcept(tao())<<endl
		<< "zen() noexcept(1-1)" << noexcept(zen()) << endl;
	cout << "calling foo () noexcept { throw 1; }:" << endl;
	foo();//这行代码会引起程序终止，因为如果在声明为noexcept的函数中抛出异常，
	//则相当于调用std::terminate()或std::abort(),均会直接终止程序
	return 0;
}