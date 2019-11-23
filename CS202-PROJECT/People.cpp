#include "People.h"

People::People() {
	pY = 45;
	pX = 80;
	state = true;
	map = new bool*[3];
	for (int i = 0; i < 3; ++i) {
		map[i] = new bool[3];
		for (int j = 0; j < 3; ++j)
			map[i][j] = true;
	}
	map[0][0] = map[0][2] = map[2][1] = false;
	
	Draw();
}

People::~People() {
	for (int i = 0; i < 3; ++i)
		delete[] map[i];
	delete[] map;
}

void People::delDraw() {
	int x = pX, y = pY;
	for (int i = 0; i < 3; ++i)
	{
		go(x, y + i);
		cout << "   ";
	}
}

void People::Draw() {
	int x = pX, y = pY;
	go(x, y);
	cout << " @ ";
	go(x, y + 1);
	cout << "-|-";
	go(x, y + 2);
	cout << "/ \\";
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
		return true;
	return false;
}

bool People::isDead() {
	if (isImpact())// wait for impact function
		return true;
	return false;
}
