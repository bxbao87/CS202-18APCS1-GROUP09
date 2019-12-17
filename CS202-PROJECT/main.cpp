#pragma comment(lib, "winmm.lib")
#pragma comment(lib,"user32.lib") 
#include "Game.h"


int main() {
	FixConsoleWindow(); //fixed screen
	Nocursortype();
	Game g;
	g.menu();
	setcursor(1, 10);
	return 0;
}