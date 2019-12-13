#ifndef _PEOPLE_H
#define _PEOPLE_H
#include "Objects.h"
//#include <math.h>

using namespace std;

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
	void Draw() const;
	bool move(int key);
	void UP();
	void DOWN();
	void LEFT();
	void RIGHT();
	bool isImpact(int objY, vector<int> objCoordX, vector<string> objMap);		// pass Object
	bool isFinish();
	void decreaseLife();
	int getLife();
	bool isDead();
	pair<int, int> getCoor();
	void setCoor(int x,int y);
	void spawn();
};

#endif
