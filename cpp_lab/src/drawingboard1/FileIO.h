#pragma once
#include<fstream>
#include<filesystem>
#include<string>
#include"Shape.h"

using std::ifstream;
using std::ofstream;
using std::ios;
namespace fs = std::filesystem;

class FileIO {
private:
public:
	FileIO();
	void ReadFromFile(vector<Shape*>&);
	void WriteToFile(vector<Shape*>&);
	void ReadFromFile1(vector<Shape*>&);
};
