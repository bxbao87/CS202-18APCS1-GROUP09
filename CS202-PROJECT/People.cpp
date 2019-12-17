#include "People.h"

People::People() {
	live = 3;
	pY = 45;
	pX = 80;
	state = true;
	ifstream fin(path + "human.txt");
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

void People::delDraw(int x,int y) {
	int n = map.size();
	if (n > 0) {
		int len = map[0].length();
		string str = "";
		for (int i = 0; i < len; ++i)
			str += " ";
		for (int i = 0; i < n; ++i) {
			go(x,y + i);
			cout << str;
		}
	}
}

void People::Draw() const{
	int n = map.size();
	for (int i = 0; i < n; ++i) {
		go(pX, pY+i);
		cout << map[i];
	}
}

void People::displayLives()
{
	go(BORDER + 23, 20);
	cout << live;
}

bool People::move(int key) {
	bool ret = false;
	int mov[] = { 'a','A','d','D','w','W','s','S' };
	for(auto i:mov)
		if (i == key) {
			ret = true;
			break;
		}
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
		int mov2[] = { 75,72,77,80 };
		for (auto i : mov2)
			if (i == key) {
				ret = true;
				break;
			}
	}
	return ret;
}

void People::UP() {
	if (pY - 5 >= Top_bound) {
		pY -= Y_MOVE;
	}
}

void People::DOWN() {
	if (pY + 5 <= Bot_bound) {
		pY += Y_MOVE;
	}
}

void People::LEFT() {
	if (pX - 1 > Left_bound) {
		pX -= X_MOVE;
	}
}

void People::RIGHT() {
	if (pX < Right_bound) {
		pX += X_MOVE;
	}
}

bool People::isImpact(int objY, vector<int> objCoordX, vector<string> objMap) {
	for (int i = 0; i < int(objCoordX.size()); i++) {
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
		for (int i = x1; i < x2; i++)
			for (int j = y1; j < y2; j++)
				if (map[abs(pY - j)][abs(pX - i)] != ' ' &&
					objMap[abs(objY - j)][abs(objX - i)] != ' ')
					return true;
	}
		return false;
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

void People::setLife(int life) {
	this->live = life;
	if (life > 0) state = true;
}

int People::getLife() {
	return live;
}

bool People::isDead() {
	return state ? false : true;
}

void People::spawn() {
	pY = 45;
	pX = 80;
	Draw();
}

pair<int, int> People::getCoor() {
	pair<int, int> tmp;
	tmp.first = pX, tmp.second = pY;
	return tmp;
}

void People::setCoor(int x, int y) {
	pX = x; pY = y;
}
