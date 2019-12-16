#pragma comment(lib, "winmm.lib")
#include "Game.h"


int main() {
	//system("chcp 437");
	FixConsoleWindow(); //fixed screen
	Game g;
	//g.main_run();
	g.menu();
	setcursor(1, 10);
	//g.menu();

	return 0;
}