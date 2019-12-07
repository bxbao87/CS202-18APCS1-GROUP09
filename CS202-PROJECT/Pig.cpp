#include "Pig.h"

//class LPIG
LPIG::LPIG(int y, int n, int d, int closeness, bool traffic)
{
	this->y = y;
	ifstream in;
	in.open(path + "LPIG.txt");
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
	this->n = n; this->d = d; this->closeness = closeness;  this->traffic = traffic; co = 6;
	lenAni = map[0].size();
	first_spawn();
}

void LPIG::draw(int x, int y)
{
	int n = map.size();
	for (int i = 0; i < n; ++i)
	{
		go(x, y + i);
		cout << map[i];
	}
}

void LPIG::erase(int x, int y)
{
	int n = map.size();
	for (int i = 0; i < n; ++i)
	{
		go(x, y + i);
		cout << "           ";
	}
}

void LPIG::light_display()
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

void LPIG::first_spawn()
{
	int s = BORDER - 1 - lenAni;
	while (s > LBORDER)
	{
		arr.push_back(s);
		s -= closeness;
	}
	light = 1; green = 1000;
}

void LPIG::makeSound()
{
	//do something
}

void LPIG::spawn_rate(int n, int d)
{
	this->n = n; this->d = d;
}

bool LPIG::spawn()
{
	if (rand() % d <= n) return true;
	return false;
}

void LPIG::close(int closeness)
{
	this->closeness = closeness;
}

void LPIG::set_traffic(bool s)
{
	if (s) traffic = true;
	else traffic = false;
}

bool LPIG::done(int second) //check if is there any light on
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

void LPIG::display()
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
	bool go; //stop at red light up to them
	if (light == 2 && rand() % 11 < 3) go = true;
	else go = false;
	for (int i = 0; i < n; ++i)
	{
		++arr[i];//move to the right
		if (i == 0)
		{
			if (arr[i] + lenAni + 1 > BORDER) //out of range
			{
				if (light == 1 || go)
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

//class RPIG
RPIG::RPIG(int y, int n, int d, int closeness, bool traffic)
{
	this->y = y;
	ifstream in;
	in.open(path + "RPIG.txt");
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
	this->n = n; this->d = d; this->closeness = closeness;  this->traffic = traffic; co = 6;
	lenAni = map[0].size();
	first_spawn();
}

void RPIG::draw(int x, int y)
{
	int n = map.size();
	for (int i = 0; i < n; ++i)
	{
		go(x, y + i);
		cout << map[i];
	}
}

void RPIG::erase(int x, int y)
{
	int n = map.size();
	for (int i = 0; i < n; ++i)
	{
		go(x, y + i);
		cout << "           ";
	}
}

void RPIG::light_display()
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

void RPIG::first_spawn()
{
	int s = LBORDER + 1;
	while (s < BORDER - lenAni)
	{
		arr.push_back(s);
		s += closeness;
	}
	light = 1; green = 1000;
}

void RPIG::makeSound()
{
	//do something
}

void RPIG::spawn_rate(int n, int d)
{
	this->n = n; this->d = d;
}

bool RPIG::spawn()
{
	if (rand() % d <= n) return true;
	return false;
}

void RPIG::close(int closeness)
{
	this->closeness = closeness;
}

void RPIG::set_traffic(bool s)
{
	if (s) traffic = true;
	else traffic = false;
}

bool RPIG::done(int second) //check if is there any light on
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

void RPIG::display()
{
	int n = arr.size();
	for (int i = 0; i < n; ++i)
		erase(arr[i], y);
	light_display();
	if (spawn() && BORDER - arr[n - 1] > closeness + lenAni) //random appearance
	{
		arr.push_back(BORDER - lenAni);
		++n;
	}
	bool go; //stop at red light up to them
	if (light == 2 && rand() % 11 < 3) go = true;
	else go = false;
	for (int i = 0; i < n; ++i)
	{
		--arr[i];//move to the left
		if (i == 0)
		{
			if (arr[i] <= 1) //out of range
			{
				if (light == 1 || go)
				{
					arr.erase(arr.begin() + i);
					--n;
				}
				else if (light == 2) --arr[i]; //stop at red light
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