#ifndef _SETTINGS_H
#define _SETTINGS_H
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <thread>
#include <fstream>
#include <mutex>
#include<iomanip>
using namespace std;

void FixConsoleWindow();
void go(int column, int line);
void color(const int& k);
void setcursor(bool x, DWORD size);


#endif 
