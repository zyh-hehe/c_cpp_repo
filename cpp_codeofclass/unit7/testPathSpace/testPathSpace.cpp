#include<iostream>
#include<filesystem>
int main(void)
{
	using std::endl;
	using std::cout;
	namespace fs = std::filesystem;
	fs::path p{ "c:\\" };
	cout << "c����������СΪ" << fs::space(p).capacity<<endl;
	cout << "c��ʣ��������СΪ" << fs::space(p).free << endl;
	cout << "c��ʣ��������СΪ" << fs::space(p).available << endl;
	//available��free����ʱ����֪����ʲô����
	return 0;
}