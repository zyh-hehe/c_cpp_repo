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
	std::cin.get();//����ע�͵����п�����ʲô��ͬ
	//�ڽ�������ǰϵͳ�����ȫ�����������������������ȫ��ɾ��
	return 0;//���£�s5������������Ȼ�ܱ���ε��ã�������s5�ͷŵ�֮�����ã���
}