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

void LDOLPHIN::draw(int x, int y)
{
	go(x, y);
	cout << "        ,     ";
	go(x, y + 1);
	cout << "      __)\\_   ";
	go(x, y + 2);
	cout << "(\\_.-'    a`-.";
	go(x, y + 3);
	cout << "(/~~````(/~^^`";
}

void LDOLPHIN::erase(int x, int y)
{
	for (int i = 0; i < 4; ++i)
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

void RDOLPHIN::draw(int x, int y)
{
	go(x, y);
	cout << "     ,        ";
	go(x, y + 1);
	cout << "   _/(__      ";
	go(x, y + 2);
	cout << ".-`a    '-._/)";
	go(x, y + 3);
	cout << "`^^~(/````~~\\)";
}

void RDOLPHIN::erase(int x, int y)
{
	for (int i = 0; i < 4; ++i)
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
	split();
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
			Sleep(50);
		}
	}
}