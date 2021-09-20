#include<iostream>
#include<filesystem>
int main(void)
{
	using std::endl;
	using std::cout;
	namespace fs = std::filesystem;
	fs::path p{ "c:\\" };
	cout << "c盘总容量大小为" << fs::space(p).capacity<<endl;
	cout << "c盘剩余容量大小为" << fs::space(p).free << endl;
	cout << "c盘剩余容量大小为" << fs::space(p).available << endl;
	//available和free我暂时还不知道有什么区别
	return 0;
}