#include "Objects.h"
#include "People.h"
#include "Game.h"
#include "Level.h"

void exitLEVEL(thread *t,LEVEL*& a)
{
	a->kill();
	t->join();
}

thread switchLEVEL(thread* t, LEVEL*& a, int level, int delay, People p)
{
	exitLEVEL(t, a);
	delete a;
	a = new LEVEL(level, delay);
	p.spawn();
	thread t1(&LEVEL::run, a);
	return t1;
}

int main() {
	FixConsoleWindow();
	setcursor(0, 0);
	Game g;
	g.instructor();
	People p;
	LEVEL* test = new LEVEL(1, 100);
	//People p;
	int k = 0, x = 0, y = 0;
	thread t1(&LEVEL::run, test);
	while (k != 27)
	{
		k = _getch();
		if (k == 27) {
			exitLEVEL(&t1, test);
		}
		else if (k == 'p' || k == 'P')
		{
			test->pause();
		}
		else if (k == 'r' || k == 'R')
		{
			test->resume();
		}
		else if (k == 'n')
		{
			t1 = switchLEVEL(&t1, test, 10, 100, p);
		}
		else
		{
			test->pause();
			while (test->oktowrite() == false);
			p.move(k);
			test->resume();
		}
	}
	if (test != nullptr) delete test;
	setcursor(1, 10);

	return 0;
}
/* flip object
int main()
{
	ifstream in;
	in.open("LDOLPHIN.txt");
	vector <string> arr;
	string t;
	while (!in.eof())
	{
		in.ignore();
		getline(in, t);
		arr.push_back(t);
	}
	in.close();
	ofstream out;
	out.open("RDOLPHIN.txt");
	for (int i = 0; i < arr.size(); ++i)
	{
		for (int j = arr[i].length() - 1; j >= 0; --j)
			out << arr[i][j];
		out << '\n';
	}
	out.close();
}*/