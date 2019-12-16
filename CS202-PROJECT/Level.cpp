#include "Level.h"

//class LEVEL
LEVEL::LEVEL(int choice, int delay)
{
	stop = false; tmp_stop = false; now = clock(); ok = true; this->delay = delay; freeze = false;
	old_coor.first = 80; old_coor.second = 45;
	current = choice;
	ifstream in;
	setLevel();
}

void LEVEL::setLevel()
{
	arr.clear();
	system("cls");
	if (current == 1)
	{
		split();
		OBJECT* a;
		a = new LDOLPHIN(4, 5, 11, 35, true);
		arr.push_back(a);
		a = new LDOLPHIN(9, 5, 11, 40, false);
		arr.push_back(a);
		a = new RDOLPHIN(14, 5, 11, 35, true);
		arr.push_back(a);
		a = new RDOLPHIN(19, 5, 11, 40, false);
		arr.push_back(a);
		a = new LWHALE(24, 5, 11, 45, false);
		arr.push_back(a);
		a = new LWHALE(29, 5, 11, 50, true);
		arr.push_back(a);
		a = new RWHALE(34, 5, 11, 45, false);
		arr.push_back(a);
		a = new RWHALE(39, 5, 11, 50, true);
		arr.push_back(a);
	}
	else if (current == 2)
	{
		split();
		OBJECT* a;
		a = new LPIG(4, 5, 11, 25, true);
		arr.push_back(a);
		a = new RPIG(9, 6, 11, 25, true);
		arr.push_back(a);
		a = new LPIG(14, 5, 11, 30, true);
		arr.push_back(a);
		a = new RPIG(19, 6, 11, 30, true);
		arr.push_back(a);
		a = new LDOLPHIN(24, 5, 11, 35, false);
		arr.push_back(a);
		a = new LDOLPHIN(29, 6, 11, 35, false);
		arr.push_back(a);
		a = new RDOLPHIN(34, 5, 11, 35, false);
		arr.push_back(a);
		a = new RDOLPHIN(39, 6, 11, 35, false);
		arr.push_back(a);
	}
	else if (current == 3)
	{
		split();
		OBJECT* a;
		a = new LPIG(4, 5, 11, 30, true);
		arr.push_back(a);
		a = new LDOLPHIN(9, 5, 11, 35, true);
		arr.push_back(a);
		a = new LBEE(14, 5, 10, 25, true);
		arr.push_back(a);
		a = new LWHALE(19, 5, 11, 45, true);
		arr.push_back(a);
		a = new RWHALE(24, 5, 11, 40, true);
		arr.push_back(a);
		a = new RBEE(29, 5, 11, 25, true);
		arr.push_back(a);
		a = new RDOLPHIN(34, 5, 11, 35, true);
		arr.push_back(a);
		a = new RPIG(39, 5, 11, 30, true);
		arr.push_back(a);
	}
	else if (current == 4)
	{
		split();
		OBJECT* a;
		a = new RPIG(4, 2, 11, 20, true);
		arr.push_back(a);
		a = new LPIG(9, 2, 11, 25, true);
		arr.push_back(a);
		a = new LPIG(14, 2, 11, 25, true);
		arr.push_back(a);
		a = new LPIG(19, 2, 11, 25, true);
		arr.push_back(a);
		a = new LPIG(24, 2, 11, 30, true);
		arr.push_back(a);
		a = new LPIG(29, 2, 11, 30, true);
		arr.push_back(a);
		a = new LPIG(34, 2, 11, 35, true);
		arr.push_back(a);
		a = new RPIG(39, 2, 11, 35, true);
		arr.push_back(a);
	}
	else if (current == 5)
	{
		split();
		OBJECT* a;
		a = new LDUCK(4, 6, 11, 22, true);
		arr.push_back(a);
		a = new LDUCK(9, 6, 11, 22, true);
		arr.push_back(a);
		a = new LDUCK(14, 6, 11, 20, true);
		arr.push_back(a);
		a = new LDUCK(19, 6, 11, 20, true);
		arr.push_back(a);
		a = new RDUCK(24, 6, 11, 20, false);
		arr.push_back(a);
		a = new RDUCK(29, 6, 11, 20, false);
		arr.push_back(a);
		a = new RDUCK(34, 6, 11, 25, false);
		arr.push_back(a);
		a = new RDUCK(39, 6, 11, 25, false);
		arr.push_back(a);
	}
	else if (current == 6)
	{
		split();
		OBJECT* a;
		a = new LWHALE(4, 0, 11, 26, false);
		arr.push_back(a);
		a = new LWHALE(9, 0, 11, 26, false);
		arr.push_back(a);
		a = new LWHALE(14, 0, 11, 26, false);
		arr.push_back(a);
		a = new LWHALE(19, 0, 11, 26, false);
		arr.push_back(a);
		a = new LWHALE(24, 0, 11, 26, false);
		arr.push_back(a);
		a = new LWHALE(29, 0, 11, 26, false);
		arr.push_back(a);
		a = new LWHALE(34, 0, 11, 26, false);
		arr.push_back(a);
		a = new LWHALE(39, 0, 11, 26, false);
		arr.push_back(a);
	}
	else if (current == 7)
	{
		split();
		OBJECT* a;
		a = new RDOLPHIN(4, 0, 11, 18, true);
		arr.push_back(a);
		a = new RDOLPHIN(9, 0, 11, 18, true);
		arr.push_back(a);
		a = new RDOLPHIN(14, 0, 11, 18, false);
		arr.push_back(a);
		a = new RDOLPHIN(19, 0, 11, 18, false);
		arr.push_back(a);
		a = new RDOLPHIN(24, 0, 11, 18, true);
		arr.push_back(a);
		a = new RDOLPHIN(29, 0, 11, 18, false);
		arr.push_back(a);
		a = new RDOLPHIN(34, 0, 11, 18, false);
		arr.push_back(a);
		a = new RDOLPHIN(39, 0, 11, 18, true);
		arr.push_back(a);
	}
	else if (current == 8)
	{
		split();
		OBJECT* a;
		a = new LBEE(4, 6, 11, 17, true);
		arr.push_back(a);
		a = new LBEE(9, 6, 11, 17, true);
		arr.push_back(a);
		a = new LPIG(14, 6, 11, 24, true);
		arr.push_back(a);
		a = new LBEE(19, 6, 11, 24, true);
		arr.push_back(a);
		a = new RBEE(24, 6, 11, 17, true);
		arr.push_back(a);
		a = new RPIG(29, 6, 11, 24, true);
		arr.push_back(a);
		a = new RBEE(34, 6, 11, 17, true);
		arr.push_back(a);
		a = new RPIG(39, 6, 11, 24, true);
		arr.push_back(a);
	}
	else if (current == 9)
	{
		split();
		OBJECT* a;
		a = new LWHALE(4, 0, 11, 32, true);
		arr.push_back(a);
		a = new LDUCK(9, 0, 11, 22, true);
		arr.push_back(a);
		a = new RWHALE(14, 0, 11, 32, true);
		arr.push_back(a);
		a = new RDOLPHIN(19, 0, 11, 24, true);
		arr.push_back(a);
		a = new LDOLPHIN(24, 0, 11, 24, true);
		arr.push_back(a);
		a = new RPIG(29, 0, 11, 20, true);
		arr.push_back(a);
		a = new RDUCK(34, 0, 11, 23, true);
		arr.push_back(a);
		a = new RPIG(39, 0, 11, 20, true);
		arr.push_back(a);
	}
	else if (current == 10 || current == 11 || current == 12)
	{
		split();
		OBJECT* a;
		int count = 4;
		int r, t, n, d;
		for (int i = 0; i < 8; ++i)
		{
			srand(clock() + rand() % 101); r = rand() % 103;
			srand(clock() + rand() % 101); t = rand() % 2;
			srand(clock() + rand() % 101); n = rand() % 11;
			srand(clock() + rand() % 101); d = rand() % 11 + 1;
			if (r <= 21)
			{
				if (t == 0) a = new LDOLPHIN(count, n, d, 24, rand() % 2);
				else if (t == 1) a = new RDOLPHIN(count, n, d, 24, rand() % 2);
			}
			else if (r <= 42)
			{
				if (t == 0) a = new LWHALE(count, n, d, 32, rand() % 2);
				else if (t == 1) a = new RWHALE(count, n, d, 32, rand() % 2);
			}
			else if (r <= 63)
			{
				if (t == 0) a = new LBEE(count, n, d, 22, rand() % 2);
				else if (t == 1) a = new RBEE(count, n, d, 22, rand() % 2);
			}
			else if (r <= 84)
			{
				if (t == 0) a = new LDUCK(count, n, d, 23, rand() % 2);
				else if (t == 1) a = new RDUCK(count, n, d, 23, rand() % 2);
			}
			else
			{
				if (t == 0) a = new LPIG(count, n, d, 23, rand() % 2);
				else if (t == 1) a = new RPIG(count, n, d, 23, rand() % 2);
			}
			count += 5;
			arr.push_back(a);
		}
	}
	else if (current == 13)
	{
		split();
	}
	else if (current == 14)
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
	while (!(ok && tmp_stop) && i++ < 500000);
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
	//insert sound of an impact " triangle ! "
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
					//or insert sound here
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