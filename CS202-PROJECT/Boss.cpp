#include "Boss.h"

//class BOSS
BOSS::BOSS(int y, int n, int d, int closeness, bool traffic)
{
	ifstream in;
	in.open(path + "BOSS.txt");
	if (in.is_open())
	{
		string g;
		while (!in.eof())
		{
			getline(in, g);
			map.push_back(g);
			g.clear();
		}
		in.close();
	}
	this->n = n; this->d = d; this->closeness = closeness;  this->traffic = traffic; c = 1; count = 0;
	first_spawn();
	arr.push_back(x);
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
	++count;
	if (count > 50)
	{
		++c;
		count = 0;
	}
	if (c > 15) c = 1;
}

void BOSS::first_spawn()
{
	//middle screen location
	x = BORDER / 2 - map[0].size() / 2;
	y = 43 / 2 - map.size() / 2;
}

void BOSS::makeSound()
{
	//do something
}

bool BOSS::spawn()
{
	int cx = map[0].size() / 2, cy = map.size() / 2;
	int xx = x + cx, yy = y + cy; //at heart of boss
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
	x = xx - cx;
	if (x < 1) x = 1;
	else if (x >= BORDER - 1 - cx*2) x = BORDER - 1 - cx*2;
	y = yy - cy;
	if (y < 4) y = 4;
	else if (y >= 43 - cy*2) y = 43 - cy*2;
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
	arr[0] = x;
	draw(x, y);
	color(15);
}