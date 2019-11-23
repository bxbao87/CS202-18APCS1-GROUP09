#ifndef _DRAW_H
#define _DRAW_H

#include "Settings.h"

using namespace std;

class DRAW {
public:
	//input functions
	void human(int x, int y); //size 3x3
	void erhuman(int x, int y);
	void ldolphin(int x, int y); //size 4x15
	void erdolphin(int x, int y);
	void rdolphin(int x, int y); //size 4x15
	void duck(int x, int y); //size 4x10
	void erduck(int x, int y); //size 4x10
	void l_light(int y, bool s); //left traffic light
	void r_light(int y, bool s); //right traffic light
	void erline(int y);
	void split(); //split screen
};


#endif