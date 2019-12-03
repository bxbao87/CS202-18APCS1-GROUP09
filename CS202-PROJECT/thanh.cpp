#include "thanh.h"

//class OBJECT
OBJECT::OBJECT()
{
	n = 0; d = 0; closeness = 0; x = 0; y = 0; hx = 80; hy = 45;
}

void OBJECT::human(int x,int y)
{
	this->hx = x;
	this->hy = y;
}

vector<string> OBJECT::getMap() {
	return map;
}



//class LIGHT
LIGHT::LIGHT() {
	side = true; stop = true;
	green_time = 0; red_time = 0;
	light = 0;
}

LIGHT::LIGHT(int type, bool side, int y) {
	this->stop = true;
	this->green_time = 0; this->red_time = 0;
	this->light = 0;
	this->side = side;
}