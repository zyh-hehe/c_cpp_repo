#include<iostream>
#include<vector>
using namespace std;
using std::vector;
//��Ҫ�ֱ���debugģʽ��releaseģʽ��ִ����γ���
int main(void)
{
	std::vector v1{ 'a','b','c','d','e' };//c++17֧���Զ������Ƶ���������v1֮ǰ��ע������
	for (int i = 0; i <= 5; i++)//�����ԣ�������Խ�����
	{
		try {
        cout << v1[i];//��debugģʽ�£�ִ�����д���ᵼ��assert������releaseģʽ���򲻻ᡣ�������д��벻���׳��쳣
		cout << v1.at(i) << endl;//���д�����releaseģʽ��ִ��ʱ���׳��쳣������������Ҫ�����쳣
		}
		catch (out_of_range& e)
		{
			cout << e.what() << endl;
			//���д���������ǰ�����һ���ո������Ī������ķ��ţ�
			//������Ϊ��release�����ǿ��ִ�е�һ�����������v[i]ʱ�����v[i]��������
			//����ľ���һ������ַ�
		}
	}
	return 0;
}