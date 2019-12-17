#pragma comment(lib, "winmm.lib")
#include "Game.h"
#include <stdio.h>
#include <io.h>
#include <fcntl.h>


int main() {
	FixConsoleWindow(); //fixed screen
	Nocursortype();
	Game g;
	g.menu();
	setcursor(1, 10);
	return 0;
}