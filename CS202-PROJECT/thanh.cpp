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

OBJECT::OBJECT()
{
	n = 0; d = 0; closeness = 0; x = 0; y = 0;
}

//class DOLPHIN
DOLPHIN::DOLPHIN(int y)
{
	this->y = y;
	bool** map = new bool* [15];
	for (int i = 0; i < 15; ++i)
		map[i] = new bool[4];

}

DOLPHIN::~DOLPHIN()
{
	for (int i = 0; i < 15; ++i)
		delete[] map[i];
	delete[]map;
}

void DOLPHIN::makeSound()
{
	//do something
}

void DOLPHIN::spawn_rate(int n, int d)
{
	this->n = n; this->d = d;
}

bool DOLPHIN::spawn()
{
	if (rand() % d <= n) return true;
	return false;
}

void DOLPHIN::close(int closeness)
{
	this->closeness = closeness;
}

void DOLPHIN::display()
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
		OBJECT* a = new DOLPHIN(4);
		a->spawn_rate(5, 10);
		a->close(50);
		arr.push_back(a);
		a = new DOLPHIN(9);
		a->spawn_rate(2, 10);
		a->close(25);
		arr.push_back(a);
	}
	stop = false; tmp_stop = false;
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
		if (tmp_stop)
		{
			//do nothing
		}
		else
		{
			for (int i = 0; i < n; ++i)
				arr[i]->display();
			Sleep(100);
		}
	}
}
