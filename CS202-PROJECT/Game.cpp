#include "Game.h"

Game::Game() {

}

void Game::menu() {
	crossyZoo();

	int t = 23;
	int y = t+3;
	int cursorColor = 176;
	int colour = 11;
	vector<std::string> command;
	command.push_back("   Start New Game   ");
	command.push_back("  Load Saved Game   ");
	command.push_back("      Settings      ");
	command.push_back("      About Us      ");
	command.push_back("        Exit        ");
	for (int i = 0; i < 5; ++i)
	{
		stringCentralization(command[i], t += 3, colour);
	}
	int line = 0;
	stringCentralization(command[line], line*3+y, cursorColor);
	int k = _getch();
	while (k != 13) {
		stringCentralization(command[line], 3*line+y, colour);
		moveCursor(k,line);
		stringCentralization(command[line], line*3+y, cursorColor);
		k = _getch();
	}
	color(8);
	if (line == 0)
		cout << "New game" << endl;//startGame();
	else if (line == 1)
		cout << "Load Game" << endl;//loadGame();
	else if (line == 2)
		cout << "Settings" << endl;//settings();
	else if (line == 3)
		cout << "About Us" << endl;//aboutUs();
	else if (line == 4)
		cout << "Exit game" << endl;//exitGame();

}

void Game::moveCursor(int key, int& y)
{
	if (y > 0 && (key == 'w' || key == 'W'))
		y -= 1;
	else if (y < 4 && (key == 's' || key == 'S'))
		y += 1;
	else if (key == 224)
	{
		key = _getch();
		if (y > 0 && key==72)
			y -= 1;
		else if (y < 4 && key==80)
			y += 1;
	}
}

void Game::stringCentralization(std::string str, int r, int colour)
{
	int len = str.length();
	const int width = 210 - len;
	int mid = width / 2;
	go(mid, r+1);
	color(colour);
	std::cout << str;
/*
	int c = mid-1;
	color(14);
	go(c, r++);

	cout << (char)201;
	for (int i = 1; i < len; ++i)
		cout << (char)205;
	cout << (char)187;

	go(c, r);
	cout << (char)186;
	go(c + len, r++);
	cout << (char)186;

	go(c, r);
	cout << (char)200;
	for (int i = 1; i < len; ++i)
		cout << (char)205;
	cout << (char)188;
*/
}

void Game::resetGame() {

}

void Game::exitGame(HANDLE) {

}

void Game::startGame() {

}

void Game::loadGame(istream) {

}

void Game::saveGame(istream) {

}

void Game::pauseGame(HANDLE) {

}

void Game::resumeGame(HANDLE) {

}

void Game::updatePosPeople(char) {

}

void Game::updatePosObject() {

}

void Game::crossyZoo()
{
	ifstream fin("crossyZoo.txt");
	if (fin.is_open()) {
		int n;
		fin >> n;
		int x = 50, y = 5;
		color(14);
		for (int i = 0; i < n; ++i) {
			string str;
			getline(fin, str, '\n');
			go(x, y++);
			cout << str;
		}
	}
	fin.close();
}
