#ifndef _PEOPLE_H
#define _PEOPLE_H

#include <iostream>

using namespace std;

class People {
private:
	int pX, pY;
	bool state;
	bool** shape;
public:
	People();	//write constructor:v
	void UP(int);
	void DOWN(int);
	void LEFT(int);
	void RIGHT(int);
//	bool isImpact(const);		// pass Object
	bool isFinish();
	bool isDead();
};

#endif
