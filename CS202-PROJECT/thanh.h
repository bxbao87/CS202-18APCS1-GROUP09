#ifndef _THANH_H
#define _THANH_H
#include "Settings.h"

using namespace std;

class DRAW
{
public:
	void human(int x,int y); //size 3x3
	void erhuman(int x,int y);
	void dolphin(int x,int y); //size 4x16
	void erdolphin(int x,int y);
	void duck(int x,int y); //size 4x10
	void erduck(int x,int y); //size 4x10
	void l_light(int y, bool s);
	void r_light(int y, bool s);
	void erline(int y);
	void split();
};

class OBJECT
{
protected:
	DRAW draw;
	bool traffic;
	int n, d, x, y, closeness, red, green;
	int light = 0; // 0 is neutral, 1 is green, 2 is red
public:
	OBJECT();
	virtual void first_spawn() = 0; //initialize first map
	virtual void set_traffic(bool s) = 0; //if it needs traffic light
	virtual void makeSound() = 0; //incoming feature
	virtual void display() = 0; //thread loop
	virtual void spawn_rate(int n, int d) = 0; //n is succeed rate, d is event
	virtual void close(int closeness) = 0; //space between 2 objects
	virtual bool spawn() = 0; //decide if spawned or not
	virtual void get_map(bool**& map, int& x, int& y) = 0; //get map of object
	virtual void switch_light() = 0; //switch between 2 signals
	virtual bool done(int second) = 0; //check if any light is on
	virtual bool turn() = 0; //display signal , true is green, false is red
};

class LDOLPHIN :public OBJECT
{
private:
	bool** map;
	vector <int> arr;
public:
	LDOLPHIN(int y); //initialize at line..
	~LDOLPHIN();
	void first_spawn();
	void set_traffic(bool s);
	void makeSound();
	void display();
	void spawn_rate(int n, int d);
	bool spawn();
	void close(int closeness);
	void get_map(bool**& map, int& x, int& y);
	void switch_light();
	bool done(int second);
	bool turn();
 };

class LEVEL
{
private:
	time_t now;
	vector <OBJECT*> arr;
	bool stop, tmp_stop;
public:
	~LEVEL();
	LEVEL(int choice);
	void kill();
	void run();
	void pause();
	void resume();
};

#endif

