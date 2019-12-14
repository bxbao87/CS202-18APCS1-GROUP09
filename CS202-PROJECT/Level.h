#ifndef _LEVEL_H
#define _LEVEL_H

#include "Settings.h"
#include "People.h"
#include "Objects.h"
#include "Dolphin.h"
#include "Pig.h"
#include "Whale.h"
#include "Boss.h"
#include "Bee.h"
#include "Duck.h"

using namespace std;

class LEVEL {
private:
	int current;
	bool ok;
	time_t now;
	vector <OBJECT*> arr;
	bool stop, tmp_stop;
	int delay;
	People human;
	void verticalLine(int col);
public:
	~LEVEL();
	LEVEL(int choice, int delay);
	bool status();
	int getLevel();
	void set_level();
	void boss_split();
	void split();
	bool oktowrite();
	void kill();
	void run(People& human);
	//void passCoor(pair <int,int> coor);
	void pause();
	void resume();
	void cooldown();
	OBJECT* getObject(int i) {
		return arr[i];
	}
	int objectSize() {
		return arr.size();
	}
};


#endif
