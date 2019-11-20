#ifndef _PEOPLE_H
#define _PEOPLE_H

#include <iostream>
using namespace std;

class People {
private:
	int pX, pY;
	bool state;
public:
	People();
	void delDraw();
	void draw();
	void move(int key);
	void UP();
	void DOWN();
	void LEFT();
	void RIGHT();
	bool isImpact();		// pass Object
	bool isFinish();
	bool isDead();
};

#endif
