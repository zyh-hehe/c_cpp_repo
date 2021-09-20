#include<iostream>
#include"square.h"
int Square::numberofsquare = 0;
int main(void)
{
	Square s1{ 10.0 };
	Square s2{ s1 };
	Square s3 = s2;
	Square s4 = { s1 };
	Square* s5 = new Square{ s4 };
	s4.~Square();
	std::cout << "Now delete s5" << std::endl;
	delete s5;
	s5 = nullptr;
	std::cout << "Now there are(is) " << Square::numberofsquare << "square(s)" << std::endl;
	std::cin.get();//可以注释掉这行看看有什么不同
	//在结束程序前系统会调用全部对象的析构函数，将对象全部删掉
	return 0;//怪事！s5的析构函数居然能被多次调用，甚至在s5释放掉之后还能用？！
}