#include "People.h"

People::People() {
	live = 3;
	pY = 45;
	pX = 80;
	state = true;
	ifstream fin("human.txt");
	if (fin.is_open()) {
		map.clear();
		while(!fin.eof()){
			string line;
			getline(fin, line, '\n');
			map.push_back(line);
		}
	}
	fin.close();
	spawn();
}

People::~People() {
}

void People::delDraw() {
	int n = map.size();
	if (n > 0)
	{
		int len = map[0].length();
		string str = "";
		for (int i = 0; i < len; ++i)
			str += " ";
		for (int i = 0; i < n; ++i) {
			go(pX, pY + i);
			cout << str;
		}
	}
}

void People::Draw() {
	int n = map.size();
	for (int i = 0; i < n; ++i) {
		go(pX, pY+i);
		cout << map[i];
	}
}

void People::move(int key) {
	if (key == 'a' || key == 'A')
		LEFT();
	else if (key == 'd' || key == 'D')
		RIGHT();
	else if (key == 'w' || key == 'W')
		UP();
	else if (key == 's' || key == 'S')
		DOWN();
	else if (key == 224)
	{
		key = _getch();
		if (key == 75)
			LEFT();
		else if (key == 77)
			RIGHT();
		else if (key == 72)
			UP();
		else if (key == 80)
			DOWN();
	}
}

void People::UP() {
	if (pY - 5 >= 0)
	{
		delDraw();
		pY -= 5;
		Draw();
	}
}

void People::DOWN() {
	if (pY + 5 <= 45)
	{
		delDraw();
		pY += 5;
		Draw();
	}
}

void People::LEFT() {
	if (pX - 1 >= 0)
	{
		delDraw();
		pX -= 1;
		Draw();
	}
}

void People::RIGHT() {
	if (pX < 157)
	{
		delDraw();
		pX += 1;
		Draw();
	}
}

bool People::isImpact() {
	return false;//do sth with this
}

bool People::isFinish() {
	if (pY == 0)
	{
		if(live<3)
			live++;
		return true;
	}
	return false;
}

bool People::isDead() {
	if (isImpact())// wait for impact function
	{
		live--;
		return true;
	}
	return false;
}

pair<int, int> People::getCor()
{
	return make_pair(pX,pY);
}

bool** People::getImpactMap()
{
	int r = map.size();
	if (r > 0) {
		int c = map[0].length();
		bool** impact = new bool* [r];
		for (int i = 0; i < r; ++i) {
			impact[i] = new bool[c];
			for (int j = 0; j < c; ++j)
			{
				if (map[i][j] != ' ')
					impact[i][j] = true;
				else impact[i][j] = false;
			}
		}
		return impact;
	}
	return nullptr;
}

void People::spawn() {
	pY = 45;
	pX = 80;
	Draw();
}
