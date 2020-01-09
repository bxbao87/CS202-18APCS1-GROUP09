#include"option.h"

bool Option::sound = true;

Option::Option() {
	x = 70, y = 7;
	music = true;
	sound = true;
	cheatmode = false;
	ifstream set(savedPath + "settings.bin", ios::binary);
	if (set.is_open()) {
		set.read((char*)& music, sizeof(music));
		set.read((char*)& sound, sizeof(sound));
		set.read((char*)& cheatmode, sizeof(cheatmode));
	}
	set.close();

	logo.push_back(" ________  ________  _________  ___  ________  _________      ");
	logo.push_back("|\\   __  \\|\\   __  \\|\\___   ___\\\\  \\|\\   __  \\|\\   ___  \\    ");
	logo.push_back("\\ \\  \\|\\  \\ \\  \\|\\  \\|___ \\  \\_\\ \\  \\ \\  \\|\\  \\ \\  \\ \\\\  \\   ");
	logo.push_back(" \\ \\  \\\\\\  \\ \\   ____\\   \\ \\  \\ \\ \\  \\ \\  \\\\\\  \\ \\  \\ \\\\  \\  ");
	logo.push_back("  \\ \\  \\\\\\  \\\ \\  \\___|    \\ \\  \\ \\ \\  \\ \\  \\\\\\  \\ \\  \\ \\\\  \\ ");
	logo.push_back("   \\ \\_______\\ \\__\\        \\ \\__\\ \\ \\__\\ \\_______\\ \\__\\ \\\\__\\");
	logo.push_back("    \\|_______|\\|__|         \\|__|  \\|__|\\|_______|\\|__|  \\|__|");

	playMusic();
}

Option::~Option()
{
	ofstream fout(savedPath + "settings.bin", ios::binary);
	if (fout.is_open()) {
		fout.write((char*)& music, sizeof(music));
		fout.write((char*)& sound, sizeof(sound));
		fout.write((char*)& cheatmode, sizeof(cheatmode));
	}
	fout.close();
}

bool Option::getcheatmode()
{
	return cheatmode;
}

void Option::setcheatmode(const bool& cheatmode)
{
	this->cheatmode = cheatmode;
}

void Option::display()
{
	system("cls");
	color(8);
	cout << "press ESC to go back menu";
	x = 70, y = 7;
	color(11);
	int size = logo.size();
	for (int i = 0; i < size; ++i) {
		go(x, y++);
		cout << logo.at(i);
	}
	color(15);
	go(x+=20, y += 5);
	cout << "MUSIC:  ";
	go(x, y += 3);
	cout << "SOUND:  ";
	go(x, y += 3);
	cout << "CHEAT:  ";
	y -= 3;
	color(111);
	displayMusic();
	color(15);
	displaySound();
	displayCheat();
}

void Option::displayMusic()
{
	int r = y - 3;
	go(x+10, r);
	if (music)
		cout << " ON";
	else cout << "OFF";
}

void Option::displaySound()
{
	go(x+10, y);
	if (sound)
		cout << " ON";
	else cout << "OFF";
}

void Option::displayCheat()
{
	go(x + 10, y+=3);
	if (cheatmode)
		cout << " ON";
	else cout << "OFF";
	y -= 3;
}

void Option::change()
{
	int op = 0;
	int a = x - 5;
	int b = y - 3;
	color(12);
	go(a, b + op * 3);
	cout << ">>";
	int key = _getch();
	color(111);
	while (key != 27) {
		if (key == 13 || key == 32) {
			if (op == 0)
			{
				changeMusic();
				displayMusic();
			}
			else if (op == 1) {
				changeSound();
				displaySound();
			}
			else 
			{
				changeCheat();
				displayCheat();
			}
		}
		else if (key == 'w' || key == 'W' || key == 's' || key == 'S' || key == 224)
		{
			bool move = true;
			int ex;
			if (key == 224)
			{
				ex = _getch();
				if (ex != 72 && ex != 80)
					move = false;
			}
			if (move) {
				color(15);
				go(a, b + op * 3);
				cout << "  ";
				if (op == 0)
					displayMusic();
				else if (op == 1)
					displaySound();
				else
					displayCheat();
				color(12);
				if (key == 'w' || key == 'W' || (key == 224 && ex == 72))
				{
					--op; if (op < 0) op = 2;
				}
				else
				{
					++op; if (op > 2) op = 0;
				}
				go(a, b + op * 3);
				cout << ">>";
				color(111);
				if (op == 0)
					displayMusic();
				else if (op == 1)
					displaySound();
				else
					displayCheat();
			}
		}
		key = _getch();
	}
	color(15);
}

void Option::changeMusic() {
	music = !music;
	if (!music)
		PlaySound(NULL, 0, 0);
	else playMusic();
}

void Option::changeSound() {
	sound = !sound;
}

void Option::changeCheat()
{
	cheatmode = !cheatmode;
}

bool Option::playSound(string path) {
	bool play = false;
	if (sound)
		play=PlaySound(TEXT(string(path).c_str()), NULL, SND_FILENAME | SND_ASYNC);
	return play;
}

void Option::playMusic() {
	if (music)
		PlaySound(TEXT(string(soundPath+"summer.wav").c_str()), NULL, SND_LOOP | SND_ASYNC);
}