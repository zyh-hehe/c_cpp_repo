#include<iostream>
#include<vector>
using namespace std;
using std::vector;
//需要分别在debug模式和release模式下执行这段程序
int main(void)
{
	std::vector v1{ 'a','b','c','d','e' };//c++17支持自动类型推导，不用在v1之前标注类型名
	for (int i = 0; i <= 5; i++)//很明显，这里有越界情况
	{
		try {
        cout << v1[i];//在debug模式下，执行这行代码会导致assert报错；在release模式下则不会。并且这行代码不会抛出异常
		cout << v1.at(i) << endl;//这行代码在release模式下执行时会抛出异常，所以我们需要处理异常
		}
		catch (out_of_range& e)
		{
			cout << e.what() << endl;
			//这行代码的输出的前面会有一个空格或其他莫名其妙的符号，
			//这是因为在release情况下强行执行第一条输出语句输出v[i]时，这个v[i]并不存在
			//输出的就是一个随机字符
		}
	}
	return 0;
}