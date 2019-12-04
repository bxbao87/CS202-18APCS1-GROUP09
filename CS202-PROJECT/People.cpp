#include "People.h"

People::People() {
	live = 3;
	pY = 45;
	pX = 80;
	state = true;
	ifstream fin("human.txt");
	if (fin.is_open()) {
		map.clear();
		while(!fin.eof()){
			string line;
			getline(fin, line, '\n');
			map.push_back(line);
		}
	}
	fin.close();
	spawn();
}

People::~People() {
}

void People::delDraw() {
	int n = map.size();
	if (n > 0) {
		int len = map[0].length();
		string str = "";
		for (int i = 0; i < len; ++i)
			str += " ";
		for (int i = 0; i < n; ++i) {
			go(pX, pY + i);
			cout << str;
		}
	}
}

void People::Draw() {
	int n = map.size();
	for (int i = 0; i < n; ++i) {
		go(pX, pY+i);
		cout << map[i];
	}
}

void People::move(int key) {
	if (key == 'a' || key == 'A')
		LEFT();
	else if (key == 'd' || key == 'D')
		RIGHT();
	else if (key == 'w' || key == 'W')
		UP();
	else if (key == 's' || key == 'S')
		DOWN();
	else if (key == 224) {
		key = _getch();
		if (key == 75)
			LEFT();
		else if (key == 77)
			RIGHT();
		else if (key == 72)
			UP();
		else if (key == 80)
			DOWN();
	}
}

void People::UP() {
	if (pY - 5 >= Top_bound) {
		delDraw();
		pY -= Y_MOVE;
		Draw();
	}
}

void People::DOWN() {
	if (pY + 5 <= Bot_bound) {
		delDraw();
		pY += Y_MOVE;
		Draw();
	}
}

void People::LEFT() {
	if (pX - 1 >= Left_bound) {
		delDraw();
		pX -= X_MOVE;
		Draw();
	}
}

void People::RIGHT() {
	if (pX < Right_bound) {
		delDraw();
		pX += X_MOVE;
		Draw();
	}
}

bool People::isImpact(int objY, vector<int> objCoordX, vector<string> objMap) {
	for (int i = 0; i < objCoordX.size(); i++) {
		int objX = objCoordX[i];
		int BRx = pX + map[0].size();		// length of rectangle
		int BRy = pY + map.size();			// width of rectangle

		int pBRx = objX + objMap[0].size();
		int pBRy = objY + objMap.size();

		// gives top-left point 
		int x1 = max(pX, objX);
		int y1 = max(pY, objY);

		// gives bottom-right point  
		int x2 = min(BRx, pBRx);
		int y2 = min(BRy, pBRy);

		// no intersection 
		if (x1 > x2 || y1 > y2)
			continue;

		// check impact 
		for (int i = x1; i <= x2; i++)
			for (int j = y1; j <= y2; j++)
				if (map[abs(pX - i)][abs(pY - j)] != 32 &&
					objMap[abs(objX - i)][abs(objY - j)] != 32)
					return true;

		return false;
	}
}

bool People::isFinish() {
	if (pY == 0) {
		if(live<3)
			live++;
		return true;
	}
	return false;
}

void People::decreaseLife() {
	live--;
	if (live == 0)
		state = false;
}

int People::getLife() {
	return live;
}

bool People::isDead() {
	if (!state)
		return true;
	return false;
}

void People::spawn() {
	pY = 45;
	pX = 80;
	Draw();
}
