#include<iostream>
using namespace std;
//void foo() { }  //�����һ�в�ע�͵����ͻᵼ���ض��塣��Ϊnoexcept������Ϊ�������غ����ı�ʶ������֮�෴��const��Ϊ��ʶ��ʱ�����������غ�����
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
	foo();//���д�������������ֹ����Ϊ���������Ϊnoexcept�ĺ������׳��쳣��
	//���൱�ڵ���std::terminate()��std::abort(),����ֱ����ֹ����
	return 0;
}