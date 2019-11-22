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

void Nocursortype() {
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}