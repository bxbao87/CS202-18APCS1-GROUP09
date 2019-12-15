#include "Level.h"

//class LEVEL
LEVEL::LEVEL(int choice, int delay)
{
	stop = false; tmp_stop = false; now = clock(); ok = true; this->delay = delay; freeze = false;
	old_coor.first = 80; old_coor.second = 45;
	current = choice;
	ifstream in;
	set_level();
}

void LEVEL::set_level()
{
	arr.clear();
	system("cls");
	if (current == 10)
	{
		split();
		OBJECT* a;
		a = new LDUCK(4, 5, 10, 20, true);
		arr.push_back(a);
		a = new RDUCK(9, 5, 10, 20, true);
		arr.push_back(a);
		a = new LDUCK(14, 4, 10, 20, true);
		arr.push_back(a);
		a = new RDUCK(19, 8, 10, 25, true);
		arr.push_back(a);
		a = new LDUCK(24, 5, 10, 35, true);
		arr.push_back(a);
		a = new RDUCK(29, 2, 10, 25, true);
		arr.push_back(a);
		a = new LDUCK(34, 4, 10, 35, true);
		arr.push_back(a);
		a = new RDUCK(39, 8, 10, 20, true);
		arr.push_back(a);
	}
	else if (current == 2)
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
	else if (current == 3)
	{
		split();
		OBJECT* a;
		a = new LBEE(4, 5, 10, 20, true);
		arr.push_back(a);
		a = new RBEE(9, 2, 10, 25, true);
		arr.push_back(a);
		a = new LBEE(14, 4, 10, 30, true);
		arr.push_back(a);
		a = new RBEE(19, 8, 10, 15, true);
		arr.push_back(a);
		a = new LBEE(24, 5, 10, 35, true);
		arr.push_back(a);
		a = new RBEE(29, 2, 10, 20, true);
		arr.push_back(a);
		a = new LBEE(34, 4, 10, 25, true);
		arr.push_back(a);
		a = new RBEE(39, 8, 10, 25, true);
		arr.push_back(a);
	}
	else if (current == 4)
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
	else if (current == 1)
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
	pause();
	int i = 0;
	while (!(ok && tmp_stop) && i < 500000) ++i;
	return true;
}

bool LEVEL::status()
{
	return tmp_stop;
}

bool LEVEL::freeze_main()
{
	return freeze;
}

void LEVEL::cooldown()
{
	freeze = true;
	for (int i = 0; i < 3; ++i)
	{
		go(1, 45);
		if (i == 0) color(12);
		else if (i == 1) color(14);
		else if (i == 2) color(10);
		cout << "Cooldown time: " << 3 - i;
		Sleep(500);
		color(15);
	}
	go(1, 45);
	cout << "                 ";
	freeze = false;
}

void LEVEL::run(People& human)
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
			human.delDraw(old_coor.first, old_coor.second);
			old_coor = human.getCoor();
			if (arr.size() == 1) arr[0]->human(old_coor);
			for (int i = 0; i < n; ++i)
			{
				if (!arr[i]->done(now)) arr[i]->switch_light();
				arr[i]->display();
			}
			//draw before checking impact
			human.Draw();
			for (int i = 0; i < n; i++)
				if (human.isImpact(arr[i]->getY(), arr[i]->getARR(), arr[i]->getMAP()))
				{
					arr[i]->impact();
					human.decreaseLife();
					go(BORDER + 23, 20);
					cout << human.getLife();
					cooldown();
					human.delDraw(old_coor.first,old_coor.second);
					human.spawn();
				}
			ok = true;
			now = clock();
			Sleep(delay);
		}
	}
}