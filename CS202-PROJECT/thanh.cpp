#include "thanh.h"

//class OBJECT
OBJECT::OBJECT()
{
	n = 0; d = 0; closeness = 0; x = 0; y = 0; green = 0; red = 0; traffic = false; hx = 80; hy = 45;
}

void OBJECT::human(int x,int y)
{
	this->hx = x;
	this->hy = y;
}

//class LDOLPHIN
LDOLPHIN::LDOLPHIN(int y,int n,int d,int closeness,bool traffic)
{
	this->y = y;
	ifstream in;
	in.open("LDOLPHIN.txt");
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

void LDOLPHIN::traffic_light()
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
	int s = 159-15;
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
	traffic_light();
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

/*
void LDOLPHIN::get_map(bool**& map, int& x, int& y)
{
	map = new bool* [15];
	for (int i = 0; i < 15; ++i)
		map[i] = new bool[4];
	x = this->x; y = this->y;
	for (int i = 0; i < 15; ++i)
		for (int j = 0; j < 4; ++j)
			map[i][j] = this->map[i][j];
}*/

void LDOLPHIN::switch_light()
{
	if (light == 0)
	{
		if (rand() % 13 < 6)
		{
			light = 2;
			red += (rand() % 5) * 1000;
		}
		else
		{
			light = 1;
			green += (rand() % 5) * 1000;
		}
	}
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
	in.open("RDOLPHIN.txt");
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

void RDOLPHIN::traffic_light()
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
	while (s < 160-15)
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
	traffic_light();
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

/*
void RDOLPHIN::get_map(bool**& map, int& x, int& y)
{
	map = new bool* [15];
	for (int i = 0; i < 15; ++i)
		map[i] = new bool[4];
	x = this->x; y = this->y;
	for (int i = 0; i < 15; ++i)
		for (int j = 0; j < 4; ++j)
			map[i][j] = this->map[i][j];
}*/

void RDOLPHIN::switch_light()
{
	if (light == 0)
	{
		if (rand() % 13 < 6)
		{
			light = 2;
			red += (rand() % 5) * 1000;
		}
		else
		{
			light = 1;
			green += (rand() % 5) * 1000;
		}
	}
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
	in.open("BOSS.txt");
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

void BOSS::traffic_light()
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
	traffic_light();
	color(c);
	draw(x, y);
	color(15);
}

//class LEVEL
LEVEL::~LEVEL()
{
	int n = arr.size();
	for (int i = 0; i < n; ++i)
		if (arr[i] != nullptr) delete arr[i];
}

LEVEL::LEVEL(int choice,int delay)
{
	system("cls");
	if (choice == 1)
	{
		split();
		OBJECT* a;
		a = new LDOLPHIN(4, 5, 10, 30, true);
		arr.push_back(a);
		a = new RDOLPHIN(9, 2, 10, 45, true);
		arr.push_back(a);
		a = new LDOLPHIN(14, 4, 10, 35, true);
		arr.push_back(a);
		a = new RDOLPHIN(19, 8, 10, 50, true);
		arr.push_back(a);
		/*
		a = new LDOLPHIN(24, 5, 10, 30, true);
		arr.push_back(a);
		a = new RDOLPHIN(29, 2, 10, 45, true);
		arr.push_back(a);
		a = new LDOLPHIN(34, 4, 10, 35, true);
		arr.push_back(a);
		a = new RDOLPHIN(39, 8, 10, 50, true);
		arr.push_back(a);*/
	}
	else if (choice == 10)
	{
		boss_split();
		OBJECT* a;
		a = new BOSS(1, 1, 1, 1, true);
		arr.push_back(a);
	}
	stop = false; tmp_stop = false; now = clock(); ok = true; this->delay = delay;
}

void LEVEL::split()
{
	string t = "---------------------------------------------------------------------------------------------------------------------------------------------------------------";
	for (int i = 0; i < 9; ++i)
	{
		go(0, 3 + i * 5);
		cout << t;
	}
	for (int i = 0; i < 48; ++i)
	{
		go(160, i);
		cout << char(179); // |
	}
}

void LEVEL::boss_split()
{
	string t = "---------------------------------------------------------------------------------------------------------------------------------------------------------------";
	go(0, 3); // upper bound
	cout << t;
	go(0, 43);
	cout << t;
	for (int i = 0; i < 48; ++i)
	{
		go(160, i);
		cout << char(179); // |
	}
}

void LEVEL::pause()
{
	tmp_stop = true;
}

void LEVEL::resume()
{
	tmp_stop = false;
}

void LEVEL::kill()
{
	stop = true;
}

bool LEVEL::oktowrite()
{
	if (ok) return true;
	return false;
}

void LEVEL::passCoor(int x, int y)
{
	if (arr.size() == 1) //applied for boss only
		arr[0]->human(x, y);
}

void LEVEL::run()
{
	int n = arr.size();
	while (!stop)
	{
		if (tmp_stop)
		{
			//do nothing
		}
		else
		{
			ok = false;
			now = clock() - now;
			for (int i = 0; i < n; ++i)
			{
				if (!arr[i]->done(now)) arr[i]->switch_light();
				arr[i]->display();
			}
			ok = true;
			now = clock();
			Sleep(100);
		}
	}
}