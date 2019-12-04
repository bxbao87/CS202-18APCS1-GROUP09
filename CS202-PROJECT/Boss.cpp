#include "Boss.h"

//class BOSS
//class BOSS
BOSS::BOSS(int y, int n, int d, int closeness, bool traffic)
{
	ifstream in;
	in.open(path + "BOSS.txt");
	if (in.is_open())
	{
		string g;
		in.ignore();
		while (!in.eof())
		{
			getline(in, g);
			map.push_back(g);
			g.clear();
		}
		in.close();
	}
	this->n = n; this->d = d; this->closeness = closeness;  this->traffic = traffic; c = 15;
	first_spawn();
}

void BOSS::draw(int x, int y)
{
	int n = map.size();
	for (int i = 0; i < n; ++i)
	{
		go(x, y + i);
		cout << map[i];
	}
}

void BOSS::erase(int x, int y)
{
	int n = map.size();
	for (int i = 0; i < n; ++i)
	{
		go(x, y + i);
		cout << "                                                                                 ";
	}
}

void BOSS::light_display()
{
	if (rand() % 27 > 25)
		c = rand() % 15;
}

void BOSS::first_spawn()
{
	x = 47, y = 17;
}

void BOSS::makeSound()
{
	//do something
}

bool BOSS::spawn()
{
	int xx = x + 32, yy = y + 5; //at heart of boss
	int hxx = hx + 1, hyy = hy + 1; //at heart of human
	//initialize steps for boss (difficulty for player)
	int steps = rand() % 11;
	if (steps < 5) steps = 2;
	else if (steps < 9) steps = 1;
	else steps = 3;
	int ix, iy; //inaccurate moves
	ix = rand() % 23, iy = rand() % 5;
	ix -= 9; iy -= 1;
	if (xx <= hxx) xx = xx + steps + ix;
	else xx = xx - steps - ix;
	if (yy <= hyy) yy = yy + steps + iy;
	else yy = yy - steps - iy;
	x = xx - 32;
	if (x < 0) x = 0;
	else if (x >= 159 - 64) x = 159 - 64;
	y = yy - 5;
	if (y < 4) y = 4;
	else if (y >= 43 - 11) y = 43 - 11;
	return true;
}

void BOSS::set_traffic(bool s)
{

}

void BOSS::display()
{
	erase(x, y);
	spawn();
	light_display();
	color(c);
	draw(x, y);
	color(15);
}
