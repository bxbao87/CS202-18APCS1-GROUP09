#ifndef _DOLPHIN_H
#define _DOLPHIN_H

#include "Settings.h"
#include "Objects.h"

using namespace std;

class LDOLPHIN :public OBJECT {
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

class RDOLPHIN :public OBJECT {
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

#endif