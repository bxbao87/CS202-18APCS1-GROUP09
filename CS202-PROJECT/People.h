#ifndef _PEOPLE_H
#define _PEOPLE_H

#include "thanh.h"

using namespace std;

const int X_MOVE = 1;
const int Y_MOVE = 5;
const int Top_bound = 0, Bot_bound = 45;
const int Left_bound = 0, Right_bound = 137;

class People {
private:
	int pX, pY;
	bool state;
	vector<string> map;			//true for existance of body part
	int live;
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
	bool isImpact(int objY, vector<int> objCoordX, vector<string> objMap);		// pass Object
	bool isFinish();
	void decreaseLife();
	int getLife();
	bool isDead();
	void spawn();
};

#endif
