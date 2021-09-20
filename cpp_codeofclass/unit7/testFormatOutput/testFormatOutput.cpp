#include<iostream>
#include<iomanip>
using std::cout;
using std::endl;
using std::left;
using std::right;
using std::setprecision;
using std::setw;
using std::fixed;
using std::fill;
using std::setfill;
using std::showpoint;
using std::hexfloat;
int main(void) {
	double a{ 3.1415926535898 };
	double b{ 3.0 };
	cout << setfill('*');
	cout << a << endl;//输出3.14159
	cout << b << endl;//输出3
	cout << setw(4) << right << a << endl;//输出3.14159，即按照实际输出
	cout << setw(4) << left << a << endl;//输出3.14159，即按照实际输出
	cout << setw(5)<< right << b << endl;//输出****3，用*填充空位
	cout << setw(5)<< left <<  b << endl;//输出3****，用*填充空位
	cout << setw(10) << right << a << endl;//输出***3.14159，在未setprecision的情况下按照6位有效数字输出
	cout << setw(10) << left << a << endl;//输出3.14159***，在未setprecision的情况下按照6位有效数字输出
	cout<< setw(10) << a << endl;//输出3.14159***，在未setprecision的情况下按照6位有效数字输出
	cout << setprecision(9) << setw(10) << a << endl; //输出3.14159265，没有fixed时setprecision的参数为有效数字位数
	cout << setprecision(9) << fixed << setw(10) << a << endl; //输出3.141592654，fixed时setprecision的参数为小数点后数字个数
	cout << showpoint << b << endl;//输出3.000000000，即showpoint会输出小数点和0
	cout << hexfloat << b << endl;//输出0x1.8000000000000p+1，即按照十六进制输出
	cout << std::defaultfloat;//回到十进制
	cout << b << endl;//输出3
	return 0;
}