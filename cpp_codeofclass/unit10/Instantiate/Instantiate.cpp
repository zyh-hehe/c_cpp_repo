#include<iostream>
#include<string>
//#include<algorithm>//这个头文件里也有个max函数
using namespace std::string_literals;//这样就可以使用"xxx"s这样的方式把生字符串变为一个string类的对象了
using std::cout;
using std::endl;
template <typename T>
T max(T x1, T x2) {
	return (x1 >= x2 ? x1 : x2);
}
template <int> int max(int, int);
int main(void) {
	cout << max(1, 2) << endl;
	cout << max(2.9, 3.1) << endl;
	cout << max('a', 'A') << endl;
	//注意下面两行代码，两次的输出结果都会是ABC
	//但实际上，ABD的ASCII值是更大的，理论上都应该输出ABD
	//导致这个结果的原因是，这里传进去的参数会是const char*类型
	//结果在下面这个调用中，ABC字面量字符串先被创建，它在常量区先被创建，地址高（我也不知道为什么）
	//max函数会比较二者的地址，ABC地址高，就被返回输出了
	//至于第二个调用，这是因为这两个字符串已经被创建了，系统就直接复用了
	//所以还是比较的两个地址
	cout << max("ABC", "ABD") << endl;
	cout << max("ABD", "ABC") << endl;
	//下面这个函数也是同理
	cout << max("123", "124") << endl;
	//下面这行函数才会真正的去比较两个字符串的ASCII值大小，进而输出正确的结果
	cout << std::max("aba"s, "abc"s) << endl;
	//由于名字空间std::string_literals中也有一个max函数可以接收string类型的参数，
	//这里的调用如果不明确调用哪一个名字空间中的max函数，就会造成重载不明确的错误
	//在视频课中有提到，algorithm头文件中也有一个max函数，这样就更容易重载不明确了
	//所以在使用名字空间的时候一定要尽量避免声明可能存在于其他头文件中的函数
	//同时要减少using namespace std;的使用
	return 0;
}