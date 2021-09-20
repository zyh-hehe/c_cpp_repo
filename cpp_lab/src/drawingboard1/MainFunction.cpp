#include<iostream>
#include"FileIO.h"
#include"Initializing.h"
#include"Menu.h"

int main(void) {
	Menu menu1{};
	ege::ege_enable_aa(true);
	while (is_run()) {
		menu1.menuloop();
		menu1.boardloop();
	}
	for (auto x : menu1.geometries) {
		delete x;
		x = nullptr;
	}
	return 0;
}