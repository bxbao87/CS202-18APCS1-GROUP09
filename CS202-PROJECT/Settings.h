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
#include<cstring>
#include<set>

using namespace std;


//please change this path and create folder to run this program
//const string soundPath = "D:\\school\\project\\CS202-18APCS1-GROUP09\\roadCrossing\\crossyRoad\\CS202-PROJECT\\sound\\";
//const string path = "D:\\school\\project\\CS202-18APCS1-GROUP09\\roadCrossing\\crossyRoad\\CS202-PROJECT\\MAP\\";
//const string savedPath = "D:\\school\\project\\CS202-18APCS1-GROUP09\\roadCrossing\\crossyRoad\\CS202-PROJECT\\Saved\\";
const string path = "H:\\APCS\\2nd year\\CS202\\CS202-PROJECT\\CS202PROJECT\\MAP\\";
const string savedPath = "H:\\APCS\\2nd year\\CS202\\CS202-PROJECT\\CS202PROJECT\\Saved\\";
const string soundPath = "H:\\APCS\\2nd year\\CS202\\CS202-PROJECT\\CS202PROJECT\\sound\\";
 // t.length()=140
const string split_lane = "-------------------------------------------------------------------------------------------------------------------------------------------";
const int BORDER = 140;//160
const int LBORDER = 0;

const int X_MOVE = 1;
const int Y_MOVE = 5;
const int Top_bound = 0;
const int Bot_bound = 45;
const int Left_bound = 1; 
const int Right_bound = BORDER - 4;

void FixConsoleWindow();
void go(int column, int line);
void color(const int& k);
void Nocursortype();				// hide the cursor
void setcursor(bool x, DWORD size);
void playSound(const char* path);

#endif