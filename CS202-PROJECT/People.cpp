#include "People.h"
#include"thanh.h"

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
	DRAW d;
	d.erhuman(pX, pY);
}

void People::draw() {
	DRAW d;
	d.human(pX, pY);
}

void People::move(int key) {
	if (key == 'a' || key == 'A' || key == 75)
		LEFT();
	else if (key == 'd' || key == 'D' || key == 77)
		RIGHT();
	else if (key == 'w' || key == 'W' || key == 72)
		UP();
	else if (key == 's' || key == 'S' || key == 80)
		DOWN();
}

void People::UP() {
	if (pY - 5 >= 0)
	{
		delDraw();
		pY -= 5;
		draw();
	}
}

void People::DOWN() {
	if (pY + 5 <= 45)
	{
		delDraw();
		pY += 5;
		draw();
	}
}

void People::LEFT() {
	if (pX - 1 >= 0)
	{
		delDraw();
		pX -= 1;
		draw();
	}
}

void People::RIGHT() {
	if (pX < 160)
	{
		delDraw();
		pX += 1;
		draw();
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
