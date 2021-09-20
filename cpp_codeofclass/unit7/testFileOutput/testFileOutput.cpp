#include<iostream>
#include<fstream>
#include<filesystem>
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
namespace fs = std::filesystem;
int main(void)
{
	fs::path p{ "score.txt" };
	ofstream output{ p };
	double lileiscore{ 90.5 };
	int hanmeimeiscore{ 90 };
	output << "lilei ' s score :" << lileiscore << endl;
	output << "hanmeimei 's score :" << hanmeimeiscore << endl;
	output.close();
	cout << "size of " << p << " is " << fs::file_size(p) << endl;
	return 0;
}