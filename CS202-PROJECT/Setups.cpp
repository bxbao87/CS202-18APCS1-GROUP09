#include "Setups.h"
#include "Objects.h"

//class OBJECT
OBJECT::OBJECT()
{
	n = 0; d = 0; closeness = 0; x = 0; y = 0; green = 0; red = 0; traffic = false; hx = 80; hy = 45;
}

void OBJECT::switch_light()
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

void OBJECT::human(int x, int y)
{
	this->hx = x;
	this->hy = y;
}

vector <string> OBJECT::getMAP()
{
	return map;
}

vector <int> OBJECT::getARR()
{
	return arr;
}

//class LEVEL
LEVEL::~LEVEL()
{
	int n = arr.size();
	for (int i = 0; i < n; ++i)
		if (arr[i] != nullptr) delete arr[i];
}

LEVEL::LEVEL(int choice, int delay)
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