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
	
	draw();
}

People::~People() {
	for (int i = 0; i < 3; ++i)
		delete[] map[i];
	delete[] map;
}

void People::delDraw() {
	DRAW::erhuman(pX, pY);
}

void People::draw() {
	DRAW::human(pX, pY);
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
	if (pY - 5 >= Top_bound)
	{
		delDraw();
		pY -= Y_MOVE;
		draw();
	}
}

void People::DOWN() {
	if (pY + 5 <= Bot_bound)
	{
		delDraw();
		pY += Y_MOVE;
		draw();
	}
}

void People::LEFT() {
	if (pX - 1 >= Left_bound)
	{
		delDraw();
		pX -= X_MOVE;
		draw();
	}
}

void People::RIGHT() {
	if (pX < Right_bound)
	{
		delDraw();
		pX += X_MOVE;
		draw();
	}
}

bool People::isImpact(OBJECT* object) {


	return false;//do sth with this
}

bool People::isFinish() {
	if (pY == 0)
		return true;
	return false;
}

bool People::isDead(OBJECT* object) {
	if (isImpact(object))// wait for impact function
		return true;
	return false;
}
