#include "thanh.h"
#include "People.h"

void exitLEVEL(thread *t,LEVEL& a)
{
	a.kill();
	t->join();
}

int main()
{
	FixConsoleWindow();
	setcursor(0, 0);
	DRAW draw;
	draw.split();
	LEVEL test(1);
	People p;
	int k = 0;
	thread t1(&LEVEL::run, &test);
	while (k != 27)
	{
		k = _getch();
		if (k == 27)
		{
			exitLEVEL(&t1, test);
		}
		else if (k == 'p' || k == 'P')
		{
			test.pause();
		}
		else if (k == 'r' || k == 'R')
		{
			test.resume();
		}
		else
		{
			test.pause();
			while (test.oktowrite() == false);
			p.move(k);
			test.resume();
		}
	}
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