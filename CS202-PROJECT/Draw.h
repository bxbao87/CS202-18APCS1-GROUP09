#ifndef _DRAW_H
#define _DRAW_H

#include "Settings.h"

using namespace std;

class DRAW {
public:
	static void human(int x, int y); //size 3x3
	static void erhuman(int x, int y);
	static void dolphin(int x, int y); //size 4x16
	static void erdolphin(int x, int y);
	void duck(int x, int y); //size 4x10
	void erduck(int x, int y); //size 4x10
	static void l_light(int y, bool s);
	static void r_light(int y, bool s);
	static void erline(int y);
	static void split();
};

#endif