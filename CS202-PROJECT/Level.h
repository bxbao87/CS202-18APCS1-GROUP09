#ifndef _LEVEL_H
#define _LEVEL_H

#include "Settings.h"
#include "Objects.h"
#include "Dolphin.h"
#include "Boss.h"

using namespace std;

class LEVEL {
private:
	bool ok;
	time_t now;
	vector <OBJECT*> arr;
	bool stop, tmp_stop;
	int delay;
public:
	~LEVEL();
	LEVEL(int choice, int delay);
	void boss_split();
	void split();
	bool oktowrite();
	void kill();
	void run();
	void passCoor(int x, int y);
	void pause();
	void resume();
};


#endif
