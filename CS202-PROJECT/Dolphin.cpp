#include "Dolphin.h"

//class LDOLPHIN
LDOLPHIN::LDOLPHIN(int y, int n, int d, int closeness) {
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
	this->n = n; this->d = d; this->closeness = closeness;
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

void LDOLPHIN::displayLight()
{
	if (light == 1)
	{
		go(BORDER - 1, y + 2);
		color(34); //green background
		cout << ' ';
		color(15);
		go(BORDER - 1, y + 1);
		cout << ' ';
	}
	else if (light == 2)
	{
		go(BORDER - 1, y + 1);
		color(68); //red blackground
		cout << ' ';
		color(15);
		go(BORDER - 1, y + 2);
		cout << ' ';
	}
}

void LDOLPHIN::first_spawn()
{
	int s = BORDER - 1 - 15;
	while (s > 0)
	{
		arr.push_back(s);
		s -= closeness;
	}
	light = 1; green_time = 1000;
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

//void LDOLPHIN::set_traffic(bool s)
//{
//	if (s) traffic = true;
//	else traffic = false;
//}

void LDOLPHIN::display()
{
	int n = arr.size();
	for (int i = 0; i < n; ++i)
		erase(arr[i], y);
	displayLight();
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
			if (arr[i] + 16 >= BORDER - 2) //out of range
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

void LDOLPHIN::switch_light()
{
	if (light == 0)
	{
		if (rand() % 13 < 6)
		{
			light = 2;
			red_time += (rand() % 5) * 1000;
		}
		else
		{
			light = 1;
			green_time += (rand() % 5) * 1000;
		}
	}
}

bool LDOLPHIN::check(int second) //check if is there any light on
{
	//if (!traffic) return true;
	if (light == 1)
	{
		green_time -= second;
		if (green_time < 0)
		{
			green_time = 0;
			light = 0;
			return false;
		}
		return true;
	}
	else if (light == 2)
	{
		red_time -= second;
		if (red_time < 0)
		{
			red_time = 0;
			light = 0;
			return false;
		}
		return true;
	}
	return false;
}

//class RDOLPHIN
RDOLPHIN::RDOLPHIN(int y, int n, int d, int closeness)
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
	this->n = n; this->d = d; this->closeness = closeness;
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

void RDOLPHIN::displayLight() {
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
	while (s < BORDER - 15)
	{
		arr.push_back(s);
		s += closeness;
	}
	light = 1; green_time = 1000;
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

//void RDOLPHIN::set_traffic(bool s)
//{
//	if (s) traffic = true;
//	else traffic = false;
//}

void RDOLPHIN::display()
{
	int n = arr.size();
	for (int i = 0; i < n; ++i)
		erase(arr[i], y);
	displayLight();
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
			red_time += (rand() % 5) * 1000;
		}
		else
		{
			light = 1;
			green_time += (rand() % 5) * 1000;
		}
	}
}

bool RDOLPHIN::done(int second) //check if is there any light on
{
	//if (!traffic) return true;
	if (light == 1)
	{
		green_time -= second;
		if (green_time < 0)
		{
			green_time = 0;
			light = 0;
			return false;
		}
		return true;
	}
	else if (light == 2)
	{
		red_time -= second;
		if (red_time < 0)
		{
			red_time = 0;
			light = 0;
			return false;
		}
		return true;
	}
	return false;
}