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

void splashscreen()
{
	color(11);
	vector <pair<int, int>> coor;
	time_t timing = 3000, now;
	int x, y, maxx, maxy;
	pair<int, int> t;
	while (timing > 0)
	{
		now = clock();
		srand(clock() % 101);
		int s, e;
		for (int i = 0; i < 1000; ++i)
		{
			x = rand() % 212;
			y = rand() % 50;
			t.first = x; t.second = y;
			coor.push_back(t);
			go(x, y); 
			if (rand() % 2 == 0) cout << '/';
			else cout << '#';
			Sleep(20);
			s = coor.size();
			if (rand() % 101 < 80 && s != 0)
			{
				e = rand() % s;
				go(coor[e].first, coor[e].second); cout << ' ';
				coor.erase(coor.begin() + e);
			}
		}
		coor.clear();
		timing -= clock() - now;
	}
	Sleep(500);
	system("cls");
	color(15);
}