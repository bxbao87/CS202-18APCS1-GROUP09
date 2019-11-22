#include "Draw.h"

void DRAW::human(int x, int y) {
	go(x, y);
	cout << " @ ";
	go(x, y + 1);
	cout << "-|-";
	go(x, y + 2);
	cout << "/ \\";
}

void DRAW::erhuman(int x, int y) {
	for (int i = 0; i < 3; ++i) {
		go(x, y + i);
		cout << "   ";
	}
}

void DRAW::dolphin(int x, int y) {
	go(x, y);
	cout << "        ,     ";
	go(x, y + 1);
	cout << "      __)\\_   ";
	go(x, y + 2);
	cout << "(\\_.-'    a`-.";
	go(x, y + 3);
	cout << "(/~~````(/~^^`";
}

void DRAW::erdolphin(int x, int y) {
	for (int i = 0; i < 4; ++i) {
		go(x, y + i);
		cout << "              ";
	}
}

void DRAW::duck(int x, int y) {
	go(x, y);
	cout << "  __     ";
	go(x, y + 1);
	cout << "<(o )___ ";
	go(x, y + 2);
	cout << " ( ._> / ";
	go(x, y + 3);
	cout << "  `---'  ";
}

void DRAW::erduck(int x, int y) {
	for (int i = 0; i < 4; ++i)
	{
		go(x, y + i);
		cout << "         ";
	}
}

void DRAW::erline(int y) {
	string t = "                                                                                                                                           ";
	for (int i = 0; i < 4; ++i) {
		go(0, y + i);
		cout << t;
	}
}

void DRAW::split() {
	string t = "-------------------------------------------------------------------------------------------------------------------------------------------";
	for (int i = 0; i < 9; ++i) {
		go(0, 3 + i * 5);
		cout << t;
	}
	for (int i = 0; i < 48; ++i) {
		go(BORDER, i);
		cout << char(179); // |
	}
}

void DRAW::l_light(int y, bool s) {
	if (s) {
		go(0, y + 2);
		color(34); //green background
		cout << ' ';
		color(15);
		go(0, y + 1);
		cout << ' ';
	}
	else {
		go(0, y + 1);
		color(68); //red blackground
		cout << ' ';
		color(15);
		go(0, y + 2);
		cout << ' ';
	}
}

void DRAW::r_light(int y, bool s) {
	if (s) {
		go(BORDER - 1, y + 2);
		color(34); //green background
		cout << ' ';
		color(15);
		go(BORDER - 1, y + 1);
		cout << ' ';
	}
	else {
		go(BORDER - 1, y + 1);
		color(68); //red blackground
		cout << ' ';
		color(15);
		go(BORDER - 1, y + 2);
		cout << ' ';
	}
}