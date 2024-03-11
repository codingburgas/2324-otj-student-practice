#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>

using namespace std;

// Structure for a single menu item
struct MenuItem {
	string label;
	void (*action)(); // Function pointer 
};

// Structure for a node in the linked list
struct MenuNode {
	MenuItem data;
	MenuNode* next;
};

// Function prototypes
void displayMenu(MenuNode* head, int screenWidth);
void addMenuItem(MenuNode** head, const MenuItem& item);
void findCity();
void findTrendingMovies();
void customFunction1();
void customFunction2();
void exitProgram();

#endif