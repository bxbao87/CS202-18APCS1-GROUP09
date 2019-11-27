#ifndef _GAME_H
#define _GAME_H

#include "Settings.h"

class Game {
private:
	void moveCursor(int key, int& y);
	void stringCentralization(std::string str, int r, int colour);
public:
	Game();
	void menu();
	void resetGame();
	void exitGame(HANDLE);			// exit thread
	void startGame();
	void loadGame(istream);
	void saveGame(istream);
	void pauseGame(HANDLE);			// pause thread
	void resumeGame(HANDLE);		// resume thread
	void updatePosPeople(char);		// eo biet lam gi luon :)))))
	void updatePosObject();			//

	void crossyZoo();
};
#endif