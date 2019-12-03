#ifndef _THANH_H
#define _THANH_H

#include "Settings.h"
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class OBJECT
{
protected:
	//bool traffic;
	int n, d, closeness; //spawning
	int x, y; //line coordinate
	//int red, green; //traffic time
	int hx, hy; //human coordinate
	//int light = 0; // 0 is neutral, 1 is green, 2 is red
	vector <string> map;
public:
	OBJECT();
	virtual void draw(int x, int y) = 0; //draw object
	virtual void erase(int x, int y) = 0; //erase object
	//virtual void traffic_light() = 0; //draw traffic_light
	virtual void first_spawn() = 0; //initialize first map
	//virtual void set_traffic(bool s) = 0; //if it needs traffic light
	virtual void makeSound() = 0; //incoming feature
	virtual void display() = 0; //thread loop
	virtual void spawn_rate(int n, int d) = 0; //n is succeed rate, d is event
	virtual void close(int closeness) = 0; //space between 2 objects
	virtual bool spawn() = 0; //decide if spawned or not
	//virtual void get_map(bool**& map, int& x, int& y) = 0; //get map of object
	//virtual void switch_light() = 0; //switch between 2 signals
	//virtual bool done(int second) = 0; //check if any light is on

	virtual bool isImpact(int px, int py, bool** pMap) = 0;
	
	void human(int x, int y); //get human coordinate
	vector<string> getMap();
	virtual vector<int> getArr() = 0;
};

class LIGHT{
protected:
	bool side, stop;	//side=true -> left
	int green_time, red_time;
	int light;			// 0=neutral, 1=green, 2=red
public:
	LIGHT();
	LIGHT(int type, bool side, int y);
	virtual void switch_light();
	virtual bool check(int sec);
	void displayLight();
	bool allowed();
};

class SKILL {

};

#endif