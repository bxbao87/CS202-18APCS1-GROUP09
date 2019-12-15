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
	_menu.display();
	crossyZoo();
	// please continue 'here' Nhat Hoang
	// i think below could be a loop

	int choice = _menu.choose();
	if (choice == 0) {
		PlaySound(NULL, 0, 0);
		// here


		op.playMusic();
	}
	else if (choice == 1) {
		PlaySound(NULL, 0, 0);
		// here


		op.playMusic();
	}
	else if (choice == 2) {
		op.display();
		op.change();
	}
	else if(choice==3){

	}
	else {

	}
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
	thread t1(&LEVEL::run, a);
	return t1;
}

void Game::displayWin()
{
	int sleep = 0;
	if (Option::playSound(soundPath + "victory.wav"))
		sleep = 3500;
	color(224);
	ifstream fin(path + "victory.txt");
	if (fin.is_open())
	{
		int x = BORDER/2-35, y = 15;
		string line;
		while (getline(fin, line, '\n')) {
			Sleep(200);
			go(x, y++);
			cout << line;
		}
	}
	fin.close();
	color(15);
	Sleep(sleep);
}

void Game::displayLose()
{
	int sleep = 0;
	if (Option::playSound(soundPath + "death.wav"))
		sleep = 800;
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
	color(15);
	Sleep(sleep);
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

void Game::settings()
{
	system("cls");
	op.display();
	op.change();
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
	color(15);
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
	color(15);
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
	thread t1(&LEVEL::run, level);
	human.spawn();
	while (k != 27)
	{
		k = _getch();
		if (k == 27) {
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
			if (l >= 3) l = 10;
			t1 = switchlevel(&t1, level, l, 100);
			level->pause();
			while (level->oktowrite() == false);
			instructor();
			level->resume();
		}
		else
		{
			if (human.isDead()) {

			}
			else {
				level->pause();
				while (level->oktowrite() == false);
				human.move(k);
				for (int i = 0; i < level->objectSize(); i++)
					if (human.isImpact(level->getObject(i)->getY(), level->getObject(i)->getARR(), level->getObject(i)->getMAP()))
						//human.decreaseLife();
						cout << "impacted" << endl;
	
				level->passCoor(human.getCoor());
				level->resume();
				Sleep(100); //delay human movement
			}
		}
	}
}