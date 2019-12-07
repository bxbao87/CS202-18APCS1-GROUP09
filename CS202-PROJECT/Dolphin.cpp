#include "Dolphin.h"

//class LDOLPHIN
LDOLPHIN::LDOLPHIN(int y, int n, int d, int closeness, bool traffic)
{
	this->y = y;
	ifstream in;
	in.open(path + "LDOLPHIN.txt");
	if (in.is_open())
	{
		string g;
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
	this->n = n; this->d = d; this->closeness = closeness;  this->traffic = traffic; co = 3;
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
	int s = 159 - map[0].size();
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
	color(co);
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
	this->n = n; this->d = d; this->closeness = closeness;  this->traffic = traffic; co = 3;
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
	color(co);
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