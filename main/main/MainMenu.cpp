#include "MainMenu.h"

void addMenuItem(MenuNode** head, const MenuItem& item) {
    MenuNode* newNode = new MenuNode{ item, nullptr };

    if (*head == nullptr) {
        *head = newNode;
    }
    else {
        MenuNode* current = *head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void displayMenu(MenuNode* head, int screenWidth) {
    system("CLS"); // Clear the console screen
    cout << string((screenWidth - 24) / 2, ' ') << "Movie Ticket Booking System\n";
    int i = 1;
    while (head != nullptr) {
        cout << i << ". " << head->data.label << endl;
        head = head->next;
        i++;
    }
}

void findCity() {
    cout << "Finding City feature (implementation needed)\n";
}

void findTrendingMovies() {
    cout << "Finding Trending Movies feature (implementation needed)\n";
}

void customFunction1() {
    cout << "Custom Function 1 (implementation needed)\n";
}

void customFunction2() {
    cout << "Custom Function 2 (implementation needed)\n";
}

void exitProgram() {
    cout << "Exiting...\n";
}