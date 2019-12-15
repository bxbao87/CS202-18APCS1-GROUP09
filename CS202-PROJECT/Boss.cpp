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
	lenAni = map[0].size();
	this->n = n; this->d = d; this->closeness = closeness;  this->traffic = traffic; c = 1; count = 0;
	reset_dir();
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
	x = BORDER / 2 - lenAni / 2;
	y = 20 - map.size() / 2;
	bx = BORDER / 2 - lenAni / 2; 
	by = 20 - map.size() / 2;
}

void BOSS::makeSound()
{
	//do something
}

bool BOSS::spawn()
{
	change_dir();
	//random move
	x = bx + rand() % 3 - 1;
	y = by + rand() % 3 - 1;
	//correct movement
	if (x < 1) x = 1;
	else if (x > BORDER - lenAni) x = BORDER - lenAni;
	if (y > 42 - 17) y = 42 - 17;
	else if (y < 4) y = 4;
	return true;
}

void BOSS::human(pair<int, int> tmp)
{
	int n = dir.size();
	if ((n == 0 || (n != 0 && tmp != dir[n - 1])) && tmp.second != 45)
		dir.push_back(tmp);
}

void BOSS::reset_dir()
{
	dir.clear();
	pair <int, int> tmp(80, 45);
	dir.push_back(tmp);
	bx = BORDER / 2 - map[0].size() / 2;
	by = 43 / 2 - map.size() / 2;
}

void BOSS::impact()
{
	reset_dir();
}

void BOSS::change_dir()
{
	if (dir.size() == 4)
	{
		int tx = dir[3].first - dir[0].first, ty = dir[3].second - dir[0].second;
		hx = dir[3].first; hy = dir[3].second;
		if (tx > 0)
		{
			if (ty > 0)
			{
				bx = hx + 3;
				by = hy + 3;
			}
			else if (ty < 0)
			{
				bx = hx + 3;
				by = hy - 17;
			}
			else
			{
				bx = hx + 3;
			}
		}
		else if (tx < 0)
		{
			if (ty > 0)
			{
				bx = hx - 81;
				by = hy + 3;
			}
			else if (ty < 0)
			{
				bx = hx - 81;
				by = hy - 3;
			}
			else
			{
				bx = hx - 81;
			}
		}
		else
		{
			if (ty > 0)
			{
				bx = hx - 40;
				by = hy + 19; 
			}
			else if (ty < 0)
			{
				bx = hx - 40;
				by = hy - 19;
			}
		}
		pair <int, int> tmp = dir[3];
		dir.clear();
		dir.push_back(tmp);
	}
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