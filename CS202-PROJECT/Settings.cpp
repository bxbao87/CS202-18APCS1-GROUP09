#include "Settings.h"

void FixConsoleWindow() {
	HWND hwnd = GetConsoleWindow(); //fullscreen mode
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);
	HWND consoleWindow = GetConsoleWindow(); //fix screen
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void go(int column, int row) {
	COORD coord;
	coord.X = column;
	coord.Y = row;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void color(const int& k) {
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, k);
}

void setcursor(bool x, DWORD size) // x = 0 : invisible, x = 1 : visible, usually size of a cursor is 10
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	if (size == 0)
		size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = x;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console, &lpCursor);
}
