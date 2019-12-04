#include "thanh.h"

//class OBJECT
OBJECT::OBJECT()
{
	n = 0; d = 0; closeness = 0; x = 0; y = 0; hx = 80; hy = 45;
}

void OBJECT::human(int x,int y)
{
	this->hx = x;
	this->hy = y;
}

vector<string> OBJECT::getMap() {
	return map;
}

#include "Objects.h"
#include "Setups.h"

//class LDOLPHIN
LDOLPHIN::LDOLPHIN(int y, int n, int d, int closeness, bool traffic)
{
	this->y = y;
	ifstream in;
	in.open(path + "LDOLPHIN.txt");
	if (in.is_open())
	{
		string g;
		in.ignore();
		while (!in.eof())
		{
			for (int i = 0; i < 4; ++i)
			{
				getline(in, g);
				map.push_back(g);
				g.clear();
			}
		}
		in.close();
	}
	this->n = n; this->d = d; this->closeness = closeness;  this->traffic = traffic;
	first_spawn();
}

void LDOLPHIN::draw(int x, int y)
{
	int n = map.size();
	for (int i = 0; i < n; ++i)
	{
		go(x, y + i);
		cout << map[i];
	}
}

void LDOLPHIN::erase(int x, int y)
{
	int n = map.size();
	for (int i = 0; i < n; ++i)
	{
		go(x, y + i);
		cout << "              ";
	}
}

void LDOLPHIN::light_display()
{
	if (light == 1)
	{
		go(159, y + 2);
		color(34); //green background
		cout << ' ';
		color(15);
		go(159, y + 1);
		cout << ' ';
	}
	else if (light == 2)
	{
		go(159, y + 1);
		color(68); //red blackground
		cout << ' ';
		color(15);
		go(159, y + 2);
		cout << ' ';
	}
}

void LDOLPHIN::first_spawn()
{
	int s = 159 - 15;
	while (s > 0)
	{
		arr.push_back(s);
		s -= closeness;
	}
	light = 1; green = 1000;
}

void LDOLPHIN::makeSound()
{
	//do something
}

void LDOLPHIN::spawn_rate(int n, int d)
{
	this->n = n; this->d = d;
}

bool LDOLPHIN::spawn()
{
	if (rand() % d <= n) return true;
	return false;
}

void LDOLPHIN::close(int closeness)
{
	this->closeness = closeness;
}

void LDOLPHIN::set_traffic(bool s)
{
	if (s) traffic = true;
	else traffic = false;
}

void LDOLPHIN::display()
{
	int n = arr.size();
	for (int i = 0; i < n; ++i)
		erase(arr[i], y);
	light_display();
	if (spawn() && arr[n - 1] > closeness) //random appearance
	{
		arr.push_back(0);
		++n;
	}
	for (int i = 0; i < n; ++i)
	{
		++arr[i];//move to the right
		if (i == 0)
		{
			if (arr[i] + 16 > 160) //out of range
			{
				if (light == 1)
				{
					arr.erase(arr.begin() + i);
					--n;
				}
				else if (light == 2) --arr[i]; //stop at red light
			}
		}
		else
		{
			if (abs(arr[i] - arr[i - 1]) < closeness) --arr[i];
		}
	}
	color(3);
	for (int i = 0; i < n; ++i)
		draw(arr[i], y);
	color(15);
}

bool LDOLPHIN::done(int second) //check if is there any light on
{
	if (!traffic) return true;
	if (light == 1)
	{
		green -= second;
		if (green < 0)
		{
			green = 0;
			light = 0;
			return false;
		}
		return true;
	}
	else if (light == 2)
	{
		red -= second;
		if (red < 0)
		{
			red = 0;
			light = 0;
			return false;
		}
		return true;
	}
	return false;
}

//class RDOLPHIN
RDOLPHIN::RDOLPHIN(int y, int n, int d, int closeness, bool traffic)
{
	this->y = y;
	ifstream in;
	in.open(path + "RDOLPHIN.txt");
	if (in.is_open())
	{
		string g;
		in.ignore();
		while (!in.eof())
		{
			for (int i = 0; i < 4; ++i)
			{
				getline(in, g);
				map.push_back(g);
				g.clear();
			}
		}
		in.close();
	}
	this->n = n; this->d = d; this->closeness = closeness;  this->traffic = traffic;
	first_spawn();
}

void RDOLPHIN::draw(int x, int y)
{
	int n = map.size();
	for (int i = 0; i < n; ++i)
	{
		go(x, y + i);
		cout << map[i];
	}
}

void RDOLPHIN::erase(int x, int y)
{
	int n = map.size();
	for (int i = 0; i < n; ++i)
	{
		go(x, y + i);
		cout << "              ";
	}
}

void RDOLPHIN::light_display()
{
	if (light == 1)
	{
		go(1, y + 2);
		color(34); //green background
		cout << ' ';
		color(15);
		go(1, y + 1);
		cout << ' ';
	}
	else if (light == 2)
	{
		go(1, y + 1);
		color(68); //red blackground
		cout << ' ';
		color(15);
		go(1, y + 2);
		cout << ' ';
	}
}

void RDOLPHIN::first_spawn()
{
	int s = 0;
	while (s < 160 - 15)
	{
		arr.push_back(s);
		s += closeness;
	}
	light = 1; green = 1000;
}

void RDOLPHIN::makeSound()
{
	//do something
}

void RDOLPHIN::spawn_rate(int n, int d)
{
	this->n = n; this->d = d;
}

bool RDOLPHIN::spawn()
{
	if (rand() % d <= n) return true;
	return false;
}

void RDOLPHIN::close(int closeness)
{
	this->closeness = closeness;
}

void RDOLPHIN::set_traffic(bool s)
{
	if (s) traffic = true;
	else traffic = false;
}

void RDOLPHIN::display()
{
	int n = arr.size();
	for (int i = 0; i < n; ++i)
		erase(arr[i], y);
	light_display();
	if (spawn() && 160 - arr[n - 1] > closeness + 15) //random appearance
	{
		arr.push_back(160 - 15);
		++n;
	}
	for (int i = 0; i < n; ++i)
	{
		--arr[i];//move to the left
		if (i == 0)
		{
			if (arr[i] <= 1) //out of range
			{
				if (light == 1)
				{
					arr.erase(arr.begin() + i);
					--n;
				}
				else if (light == 2) ++arr[i]; //stop at red light
			}
		}
		else
		{
			if (abs(arr[i] - arr[i - 1]) < closeness) ++arr[i];
		}
	}
	color(3);
	for (int i = 0; i < n; ++i)
		draw(arr[i], y);
	color(15);
}

bool RDOLPHIN::done(int second) //check if is there any light on
{
	if (!traffic) return true;
	if (light == 1)
	{
		green -= second;
		if (green < 0)
		{
			green = 0;
			light = 0;
			return false;
		}
		return true;
	}
	else if (light == 2)
	{
		red -= second;
		if (red < 0)
		{
			red = 0;
			light = 0;
			return false;
		}
		return true;
	}
	return false;
}

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
		cout << "                                                               ";
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


//class LIGHT
LIGHT::LIGHT() {
	side = true; stop = true;
	green_time = 0; red_time = 0;
	light = 0;
}

LIGHT::LIGHT(int type, bool side, int y) {
	this->stop = true;
	this->green_time = 0; this->red_time = 0;
	this->light = 0;
	this->side = side;
void BOSS::display()
{
	erase(x, y);
	spawn();
	light_display();
	color(c);
	draw(x, y);
	color(15);
}