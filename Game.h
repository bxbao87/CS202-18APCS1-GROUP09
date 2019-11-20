#ifndef _GAME_H
#define _GAME_H

#include <iostream>
#include <Windows.h>

using namespace std;

class Game {
private:

public:
	Game();
	void resetGame();
	void exitGame(HANDLE);			// exit thread
	void startGame();
	void loadGame(istream);
	void saveGame(istream);
	void pauseGame(HANDLE);			// pause thread
	void resumeGame(HANDLE);		// resume thread
	void updatePosPeople(char);		// eo biet lam gi luon :)))))
	void updatePosObject();			//
};
#endif