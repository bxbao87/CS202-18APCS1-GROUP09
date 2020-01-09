#include "Game.h"

Game::Game() {
	cheatmode = op.getcheatmode();
	current_level = 1;
}

Game::~Game()
{
	if (level != nullptr) delete level;
}

void Game::menu() {
	int choice = 0;
	while (choice <= 3) {
		system("cls");
		_menu.display();
		crossyZoo();
		choice = _menu.choose();
		
		if (choice == 0) {			// start new game
			PlaySound(NULL, 0, 0);
			system("cls");
			current_level = 1;
			main_run(1, 3);

			op.playMusic();
		}
		else if (choice == 1) {		//load saved game
			PlaySound(NULL, 0, 0);
			// here
			system("cls");
			crossyZoo();

			int leve=0, life=0;
			loadOption(0, leve, life);
			if (leve == 0 && life == 0)
				continue;
			current_level = leve;
			main_run(leve, life);

			op.playMusic();
		}
		else if (choice == 2) {		// setting
			op.display();
			op.change();
		}
		else if (choice == 3) {		// about us
			aboutus();
		}
		else {						// exit

		}
	}
}

void Game::aboutus()
{
	std::system("cls");
	color(15);
	string a = "    LE VIET THANH      - 18125023 - HCMUS -  CHAOTIC ZOOKEEPER ";
	string b = "NGUYEN PHAN NHAT HOANG - 18125050 - HCMUS -  ANIMAL SPECIALIST ";
	string c = "    BUI XUAN BAO       - 18125063 - HCMUS -   RUNNING VISITOR  ";
	string contact = "Any feedback :), please email me at lvthanh18@apcs.vn, thanks for playing our game!";
	string prank = "(positive only =)) )";
	vector <string> block = { a, "\n", b,"\n",c };
	vector <pair<int, int>> coor;
	time_t timing = 5000;
	int x, y, maxx = 212, maxy = 50, cx = 0, cy = 0;

	while (maxx > 60 && maxy > 5)
	{
		srand(clock() + rand() % 31);
		pair<int, int> tmp;
		while (timing > 0)
		{
			time_t ttmp = clock();
			//srand(clock() + rand() % 31);
			x = rand() % maxx;
			y = rand() % maxy;
			tmp.first = x;
			tmp.second = y;
			coor.push_back(tmp);
			//create
			go(x + cx, y + cy);
			int c = rand() % 37;
			if (c < 11) cout << char(rand() % 10 + 48); //random 0-9
			else if (c < 19) cout << char(rand() % 26 + 97); //random a-z
			else cout << char(rand() % 26 + 65); //random A-Z
			//delete
			if (rand() % 101 < 90 && coor.size() != 0)
			{
				int r = rand() % coor.size();
				go(coor[r].first, coor[r].second);
				cout << ' ';
			}
			timing -= clock() - ttmp;
		}
		timing = 1500;
		maxx *= 0.9;
		if (maxx > 100) cx += 7;
		else cx += 6;
		maxy *= 0.875; 
		if (maxy > 30) cy += 2;
		else cy += 1;
	}
	Sleep(500);
	x = 71, y = 15;
	for (int i = 0; i < block.size()+2; ++i)
	{
		go(x, y++);
		cout << "                                                                 ";
	}
	x = 72, y = 16;
	for (int i = 0; i < block.size(); ++i)
	{
		go(x, y++);
		cout << block[i];
	}
	Sleep(500);
	system("cls");
	x = 72, y = 16;
	for (int i = 0; i < block.size(); ++i)
	{
		go(x, y++);
		cout << block[i];
	}
	go(x - 9, ++y);
	setcursor(1, 10);
	int i = contact.size(), j = prank.size(), k = 0, m = 0, n = 0;
	while (k < i)
	{
		if (contact[m] == '32') Sleep(200);
		else Sleep(120);
		cout << contact[m++];
		if (m == 12)
		{
			Sleep(500);
			while (n < j)
			{
				cout << prank[n++];
				Sleep(100);
			}
			n = 0;
			Sleep(500);
			while (n < j)
			{
				cout << '\b' << ' ' << '\b';
				Sleep(100);
				++n;
			}
		}
		++k;
	}
	setcursor(0, 0);
	go(0, ++y);
	cout << "PRESS ANY KEY TO GO BACK..";
	int q = _getch();
}

string Game::inputFileName(int x, int y) {
	go(x, y);
	cout << "Type file name: ";
	string fileName = "";
	char ch;
	int index_ch = BORDER + 18;

	ch = _getch();
	string t = " ";
	bool ok = true;
	while (ch != 13) {
		if (ch == 27) {
			fileName.clear();
			fileName.push_back(27);
			go(x, y);
			cout << "                                   ";
			return fileName;
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
			if ((fileName.length() < 19) && (ch >= 32 && ch <= 126)) {
				fileName.push_back(ch);
				ok = true;
			}
			else ok = false;
		}
		go(x + 16, y);
		cout << "                     ";
		go(x + 16, y);
		cout << fileName;
		if (ok)
			index_ch++;
		go(index_ch, y);
		ch = _getch();
	}
	return fileName;
}

void Game::loadOption(int p, int& leve, int& life) {
	int x, y;
	if (p == 0) {
		x = BORDER / 2;
		y = 27;
	}
	else {
		x = BORDER + 2;
		y = 44;
	}
	string fileName;
	do {
		go(x, y-1);
		cout << "                               ";
		go(x, y-1);
		cout << "Loading process..";
		go(x, y);
		cout << "                               ";
		fileName = inputFileName(x, y);
		if (fileName == "" || (fileName.size() == 1 && fileName[0] == 27)) break;
	} while (!loadGame(fileName, x, y, leve, life));
	go(x, y-1);
	cout << "                                     ";
	go(x, y);
	cout << "                                     ";
}

bool Game::loadGame(string fileName, int x, int y, int& leve, int& life) {
	ifstream file;
	file.open(savedPath + fileName + ".bin", ios::binary);
	if (!file.is_open()) {
		go(x, y);
		cout << "                               ";
		go(x, y);
		cout << "File not found!";
		go(x, y);
		int temp = _getch();
		cout << "                               ";
		return false;
	}
	file.read((char*)& leve, sizeof(leve));
	file.read((char*)& life, sizeof(life));
	file.read((char*)& cheatmode, sizeof(cheatmode));
	file.close();
	return true;
}

void Game::saveOption() {
	string fileName;
	do {
		go(BORDER + 2, 43);
		cout << "                               ";
		go(BORDER + 2, 43);
		cout << "Saving process..";
		go(BORDER + 2, 44);
		cout << "                               ";
		fileName = inputFileName(BORDER+2, 44);
		if (fileName == "" || (fileName.size() == 1 && fileName[0] == 27)) break;
	} while (!saveGame(fileName));
	go(BORDER + 2, 43);
	cout << "                               ";
	go(BORDER + 2, 44);
	cout << "                               ";
}

bool Game::saveGame(string fileName) {
	ofstream file;
	ifstream check;
	check.open(savedPath + fileName + ".bin", ios::binary);
	//confirmation
	if (check.is_open())
	{
		check.close();
		go(BORDER + 2, 45);
		cout << "File already exists...";
		go(BORDER + 2, 46);
		cout << "this process will overwrite it";
		go(BORDER + 2, 47);
		cout << "Y to proceed or ESC to exit";
		int k = 0;
		while (k != 'y' && k != 'Y' && k != 27) k = _getch();
		for (int i = 0; i < 3; ++i)
		{
			go(BORDER + 2, 45 + i);
			cout << "                              ";
		}
		if (k == 27) return false;
	}
	file.open(savedPath + fileName + ".bin", ios::binary);
	if (!file.is_open())
		return false;
	int leve = current_level;
	int life = human.getLife();
	file.write((char*)& leve, sizeof(leve));
	file.write((char*)& life, sizeof(life));
	file.write((char*)& cheatmode, sizeof(cheatmode));
	file.close();
	go(BORDER + 2, 44);
	cout << "                               ";
	go(BORDER + 2, 44);
	cout << "Save successful!";
	Sleep(500);
	go(BORDER + 2, 44);
	cout << "                ";
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
	int sleep = 0;
	if (Option::playSound(soundPath + "victory.wav"))
		sleep = 3500;
	color(224);
	vector <string> win;
	win.push_back("..........................................................................................");
	win.push_back("'##::::'##:'####::'######::'########::'#######::'########::'##:::'##::::'####:'####:'####:");
	win.push_back(" ##:::: ##:. ##::'##... ##:... ##..::'##.... ##: ##.... ##:. ##:'##::::: ####: ####: ####:");
	win.push_back(" ##:::: ##:: ##:: ##:::..::::: ##:::: ##:::: ##: ##:::: ##::. ####:::::: ####: ####: ####:");
	win.push_back(" ##:::: ##:: ##:: ##:::::::::: ##:::: ##:::: ##: ########::::. ##:::::::: ##::: ##::: ##::");
	win.push_back(". ##:: ##::: ##:: ##:::::::::: ##:::: ##:::: ##: ##.. ##:::::: ##::::::::..::::..::::..:::");
	win.push_back(":. ## ##:::: ##:: ##::: ##:::: ##:::: ##:::: ##: ##::. ##::::: ##:::::::'####:'####:'####:");
	win.push_back("::. ###::::'####:. ######::::: ##::::. #######:: ##:::. ##:::: ##::::::: ####: ####: ####:");
	win.push_back(":::...:::::....:::......::::::..::::::.......:::..:::::..:::::..::::::::....::....::....::");

	int x = BORDER / 2 - 35, y = 15, n = win.size();
	for (int i = 0; i < n; ++i)
	{
		Sleep(200);
		go(x, y++);
		cout << win[i];
	}
	color(15);
	Sleep(sleep);
}

void Game::displayLose()
{
	Sleep(500);
	int sleep = 0;
	if (Option::playSound(soundPath + "death.wav"))
		sleep = 800;
	color(192);
	vector <string> lose;
	lose.push_back(".........................................................................................");
	lose.push_back(":'######::::::'###::::'##::::'##:'########:::::'#######::'##::::'##:'########:'########::");
	lose.push_back("'##... ##::::'## ##::: ###::'###: ##.....:::::'##.... ##: ##:::: ##: ##.....:: ##.... ##:");
	lose.push_back(" ##:::..::::'##:. ##:: ####'####: ##:::::::::: ##:::: ##: ##:::: ##: ##::::::: ##:::: ##:");
	lose.push_back(" ##::'####:'##:::. ##: ## ### ##: ######:::::: ##:::: ##: ##:::: ##: ######::: ########::");
	lose.push_back(" ##::: ##:: #########: ##. #: ##: ##...::::::: ##:::: ##:. ##:: ##:: ##...:::: ##.. ##:::");
	lose.push_back(" ##::: ##:: ##.... ##: ##:.:: ##: ##:::::::::: ##:::: ##::. ## ##::: ##::::::: ##::. ##::");
	lose.push_back(". ######::: ##:::: ##: ##:::: ##: ########::::. #######::::. ###:::: ########: ##:::. ##:");
	lose.push_back(":......::::..:::::..::..:::::..::........::::::.......::::::...:::::........::..:::::..::");

	int x = BORDER / 2 - 35, y = 15, n = lose.size();
	for (int i = 0; i < n; ++i)
	{
		Sleep(200);
		go(x, y++);
		cout << lose[i];
	}
	color(15);
	Sleep(sleep);
}

void Game::displayLevel()
{
	go(BORDER + 23, 17);
	if (current_level == 14)
		cout << 13;
	else 
		cout << current_level;
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
	while (!level->oktowrite());
	instructor();
	level->resume();
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
	vector <string> tmp;
	tmp.push_back("      # ###                                                            /###           /                     x");
	tmp.push_back("    /  /###  /                                                        /  ############/                      ");
	tmp.push_back("   /  /  ###/                                                        /     ##########                       ");
	tmp.push_back("  /  ##   ##                                                         #             /                        ");
	tmp.push_back(" /  ###                                                               ##          /                         ");
	tmp.push_back("##   ##     ###  /###     /###     /###     /###   ##   ####                     /         /###     /###    ");
	tmp.push_back("##   ##      ###/ #### / / ###  / / #### / / #### / ##    ###  /                /         / ###  / / ###  / ");
	tmp.push_back("##   ##       ##   ###/ /   ###/ ##  ###/ ##  ###/  ##     ###/                /         /   ###/ /   ###/  ");
	tmp.push_back("##   ##       ##       ##    ## ####     ####       ##      ##                /         ##    ## ##    ##   ");
	tmp.push_back("##   ##       ##       ##    ##   ###      ###      ##      ##               /          ##    ## ##    ##   ");
	tmp.push_back(" ##  ##       ##       ##    ##     ###      ###    ##      ##              /           ##    ## ##    ##   ");
	tmp.push_back("  ## #      / ##       ##    ##       ###      ###  ##      ##             /            ##    ## ##    ##   ");
	tmp.push_back("   ###     /  ##       ##    ##  /###  ## /###  ##  ##      ##         /##/           / ##    ## ##    ##   ");
	tmp.push_back("    ######/   ###       ######  / #### / / #### /    #########        /  ############/   ######   ######    ");
	tmp.push_back("      ###      ###       ####      ###/     ###/       #### ###      /     ##########     ####     ####     ");
	tmp.push_back("                                                             ###                                            ");
	tmp.push_back("                                                      #####   ###                                           ");
	tmp.push_back("                                                    /#######  /#                                            ");
	tmp.push_back("                                                   /      ###/                                              ");

	int n = tmp.size();
	int x = 50, y = 5;
	color(14);
	for (int i = 0; i < n; ++i) {
		go(x, y++);
		cout << tmp[i];
	}
	color(15);
}

void Game::instructor() {
	setcursor(0, 0); //hide cursor

	int x = BORDER + 5, y = 3;
	vector <string> crossy;
	crossy.push_back("  ___________  ____  ______ _________.__.");
	crossy.push_back("_/ ___\\_  __ \\/  _ \\/  ___//  ___<   |  |");
	crossy.push_back("\\  \\___|  | \\(  <_> )___ \\ \\___ \\ \\___  |");
	crossy.push_back(" \\___  >__|   \\____/____  >____  >/ ____|");
	crossy.push_back("     \\/                 \\/     \\/ \\/     ");

	color(4);
	int n = crossy.size();
	for (int i =0;i<n;++i)
	{
		go(x, y++);
		cout << crossy[i];
	}

	vector <string> zoo;
	zoo.push_back("____________   ____  ");
	zoo.push_back("\\___   /  _ \\ /  _ \\ ");
	zoo.push_back(" /    (  <_> |  <_> )");
	zoo.push_back("/_____ \\____/ \\____/ ");
	zoo.push_back("      \\/             ");

	x += 10;
	color(11);
	
	n = zoo.size();
	for (int i = 0; i < n; ++i)
	{
		go(x, y++);
		cout << zoo[i];
	}

	x = BORDER + 15;
	y = 17;
	color(15);
	go(x, y);
	cout << "LEVEL: ";
	displayLevel();
	go(x, y+=3);
	cout << "LIVES: ";
	human.displayLives();
	
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
	cout << setw(20) << "Press K to SAVE";
	go(x, y += 2);
	cout << setw(20) << "Press L to LOAD";
	go(x, y += 2);
	cout << setw(20) << "Press ESC to EXIT";

}

void Game::main_run(int leve, int life) {
	//first initialization
	cheatmode = op.getcheatmode();
	human.setLife(life);
	level = new LEVEL(leve, 100 -leve*3);
	int k = 0, l = 1;
	thread t1(&LEVEL::run, level, ref(human));
	while (!level->oktowrite());
	instructor();
	human.spawn();
	level->resume();

	//game loop
	while (k != 27)
	{
		k = _getch();
		bool keep = level->status();
		if (k == 'p' || k == 'P') //pause game
		{
			while (!level->oktowrite());
		}
		else if (k == 'r' || k == 'R') //resume game
		{
			level->resume();
		}
		else if (k == 'k' || k == 'K') //save game
		{
			while (!level->oktowrite());
			saveOption();
			if (keep) level->pause();
			else level->resume();
		}
		else if (k == 'l' || k == 'L') //load game
		{
			while (!level->oktowrite());
			int leve = 0, life = 0;
			loadOption(1, leve, life);
			human.setLife(life);
			if (leve != 0 && life != 0)
			{
				t1 = switchlevel(&t1, level, leve, 100 - leve * 3);
				while (!level->oktowrite());
				instructor();
				human.spawn();
			}
			if (keep) level->pause();
			else level->resume();
		}
		//for testing only
		else if ((k == 'n' || k == 'N')&& cheatmode)
		{
			if (current_level < 14)
				t1 = switchlevel(&t1, level, ++current_level, 100 - current_level*3);
			while (!level->oktowrite());
			instructor();
			human.spawn();
			level->resume();
		}
		else
		{
			if (keep) continue;
			while (!level->oktowrite());
			if (human.move(k))
			{
				level->resume();
				Sleep(100); //delay human movement
				//if there is an impact
				if (level->freeze_main())
				{
					Sleep(1500);
					//confirmation, actually bug avoiding :)
					go(1, 46);
					// check if player is dead
					if (human.isDead()) {
						//insert lose display
						while (!level->oktowrite());
						displayLose();
						Sleep(1500);
						k = 27;
						continue;
					}
					cout << "Press c to continue";
					while (k != 'c' && k != 'C' && k != 27) k = _getch();
					go(1, 46);
					cout << "                   ";
				}
				//check human status
				if (human.isFinish())
				{
					if (current_level < 14)
					{
						t1 = switchlevel(&t1, level, ++current_level, 100-current_level*3);
						while (!level->oktowrite());
						instructor();
						level->resume();
						human.spawn();
					}
					else {
						//insert win display
						while (!level->oktowrite());
						displayWin();
						Sleep(1500);
						k = 27;
					}
				}
			}
			if (keep) level->pause();
			else level->resume();
		}
		if (human.isDead()) {
			//insert lose display
			while (!level->oktowrite());
			displayLose();
			Sleep(1500);
			k = 27;
		}
	}
	if (k == 27)
	{
		exitGame(&t1, level);
	}
}