#ifndef _THANH_H
#define _THANH_H
//#include "Settings.h"
#include "Draw.h"
#include "People.h"
#include <math.h>

using namespace std;

class OBJECT
{
protected:
	bool traffic;
	int n, d, closeness; //spawning
	int x, y; //line coordinate
	int red, green; //traffic time
	int hx, hy; //human coordinate
	int light = 0; // 0 is neutral, 1 is green, 2 is red
	vector <string> map;
public:
	OBJECT();
	virtual void draw(int x, int y) = 0; //draw object
	virtual void erase(int x, int y) = 0; //erase object
	virtual void traffic_light() = 0; //draw traffic_light
	virtual void first_spawn() = 0; //initialize first map
	virtual void set_traffic(bool s) = 0; //if it needs traffic light
	virtual void makeSound() = 0; //incoming feature
	virtual void display() = 0; //thread loop
	virtual void spawn_rate(int n, int d) = 0; //n is succeed rate, d is event
	virtual void close(int closeness) = 0; //space between 2 objects
	virtual bool spawn() = 0; //decide if spawned or not
	//virtual void get_map(bool**& map, int& x, int& y) = 0; //get map of object
	virtual void switch_light() = 0; //switch between 2 signals
	virtual bool done(int second) = 0; //check if any light is on

	virtual bool isImpact(int px, int py, bool** pMap) = 0;
	
	void human(int x, int y); //get human coordinate
};

class LDOLPHIN :public OBJECT
{
private:
	vector <int> arr;
public:
	LDOLPHIN(int y,int n, int d,int closeness,bool traffic); //line, spawn rate, closeness, traffic
	//~LDOLPHIN();
	void draw(int x, int y);
	void erase(int x, int y);
	void traffic_light();
	void first_spawn();
	void set_traffic(bool s);
	void makeSound();
	void display();
	void spawn_rate(int n, int d);
	bool spawn();
	void close(int closeness);
	//void get_map(bool**& map, int& x, int& y);
	void switch_light();
	bool done(int second);

	bool isImpact(int px, int py, bool** pMap);
 };

class RDOLPHIN :public OBJECT
{
private:
	vector <int> arr;
public:
	RDOLPHIN(int y, int n, int d, int closeness, bool traffic); //line, spawn rate, closeness, traffic
	//~RDOLPHIN();
	void draw(int x, int y);
	void erase(int x, int y);
	void traffic_light();
	void first_spawn();
	void set_traffic(bool s);
	void makeSound();
	void display();
	void spawn_rate(int n, int d);
	bool spawn();
	void close(int closeness);
	//void get_map(bool**& map, int& x, int& y);
	void switch_light();
	bool done(int second);

	bool isImpact(int px, int py, bool** pMap);
	
};

class BOSS :public OBJECT
{
private:
	int c; //color of boss
public:
	BOSS(int y, int n, int d, int closeness, bool traffic); //line, spawn rate, closeness, traffic
	//~RDOLPHIN();
	void draw(int x, int y);
	void erase(int x, int y);
	void traffic_light(); //change boss color :)
	void first_spawn(); //at middle screen
	void set_traffic(bool s); //none
	void makeSound();
	void display();
	void spawn_rate(int n, int d) {}; //none
	bool spawn(); //where to spawn
	void close(int closeness) {}; //none
	//void get_map(bool**& map, int& x, int& y);
	void switch_light() {}; // none
	bool done(int second) { return true; } //none
};

class LEVEL
{
private:
	bool ok;
	time_t now;
	vector <OBJECT*> arr;
	bool stop, tmp_stop;
	int delay;
public:
	~LEVEL();
	LEVEL(int choice,int delay);
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