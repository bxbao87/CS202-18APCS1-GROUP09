#ifndef MENU_H
#define MENU_H
#include "Settings.h"

class Menu {
private:
	int colour;
	int cursorColor;
	int y;
	vector<string> command;
	void stringCentralization(std::string str, int r, int colour);
	void moveCursor(int key, int& y);
public:
	Menu();
	void display();
	int choose();
};

#endif