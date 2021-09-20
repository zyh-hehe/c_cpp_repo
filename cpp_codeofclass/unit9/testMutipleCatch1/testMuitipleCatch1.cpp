#include"Vec3D.h"

int main(void)
{
	Vec3D v(1.5, 2.5, 3.5);
	try {
		cout << (v / 1.0)[3] << endl;
		//注意这个语句。理论上而言，这下面的两个catch应该先判断执行第一个，再执行第二个
		//但实际上，如果写成(v/0.0)[3]，即两个异常都有，他会直接执行ZeroException这个catch
		//原因是，(v/0.0)[3]，先执行的是除法运算，如果除数是0.0就直接抛出异常了，根本轮不到抛出越界异常
	}
	catch (RangeException& e)
	{
		cout << e.what() << endl;
		//再注意这个语句。这个what调用的是我们重定义的what函数，即RangeException::what()，而非out_of_range::what()
		//原因要从多态方面去理解，涉及到动态联编。记得复习多态和覆写，很重要！
		//即在执行类内虚函数时，会根据引用/指针的真实类型(而非声明的类型)去调用不同的重定义函数
		//所以，这里只有显式的把e转化为out_of_range类(而非引用/指针)，才会调用out_of_range::what()
		cout << "dimension: " << e.getDimension() << endl;
		cout << "index: " << e.getIndex() << endl;
	}
	catch (ZeroException& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}

//