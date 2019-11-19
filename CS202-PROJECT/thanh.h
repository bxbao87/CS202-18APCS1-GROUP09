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
	void erline(int y);
	void split();
};

class OBJECT
{
protected:
	DRAW draw;
	int n, d, x, y, closeness;
public:
	OBJECT();
	virtual void makeSound() = 0; //incoming feature
	virtual void display() = 0;
	virtual void spawn_rate(int n, int d) = 0; //n is succeed rate, d is event
	virtual void close(int closeness) = 0; //space between 2 objects
	virtual bool spawn() = 0; //decide if spawned or not
};

class DOLPHIN :public OBJECT
{
private:
	bool** map;
	vector <int> arr;
public:
	DOLPHIN(int y); //initialize at line..
	~DOLPHIN();
	void makeSound();
	void display();
	void spawn_rate(int n, int d);
	bool spawn();
	void close(int closeness);
	//void get_map(bool**& map, int& x, int& y);
};

class LEVEL
{
private:
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

