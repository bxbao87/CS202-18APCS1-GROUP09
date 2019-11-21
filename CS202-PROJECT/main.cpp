#include "thanh.h"
#include "People.h"

void exitThread(thread* t,LEVEL& a)
{
	a.kill();
	t->join();
}

int main()
{
	DRAW screen;
	
	screen.split();
	
	LEVEL test(1);
	People p;
	int k = 0;
	thread t(&LEVEL::run, &test);
	while (k != 27)
	{
		k = _getch();
		if (k == 27)
		{
			exitThread(&t, test);
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
			p.move(k);
		}
	}
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