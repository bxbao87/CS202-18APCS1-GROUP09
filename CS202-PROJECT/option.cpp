#include"option.h"

bool Option::sound = true;

Option::Option() {
	x = 70, y = 7;
	music = true;
	ifstream set(savedPath + "settings.bin", ios::binary);
	if (set.is_open()) {
		set.read((char*)& music, sizeof(music));
		set.read((char*)& sound, sizeof(sound));
	}
	set.close();
	ifstream fin(path + "option.txt");
	if (fin.is_open()) {
		string line;
		while (getline(fin, line, '\n')) {
			logo.push_back(line);
		}
	}
	fin.close();
	playMusic();
}

Option::~Option()
{
	ofstream fout(savedPath + "settings.bin", ios::binary);
	if (fout.is_open()) {
		fout.write((char*)& music, sizeof(music));
		fout.write((char*)& sound, sizeof(sound));
	}
	fout.close();
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
	color(111);
	displayMusic();
	color(15);
	displaySound();
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
		if (key == 13) {
			if (op == 0)
			{
				changeMusic();
				displayMusic();
			}
			else {
				changeSound();
				displaySound();
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
				else displaySound();
				op = (++op) % 2;
				color(12);
				go(a, b + op * 3);
				cout << ">>";
				color(111);
				if (op == 0)
					displayMusic();
				else displaySound();
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