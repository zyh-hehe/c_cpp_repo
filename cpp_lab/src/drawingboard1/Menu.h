#pragma once
#include"Initializing.h"
#include"Board.h"

class Menu :public Board {
private:
public:
	Menu();
	void menuloop();
	void beginmenu(mouse_msg&);
	void geomenu(mouse_msg&);
	void colormenu(mouse_msg&);
	void colormenu2(mouse_msg&);
	void whetherread(mouse_msg&);
	void testoperatoroverride(mouse_msg&);
	void testoperatoroverride2(mouse_msg&);
	void testoperatoroverride3(mouse_msg&);
	void testcoloroperator(Shape&, Shape&, mouse_msg&);
	void testdeepcopy(Shape*&, Shape*&, mouse_msg&);
};
