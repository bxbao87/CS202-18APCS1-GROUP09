#pragma comment(lib, "winmm.lib")
#include "Game.h"
#include <stdio.h>
#include <io.h>
#include <fcntl.h>


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