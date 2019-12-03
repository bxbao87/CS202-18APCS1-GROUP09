#ifndef _PEOPLE_H
#define _PEOPLE_H
#include "Objects.h"

class People {
private:
	int pX, pY;
	bool state;
	vector<string> map;//true for existance of body part
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
	bool isImpact();		// pass Object
	bool isFinish();
	bool isDead();
	pair<int, int> getCor();
	bool** getImpactMap();
	void spawn();
};

#endif
