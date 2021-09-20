#include"Board.h"

Board::Board() = default;

Board::Board(NOWGEO nowGeo_) {
	this->nowGeo = nowGeo_;
}

void Board::setnowColor(color_t nowColor_) {
	this->nowColor = nowColor_;
}

void Board::setnowGeo(NOWGEO nowGeo_) {
	this->nowGeo = nowGeo_;
}

void Board::boardloop() {
	for (; is_run(); delay_fps(300)) {
		cleardevice();
		drawgeometries();
		f.WriteToFile(this->geometries);
		judgewhetherfilled();
		createmenuboard();
		int x, y;
		mousepos(&x, &y);
		setfillcolor(CYAN);
		if (x < 300) {
			mouse_msg msg = { 0 };
			while (mousemsg()) {
				msg = getmouse();
			}
			if (x >= 30 && x <= 270 && y >= 180 && y <= 230) {
				setfontbkcolor(LIGHTGRAY);
				setfillcolor(LIGHTGRAY);
				bar(30, 180, 270, 230);
				rectangle(30, 180, 270, 230);
				outtextrect(90, 190, 270, 30, "填    充");
				if (msg.is_down() && msg.is_left()) {
					this->nowIsFilled = !this->nowIsFilled;
				}
			}
			else if (x >= 30 && x <= 270 && y >= 280 && y <= 330) {
				setfontbkcolor(LIGHTGRAY);
				setfillcolor(LIGHTGRAY);
				bar(30, 280, 270, 330);
				rectangle(30, 280, 270, 330);
				outtextrect(55, 290, 270, 30, "我要换个图形~");
				if (msg.is_down() && msg.is_left()) {
					this->mode = Mode::ChooseToDrawWhat;
					break;
				}
			}
			else if (x >= 30 && x <= 270 && y >= 380 && y <= 430) {
				setfontbkcolor(LIGHTGRAY);
				setfillcolor(LIGHTGRAY);
				bar(30, 380, 270, 430);
				rectangle(30, 380, 270, 430);
				outtextrect(55, 390, 270, 30, "刚才画错了呢~");
				if (msg.is_down() && msg.is_left()) {
					withdraw();
				}
			}
			else if (x >= 30 && x <= 270 && y >= 480 && y <= 530 && this->geometries.size() >= 2) {
				setfontbkcolor(LIGHTGRAY);
				setfillcolor(LIGHTGRAY);
				bar(30, 480, 270, 530);
				rectangle(30, 480, 270, 530);
				outtextrect(45, 490, 270, 30, "测试重载运算符");
				if (msg.is_down() && msg.is_left()) {
					this->mode = Mode::TestOperatorOverride1;
					break;
				}
			}
		}
		else if (x >= 300) {
			if (NOWGEO::CIRCLE == this->nowGeo) {
				drawcircle();
			}
			else if (NOWGEO::RECTANGLE == this->nowGeo) {
				drawrectangle();
			}
			else if (NOWGEO::TRIANGLE == this->nowGeo) {
				drawtriangle();
			}
		}
	}
}

void Board::drawcircle() {
	bool downflag{ false };
	mouse_msg firstmsg{ 0 };
	int first_x, first_y;
	mousepos(&first_x, &first_y);
	while (mousemsg())
		firstmsg = getmouse();
	if (firstmsg.is_left() && firstmsg.is_down()) {
		downflag = !downflag;
		Point p1(firstmsg.x, firstmsg.y);
		while (downflag) {
			mouse_msg secondmsg{ 0 };
			int second_x{ 0 }, second_y{ 0 };
			while (mousemsg()) 
				secondmsg = getmouse();
			mousepos(&second_x, &second_y);
			Point p2{ static_cast<int>(second_x),static_cast<int>(second_y) };
			Circle* c1 = new Circle(p1.getX(), p1.getY(), p2.getX(), p2.getY(), this->nowColor, this->nowColor, this->nowIsFilled);
			if (secondmsg.is_up() && secondmsg.is_left()) {
				geometries.push_back(c1);
				downflag = !downflag;
				break;
			}
			else{
				setfont(20, 0, "楷体");
				xyprintf(30, 650, "起始点坐标：%4d,%4d", firstmsg.x, firstmsg.y);
				xyprintf(30, 670, "当前点坐标: %4d,%4d", second_x, static_cast<int>(second_y));
				if (second_x <= 300) {
					setcolor(RED);
					xyprintf(30, 690, "请勿将图形画在菜单区！");
					setcolor(BLACK);
				}
				else {
					xyprintf(30, 690, "                     ");
				}
				setfont(30, 0, "楷体");
				setviewport(301, 0, 2560, 2560);
				clearviewport();
				setviewport(0, 0, 2560, 2560);
				drawgeometries();
				c1->draw();
				delete c1;
				c1 = nullptr;
			}
		}
	}
}

void Board::drawrectangle() {
	bool downflag{ false };
	mouse_msg firstmsg{ 0 };
	int first_x, first_y;
	mousepos(&first_x, &first_y);
	while (mousemsg())
		firstmsg = getmouse();
	if (firstmsg.is_left() && firstmsg.is_down()) {
		downflag = !downflag;
		Point p1(firstmsg.x, firstmsg.y);
		while (downflag) {
			mouse_msg secondmsg{ 0 };
			int second_x{ 0 }, second_y{ 0 };
			while (mousemsg())
				secondmsg = getmouse();
			mousepos(&second_x, &second_y);
			Point p2{ static_cast<int>(second_x),static_cast<int>(second_y) };
			cRectangle* r1 = new cRectangle(p1.getX(), p1.getY(), p2.getX(), p2.getY(), this->nowColor, this->nowColor, this->nowIsFilled);
			if (secondmsg.is_up() && secondmsg.is_left()) {
				geometries.push_back(r1);
				downflag = !downflag;
				break;
			}
			else {
				setfont(20, 0, "楷体");
				xyprintf(30, 650, "起始点坐标：%4d,%4d", firstmsg.x, firstmsg.y);
				xyprintf(30, 670, "当前点坐标: %4d,%4d", second_x, static_cast<int>(second_y));
				if (second_x <= 300) {
					setcolor(RED);
					xyprintf(30, 690, "请勿将图形画在菜单区！");
					setcolor(BLACK);
				}
				else {
					xyprintf(30, 690, "                     ");
				}
				setfont(30, 0, "楷体");
				setviewport(301, 0, 2560, 2560);
				clearviewport();
				setviewport(0, 0, 2560, 2560);
				drawgeometries();
				r1->draw();
				delete r1;
				r1 = nullptr;
			}
		}
	}
}

void Board::drawtriangle() {
	bool downflag{ false };
	mouse_msg firstmsg{ 0 };
	int first_x, first_y;
	mousepos(&first_x, &first_y);
	while (mousemsg())
		firstmsg = getmouse();
	if (firstmsg.is_left() && firstmsg.is_down()) {
		downflag = !downflag;
		Point p1(firstmsg.x, firstmsg.y);
		while (is_run()) {
			mouse_msg secondmsg{ 0 };
			int second_x{ 0 }, second_y{ 0 };
			while (mousemsg())
				secondmsg = getmouse();
			mousepos(&second_x, &second_y);
			Point p2{ static_cast<int>(second_x),static_cast<int>(second_y) };
			tempLine[0] = p1.getX();
			tempLine[1] = p1.getY();
			tempLine[2] = p2.getX();
			tempLine[3] = p2.getY();
			line(tempLine[0], tempLine[1], tempLine[2], tempLine[3]);
			if (secondmsg.is_up() && secondmsg.is_left() && downflag) {
				setcolor(this->nowColor);
				line(p1.getX(), p1.getY(), p2.getX(), p2.getY());
				downflag = !downflag;
				while (is_run()) {
					mouse_msg thirdmsg{ 0 };
					int third_x{ 0 }, third_y{ 0 };
					while (mousemsg())
						thirdmsg = getmouse();
					mousepos(&third_x, &third_y);
					if (thirdmsg.is_down() && thirdmsg.is_left()) {
						Point p3{ static_cast<int>(third_x),static_cast<int>(third_y) };
						Triangle* t1 = new Triangle(p1, p2, p3, this->nowColor, this->nowColor, this->nowIsFilled);
						geometries.push_back(t1);
						break;
					}
					else {
						setfont(20, 0, "楷体");
						setcolor(BLACK);
						xyprintf(30, 650, "顶点一坐标：%4d,%4d", firstmsg.x, firstmsg.y);
						xyprintf(30, 670, "顶点二坐标: %4d,%4d", static_cast<int>(second_x), static_cast<int>(second_y));
						xyprintf(30, 690, "当前点坐标: %4d,%4d", static_cast<int>(third_x), static_cast<int>(third_y));
						if (third_x <= 300) {
							setcolor(RED);
							xyprintf(30, 690, "请勿将图形画在菜单区！");
							setcolor(BLACK);
						}
						else {
							xyprintf(30, 690, "                     ");
						}
						setfont(30, 0, "楷体");
						setviewport(301, 0, 2560, 2560);
						setfillcolor(WHITE);
						clearviewport();
						setviewport(0, 0, 2560, 2560);
						drawgeometries();
						setcolor(this->nowColor);
						line(p1.getX(), p1.getY(), p2.getX(), p2.getY());
					}
			}
				break;
		}
			else if(downflag) {
				setfont(20, 0, "楷体");
				setcolor(BLACK);
				xyprintf(30, 650, "顶点一坐标：%4d,%4d", firstmsg.x, firstmsg.y);
				xyprintf(30, 670, "顶点二坐标: %4d,%4d", second_x, static_cast<int>(second_y));
				if (second_x <= 300) {
					xyprintf(30, 690, "请勿将图形画在菜单区！");
				}
				else {
					xyprintf(30, 690, "                     ");
				}
				setfont(30, 0, "楷体");
				setviewport(301, 0, 2560, 2560);
				setfillcolor(WHITE);
				clearviewport();
				setviewport(0, 0, 2560, 2560);
				drawgeometries();
				setcolor(this->nowColor);
				line(p1.getX(), p1.getY(), p2.getX(), p2.getY());
			}
		}
	}
}

void Board::drawgeometries() {
	for (auto x : geometries) {
		x->draw();
	}
}

void Board::judgewhetherfilled() {
	if (this->nowIsFilled) {
		setfontbkcolor(CYAN);
		setfillcolor(CYAN);
		bar(30, 180, 270, 230);
		rectangle(30, 180, 270, 230);
		outtextrect(90, 190, 270, 30, "填    充");
	}
	else {
		rectangle(30, 180, 270, 230);
		setfontbkcolor(WHITE);
		outtextrect(90, 190, 270, 30, "填    充");
	}
}

void Board::createmenuboard() {
	setfontbkcolor(WHITE);
	rectangle(30, 280, 270, 330);
	outtextrect(55, 290, 270, 30, "我要换个图形~");
	rectangle(30, 380, 270, 430);
	outtextrect(55, 390, 270, 30, "刚才画错了呢~");
	if (this->geometries.size() >= 2) {
		rectangle(30, 480, 270, 530);
		outtextrect(45, 490, 270, 30, "测试重载运算符");
	}
	setcolor(BLACK);
	outtextrect(30, 30, 280, 30, "可以开始画图了！");
	setfont(20, 0, "楷体");
	xyprintf(30, 70, "你已经画了%d个图形了！", static_cast<int>(geometries.size()));
	xyprintf(30, 90, "你已经画了%d个圆形了！", Circle::getCountOfCircle());
	xyprintf(30, 110, "你已经画了%d个矩形了！", cRectangle::getCountOfRectangle());
	xyprintf(30, 130, "你已经画了%d个三角形了！", Triangle::getCountOfTriangle());
	setfont(30, 0, "楷体");
	setlinewidth(1.0);
	setcolor(BLACK);
	line(300, 0, 300, 2560);
}

void Board::withdraw() {
	if (!this->geometries.empty()) {
		delete geometries.back();
		geometries.back() = nullptr;
		geometries.pop_back();
	}
}


