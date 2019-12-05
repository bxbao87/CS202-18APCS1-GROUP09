#ifndef _GAME_H
#define _GAME_H

#include "Settings.h"
#include "People.h"
#include "Level.h"

const string DirToGame = "";

class Game {
private:
	People human;
	LEVEL* level;
	void moveCursor(int key, int& y);
	void stringCentralization(std::string str, int r, int colour);
	string inputFileName();
	bool loadGame(string fileName);
	bool saveGame(string fileName);

public:
	Game();
	~Game();
	void menu();
	thread resetGame(thread* t);
	void exitGame(thread* t, LEVEL*& a);			// exit thread
	thread startGame(thread* t);
	void loadOption();
	void saveOption();
	void pauseGame(LEVEL*& a);			// pause thread
	void resumeGame(LEVEL*& a);		// resume thread

	People getPeople();

	void crossyZoo();
	void instructor();

	void main_run();
	thread switchlevel(thread* t, LEVEL*& a, int level, int delay);
};
#endif