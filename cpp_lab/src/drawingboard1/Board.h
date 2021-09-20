#pragma once
#include"Initializing.h"
#include"FileIO.h"

enum class Mode {
	ChooseWhetherRead, ChooseWhetherBegin, ChooseToDrawWhat, ChooseGeometricColor,
	Draw, TestOperatorOverride1, TestOperatorOverride2, TestOperatorOverride3, EXIT
};

enum class NOWGEO{CIRCLE,RECTANGLE,TRIANGLE};

class Board :public Initializing {
private:
	std::array<int, 4> tempLine{ 0,0,0,0 };
public:
	FileIO f;
	NOWGEO nowGeo{ NOWGEO::CIRCLE };
	vector<Shape*> geometries;
	color_t nowColor{ 0xFFFFFF };
	bool nowIsFilled{ false };
	Mode mode{ Mode::ChooseWhetherRead };
	Board();
	Board(NOWGEO);
	void setnowColor(color_t);
	void setnowGeo(NOWGEO);
	void boardloop();
	void drawcircle();
	void drawrectangle();
	void drawtriangle();
	void drawgeometries();
	void judgewhetherfilled();
	void createmenuboard();
	void withdraw();
};