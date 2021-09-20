#include<typeinfo>
#include"Menu.h"
#include"FileIOExceptions.h"

Menu::Menu() = default;

void Menu::menuloop() {
	for (; is_run(); delay_fps(300)) {
		cleardevice();
		drawgeometries();
		setcolor(BLACK);
		setlinewidth(1.0);
		mouse_msg msg = { 0 };
		while (mousemsg()) {
			msg = getmouse();
		}
		if (Mode::ChooseWhetherRead == this->mode) {
			setcolor(BLACK);
			setlinewidth(1.0);
			line(300, 0, 300, 2560);
			whetherread(msg);
		}
		else if (Mode::ChooseWhetherBegin == this->mode) {
			setcolor(BLACK);
			setlinewidth(1.0);
			line(300, 0, 300, 2560);
			beginmenu(msg);
		}
		else if (Mode::ChooseToDrawWhat == this->mode) {
			setcolor(BLACK);
			setlinewidth(1.0);
			line(300, 0, 300, 2560);
			geomenu(msg);
		}
		else if (Mode::ChooseGeometricColor == this->mode) {
			setcolor(BLACK);
			setlinewidth(1.0);
			line(300, 0, 300, 2560);
			setcolor(BLACK);
			setlinewidth(1.0);
			/*colormenu(msg);*/
			colormenu2(msg);
		}
		else if (Mode::Draw == this->mode) {
			cleardevice();
			break;
		}
		else if (Mode::TestOperatorOverride1 == this->mode) {
			setcolor(BLACK);
			setlinewidth(1.0);
			line(300, 0, 300, 2560);
			testoperatoroverride(msg);
		}
		else if (Mode::TestOperatorOverride2 == this->mode) {
			setcolor(BLACK);
			setlinewidth(1.0);
			line(300, 0, 300, 2560);
			testoperatoroverride2(msg);
		}
		else if (Mode::TestOperatorOverride3 == this->mode) {
			setcolor(BLACK);
			setlinewidth(1.0);
			line(300, 0, 300, 2560);
			testoperatoroverride3(msg);
		}
		else if (Mode::EXIT == this->mode) {
			std::exit(0);
		}
	}
}

void Menu::beginmenu(mouse_msg& msg) {
	setfontbkcolor(WHITE);
	outtextrect(30, 30, 280, 30, "你要开始绘图吗？");
	setfillcolor(LIGHTGRAY);
	int x, y;
	mousepos(&x, &y);
	if (x >= 30 && x <= 270 && y >= 180 && y <= 230) {
		rectangle(30, 280, 270, 330);
		outtextrect(65, 290, 270, 30, "再等一会儿？");
		setfontbkcolor(LIGHTGRAY);
		bar(30, 180, 270, 230);
		rectangle(30, 180, 270, 230);
		outtextrect(65, 190, 270, 30, "我准备好了！");
		if (msg.is_left() && msg.is_down()) {
			this->mode = Mode::ChooseToDrawWhat;
		}
	}
	else if (x >= 30 && x <= 270 && y >= 280 && y <= 330) {
		rectangle(30, 180, 270, 230);
		outtextrect(65, 190, 270, 30, "我准备好了！");
		setfontbkcolor(LIGHTGRAY);
		bar(30, 280, 270, 330);
		rectangle(30, 280, 270, 330);
		outtextrect(65, 290, 270, 30, "再等一会儿？");
		if (msg.is_left() && msg.is_down()) {
			this->mode = Mode::EXIT;
		}
	}
	else {
		rectangle(30, 180, 270, 230);
		outtextrect(65, 190, 270, 30, "我准备好了！");
		rectangle(30, 280, 270, 330);
		outtextrect(65, 290, 270, 30, "再等一会儿？");
	}
}

void Menu::geomenu(mouse_msg& msg) {
	setfontbkcolor(WHITE);
	outtextrect(30, 30, 280, 30, "你要画个什么呢？");
	setfillcolor(LIGHTGRAY);
	int x, y;
	mousepos(&x, &y);
	if (x >= 30 && x <= 270 && y >= 180 && y <= 230) {
		rectangle(30, 280, 270, 330);
		outtextrect(55, 290, 270, 30, "我要画个矩形~");
		rectangle(30, 380, 270, 430);
		outtextrect(35, 390, 270, 30, "我要画个三角形~");
		setfontbkcolor(LIGHTGRAY);
		bar(30, 180, 270, 230);
		rectangle(30, 180, 270, 230);
		outtextrect(70, 190, 270, 30, "我要画个圆~");
		if (msg.is_left() && msg.is_down()) {
			this->mode = Mode::ChooseGeometricColor;
			setnowGeo(NOWGEO::CIRCLE);
		}
	}
	else if (x >= 30 && x <= 270 && y >= 280 && y <= 330) {
		rectangle(30, 180, 270, 230);
		outtextrect(70, 190, 270, 30, "我要画个圆~");
		rectangle(30, 380, 270, 430);
		outtextrect(35, 390, 270, 30, "我要画个三角形~");
		setfontbkcolor(LIGHTGRAY);
		bar(30, 280, 270, 330);
		rectangle(30, 280, 270, 330);
		outtextrect(55, 290, 270, 30, "我要画个矩形~");
		if (msg.is_left() && msg.is_down()) {
			this->mode = Mode::ChooseGeometricColor;
			setnowGeo(NOWGEO::RECTANGLE);
		}
	}
	else if (x >= 30 && x <= 270 && y >= 380 && y <= 430) {
		rectangle(30, 180, 270, 230);
		outtextrect(70, 190, 270, 30, "我要画个圆~");
		rectangle(30, 280, 270, 330);
		outtextrect(55, 290, 270, 30, "我要画个矩形~");
		setfontbkcolor(LIGHTGRAY);
		bar(30, 380, 270, 430);
		rectangle(30, 380, 270, 430);
		outtextrect(35, 390, 270, 30, "我要画个三角形~");
		if (msg.is_left() && msg.is_down()) {
			this->mode = Mode::ChooseGeometricColor;
			setnowGeo(NOWGEO::TRIANGLE);
		}
	}
	else {
		rectangle(30, 180, 270, 230);
		outtextrect(70, 190, 270, 30, "我要画个圆~");
		rectangle(30, 280, 270, 330);
		outtextrect(55, 290, 270, 30, "我要画个矩形~");
		rectangle(30, 380, 270, 430);
		outtextrect(35, 390, 270, 30, "我要画个三角形~");
	}
}

void Menu::colormenu(mouse_msg& msg) {
	setfontbkcolor(WHITE);
	outtextrect(30, 30, 280, 30, "快来选个颜色吧！");
	setfillcolor(BLACK);
	bar(20,180,85,245);
	setfillcolor(BLUE);
	bar(85,180,150,245);
	setfillcolor(GREEN);
	bar(150,180,215,245);
	setfillcolor(CYAN);
	bar(215,180,280,245);
	setfillcolor(RED);
	bar(20,245,85,310);
	setfillcolor(MAGENTA);
	bar(85,245,250,310);
	setfillcolor(BROWN);
	bar(150,245,215,310);
	setfillcolor(LIGHTGRAY);
	bar(215,245,280,310);
	setfillcolor(DARKGRAY);
	bar(20,310,85,375);
	setfillcolor(LIGHTBLUE);
	bar(85,310,150,375);
	setfillcolor(LIGHTGREEN);
	bar(150,310,215,375); 
	setfillcolor(LIGHTCYAN);
	bar(215,310,280,375);
	setfillcolor(LIGHTRED);
	bar(20,375,85,440);
	setfillcolor(LIGHTMAGENTA);
	bar(85,375,150,440);
	setfillcolor(YELLOW);
	bar(150,375,215,440);
	setfillcolor(WHITE);
	bar(215,375,280,440);
	int x, y;
	mousepos(&x, &y);
	setcolor(BLACK);
	if (y > 180 && y < 245) {
		if (x > 20 && x < 85) {
			rectangle(20, 180, 85, 245);
			if (msg.is_down() && msg.is_left() ) {
				setnowColor(getpixel(x, y));
				this->mode = Mode::Draw;
			}
		}
		else if (x > 85 && x < 150) {
			rectangle(85, 180, 150, 245);
			if (msg.is_down() && msg.is_left()) {
				setnowColor(getpixel(x, y));
				this->mode = Mode::Draw;
			}
		}
		else if (x > 150 && x < 215) {
			rectangle(150, 180, 215, 245);
			if (msg.is_down() && msg.is_left()) {
				setnowColor(getpixel(x, y));
				this->mode = Mode::Draw;
			}
		}
		else if (x > 215 && x < 280) {
			rectangle(215, 180, 280, 245);
			if (msg.is_down() && msg.is_left()) {
				setnowColor(getpixel(x, y));
				this->mode = Mode::Draw;
			}
		}
	}
	else if (y > 245 && y < 320) {
		if (x > 20 && x < 85) {
			rectangle(20, 245, 85, 310);
			if (msg.is_down() && msg.is_left()) {
				setnowColor(getpixel(x, y));
				this->mode = Mode::Draw;
			}
		}
		else if (x > 85 && x < 150) {
			rectangle(85, 245, 150, 310);
			if (msg.is_down() && msg.is_left()) {
				setnowColor(getpixel(x, y));
				this->mode = Mode::Draw;
			}
		}
		else if (x > 150 && x < 215) {
			rectangle(150, 245, 215, 310);
			if (msg.is_down() && msg.is_left()) {
				setnowColor(getpixel(x, y));
				this->mode = Mode::Draw;
			}
		}
		else if (x > 215 && x < 280) {
			rectangle(215, 245, 280, 310);
			if (msg.is_down() && msg.is_left()) {
				setnowColor(getpixel(x, y));
				this->mode = Mode::Draw;
			}
		}
	}
	else if (y > 320 && y < 375) {
		if (x > 20 && x < 85) {
			rectangle(20, 310, 85, 375);
			if (msg.is_down() && msg.is_left()) {
				setnowColor(getpixel(x, y));
				this->mode = Mode::Draw;
			}
		}
		else if (x > 85 && x < 150) {
			rectangle(85, 310, 150, 375);
			if (msg.is_down() && msg.is_left()) {
				setnowColor(getpixel(x, y));
				this->mode = Mode::Draw;
			}
		}
		else if (x > 150 && x < 215) {
			rectangle(150, 310, 215, 375);
			if (msg.is_down() && msg.is_left()) {
				setnowColor(getpixel(x, y));
				this->mode = Mode::Draw;
			}
		}
		else if (x > 215 && x < 280) {
			rectangle(215, 310, 280, 375);
			if (msg.is_down() && msg.is_left()) {
				setnowColor(getpixel(x, y));
				this->mode = Mode::Draw;
			}
		}
	}
	else if (y > 375 && y < 440) {
		if (x > 20 && x < 85) {
			rectangle(20, 375, 85, 440);
			if (msg.is_down() && msg.is_left()) {
				setnowColor(getpixel(x, y));
				this->mode = Mode::Draw;
			}
		}
		else if (x > 85 && x < 150) {
			rectangle(85, 375, 150, 440);
			if (msg.is_down() && msg.is_left()) {
				setnowColor(getpixel(x, y));
				this->mode = Mode::Draw;
			}
		}
		else if (x > 150 && x < 215) {
			rectangle(150, 375, 215, 440);
			if (msg.is_down() && msg.is_left()) {
				setnowColor(getpixel(x, y));
				this->mode = Mode::Draw;
			}
		}
		else if (x > 215 && x < 280) {
			rectangle(215, 375, 280, 440);
			if (msg.is_down() && msg.is_left()) {
				setnowColor(getpixel(x, y));
				this->mode = Mode::Draw;
			}
		}
	}
}

void Menu::colormenu2(mouse_msg& msg) {
	setfontbkcolor(WHITE);
	outtextrect(30, 30, 280, 30, "快来选个颜色吧！");
	setfillcolor(BLACK);
	PIMAGE pimg = newimage(180,500);
	PIMAGE temp = newimage();
	getimage(temp, "RGB.png");
	int tempWidth = getwidth(temp), tempHeight = getheight(temp);
	putimage(pimg, 0, 0, 180, 500, temp, 0, 0, tempWidth, tempHeight);
	delimage(temp);
	temp = nullptr;
	putimage(60, 120, pimg);
	int x, y;
	mousepos(&x, &y);
	if (x >= 60 && x <=240 && y >= 120 && y <= 620 ) {
		color_t tempcolor = getpixel(x, y) & 0x00FFFFFF;
		setfillcolor(tempcolor);
		setfont(20, 0, "楷体");
		xyprintf(30, 80, "当前所选颜色：");
		setfont(30, 0, "楷体");
		bar(180, 80, 250, 100);
		setfillcolor(BLACK);
		if (msg.is_down() && msg.is_left()) {
			setnowColor(getpixel(x, y) & 0x00FFFFFF);
			this->mode = Mode::Draw;
		}
	}
	else {
		setfont(20, 0, "楷体");
		outtextrect(30, 80, 290, 80, "请在下方调色盘中选择颜色！");
		setfont(30, 0, "楷体");
	}
	delimage(pimg);
}

void Menu::whetherread(mouse_msg& msg) {
	setfontbkcolor(WHITE);
	outtextrect(30, 30, 280, 30, "你要读取文件吗？");
	setfillcolor(LIGHTGRAY);
	int x, y;
	mousepos(&x, &y);
	if (x >= 30 && x <= 270 && y >= 180 && y <= 230) {
		rectangle(30, 280, 270, 330);
		outtextrect(60, 290, 270, 30, "先不读取文件");
		setfontbkcolor(LIGHTGRAY);
		bar(30, 180, 270, 230);
		rectangle(30, 180, 270, 230);
		outtextrect(60, 190, 270, 30, "我要读取文件");
		if (msg.is_left() && msg.is_down()) {
			try {
				f.ReadFromFile1(geometries);
			}
			catch (exception& e) {
				setfontbkcolor(WHITE);
				setfillcolor(WHITE);
				setviewport(0, 0, 300, 1920);
				clearviewport();
				setviewport(0, 0, 2560, 2560);
				outtextrect(30, 30, 280, 30, "文件读取出错！");
				setfont(20, 0, "楷体");
				outtextrect(30, 70, 280, 30, "具体错误原因:");
				outtextrect(30, 90, 280, 30, e.what());
				setfont(30, 0, "楷体");
				outtextrect(30, 140, 280, 30, "请按任意键继续！");
				getch();
			}
			this->mode = Mode::ChooseWhetherBegin;
		}
	}
	else if (x >= 30 && x <= 270 && y >= 280 && y <= 330) {
		rectangle(30, 180, 270, 230);
		outtextrect(60, 190, 270, 30, "我要读取文件");
		setfontbkcolor(LIGHTGRAY);
		bar(30, 280, 270, 330);
		rectangle(30, 280, 270, 330);
		outtextrect(60, 290, 270, 30, "先不读取文件");
		if (msg.is_left() && msg.is_down()) {
			fs::path geofile{ "figure files.txt" };
			ofstream tempout{ geofile,std::ios::trunc };
			tempout.close();
			this->mode = Mode::ChooseWhetherBegin;
		}
	}
	else {
		rectangle(30, 180, 270, 230);
		outtextrect(60, 190, 270, 30, "我要读取文件");
		rectangle(30, 280, 270, 330);
		outtextrect(60, 290, 270, 30, "先不读取文件");
	}
}

void Menu::testoperatoroverride(mouse_msg& msg) {
	int x, y;
	mousepos(&x, &y);
	setfontbkcolor(WHITE);
	outtextrect(10, 30, 300, 30, "欢迎测试运算符重载！");
	line(300, 0, 300, 1920);
	setfillcolor(LIGHTGRAY);
	setfont(20, 0, "楷体");
	xyprintf(10, 100, "比较最后两个图形面积的结果：");
	setfont(20, 0, "黑体");
	xyprintf(10, 130, "Area of Shape1 : %.3f", geometries[geometries.size() - 2]->getArea());
	xyprintf(10, 160, "Area of Shape2 : %.3f", geometries[geometries.size() - 1]->getArea());
	const char* cpr1 = geometries[geometries.size() - 2]->operator>=(geometries[geometries.size() - 1]) ? "true" : "false";
	const char* cpr2 = geometries[geometries.size() - 2]->operator>(geometries[geometries.size() - 1]) ? "true" : "false";
	const char* cpr3 = geometries[geometries.size() - 2]->operator<=(geometries[geometries.size() - 1]) ? "true" : "false";
	const char* cpr4 = geometries[geometries.size() - 2]->operator<(geometries[geometries.size() - 1]) ? "true" : "false";
	const char* cpr5 = geometries[geometries.size() - 2]->operator==(geometries[geometries.size() - 1]) ? "true" : "false";
	const char* cpr6 = geometries[geometries.size() - 2]->operator!=(geometries[geometries.size() - 1]) ? "true" : "false";
	xyprintf(10, 190, "Shape1 >= Shape2 : %s", cpr1);
	xyprintf(10, 220, "Shape1 >  Shape2 : %s", cpr2);
	xyprintf(10, 250, "Shape1 <= Shape2 : %s", cpr3);
	xyprintf(10, 280, "Shape1 <  Shape2 : %s", cpr4);
	xyprintf(10, 310, "Shape1 == Shape2 : %s", cpr5);
	xyprintf(10, 340, "Shape1 != Shape2 : %s", cpr6);
	setfont(30, 0, "楷体");
	rectangle(30, 380, 270, 430);
	outtextrect(45, 390, 270, 30, "测试其他运算符");
	rectangle(30, 480, 270, 530);
	outtextrect(60, 490, 270, 30, "返回绘图界面");
	if (x >= 30 && x <= 270 && y >= 480 && y <= 530 && this->geometries.size() >= 2) {
		setfontbkcolor(LIGHTGRAY);
		setfillcolor(LIGHTGRAY);
		bar(30, 480, 270, 530);
		rectangle(30, 480, 270, 530);
		outtextrect(60, 490, 270, 30, "返回绘图界面");
		if (msg.is_down() && msg.is_left())
			this->mode = Mode::Draw;
	}
	else if (x >= 30 && x <= 270 && y >= 380 && y <= 430 && this->geometries.size() >= 2) {
		setfontbkcolor(LIGHTGRAY);
		setfillcolor(LIGHTGRAY);
		bar(30, 380, 270, 430);
		rectangle(30, 380, 270, 430);
		outtextrect(45, 390, 270, 30, "测试其他运算符");
		if (msg.is_down() && msg.is_left())
			this->mode = Mode::TestOperatorOverride2;
	}
}

void Menu::testoperatoroverride2(mouse_msg& msg) {
	int x, y;
	mousepos(&x, &y);
	setfontbkcolor(WHITE);
	outtextrect(10, 30, 300, 30, "欢迎测试运算符重载！");
	line(300, 0, 300, 1920);
	setfillcolor(LIGHTGRAY);
	setfont(20, 0, "楷体");
	testcoloroperator(*(geometries[geometries.size() - 2]), *(geometries[geometries.size() - 1]), msg);
	testdeepcopy(geometries[geometries.size() - 2], geometries[geometries.size() - 1], msg);
	setfont(30, 0, "楷体");
	rectangle(30, 480, 270, 530);
	outtextrect(60, 490, 270, 30, "返回上一界面");
	rectangle(30, 580, 270, 630);
	outtextrect(45, 590, 270, 30, "测试特殊运算符");
	if (x >= 30 && x <= 270 && y >= 480 && y <= 530 && this->geometries.size() >= 2) {
		setfontbkcolor(LIGHTGRAY);
		setfillcolor(LIGHTGRAY);
		bar(30, 480, 270, 530);
		rectangle(30, 480, 270, 530);
		outtextrect(60, 490, 270, 30, "返回上一界面");
		if (msg.is_down() && msg.is_left())
			this->mode = Mode::TestOperatorOverride1;
	}
	else if (x >= 30 && x <= 270 && y >= 580 && y <= 630 && this->geometries.size() >= 2) {
		setfontbkcolor(LIGHTGRAY);
		setfillcolor(LIGHTGRAY);
		bar(30, 580, 270, 630);
		rectangle(30, 580, 270, 630);
		outtextrect(45, 590, 270, 30, "测试特殊运算符");
		if (msg.is_down() && msg.is_left())
			this->mode = Mode::TestOperatorOverride3;
	}
}

void Menu::testoperatoroverride3(mouse_msg& msg) {
	int x, y;
	mousepos(&x, &y);
	setfontbkcolor(WHITE);
	Color tempcolor{ geometries.back()->getBorderColor() };
	setfont(20, 0, "楷体");
	outtextrect(10, 30, 270, 60, "现在让我们来测试一些奇怪的运算符吧！");
	xyprintf(10, 100, "最后一个图形的颜色为：");
	xyprintf(10, 130, "(%d,%d,%d)", tempcolor[0], tempcolor[1], tempcolor[2]);
	Color tempcolor1 = tempcolor++;
	xyprintf(10, 160, "执行一次后置++：(%d,%d,%d)",tempcolor1[0],tempcolor1[1],tempcolor1[2]);
	Color tempcolor2 = ++tempcolor;
	xyprintf(10, 190, "再执行一次前置++：(%d,%d,%d)", tempcolor2[0], tempcolor2[1], tempcolor2[2]);
	xyprintf(10, 220, "shape1[0]:(%d,%d)",
		geometries[geometries.size() - 2]->operator[](0).getX(), geometries[geometries.size() - 2]->operator[](0).getY());
	xyprintf(10, 250, "shape2[0]:(%d,%d)",
		geometries[geometries.size() - 1]->operator[](0).getX(), geometries[geometries.size() - 1]->operator[](0).getY());
	Point temppoint = geometries[geometries.size() - 2]->operator[](0) + geometries[geometries.size() - 1]->operator[](0);
	xyprintf(10, 280, "shape1[0]+shape2[0]=(%d,%d)", temppoint.getX(), temppoint.getY());
	setfont(30, 0, "楷体");
	rectangle(30, 380, 270, 430);
	outtextrect(60, 390, 270, 30, "返回上一界面");
	rectangle(30, 480, 270, 530);
	outtextrect(60, 490, 270, 30, "返回绘图界面");
	if (x >= 30 && x <= 270 && y >= 380 && y <= 430 && this->geometries.size() >= 2) {
		setfontbkcolor(LIGHTGRAY);
		setfillcolor(LIGHTGRAY);
		bar(30, 380, 270, 430);
		rectangle(30, 380, 270, 430);
		outtextrect(60, 390, 270, 30, "返回上一界面");
		if (msg.is_down() && msg.is_left())
			this->mode = Mode::TestOperatorOverride2;
	}
	else if (x >= 30 && x <= 270 && y >= 480 && y <= 530 && this->geometries.size() >= 2) {
		setfontbkcolor(LIGHTGRAY);
		setfillcolor(LIGHTGRAY);
		bar(30, 480, 270, 530);
		rectangle(30, 480, 270, 530);
		outtextrect(60, 490, 270, 30, "返回绘图界面");
		if (msg.is_down() && msg.is_left())
			this->mode = Mode::Draw;
	}
}

void Menu::testcoloroperator(Shape& s1,Shape& s2,mouse_msg& msg) {
	int x, y;
	mousepos(&x, &y);
	xyprintf(10, 100, "比较最后两个图形颜色的结果：");
	xyprintf(10, 130, "Color of Shape1:");
	xyprintf(10, 160, "(%d,%d,%d)", s1.getBorderColor1()[0], s1.getBorderColor1()[1], s1.getBorderColor1()[2]);
	xyprintf(10, 190, "Color of Shape2:");
	xyprintf(10, 220, "(%d,%d,%d)", s2.getBorderColor1()[0], s2.getBorderColor1()[1], s2.getBorderColor1()[2]);
	rectangle(150, 160, 200, 180);
	outtextrect(165, 161, 40, 18, "++");
	rectangle(200, 160, 250, 180);
	outtextrect(215, 161, 40, 18, "--");
	rectangle(150, 220, 200, 240);
	outtextrect(165, 221, 40, 18, "++");
	rectangle(200, 220, 250, 240);
	outtextrect(215, 221, 40, 18, "--");
	if (x >= 150 && x <= 200 && y >= 160 && y <= 180) {
		setfontbkcolor(LIGHTGRAY);
		setfillcolor(LIGHTGRAY);
		bar(150, 160, 200, 180);
		rectangle(150, 160, 200, 180);
		outtextrect(165, 161, 40, 18, "++");
		if (msg.is_down() && msg.is_left() /*|| keystate(key_mouse_l)*/)/*这是快速模式，要减速就注释掉||之后的东西*/ {
			for (int i = 0; i < 5; i++)
				s1.getBorderColor1()++, s1.getFilledColor1()++;
		}
	}
	else if (x >= 200 && x <= 250 && y >= 160 && y <= 180) {
		setfontbkcolor(LIGHTGRAY);
		setfillcolor(LIGHTGRAY);
		bar(200, 160, 250, 180);
		rectangle(200, 160, 250, 180);
		outtextrect(215, 161, 40, 18, "--");
		if (msg.is_down() && msg.is_left()/*||keystate(key_mouse_l)*/) {
			for (int i = 0; i < 5; i++)
				s1.getBorderColor1()--, s1.getFilledColor1()--;
		}
	}
	else if (x >= 150 && x <= 200 && y >= 220 && y <= 240) {
		setfontbkcolor(LIGHTGRAY);
		setfillcolor(LIGHTGRAY);
		bar(150, 220, 200, 240);
		rectangle(150, 220, 200, 240);
		outtextrect(165, 221, 40, 18, "++");
		if (msg.is_down() && msg.is_left() /*|| keystate(key_mouse_l)*/)/*这是快速模式，要减速就注释掉||之后的东西*/ {
			for (int i = 0; i < 5; i++)
				s2.getBorderColor1()++, s2.getFilledColor1()++;
		}
	}
	else if (x >= 200 && x <= 250 && y >= 220 && y <= 240) {
		setfontbkcolor(LIGHTGRAY);
		setfillcolor(LIGHTGRAY);
		bar(200, 220, 250, 240);
		rectangle(200, 220, 250, 240);
		outtextrect(215, 221, 40, 18, "--");
		if (msg.is_down() && msg.is_left()/*||keystate(key_mouse_l)*/) {
			for (int i = 0; i < 5; i++)
				s2.getBorderColor1()--, s2.getFilledColor1()--;
		}
	}
	const char* cpr1 = s1.getBorderColor1() == s2.getBorderColor1() ? "true" : "false";
	const char* cpr2 = s1.getBorderColor1() != s2.getBorderColor1() ? "true" : "false";
	setfontbkcolor(WHITE);
	xyprintf(10, 250, "Color1 == Color2 : %s", cpr1);
	xyprintf(10, 280, "Color1 != Color2 : %s", cpr2);
}

void Menu::testdeepcopy(Shape*& s1, Shape*& s2, mouse_msg& msg) {
	int x, y;
	mousepos(&x, &y);
	if (typeid(*s1) == typeid(*s2)) {
		xyprintf(10, 310, "最后两个图形类型相同！");
		xyprintf(10, 340, "允许进行深拷贝！");
		setfont(30, 0, "楷体");
		rectangle(30, 380, 270, 430);
		outtextrect(75, 390, 270, 30, "测试深拷贝");
		if (x >= 30 && x <= 270 && y >= 380 && y <= 430) {
			setfontbkcolor(LIGHTGRAY);
			setfillcolor(LIGHTGRAY);
			bar(30, 380, 270, 430);
			rectangle(30, 380, 270, 430);
			outtextrect(75, 390, 270, 30, "测试深拷贝");
			if (msg.is_down() && msg.is_left()) {
				if (typeid(*s1) == typeid(Circle)) {
					Circle* temp1 = new Circle(dynamic_cast<Circle*>(s1));
					Circle* temp2 = new Circle(dynamic_cast<Circle*>(s2));
					*temp1 = *(temp2);
					delete s1;
					s1 = nullptr;
					s1 = temp1;
					delete temp2;
					temp2 = nullptr;
				}
				else if (typeid(*s1) == typeid(cRectangle)) {
					cRectangle* temp1 = new cRectangle(dynamic_cast<cRectangle*>(s1));
					cRectangle* temp2 = new cRectangle(dynamic_cast<cRectangle*>(s2));
					*temp1 = *(temp2);
					delete s1;
					s1 = nullptr;
					s1 = temp1;
					delete temp2;
					temp2 = nullptr;
				}
				else if (typeid(*s1) == typeid(Triangle)) {
					Triangle* temp1 = new Triangle(dynamic_cast<Triangle*>(s1));
					Triangle* temp2 = new Triangle(dynamic_cast<Triangle*>(s2));
					*temp1 = *(temp2);
					delete s1;
					s1 = nullptr;
					s1 = temp1;
					delete temp2;
					temp2 = nullptr;
				}
			}
		}
	}
	else 
		xyprintf(10, 310, "最后两个图形类型不同！");
	setfontbkcolor(WHITE);
}