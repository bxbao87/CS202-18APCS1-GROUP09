#include "thanh.h"

OBJECT::OBJECT()
{
	n = 0; d = 0; closeness = 0; x = 0; y = 0; green = 0; red = 0; traffic = false;
}

//class LDOLPHIN
LDOLPHIN::LDOLPHIN(int y,int n,int d,int closeness,bool traffic)
{
	this->y = y;
	bool** map = new bool* [15];
	for (int i = 0; i < 15; ++i)
		map[i] = new bool[4];
	ifstream in;
	in.open("LDOLPHIN.txt");
	if (in.is_open())
	{
		string g;
		for (int i = 0; i < 4; ++i)
		{
			in.ignore();
			getline(in, g);
			int n = g.length();
			for (int j = 0; j < n; ++j)
				if (g[j] == ' ') map[i][j] = false;
				else map[i][j] = true;
		}
		in.close();
	}
	this->n = n; this->d = d; this->closeness = closeness;  this->traffic = traffic;
	first_spawn();
}

LDOLPHIN::~LDOLPHIN()
{
	for (int i = 0; i < 15; ++i)
		delete[] map[i];
	delete[]map;
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
		draw.erdolphin(arr[i], y);
	if (light == 1) draw.r_light(y, true);
	else if (light == 2) draw.r_light(y, false);
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
			if (arr[i] + 16 >= BORDER-2) //out of range
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
	for (int i = 0; i < n; ++i)
		draw.ldolphin(arr[i], y);
}

void LDOLPHIN::get_map(bool**& map, int& x, int& y)
{
	map = new bool* [15];
	for (int i = 0; i < 15; ++i)
		map[i] = new bool[4];
	x = this->x; y = this->y;
	for (int i = 0; i < 15; ++i)
		for (int j = 0; j < 4; ++j)
			map[i][j] = this->map[i][j];
}

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
	else if (light == 0) return false;
}

//class RDOLPHIN
RDOLPHIN::RDOLPHIN(int y, int n, int d, int closeness, bool traffic)
{
	this->y = y;
	bool** map = new bool* [15];
	for (int i = 0; i < 15; ++i)
		map[i] = new bool[4];
	ifstream in;
	in.open("RDOLPHIN.txt");
	if (in.is_open())
	{
		string g;
		for (int i = 0; i < 4; ++i)
		{
			in.ignore();
			getline(in, g);
			int n = g.length();
			for (int j = 0; j < n; ++j)
				if (g[j] == ' ') map[i][j] = false;
				else map[i][j] = true;
		}
		in.close();
	}
	this->n = n; this->d = d; this->closeness = closeness;  this->traffic = traffic;
	first_spawn();
}

RDOLPHIN::~RDOLPHIN()
{
	for (int i = 0; i < 15; ++i)
		delete[] map[i];
	delete[]map;
}

void RDOLPHIN::first_spawn()
{
	int s = 0;
	while (s < BORDER-15)
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
		draw.erdolphin(arr[i], y);
	if (light == 1) draw.l_light(y, true);
	else if (light == 2) draw.l_light(y, false);
	if (spawn() && BORDER - arr[n - 1] > closeness + 15) //random appearance
	{
		arr.push_back(BORDER - 15);
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
	for (int i = 0; i < n; ++i)
		draw.rdolphin(arr[i], y);
}

void RDOLPHIN::get_map(bool**& map, int& x, int& y)
{
	map = new bool* [15];
	for (int i = 0; i < 15; ++i)
		map[i] = new bool[4];
	x = this->x; y = this->y;
	for (int i = 0; i < 15; ++i)
		for (int j = 0; j < 4; ++j)
			map[i][j] = this->map[i][j];
}

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
	else if (light == 0) return false;
}

//class LEVEL
LEVEL::~LEVEL()
{
	int n = arr.size();
	for (int i = 0; i < n; ++i)
		if (arr[i] != nullptr) delete arr[i];
}

LEVEL::LEVEL(int choice)
{
	if (choice == 1)
	{
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
	stop = false; tmp_stop = false;
	now = clock(); ok = true;
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

bool LEVEL::oktowrite()
{
	if (ok) return true;
	return false;
}

bool LDOLPHIN::isImpact(int px, int py, bool** pMap) {
	for (int i = 0; i < arr.size(); i++) {
		x = arr[i];
		int BRx = x + sizeof(*map) / sizeof(bool);
		int BRy = y + sizeof(map) / sizeof(*map);

		int pBRx = px + sizeof(*pMap) / sizeof(bool);
		int pBRy = py + sizeof(pMap) / sizeof(*pMap);
		
		// gives top-left point 
		int x1 = max(x, px);
		int y1 = max(y, py);

		// gives bottom-right point  
		int x2 = min(BRx, pBRx);
		int y2 = min(BRy, pBRy);

		// no intersection 
		if (x1 > x2 || y1 > y2)
			continue;
		
		// check impact 
		for (int i = x1; i <= x2; i++)
			for (int j = y1; j <= y2; j++)
				if (map[abs(x - i)][abs(y - j)] == true &&
					pMap[abs(px - i)][abs(py - j)] == true)
					return true;
	}
	return false;
}

bool RDOLPHIN::isImpact(int px, int py, bool** pMap) {
	for (int i = 0; i < arr.size(); i++) {
		x = arr[i];
		int BRx = x + sizeof(*map) / sizeof(bool);
		int BRy = y + sizeof(map) / sizeof(*map);

		int pBRx = px + sizeof(*pMap) / sizeof(bool);
		int pBRy = py + sizeof(pMap) / sizeof(*pMap);

		// gives top-left point 
		int x1 = max(x, px);
		int y1 = max(y, py);

		// gives bottom-right point  
		int x2 = min(BRx, pBRx);
		int y2 = min(BRy, pBRy);

		// no intersection 
		if (x1 > x2 || y1 > y2)
			continue;

		// check impact 
		for (int i = x1; i <= x2; i++)
			for (int j = y1; j <= y2; j++)
				if (map[abs(x - i)][abs(y - j)] == true &&
					pMap[abs(px - i)][abs(py - j)] == true)
					return true;
	}
	return false;
}
