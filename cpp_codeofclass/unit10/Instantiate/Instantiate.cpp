#include<iostream>
#include<string>
//#include<algorithm>//���ͷ�ļ���Ҳ�и�max����
using namespace std::string_literals;//�����Ϳ���ʹ��"xxx"s�����ķ�ʽ�����ַ�����Ϊһ��string��Ķ�����
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
	//ע���������д��룬���ε�������������ABC
	//��ʵ���ϣ�ABD��ASCIIֵ�Ǹ���ģ������϶�Ӧ�����ABD
	//������������ԭ���ǣ����ﴫ��ȥ�Ĳ�������const char*����
	//�����������������У�ABC�������ַ����ȱ����������ڳ������ȱ���������ַ�ߣ���Ҳ��֪��Ϊʲô��
	//max������Ƚ϶��ߵĵ�ַ��ABC��ַ�ߣ��ͱ����������
	//���ڵڶ������ã�������Ϊ�������ַ����Ѿ��������ˣ�ϵͳ��ֱ�Ӹ�����
	//���Ի��ǱȽϵ�������ַ
	cout << max("ABC", "ABD") << endl;
	cout << max("ABD", "ABC") << endl;
	//�����������Ҳ��ͬ��
	cout << max("123", "124") << endl;
	//�������к����Ż�������ȥ�Ƚ������ַ�����ASCIIֵ��С�����������ȷ�Ľ��
	cout << std::max("aba"s, "abc"s) << endl;
	//�������ֿռ�std::string_literals��Ҳ��һ��max�������Խ���string���͵Ĳ�����
	//����ĵ����������ȷ������һ�����ֿռ��е�max�������ͻ�������ز���ȷ�Ĵ���
	//����Ƶ�������ᵽ��algorithmͷ�ļ���Ҳ��һ��max�����������͸��������ز���ȷ��
	//������ʹ�����ֿռ��ʱ��һ��Ҫ���������������ܴ���������ͷ�ļ��еĺ���
	//ͬʱҪ����using namespace std;��ʹ��
	return 0;
}