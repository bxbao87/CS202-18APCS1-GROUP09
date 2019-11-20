#include "thanh.h"

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
	return 0;
}