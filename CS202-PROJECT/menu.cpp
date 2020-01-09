#include"menu.h"

Menu::Menu() {
	y = 26;
	cursorColor = 176;
	colour = 11;
	command.push_back("  Start Challenges  ");
	command.push_back("  Load Saved Game   ");
	command.push_back("      Settings      ");
	command.push_back("      About Us      ");
	command.push_back("        Exit        ");
}

void Menu::stringCentralization(std::string str, int r, int colour)
{
	int len = str.length();
	const int width = 210 - len;
	int mid = width / 2;
	go(mid, r + 1);
	color(colour);
	std::cout << str;
	/*
		int c = mid-1;
		color(14);
		go(c, r++);

		cout << (char)201;
		for (int i = 1; i < len; ++i)
			cout << (char)205;
		cout << (char)187;

		go(c, r);
		cout << (char)186;
		go(c + len, r++);
		cout << (char)186;

		go(c, r);
		cout << (char)200;
		for (int i = 1; i < len; ++i)
			cout << (char)205;
		cout << (char)188;
	*/
}


void Menu::display() {
	system("cls");
	int t = y-3;
	for (int i = 0; i < 5; ++i)
	{
		stringCentralization(command[i], t += 3, colour);
	}
}
int Menu::choose() {
	int line = 0;
	stringCentralization(command[line], line * 3 + y, cursorColor);
	int k = _getch();
	//enter or space to confirm, ESC to exit
	while (k != 13 && k != 32 && k != 27) {
		stringCentralization(command[line], 3 * line + y, colour);
		moveCursor(k, line);
		stringCentralization(command[line], line * 3 + y, cursorColor);
		k = _getch();
	}
	color(15);
	if (k == 27) return 4;
	return line;
}

void Menu::moveCursor(int key, int& y)
{
	if (y > 0 && (key == 'w' || key == 'W'))
		y -= 1;
	else if (y < 4 && (key == 's' || key == 'S'))
		y += 1;
	else if (key == 224)
	{
		key = _getch();
		if (y > 0 && key == 72)
			y -= 1;
		else if (y < 4 && key == 80)
			y += 1;
	}
}