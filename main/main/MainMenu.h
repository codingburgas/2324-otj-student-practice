#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <fstream>
#include <ctime>
#include <string>
#include <sstream>
#include <vector>


using namespace std;

const int WIDTH = 80;
extern int centerPos;
extern int choicePos;
extern int choice;

int main();
void ascii();
void cinemafinder();
void checkFile();
void message();
void reg();
void viralmovies();
void currentmovies();
void city();
void dashboard();
void about();
#endif