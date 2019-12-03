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
using namespace std;

const int BORDER = 160;

void FixConsoleWindow();
void go(int column, int line);
void color(const int& k);
void Nocursortype();				// hide the cursor
void setcursor(bool x, DWORD size);


#endif 
