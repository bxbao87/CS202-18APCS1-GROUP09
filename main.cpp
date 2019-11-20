#include "thanh.h"
#include"People.h"

void exitThread(thread* t,LEVEL& a)
{
	a.kill();
	t->join();
}

int main()
{
	system("chcp 437");
	system("cls");
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
		else if (k == 'p')
		{
			test.pause();
		}
		else if (k == 'r')
		{
			test.resume();
		}
	}
	system("pause");
	return 0;
}