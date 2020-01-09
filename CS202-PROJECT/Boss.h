#ifndef _BOSS_H
#define _BOSS_H

#include "Objects.h"

using namespace std;

class BOSS :public OBJECT {
private:
	int count;
	int c; //color of boss
	vector <pair<int, int>> dir;
	pair<int, int> last = { 0,0 };
	int bx, by; //base coordinate
public:
	BOSS(int y, int n, int d, int closeness, bool traffic); //line, spawn rate, closeness, traffic
	void reset_dir();
	void draw(int x, int y);
	void erase(int x, int y);
	void light_display(); //change boss color :)
	void first_spawn(); //at middle screen
	void set_traffic(bool s) {};
	void makeSound();
	void display();
	void spawn_rate(int n, int d) {}; //none
	bool spawn(); //where to spawn
	void close(int closeness) {}; //none
	void switch_light() {}; // none
	bool done(int second) { return true; } //none
	void human(pair<int,int> tmp);
	void change_dir();
	void impact();
};

#endif