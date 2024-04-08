#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
struct MenuItem {
	string label;
	void (*action)();
};
struct MenuNode {
	MenuItem data;
	MenuNode* next;
};
void displayMenu(MenuNode* head, int screenWidth);
void addMenuItem(MenuNode** head, const MenuItem& item);
void findCity();
void findTrendingMovies();
void customFunction1();
void customFunction2();
void exitProgram();
void ascii();
int currentmovies();
int main();
#endif