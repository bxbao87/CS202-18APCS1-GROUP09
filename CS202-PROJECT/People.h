#ifndef _PEOPLE_H
#define _PEOPLE_H

#include "Draw.h"

using namespace std;

const int X_MOVE = 1;
const int Y_MOVE = 5;
const int Top_bound = 0, Bot_bound = 45;
const int Left_bound = 0, Right_bound = 137;

class People {
private:
	DRAW draw;
	int pX, pY;
	bool state;
	bool** map;//true for existance of body part
public:
	People();
	~People();
	void delDraw();
	void Draw();
	void move(int key);
	void UP();
	void DOWN();
	void LEFT();
	void RIGHT();
	//bool isImpact(OBJECT* object);		// pass Object
	bool isFinish();
	//bool isDead(OBJECT* object);
};

#endif
