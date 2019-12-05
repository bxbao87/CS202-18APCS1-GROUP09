#include "Level.h"

//class LEVEL
LEVEL::LEVEL(int choice, int delay)
{
	stop = false; tmp_stop = false; now = clock(); ok = true; this->delay = delay;
	current = choice;
	set_level();
}

void LEVEL::set_level()
{
	arr.clear();
	system("cls");
	if (current == 1)
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
	else if (current == 10)
	{
		boss_split();
		OBJECT* a;
		a = new BOSS(1, 1, 1, 1, true);
		arr.push_back(a);
	}
}

LEVEL::~LEVEL()
{
	int n = arr.size();
	for (int i = 0; i < n; ++i)
		if (arr[i] != nullptr) delete arr[i];
}

int LEVEL::getLevel()
{
	return current;
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

void LEVEL::passCoor(pair<int,int> coor)
{
	if (arr.size() == 1) //applied for boss only
		arr[0]->human(coor.first, coor.second);
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

