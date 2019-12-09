#ifndef _PIG_H
#define _PIG_H

#include "Settings.h"
#include "Objects.h"

using namespace std;

class LPIG :public OBJECT {
private:
	int co; //color of object
	bool stop; //wait till red ends
public:
	LPIG(int y, int n, int d, int closeness, bool traffic); //line, spawn rate, closeness, traffic
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

class RPIG :public OBJECT {
private:
	int co; //color of object
	bool stop; //wait till red ends
public:
	RPIG(int y, int n, int d, int closeness, bool traffic); //line, spawn rate, closeness, traffic
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
