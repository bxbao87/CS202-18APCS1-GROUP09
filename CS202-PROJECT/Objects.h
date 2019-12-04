#ifndef _OBJECTS_H
#define _OBJECTS_H
#include "Settings.h"
#include "Setups.h"

using namespace std;

class LDOLPHIN :public OBJECT
{
private:
public:
	LDOLPHIN(int y, int n, int d, int closeness, bool traffic); //line, spawn rate, closeness, traffic
	void draw(int x, int y);
	void erase(int x, int y);
	void light_display();
	void first_spawn();
	void set_traffic(bool s);
	void makeSound();
	void display();
	void spawn_rate(int n, int d);
	bool spawn();
	void close(int closeness);
	bool done(int second);
};

class RDOLPHIN :public OBJECT
{
private:
public:
	RDOLPHIN(int y, int n, int d, int closeness, bool traffic); //line, spawn rate, closeness, traffic
	void draw(int x, int y);
	void erase(int x, int y);
	void light_display();
	void first_spawn();
	void set_traffic(bool s);
	void makeSound();
	void display();
	void spawn_rate(int n, int d);
	bool spawn();
	void close(int closeness);
	bool done(int second);
};

class BOSS :public OBJECT
{
private:
	int c; //color of boss
public:
	BOSS(int y, int n, int d, int closeness, bool traffic); //line, spawn rate, closeness, traffic
	void draw(int x, int y);
	void erase(int x, int y);
	void light_display(); //change boss color :)
	void first_spawn(); //at middle screen
	void set_traffic(bool s); //none
	void makeSound();
	void display();
	void spawn_rate(int n, int d) {}; //none
	bool spawn(); //where to spawn
	void close(int closeness) {}; //none
	void switch_light() {}; // none
	bool done(int second) { return true; } //none
};

#endif