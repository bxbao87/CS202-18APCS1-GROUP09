#ifndef OPTION_H
#define OPTION_H

#include"Settings.h"

class Option{
private:
	int x, y;
	bool music;
	static bool sound;
	bool cheatmode;
	vector<string> logo;
	void displayMusic();
	void displaySound();
	void changeMusic();
	void changeSound();
	void displayCheat();
	void changeCheat();
public:
	Option();
	~Option();
	void display();
	void change();
	void setcheatmode(const bool& cheatmode);
	bool getcheatmode();
	static bool playSound(string path);
	void playMusic();
};

#endif // !OpTION_H
