#include "BEE.h"

//class LBEE
LBEE::LBEE(int y, int n, int d, int closeness, bool traffic) {
	this->y = y;
	ifstream in;
	in.open(path + "LBEE.txt");
	if (in.is_open()) {
		string g;
		while (!in.eof()) {
			for (int i = 0; i < 4; i++) {
				getline(in, g);
				map.push_back(g);
				g.clear();
			}
		}
		in.close();
	}

	this->n = n; this->d = d; this->closeness = closeness;  this->traffic = traffic; co = 6;
	lenAni = map[0].size();
	first_spawn();
}

void LBEE::draw(int x, int y) {
	int n = map.size();
	for (int i = 0; i < n; i++) {
		go(x, y + i);
		cout << map[i];
	}
}

void LBEE::erase(int x, int y) {
	int n = map.size();
	for (int i = 0; i < n; i++) {
		go(x, y + i);
		cout << "        ";
	}
}

void LBEE::light_display() {
	if (light == 1) {
		go(BORDER - 1, y + 2);
		color(34); //green background
		cout << ' ';
		color(15);
		go(BORDER - 1, y + 1);
		cout << ' ';
	}
	else if (light == 2) {
		go(BORDER - 1, y + 1);
		color(68); //red blackground
		cout << ' ';
		color(15);
		go(BORDER - 1, y + 2);
		cout << ' ';
	}
}

void LBEE::first_spawn() {
	int s = BORDER - 1 - lenAni;
	while (s > LBORDER) {
		arr.push_back(s);
		s -= closeness;
	}
	light = 1; green = 1000;
}

void LBEE::makeSound()
{
	//do something
}

void LBEE::spawn_rate(int n, int d) {
	this->n = n; this->d = d;
}

bool LBEE::spawn() {
	if (rand() % d <= n) return true;
	return false;
}

void LBEE::close(int closeness) {
	this->closeness = closeness;
}

void LBEE::set_traffic(bool s) {
	if (s) traffic = true;
	else traffic = false;
}

void LBEE::display() {
	int n = arr.size();
	for (int i = 0; i < n; i++)
		erase(arr[i], y);
	if (traffic) light_display();
	if (spawn() && arr[n - 1] > closeness) //random appearance
	{
		arr.push_back(0);
		n++;
	}
	for (int i = 0; i < n; i++) {
		arr[i]++;//move to the right
		if (i == 0) 
		{
			if (arr[i] + lenAni + 1 > BORDER) //out of range
			{
				arr.erase(arr.begin() + i);
				n--;
			}
		}
		else
			if (abs(arr[i] - arr[i - 1]) < closeness) arr[i]--;
	}
	color(co);
	for (int i = 0; i < n; i++)
		draw(arr[i], y);
	color(15);
}

bool LBEE::done(int second) {//check if is there any light on{
	if (!traffic) return true;
	if (light == 1) {
		green -= second;
		if (green < 0) {
			green = 0;
			light = 0;
			return false;
		}
		return true;
	}
	else if (light == 2) {
		red -= second;
		if (red < 0) {
			red = 0;
			light = 0;
			return false;
		}
		return true;
	}
	return false;
}

//class RBEE
RBEE::RBEE(int y, int n, int d, int closeness, bool traffic) {
	this->y = y;
	ifstream in;
	in.open(path + "RBEE.txt");
	if (in.is_open()) {
		string g;
		while (!in.eof()) {
			for (int i = 0; i < 4; i++) {
				getline(in, g);
				map.push_back(g);
				g.clear();
			}
		}
		in.close();
	}
	this->n = n; this->d = d; this->closeness = closeness;  this->traffic = traffic; co = 6;
	lenAni = map[0].size();
	first_spawn();
}

void RBEE::draw(int x, int y) {
	int n = map.size();
	for (int i = 0; i < n; i++) {
		go(x, y + i);
		cout << map[i];
	}
}

void RBEE::erase(int x, int y) {
	int n = map.size();
	for (int i = 0; i < n; i++) {
		go(x, y + i);
		cout << "        ";
	}
}

void RBEE::light_display() {
	if (light == 1) {
		go(1, y + 2);
		color(34); //green background
		cout << ' ';
		color(15);
		go(1, y + 1);
		cout << ' ';
	}
	else if (light == 2)
	{
		go(1, y + 1);
		color(68); //red blackground
		cout << ' ';
		color(15);
		go(1, y + 2);
		cout << ' ';
	}
}

void RBEE::first_spawn() {
	int s = LBORDER + 1;
	while (s < BORDER - lenAni) {
		arr.push_back(s);
		s += closeness;
	}
	light = 1; green = 1000;
}

void RBEE::makeSound() {
	//do something
}

void RBEE::spawn_rate(int n, int d) {
	this->n = n; this->d = d;
}

bool RBEE::spawn() {
	if (rand() % d <= n) return true;
	return false;
}

void RBEE::close(int closeness) {
	this->closeness = closeness;
}

void RBEE::set_traffic(bool s) {
	if (s) traffic = true;
	else traffic = false;
}

void RBEE::display()
{
	int n = arr.size();
	for (int i = 0; i < n; i++)
		erase(arr[i], y);
	if (traffic) light_display();
	if (spawn() && BORDER - arr[n - 1] > closeness + lenAni) { //random appearance
		arr.push_back(BORDER - lenAni);
		n++;
	}
	for (int i = 0; i < n; i++) 
	{
		arr[i]--;//move to the left
		if (i == 0)
		{
			if (arr[i] <= 1)
			{//out of range
				arr.erase(arr.begin() + i);
				n--;

			}
		}
		else
			if (abs(arr[i] - arr[i - 1]) < closeness) arr[i]++;
	}
	color(co);
	for (int i = 0; i < n; i++)
		draw(arr[i], y);
	color(15);
}

bool RBEE::done(int second) {//check if is there any light on
	if (!traffic) return true;
	if (light == 1) {
		green -= second;
		if (green < 0) {
			green = 0;
			light = 0;
			return false;
		}
		return true;
	}
	else if (light == 2) {
		red -= second;
		if (red < 0) {
			red = 0;
			light = 0;
			return false;
		}
		return true;
	}
	return false;
}