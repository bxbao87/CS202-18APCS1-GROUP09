#pragma comment(lib, "winmm.lib")
#pragma comment(lib,"user32.lib") 
#include "Game.h"
#include <stdio.h>
#include <io.h>
#include <fcntl.h>


int main() {
	//system("chcp 437");
	FixConsoleWindow(); //fixed screen
	Nocursortype();
	Game g;
	g.menu();
	setcursor(1, 10);
	//g.menu();

	return 0;
}