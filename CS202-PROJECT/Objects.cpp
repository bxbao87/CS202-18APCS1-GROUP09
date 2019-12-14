#include "Objects.h"

//class OBJECT
OBJECT::OBJECT()
{
	n = 0; d = 0; closeness = 0; x = 0; y = 0; green = 0; red = 0; traffic = false; hx = 80; hy = 45; lenAni = 0;
}

void OBJECT::switch_light()
{
	if (light == 0)
	{
		if (rand() % 13 < 6)
		{
			light = 2;
			red += (rand() % 5) * 1000;
		}
		else
		{
			light = 1;
			green += (rand() % 5) * 1000;
		}
	}
}

void OBJECT::human(pair <int,int> tmp)
{
	this->hx = tmp.first;
	this->hy = tmp.second;
}

vector <string> OBJECT::getMAP() {
	return map;
}

vector <int> OBJECT::getARR() {
	return arr;
}

int OBJECT::getY() {
	return y;
}

