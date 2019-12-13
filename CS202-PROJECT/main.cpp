#include "Game.h"


int main() {
	FixConsoleWindow(); //fixed screen
	Game g;
	g.main_run();
	setcursor(1, 10);
	
	
	return 0;
}