#ifndef _DOLPHIN_H
#define _DOLPHIN_H

#include "thanh.h"

using namespace std;

class LDOLPHIN :public OBJECT, public LIGHT {
private:
	vector <int> arr;
public:
	LDOLPHIN(int y, int n, int d, int closeness); //line, spawn rate, closeness, traffic
	//~LDOLPHIN();
	void draw(int x, int y);
	void erase(int x, int y);
	void displayLight();
	void first_spawn();
	//void set_traffic(bool s);
	void makeSound();
	void display();
	void spawn_rate(int n, int d);
	bool spawn();
	void close(int closeness);
	//void get_map(bool**& map, int& x, int& y);
	void switch_light();
	bool check(int second);
};

class RDOLPHIN :public OBJECT,public LIGHT {
private:
	vector <int> arr;
public:
	RDOLPHIN(int y, int n, int d, int closeness); //line, spawn rate, closeness, traffic
	//~RDOLPHIN();
	void draw(int x, int y);
	void erase(int x, int y);
	void displayLight();
	void first_spawn();
	//void set_traffic(bool s);
	void makeSound();
	void display();
	void spawn_rate(int n, int d);
	bool spawn();
	void close(int closeness);
	//void get_map(bool**& map, int& x, int& y);
	void switch_light();
	bool done(int second);
};

#endif