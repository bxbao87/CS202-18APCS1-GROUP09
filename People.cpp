#include "People.h"
#include"thanh.h"

People::People() {
	pY = 45;
	pX = 80;
	state = true;
	draw();
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
	if (key == 'a' || key == 'A')
		LEFT();
	else if (key == 'd' || key == 'D')
		RIGHT();
	else if (key == 'w' || key == 'W')
		UP();
	else if (key == 's' || key == 'S')
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
