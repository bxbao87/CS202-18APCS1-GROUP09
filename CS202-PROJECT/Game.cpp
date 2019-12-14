#include "Game.h"

Game::Game() 
{
	level = new LEVEL(1, 100);
}

Game::~Game()
{
	if (level != nullptr) delete level;
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

string Game::inputFileName() {
	go(BORDER + 2, 44);
	cout << "Type file name: ";
	string fileName = "";
	char ch;
	int index_ch = BORDER + 18;

	ch = _getch();
	string t;
	bool ok = true;
	while (ch != 13) {
		if (ch == 27) {
			ch = _getch();
			if (ch == 27) {
				fileName.clear();
				fileName.push_back(27);
				return fileName;
			}
		}
		if (ch == -32) {
			ch = _getch();
			if (ch == 72) ch = 00;
			if (ch == 75) ch = 00;
			if (ch == 77) ch = 00;
			if (ch == 80) ch = 00;
		}
		if (ch == '\b') {
			t.clear();
			t = fileName.substr(0, fileName.length() - 1);
			fileName.clear();
			fileName = t;
			index_ch -= 2;
		}
		else {
			if ((fileName.length() < 21) && (ch >= 32 && ch <= 126)) {
				fileName.push_back(ch);
				ok = true;
			}
			else ok = false;
		}
		go(BORDER + 18, 44);
		cout << fileName;
		if (ok)
			index_ch++;
		go(index_ch, 44);
		ch = _getch();
	}
	return fileName;
}

void Game::loadOption() {
	string fileName;
	do {
		go(BORDER + 2, 44);
		cout << "                               ";
		fileName = inputFileName();
		if (fileName == "") break;
	} while (!loadGame(fileName));
}

bool Game::loadGame(string fileName) {
	ifstream file;
	file.open(savedPath + fileName + ".bin", ios::binary);
	if (!file.is_open())
		return false;
	int leve = level->getLevel();
	int life = human.getLife();
	file.read((char*)& leve, sizeof(leve));
	file.read((char*)& life, sizeof(life));
	file.close();
	return true;
}

void Game::saveOption() {
	string fileName;
	do {
		go(BORDER + 2, 44);
		cout << "                               ";
		fileName = inputFileName();
		if (fileName == "") break;
	} while (!saveGame(fileName));
	return;
}

bool Game::saveGame(string fileName) {
	ofstream file;
	file.open(savedPath + fileName + ".bin", ios::binary);
	if (!file.is_open())
		return false;
	int leve = level->getLevel();
	int life = human.getLife();
	file.write((char*)& leve, sizeof(leve));
	file.write((char*)& life, sizeof(life));
	file.close();
	return true;
}

void Game::pauseGame(LEVEL*& a) {
	a->pause();
}

void Game::resumeGame(LEVEL*& a) {
	a->resume();
}

People Game::getPeople() {
	return human;
}

thread Game::switchlevel(thread* t, LEVEL*& a, int level, int delay)
{
	exitGame(t, a);
	delete a;
	a = new LEVEL(level, delay);
	human.spawn();
	thread t1(&LEVEL::run, a,ref(human));
	return t1;
}

void Game::displayWin()
{
	playSound(string(soundPath+"victory.wav").c_str());
	color(224);
	ifstream fin(path + "victory.txt");
	if (fin.is_open())
	{
		int x = BORDER/2-35, y = 15;
		string line;
		while (getline(fin, line, '\n')) {
			Sleep(150);
			go(x, y++);
			cout << line;
		}
	}
	fin.close();
	color(8);
	Sleep(800);
}

void Game::displayLose()
{
	playSound(string(soundPath+"death.wav").c_str());
	color(192);
	ifstream fin(path + "gameOver.txt");
	if (fin.is_open())
	{
		int x = BORDER/2-35, y = 15;
		string line;
		while (getline(fin, line, '\n')) {
			Sleep(150);
			go(x, y++);
			cout << line;
		}
	}
	fin.close();
	color(8);
	Sleep(800);
}

void Game::displayLevel()
{
	go(BORDER + 23, 17);
	cout << level->getLevel();
}

void Game::displayLives()
{
	go(BORDER + 23, 20);
	cout << human.getLife();
}


thread Game::resetGame(thread* t) {

	thread tmp = switchlevel(t, level, 1, 100); 
	return tmp;
}

void Game::exitGame(thread* t, LEVEL*& a) {
	a->kill();
	t->join();
}

thread Game::startGame(thread* t) {
	thread tmp = switchlevel(t, level, 1, 100);
	return tmp;
}


void Game::crossyZoo() {
	ifstream fin(path + "crossyZoo.txt");
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

void Game::instructor()
{
	setcursor(0, 0); //hide cursor

	int x = BORDER + 5, y = 3;
	color(4);
	ifstream fin( path + "crossy.txt");
	if (fin.is_open()) {
		string line;
		while (getline(fin, line, '\n')) {
			go(x, y++);
			cout << line;
		}
	}
	fin.close();

	x += 10;
	color(11);
	fin.open(path + "zoo.txt");
	if (fin.is_open()) {
		string line;
		while (getline(fin, line, '\n')) {
			go(x, ++y);
			cout << line;
		}
	}
	fin.close();

	x = BORDER + 15;
	y = 17;
	color(7);
	go(x, y);
	cout << "LEVEL: ";
	displayLevel();
	go(x, y+=3);
	cout << "LIVES: ";
	displayLives();
	
	go(BORDER, y += 3);
	cout << (char)195;
	for (int i = 0; i < 50; ++i)
		cout << (char)196;

	x = BORDER + 5;
	go(x, y = 25);
	cout << "Press W to UP";
	go(x, y += 2);
	cout << "Press S to DOWN";
	go(x, y += 2);
	cout << "Press A to LEFT";
	go(x, y += 2);
	cout << "Press D to RIGHT";

	go(x+=20, y = 33);
	cout << setw(20) << "Press P to PAUSE";
	go(x, y += 2);
	cout << setw(20) << "Press R to RESUME";
	go(x, y += 2);
	cout << setw(20) << "Press L to SAVE";
	go(x, y += 2);
	cout << setw(20) << "Press T to LOAD";
	go(x, y += 2);
	cout << setw(20) << "Press ESC to EXIT";

}

void Game::main_run()
{
	int k = 0, l = 1;
	instructor();
	thread t1(&LEVEL::run, level, ref(human));
	human.spawn();
	while (k != 27)
	{
		k = _getch();
		if (k == 27 && !human.isDead()) {
			exitGame(&t1, level);
		}
		else if (k == 'p' || k == 'P') {
			level->pause();
		}
		else if (k == 'r' || k == 'R') {
			level->resume();
		}
		else if (k == 'l' || k == 'L') {
			level->pause();
			saveOption();
			//level->resume();
		}
		else if (k == 't' || k == 'T') {
			level->pause();
			loadOption();
		}
		else if (k == 'n') {
			++l;
			if (l > 10) l = 1;
			if (l > 4) l = 10;
			t1 = switchlevel(&t1, level, l, 100);
			while (!level->oktowrite());
			instructor();
			level->resume();
		}
		else
		{
			bool keep = level->status();
			while (!level->oktowrite());
			if (human.move(k))
			{
				level->resume();
				if (level->freeze_main())
				{
					Sleep(1500);
					go(1, 45);
					cout << "Press c to continue";
					while (k != 'c') k = _getch();
					go(1, 45);
					cout << "                   ";
				}
			}
			if (keep) level->pause();
			else level->resume();
			if (human.isDead()) {
				exitGame(&t1, level);
				k = 27;
				continue;
			}
			Sleep(100); //delay human movement
		}
	}
}