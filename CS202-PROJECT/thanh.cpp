#include "thanh.h"

//class DRAW
void DRAW::human(int x,int y)
{
	go(x, y);
	cout << " @ ";
	go(x, y + 1);
	cout << "-|-";
	go(x, y + 2);
	cout << "/ \\";
}

void DRAW::erhuman(int x,int y)
{
	for (int i = 0; i < 3; ++i)
	{
		go(x, y + i);
		cout << "   ";
	}
}

void DRAW::dolphin(int x,int y)
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

void DRAW::erdolphin(int x,int y)
{
	for (int i = 0; i < 4; ++i)
	{
		go(x, y + i);
		cout << "              ";
	}
}

void DRAW::duck(int x,int y)
{
	go(x, y);
	cout << "  __     ";
	go(x, y + 1);
	cout << "<(o )___ ";
	go(x, y + 2);
	cout << " ( ._> / ";
	go(x, y + 3);
	cout << "  `---'  ";
}

void DRAW::erduck(int x,int y)
{
	for (int i = 0; i < 4; ++i)
	{
		go(x, y + i);
		cout << "         ";
	}
}

void DRAW::erline(int y)
{
	string t = "                                                                                                                                                               ";
	for (int i = 0; i < 4; ++i)
	{
		go(0, y + i);
		cout << t;
	}
}

void DRAW::split()
{
	FixConsoleWindow();
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

void DRAW::l_light(int y, bool s)
{
	if (s)
	{
		go(0, y+2);
		color(34); //green background
		cout << ' ';
		color(15);
		go(0, y + 1);
		cout << ' ';
	}
	else
	{
		go(0, y+1);
		color(68); //red blackground
		cout << ' ';
		color(15);
		go(0, y + 2);
		cout << ' ';
	}
}

void DRAW::r_light(int y, bool s)
{
	if (s)
	{
		go(159, y + 2);
		color(34); //green background
		cout << ' ';
		color(15);
		go(159, y + 1);
		cout << ' ';
	}
	else
	{
		go(159, y + 1);
		color(68); //red blackground
		cout << ' ';
		color(15);
		go(159, y + 2);
		cout << ' ';
	}
}

OBJECT::OBJECT()
{
	n = 0; d = 0; closeness = 0; x = 0; y = 0;
}

//class DOLPHIN
LDOLPHIN::LDOLPHIN(int y)
{
	this->y = y;
	bool** map = new bool* [15];
	for (int i = 0; i < 15; ++i)
		map[i] = new bool[4];
	ifstream in;
	in.open("DOLPHIN.txt");
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
}

LDOLPHIN::~LDOLPHIN()
{
	for (int i = 0; i < 15; ++i)
		delete[] map[i];
	delete[]map;
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

void LDOLPHIN::display()
{
	draw.erline(y);
	if (arr.size() == 0)
	{
		draw.dolphin(0, y);
		arr.push_back(0);
	}
	else
	{
		int n = arr.size();
		if (spawn() && arr[n - 1] > closeness) //random appearance
		{
			arr.push_back(0);
			++n;
		}
		for (int i = 0; i < n; ++i)
		{
			++arr[i];//move to the right
			if (arr[i] + 16 > 160) //out of range
			{
				arr.erase(arr.begin() + i);
				--n;
			}
			draw.dolphin(arr[i], y);
		}
	}
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

bool LDOLPHIN::turn()
{
	if (light == 1)
	{
		draw.r_light(y, true);
		return true;
	}
	else if (light == 2)
	{
		draw.r_light(y, false);
		return false;
	}
}

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
		OBJECT* a = new LDOLPHIN(4);
		a->spawn_rate(5, 10);
		a->close(30);
		arr.push_back(a);
		a = new LDOLPHIN(9);
		a->spawn_rate(2, 10);
		a->close(45);
		arr.push_back(a);
		a = new LDOLPHIN(14);
		a->spawn_rate(4, 10);
		a->close(35);
		arr.push_back(a);
		a = new LDOLPHIN(19);
		a->spawn_rate(8, 10);
		a->close(50);
		arr.push_back(a);
	}
	stop = false; tmp_stop = false;
	now = clock();
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
		now = clock() - now;
		if (tmp_stop)
		{
			//do nothing
		}
		else
		{
			for (int i = 0; i < n; ++i)
			{
				if (!arr[i]->done(now)) arr[i]->switch_light();
				if (arr[i]->turn()) arr[i]->display();
			}
			now = clock();
			Sleep(100);
		}
	}
}
