#include "Game.h"
#include <stdio.h>
#include <io.h>
#include <fcntl.h>


int main() {
	FixConsoleWindow(); //fixed screen
	Game g;
	g.main_run();
	setcursor(1, 10);
	/*_setmode(_fileno(stdout), _O_U16TEXT);
	wprintf(L"\x2665 \x2665 \x2665 hello world\n");
	RDOLPHIN a(4, 1, 6, 11, true);*/
	return 0;
}