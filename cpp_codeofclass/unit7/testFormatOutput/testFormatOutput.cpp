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
	cout << a << endl;//���3.14159
	cout << b << endl;//���3
	cout << setw(4) << right << a << endl;//���3.14159��������ʵ�����
	cout << setw(4) << left << a << endl;//���3.14159��������ʵ�����
	cout << setw(5)<< right << b << endl;//���****3����*����λ
	cout << setw(5)<< left <<  b << endl;//���3****����*����λ
	cout << setw(10) << right << a << endl;//���***3.14159����δsetprecision������°���6λ��Ч�������
	cout << setw(10) << left << a << endl;//���3.14159***����δsetprecision������°���6λ��Ч�������
	cout<< setw(10) << a << endl;//���3.14159***����δsetprecision������°���6λ��Ч�������
	cout << setprecision(9) << setw(10) << a << endl; //���3.14159265��û��fixedʱsetprecision�Ĳ���Ϊ��Ч����λ��
	cout << setprecision(9) << fixed << setw(10) << a << endl; //���3.141592654��fixedʱsetprecision�Ĳ���ΪС��������ָ���
	cout << showpoint << b << endl;//���3.000000000����showpoint�����С�����0
	cout << hexfloat << b << endl;//���0x1.8000000000000p+1��������ʮ���������
	cout << std::defaultfloat;//�ص�ʮ����
	cout << b << endl;//���3
	return 0;
}