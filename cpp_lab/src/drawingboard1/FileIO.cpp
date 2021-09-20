#include"FileIO.h"
#include"FileIOExceptions.h"
#include"Circle.h"
#include"Rectangle.h"
#include"Triangle.h"

FileIO::FileIO() = default;

void FileIO::ReadFromFile(vector<Shape*>& geometries_) {
	fs::path geofile{ "figure files.txt" };
	ifstream input{ geofile };
	if (input.fail()) {
		throw FileException();
	}
	while (is_run()) {
		char ID{ ' ' };
		while (ID=='\n'||ID==' ') {
			if (input.get(ID).eof())
				break;
		}
		if ('1' == ID) {
			string cx{ "000" }, cy{ "000" }, radius{ "100" }, RGBvalue, isFilled_, line2;
			long int rgbvalue;
			std::getline(input, cx, ' ');
			std::getline(input, cy, ' ');
			std::getline(input, radius, '\n');
			std::getline(input, RGBvalue, ' ');
			try {
				rgbvalue = stol(RGBvalue);
				if (rgbvalue > 0xFFFFFF || rgbvalue < 0)
					throw ColorException();
			}
			catch (ColorException& e) {
				rgbvalue = 0;
				setfontbkcolor(WHITE);
				setfillcolor(WHITE);
				setviewport(0, 0, 300, 1920);
				clearviewport();
				setviewport(0, 0, 2560, 2560);
				outtextrect(30, 30, 280, 30, "文件读取出错！");
				setfont(20, 0, "楷体");
				outtextrect(30, 70, 280, 30, "具体错误原因:");
				outtextrect(30, 90, 280, 30, e.what());
				outtextrect(30, 110, 280, 30, "已将错误值设为默认！");
				setfont(30, 0, "楷体");
				outtextrect(30, 140, 280, 30, "请按任意键继续！");
				getch();
			}
			std::getline(input, isFilled_, '\n');
			Circle* c1 = new Circle(stoi(cx), stoi(cy), stod(radius), rgbvalue, rgbvalue, stoi(isFilled_));
			geometries_.push_back(c1);
		}
		else if ('2' == ID) {
			string x1, y1, x2, y2, RGBvalue, isFilled_;
			long int rgbvalue;
			std::getline(input, x1, ' ');
			std::getline(input, y1, ' ');
			std::getline(input, x2, ' ');
			std::getline(input, y2, '\n');
			std::getline(input, RGBvalue, ' ');
			try {
				rgbvalue = stol(RGBvalue);
				if (rgbvalue > 0xFFFFFF || rgbvalue < 0)
					throw ColorException();
			}
			catch (ColorException& e) {
				rgbvalue = 0;
				setfontbkcolor(WHITE);
				setfillcolor(WHITE);
				setviewport(0, 0, 300, 1920);
				clearviewport();
				setviewport(0, 0, 2560, 2560);
				ege::outtextrect(30, 30, 280, 30, "文件读取出错！");
				ege::setfont(20, 0, "楷体");
				ege::outtextrect(30, 70, 280, 30, "具体错误原因:");
				ege::outtextrect(30, 90, 280, 30, e.what());
				ege::outtextrect(30, 110, 280, 30, "已将错误值设为默认！");
				ege::setfont(30, 0, "楷体");
				ege::outtextrect(30, 140, 280, 30, "请按任意键继续！");
				ege::getch();
			}
			std::getline(input, isFilled_, '\n');
			cRectangle* r1 = new cRectangle(stoi(x1), stoi(y1), stoi(x2), stoi(y2), rgbvalue, rgbvalue, stoi(isFilled_));
			geometries_.push_back(r1);
		}
		else if ('3' == ID) {
			string x1, y1, x2, y2, x3, y3, RGBvalue, isFilled_;
			long int rgbvalue;
			std::getline(input, x1, ' ');
			std::getline(input, y1, ' ');
			std::getline(input, x2, ' ');
			std::getline(input, y2, ' ');
			std::getline(input, x3, ' ');
			std::getline(input, y3, '\n');
			std::getline(input, RGBvalue, ' ');
			try {
				rgbvalue = stol(RGBvalue);
				if (rgbvalue > 0xFFFFFF || rgbvalue < 0)
					throw ColorException();
			}
			catch (ColorException& e) {
				rgbvalue = 0;
				setfontbkcolor(WHITE);
				setfillcolor(WHITE);
				setviewport(0, 0, 300, 1920);
				clearviewport();
				setviewport(0, 0, 2560, 2560);
				ege::outtextrect(30, 30, 280, 30, "文件读取出错！");
				ege::setfont(20, 0, "楷体");
				ege::outtextrect(30, 70, 280, 30, "具体错误原因:");
				ege::outtextrect(30, 90, 280, 30, e.what());
				ege::outtextrect(30, 110, 280, 30, "已将错误值设为默认！");
				ege::setfont(30, 0, "楷体");
				ege::outtextrect(30, 140, 280, 30, "请按任意键继续！");
				ege::getch();
			}
			std::getline(input, isFilled_, '\n');
			Point p1(stoi(x1), stoi(y1));
			Point p2(stoi(x2), stoi(y2));
			Point p3(stoi(x3), stoi(y3));
			Triangle* t1 = new Triangle(p1, p2, p3, rgbvalue, rgbvalue, stoi(isFilled_));
			geometries_.push_back(t1);
		}
		else if (ID ==' ')
		    break;
		else 
		    throw IDException();
	}
	input.close();
}

void FileIO::ReadFromFile1(vector<Shape*>& geometries) {
	fs::path geofile{ "figure files.txt" };
	ifstream input{ geofile };
	if (input.fail()) {
		throw FileException();
	}
	while (!input.eof()) {
		string line1, line2, line3;
		std::getline(input, line1);
		std::getline(input, line2);
		std::getline(input, line3);
		if (line1 == "1") {
			string cx, cy, radius, RGBvalue, isfilled;
			long int rgbvalue;
			try {
				size_t pos1 = line2.find(" ", 0);
				size_t pos2 = line2.find(" ", pos1 + 1);
				size_t pos3 = line2.find(" ", pos2 + 1);
				if (pos1 == string::npos || pos2 == string::npos)
					throw DataLackException();
				else if (pos3 != string::npos)
					throw DataSuperfluousException();
				cx = line2.substr(0, pos1);
				cy = line2.substr(pos1 + 1, pos2 - pos1 - 1);
				radius = line2.substr(pos2 + 1);
			}
			catch (DataException& e) {
				cx = "0", cy = "0", radius = "0";
				setfontbkcolor(WHITE);
				setfillcolor(WHITE);
				setviewport(0, 0, 300, 1920);
				clearviewport();
				setviewport(0, 0, 2560, 2560);
				ege::outtextrect(30, 30, 280, 30, "文件读取出错！");
				ege::setfont(20, 0, "楷体");
				ege::outtextrect(30, 70, 280, 30, "具体错误原因:");
				ege::outtextrect(30, 90, 280, 30, e.what());
				ege::outtextrect(30, 110, 280, 30, "已跳过错误数据！");
				ege::setfont(30, 0, "楷体");
				ege::outtextrect(30, 140, 280, 30, "请按任意键继续！");
				ege::getch();
				continue;
			}
			try {
				try {
					size_t pos1 = line3.find(" ");
					if (pos1 == string::npos) {
						throw DataLackException();
					}
					RGBvalue = line3.substr(0, pos1);
					isfilled = line3.substr(pos1 + 1);
				}
				catch (DataLackException& e) {
					RGBvalue = "0", isfilled = "1";
					setfontbkcolor(WHITE);
					setfillcolor(WHITE);
					setviewport(0, 0, 300, 1920);
					clearviewport();
					setviewport(0, 0, 2560, 2560);
					ege::outtextrect(30, 30, 280, 30, "文件读取出错！");
					ege::setfont(20, 0, "楷体");
					ege::outtextrect(30, 70, 280, 30, "具体错误原因:");
					ege::outtextrect(30, 90, 280, 30, e.what());
					ege::outtextrect(30, 110, 280, 30, "已将错误值设为0！");
					ege::setfont(30, 0, "楷体");
					ege::outtextrect(30, 140, 280, 30, "请按任意键继续！");
					ege::getch();
				}
				rgbvalue = stol(RGBvalue);
				if (rgbvalue > 0xFFFFFF || rgbvalue < 0)
					throw ColorException();
			}
			catch (ColorException& e) {
				rgbvalue = 0;
				setfontbkcolor(WHITE);
				setfillcolor(WHITE);
				setviewport(0, 0, 300, 1920);
				clearviewport();
				setviewport(0, 0, 2560, 2560);
				ege::outtextrect(30, 30, 280, 30, "文件读取出错！");
				ege::setfont(20, 0, "楷体");
				ege::outtextrect(30, 70, 280, 30, "具体错误原因:");
				ege::outtextrect(30, 90, 280, 30, e.what());
				ege::outtextrect(30, 110, 280, 30, "已将错误值设为0！");
				ege::setfont(30, 0, "楷体");
				ege::outtextrect(30, 140, 280, 30, "请按任意键继续！");
				ege::getch();
			}
			Circle* c1 = new Circle(stoi(cx), stoi(cy), stod(radius), rgbvalue, rgbvalue, stoi(isfilled));
			geometries.push_back(c1);
		}
		else if (line1 == "2") {
			string x1, x2, y1, y2, RGBvalue, isfilled;
			long int rgbvalue;
			try {
				size_t pos1 = line2.find(" ", 0);
				size_t pos2 = line2.find(" ", pos1 + 1);
				size_t pos3 = line2.find(" ", pos2 + 1);
				size_t pos4 = line2.find(" ", pos3 + 1);
				if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos)
					throw DataLackException();
				else if (pos4 != string::npos)
					throw DataSuperfluousException();
				x1 = line2.substr(0, pos1);
				y1 = line2.substr(pos1 + 1, pos2 - pos1 - 1);
				x2 = line2.substr(pos2 + 1, pos3 - pos2 - 1);
				y2 = line2.substr(pos3 + 1);
			}
			catch (DataException& e) {
				x1 = "0", x2 = "0", y1 = "0", y2 = "0";
				setfontbkcolor(WHITE);
				setfillcolor(WHITE);
				setviewport(0, 0, 300, 1920);
				clearviewport();
				setviewport(0, 0, 2560, 2560);
				ege::outtextrect(30, 30, 280, 30, "文件读取出错！");
				ege::setfont(20, 0, "楷体");
				ege::outtextrect(30, 70, 280, 30, "具体错误原因:");
				ege::outtextrect(30, 90, 280, 30, e.what());
				ege::outtextrect(30, 110, 280, 30, "已跳过错误数据！");
				ege::setfont(30, 0, "楷体");
				ege::outtextrect(30, 140, 280, 30, "请按任意键继续！");
				ege::getch();
				continue;
			}
			try {
				try {
					size_t pos1 = line3.find(" ");
					if (pos1 == string::npos) {
						throw DataLackException();
					}
					RGBvalue = line3.substr(0, pos1);
					isfilled = line3.substr(pos1 + 1);
				}
				catch (DataLackException& e) {
					RGBvalue = "0", isfilled = "1";
					setfontbkcolor(WHITE);
					setfillcolor(WHITE);
					setviewport(0, 0, 300, 1920);
					clearviewport();
					setviewport(0, 0, 2560, 2560);
					ege::outtextrect(30, 30, 280, 30, "文件读取出错！");
					ege::setfont(20, 0, "楷体");
					ege::outtextrect(30, 70, 280, 30, "具体错误原因:");
					ege::outtextrect(30, 90, 280, 30, e.what());
					ege::outtextrect(30, 110, 280, 30, "已将错误值设为0！");
					ege::setfont(30, 0, "楷体");
					ege::outtextrect(30, 140, 280, 30, "请按任意键继续！");
					ege::getch();
				}
				rgbvalue = stol(RGBvalue);
				if (rgbvalue > 0xFFFFFF || rgbvalue < 0)
					throw ColorException();
			}
			catch (ColorException& e) {
				rgbvalue = 0;
				setfontbkcolor(WHITE);
				setfillcolor(WHITE);
				setviewport(0, 0, 300, 1920);
				clearviewport();
				setviewport(0, 0, 2560, 2560);
				ege::outtextrect(30, 30, 280, 30, "文件读取出错！");
				ege::setfont(20, 0, "楷体");
				ege::outtextrect(30, 70, 280, 30, "具体错误原因:");
				ege::outtextrect(30, 90, 280, 30, e.what());
				ege::outtextrect(30, 110, 280, 30, "已将错误值设为0！");
				ege::setfont(30, 0, "楷体");
				ege::outtextrect(30, 140, 280, 30, "请按任意键继续！");
				ege::getch();
			}
			cRectangle* r1 = new cRectangle(stoi(x1), stoi(y1), stoi(x2), stoi(y2), rgbvalue, rgbvalue, stoi(isfilled));
			geometries.push_back(r1);
		}
		else if (line1 == "3") {
		string x1, x2, y1, y2, x3, y3, RGBvalue, isfilled;
		long int rgbvalue;
		try {
			size_t pos1 = line2.find(" ", 0);
			size_t pos2 = line2.find(" ", pos1 + 1);
			size_t pos3 = line2.find(" ", pos2 + 1);
			size_t pos4 = line2.find(" ", pos3 + 1);
			size_t pos5 = line2.find(" ", pos4 + 1);
			size_t pos6 = line2.find(" ", pos5 + 1);
			if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos
				|| pos4 == string::npos || pos5 == string::npos) {
				throw DataLackException();
			}
			else if (pos6 != string::npos)
				throw DataSuperfluousException();
			x1 = line2.substr(0, pos1);
			y1 = line2.substr(pos1 + 1, pos2 - pos1 - 1);
			x2 = line2.substr(pos2 + 1, pos3 - pos2 - 1);
			y2 = line2.substr(pos3 + 1, pos4 - pos3 - 1);
			x3 = line2.substr(pos4 + 1, pos5 - pos4 - 1);
			y3 = line2.substr(pos5 + 1);
		}
		catch (DataException& e) {
			x1 = "0", x2 = "0", y1 = "0", y2 = "0", x3 = "0", y3 = "0";
			setfontbkcolor(WHITE);
			setfillcolor(WHITE);
			setviewport(0, 0, 300, 1920);
			clearviewport();
			setviewport(0, 0, 2560, 2560);
			ege::outtextrect(30, 30, 280, 30, "文件读取出错！");
			ege::setfont(20, 0, "楷体");
			ege::outtextrect(30, 70, 280, 30, "具体错误原因:");
			ege::outtextrect(30, 90, 280, 30, e.what());
			ege::outtextrect(30, 110, 280, 30, "已跳过错误数据！");
			ege::setfont(30, 0, "楷体");
			ege::outtextrect(30, 140, 280, 30, "请按任意键继续！");
			ege::getch();
			continue;
		}
		try {
			try {
				size_t pos1 = line3.find(" ");
				if (pos1 == string::npos) {
					throw DataLackException();
				}
				RGBvalue = line3.substr(0, pos1);
				isfilled = line3.substr(pos1 + 1);
			}
			catch (DataLackException& e) {
				RGBvalue = "0", isfilled = "1";
				setfontbkcolor(WHITE);
				setfillcolor(WHITE);
				setviewport(0, 0, 300, 1920);
				clearviewport();
				setviewport(0, 0, 2560, 2560);
				ege::outtextrect(30, 30, 280, 30, "文件读取出错！");
				ege::setfont(20, 0, "楷体");
				ege::outtextrect(30, 70, 280, 30, "具体错误原因:");
				ege::outtextrect(30, 90, 280, 30, e.what());
				ege::outtextrect(30, 110, 280, 30, "已将错误值设为0！");
				ege::setfont(30, 0, "楷体");
				ege::outtextrect(30, 140, 280, 30, "请按任意键继续！");
				ege::getch();
			}
			rgbvalue = stol(RGBvalue);
			if (rgbvalue > 0xFFFFFF || rgbvalue < 0)
				throw ColorException();
		}
		catch (ColorException& e) {
			rgbvalue = 0;
			setfontbkcolor(WHITE);
			setfillcolor(WHITE);
			setviewport(0, 0, 300, 1920);
			clearviewport();
			setviewport(0, 0, 2560, 2560);
			ege::outtextrect(30, 30, 280, 30, "文件读取出错！");
			ege::setfont(20, 0, "楷体");
			ege::outtextrect(30, 70, 280, 30, "具体错误原因:");
			ege::outtextrect(30, 90, 280, 30, e.what());
			ege::outtextrect(30, 110, 280, 30, "已将错误值设为0！");
			ege::setfont(30, 0, "楷体");
			ege::outtextrect(30, 140, 280, 30, "请按任意键继续！");
			ege::getch();
		}
		Point p1(stoi(x1), stoi(y1));
		Point p2(stoi(x2), stoi(y2));
		Point p3(stoi(x3), stoi(y3));
		Triangle* t1 = new Triangle(p1, p2, p3, rgbvalue, rgbvalue, stoi(isfilled));
		geometries.push_back(t1);
        }
		else if (line1 == "")
			break;
		else
			throw IDException();
	}
	input.close();
}

void FileIO::WriteToFile(vector<Shape*>& geometries) {
	fs::path geofile{ "figure files.txt" };
	ofstream output;
	output.open(geofile,ios::trunc);
	for (auto x : geometries) {
		x->WriteToFile(output);
	}
	output.close();
}



