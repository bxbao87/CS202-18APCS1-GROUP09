#ifndef _DUCK_H
#define _DUCK_H

#include "Settings.h"
#include "Objects.h"

using namespace std;

class LDUCK :public OBJECT {
private:
	int co; //color of OBJECT
	int crowd_size; //size of a crowd
public:
	LDUCK(int y, int n, int d, int closeness, bool traffic); //line, spawn rate, closeness, traffic
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

class RDUCK :public OBJECT {
private:
	int co; //color of OBJECT
	int crowd_size; //size of a crowd
public:
	RDUCK(int y, int n, int d, int closeness, bool traffic); //line, spawn rate, closeness, traffic
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

#endif