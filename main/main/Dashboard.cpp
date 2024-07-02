#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "MainMenu.h"
#include "TicketPurch.h"

using namespace std;

struct Booking {
    int bookingId;
    string customerName;
    int row;
    int seat;
};



vector<Booking> bookings;
void cancelbooking() {
    system("CLS");
     ascii();
     cout << setw(40) << "" << "Booking cancelation" << endl;
     cout << endl;
     cout << setw(40) << "" << "Booking detected, are you sure you want to cancel" << endl;
}
void displayDashboard() {
    while (true) {
        system("CLS");
        ascii();
        cout << setw(40) << "" << "Filmtastic System Dashboard" << endl;
        cout << endl;
        cout << setw(40) << "" << "1. User Options" << endl;
        cout << setw(40) << "" << "2. Admin Login" << endl;
        cout << setw(40) << "" << "3. Exit" << endl;
        cout << endl;
        cout << setw(40) << "" << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            userDashboard();
            break;
        case 2:
        {
            string username, password;
            system("CLS");
            ascii();
            cout << setw(40) << "" << "Admin Dashboard";
            cout << endl;
            cout << setw(40) << "" << "Enter username: ";
            cin >> username;
            cout << setw(40) << "" << "Enter password: ";
            cin >> password;

            if (username == "admin" && password == "12345678") {
                adminDashboard();
            }
            else {
                cout << setw(40) << "" << "\033[1;31mInvalid credentials. Access denied.\033[0m" << endl;
                system("pause");
            }
        }
        break;
        case 3:
            system("CLS");
            main();
        default:
            cout << setw(40) << "" << "\033[1;31mInvalid choice. Please try again.\033[0m" << endl;
            system("pause");
        }
    }
}

void userDashboard() {
    while (true) {
        system("CLS");
        ascii();
        cout << setw(40) << "" << "User Dashboard" << endl;
        cout << endl;
        cout << setw(40) << "" << "1. Cancel booking" << endl;
        cout << setw(40) << "" << "2. Change seats" << endl;
        cout << setw(40) << "" << "3. Return to main dashboard" << endl;
        cout << endl;
        cout << setw(40) << "" << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            cancelBooking();
            break;
        case 2:
            changeSeats();
            break;
        case 3:
            return;
        default:
            cout << setw(40) << "" << "\033[1;31mInvalid choice. Please try again.\033[0m" << endl;
            system("pause");
        }
    }
}

void adminDashboard() {
    system("CLS");
    ascii();
    cout << setw(40) << "" << "Admin Dashboard" << endl;
    cout << endl;
    cout << setw(40) << "" << "Welcome, Admin!" << endl;
    system("pause");
}

void cancelBooking() {
    cout << setw(40) << "" << "Booking cancellation functionality to be implemented." << endl;
    system("pause");
}

void changeSeats() {
    cout << setw(40) << "" << "Seat change functionality to be implemented." << endl;
    system("pause");
}
void dashboard() {
    ifstream inputFile("../logins.txt");
    inputFile.seekg(0, ios::end);
    if (inputFile.tellg() == 0) {
        system("CLS");
        cout << setw(choicePos) << "" << "\x1b[31m" << "No user information available. Please register first." << "\x1b[0m" << endl;
        main();
    }
    else {
        system("CLS");
        displayDashboard();

    }
    inputFile.close();
}