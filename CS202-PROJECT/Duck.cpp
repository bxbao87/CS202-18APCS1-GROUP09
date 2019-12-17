#include "Duck.h"

//class LDUCK
LDUCK::LDUCK(int y, int n, int d, int closeness, bool traffic) {
	this->y = y;
	ifstream in;
	in.open(path + "LDUCK.txt");
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
	this->n = n; this->d = d; this->closeness = closeness;  this->traffic = traffic; co = 14; crowd_size = 0;
	lenAni = map[0].size();
	first_spawn();
}

void LDUCK::draw(int x, int y) {
	int n = map.size();
	for (int i = 0; i < n; i++) {
		go(x, y + i);
		cout << map[i];
	}
}

void LDUCK::erase(int x, int y) {
	int n = map.size();
	for (int i = 0; i < n; i++) {
		go(x, y + i);
		cout << "        ";
	}
}

void LDUCK::light_display() {
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

void LDUCK::first_spawn() {
	int s = BORDER - 1 - lenAni;
	int count = rand() % 3 + 2;
	while (s > LBORDER) {
		arr.push_back(s);
		--count;
		if (count == 0)
		{
			count = rand() % 3 + 2;
			s -= closeness;
		}
		else s -= lenAni +1;
	}
	light = 1; green = 1000;
}

void LDUCK::makeSound() {
	Option::playSound(soundPath + "duck.wav");

}

void LDUCK::spawn_rate(int n, int d) {
	this->n = n; this->d = d;
}

bool LDUCK::spawn() {
	if (crowd_size == 0 && arr[arr.size() - 1] > closeness && rand() % d <= n)
	{
		crowd_size = rand() % 3 + 1; //take 3 values 2 3 4
		//choose when to spawn the crowd
		arr.push_back(1);
	}
	else if (crowd_size > 0 && arr[arr.size() - 1] > lenAni)
	{
		arr.push_back(1);
		--crowd_size;
	}
	return true;
}

void LDUCK::close(int closeness) {
	this->closeness = closeness;
}

void LDUCK::set_traffic(bool s) {
	if (s) traffic = true;
	else traffic = false;
}

void LDUCK::display() {
	int n = arr.size();
	for (int i = 0; i < n; i++)
		erase(arr[i], y);
	if (traffic) light_display();
	spawn();
	n = arr.size();
	for (int i = 0; i < n; i++) 
	{
		arr[i]++;//move to the right
		if (i == 0)
		{
			if (arr[i] + lenAni + 1 > BORDER) //out of range
			{
				if (light == 1)
				{
					arr.erase(arr.begin() + i);
					n--;
				}
				else if (light == 2) //stop at red light
					--arr[i];
			}
		}
		else
		{
			if (light == 2)
			{
				//if 2 ducks are not in a crowd ... 2 ducks are in a same crowd
				if ((arr[i-1] - arr[i] > lenAni + 1 && arr[i-1] - arr[i] <= closeness) || arr[i-1] - arr[i] <= lenAni) --arr[i];
			}
		}
	}
	color(co);
	for (int i = 0; i < n; i++)
		draw(arr[i], y);
	color(15);
}

bool LDUCK::done(int second) {//check if is there any light on{
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

//class RDUCK
RDUCK::RDUCK(int y, int n, int d, int closeness, bool traffic) {
	this->y = y;
	ifstream in;
	in.open(path + "RDUCK.txt");
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
	this->n = n; this->d = d; this->closeness = closeness;  this->traffic = traffic; co = 14; crowd_size = 0;
	lenAni = map[0].size();
	first_spawn();
}

void RDUCK::draw(int x, int y) {
	int n = map.size();
	for (int i = 0; i < n; i++) {
		go(x, y + i);
		cout << map[i];
	}
}

void RDUCK::erase(int x, int y) {
	int n = map.size();
	for (int i = 0; i < n; i++) {
		go(x, y + i);
		cout << "        ";
	}
}

void RDUCK::light_display() {
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

void RDUCK::first_spawn() {
	int s = LBORDER + 1;
	int count = rand() % 3 + 2;
	while (s < BORDER - lenAni) {
		arr.push_back(s);
		--count;
		if (count == 0)
		{
			count = rand() % 3 + 2;
			s += closeness + lenAni;
		}
		else s += lenAni;
	}
	light = 1; green = 1000;
}

void RDUCK::makeSound() {
	Option::playSound(soundPath + "duck.wav");

}

void RDUCK::spawn_rate(int n, int d) {
	this->n = n; this->d = d;
}

bool RDUCK::spawn() {
	if (crowd_size == 0 && arr[arr.size() - 1] + closeness + 2*lenAni < BORDER && rand() % d <= n)
	{
		crowd_size = rand() % 3 + 1; //take 3 values 2 3 4
		//choose when to spawn the crowd
		arr.push_back(BORDER-lenAni);
	}
	else if (crowd_size > 0 && arr[arr.size() - 1] + 2*lenAni < BORDER)
	{
		arr.push_back(BORDER-lenAni);
		--crowd_size;
	}
	return true;
}

void RDUCK::close(int closeness) {
	this->closeness = closeness;
}

void RDUCK::set_traffic(bool s) {
	if (s) traffic = true;
	else traffic = false;
}

void RDUCK::display()
{
	int n = arr.size();
	for (int i = 0; i < n; i++)
		erase(arr[i], y);
	if (traffic) light_display();
	spawn();
	n = arr.size();
	for (int i = 0; i < n; i++) {
		arr[i]--;//move to the left
		if (i == 0) {
			if (arr[i] <= 1) {//out of range
				if (light == 1) {
					arr.erase(arr.begin() + i);
					n--;
				}
				else if (light == 2) arr[i]++; //stop at red light
			}
		}
		else
		{
			if (light == 2)
			{
				//if 2 ducks are not in a crowd ... 2 ducks are in a same crowd
				if ((arr[i] - arr[i - 1] > lenAni + 1 && arr[i] - arr[i - 1] <= closeness + lenAni) || arr[i] - arr[i - 1] <= lenAni) ++arr[i];
			}
		}
	}
	color(co);
	for (int i = 0; i < n; i++)
		draw(arr[i], y);
	color(15);
}

bool RDUCK::done(int second) {//check if is there any light on
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