#include "Level.h"

//class LEVEL
LEVEL::LEVEL(int choice, int delay)
{
	stop = false; tmp_stop = false; now = clock(); ok = true; this->delay = delay;
	current = choice;
	ifstream in;
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
		a = new LDOLPHIN(4, 5, 10, 20, true);
		arr.push_back(a);
		a = new RDOLPHIN(9, 2, 10, 40, true);
		arr.push_back(a);
		a = new LDOLPHIN(14, 4, 10, 20, true);
		arr.push_back(a);
		a = new RDOLPHIN(19, 8, 10, 40, true);
		arr.push_back(a);
		
		a = new LWHALE(24, 5, 10, 35, true);
		arr.push_back(a);
		a = new RWHALE(29, 2, 10, 50, true);
		arr.push_back(a);
		a = new LWHALE(34, 4, 10, 40, true);
		arr.push_back(a);
		a = new RWHALE(39, 8, 10, 50, true);
		arr.push_back(a);
	}
	else if (current == 2)
	{
		split();
		OBJECT* a;
		a = new LPIG(4, 5, 10, 30, true);
		arr.push_back(a);
		a = new RPIG(9, 2, 10, 45, true);
		arr.push_back(a);
		a = new LPIG(14, 4, 10, 35, true);
		arr.push_back(a);
		a = new RPIG(19, 8, 10, 50, true);
		arr.push_back(a);
		a = new LPIG(24, 5, 10, 30, false);
		arr.push_back(a);
		a = new RPIG(29, 2, 10, 45, false);
		arr.push_back(a);
		a = new LPIG(34, 4, 10, 35, false);
		arr.push_back(a);
		a = new RPIG(39, 8, 10, 50, false);
		arr.push_back(a);
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

void LEVEL::verticalLine(int col) {
	for (int i = 0; i < 48; ++i) {
		go(col, i);
		cout << char(179); // |
	}
}

void LEVEL::split() 
{
	verticalLine(LBORDER);
	for (int i = 0; i < 9; ++i)
	{
		go(LBORDER + 1, 3 + i * 5);
		cout << split_lane;
	}
	verticalLine(BORDER);
}

void LEVEL::boss_split()
{
	verticalLine(LBORDER);
	go(LBORDER + 1, 3); // upper bound
	cout << split_lane;
	go(LBORDER + 1, 43);
	cout << split_lane;
	verticalLine(BORDER);
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

void LEVEL::passCoor(pair <int,int> coor)
{
	int n = arr.size();
	for (int i = 0; i < n; ++i)
		arr[i]->human(coor.first, coor.second);
	//update human coordinate
	human.setCoor(coor.first, coor.second);
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
			//check impact before this
			human.Draw();
			ok = true;
			now = clock();
			Sleep(delay);
		}
	}
}