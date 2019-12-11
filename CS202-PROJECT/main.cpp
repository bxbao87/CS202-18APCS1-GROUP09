#include "Game.h"


int main() {
	//system("chcp 437");
	FixConsoleWindow(); //fixed screen
	Game g;
	g.main_run();
	setcursor(1, 10);
	return 0;
}

//flip object
// int main()
//{
//	ifstream in;
//	in.open(path + "RWHALE.txt");
//	vector <string> arr;
//	string t;
//	while (!in.eof())
//	{
//		getline(in, t);
//		arr.push_back(t);
//	}
//	in.close();
//	ofstream out;
//	out.open(path + "LWHALE.txt");
//	for (int i = 0; i < arr.size(); ++i)
//	{
//		for (int j = arr[i].length() - 1; j >= 0; --j)
//			out << arr[i][j];
//		out << '\n';
//	}
//	out.close();
//	return 0;
//}