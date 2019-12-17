#ifndef OPTION_H
#define OPTION_H

#include"Settings.h"

class Option{
private:
	int x, y;
	bool music;
	static bool sound;
	vector<string> logo;
	void displayMusic();
	void displaySound();
	void changeMusic();
	void changeSound();
public:
	Option();
	~Option();
	void display();
	void change();
	static bool playSound(string path);
	void playMusic();
};

#endif // !OpTION_H
