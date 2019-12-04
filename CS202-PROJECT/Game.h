#ifndef _GAME_H
#define _GAME_H

#include "Settings.h"
#include "People.h"

const string DirToGame = "";

class Game {
private:
	People human;

	void moveCursor(int key, int& y);
	void stringCentralization(std::string str, int r, int colour);
	string inputFileName();
public:
	Game();
	void menu();
	void resetGame();
	void exitGame(HANDLE);			// exit thread
	void startGame();
	void loadOption();
	void loadGame(string fileName);
	void saveOption();
	void saveGame(string fileName);
	void pauseGame(HANDLE);			// pause thread
	void resumeGame(HANDLE);		// resume thread

	People getPeople();

	void crossyZoo();
	void instructor();
};
#endif