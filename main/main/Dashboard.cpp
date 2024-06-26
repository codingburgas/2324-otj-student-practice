#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "MainMenu.h"
#include "TicketPurch.h"

using namespace std;

// Assuming these are defined elsewhere or will be linked later
extern vector<Ticket> bookedTickets;
extern const double ADULT_PRICE;
extern const double CHILD_PRICE;

void displayUserDashboard() {
    while (true) {
        system("CLS");
        ascii();
        cout << setw(40) << "" << "User Dashboard" << endl;
        cout << endl;
        cout << setw(40) << "" << "1. View Booked Tickets" << endl;
        cout << setw(40) << "" << "2. Cancel Booking" << endl;
        cout << setw(40) << "" << "3. Return to Main Menu" << endl;
        cout << endl;
        int choice;
        cout << setw(38) << "" << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            system("CLS");
            ascii();
            cout << setw(40) << "" << "Booked Tickets:" << endl;
            cout << endl;
            double totalPrice = 0.0;
            for (size_t i = 0; i < bookedTickets.size(); ++i) {
                const auto& ticket = bookedTickets[i];
                cout << setw(40) << "" << i + 1 << ". " << (ticket.isAdult ? "Adult" : "Child")
                    << " ticket: Row " << char('A' + ticket.row) << ", Seat " << (ticket.seat + 1)
                    << " - $" << (ticket.isAdult ? ADULT_PRICE : CHILD_PRICE) << endl;
                totalPrice += (ticket.isAdult ? ADULT_PRICE : CHILD_PRICE);
            }
            cout << endl;
            cout << setw(40) << "" << "Total Price: $" << totalPrice << endl;
            cout << endl;
            cout << setw(40) << "" << "Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        }
        case 2: {
            if (bookedTickets.empty()) {
                cout << setw(40) << "" << "No tickets booked to cancel." << endl;
                cout << setw(40) << "" << "Press any key to continue...";
                cin.ignore();
                cin.get();
                break;
            }

            system("CLS");
            ascii();
            cout << setw(40) << "" << "Cancel Booking" << endl;
            cout << endl;
            for (size_t i = 0; i < bookedTickets.size(); ++i) {
                const auto& ticket = bookedTickets[i];
                cout << setw(40) << "" << i + 1 << ". " << (ticket.isAdult ? "Adult" : "Child")
                    << " ticket: Row " << char('A' + ticket.row) << ", Seat " << (ticket.seat + 1) << endl;
            }
            cout << endl;
            int cancelChoice;
            cout << setw(38) << "" << "Enter the number of the ticket to cancel (0 to go back): ";
            cin >> cancelChoice;

            if (cancelChoice > 0 && cancelChoice <= static_cast<int>(bookedTickets.size())) {
                bookedTickets.erase(bookedTickets.begin() + cancelChoice - 1);
                cout << setw(40) << "" << "Ticket cancelled successfully." << endl;
            }
            else if (cancelChoice != 0) {
                cout << setw(40) << "" << "Invalid choice." << endl;
            }

            cout << setw(40) << "" << "Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        }
        case 3:
            return;
        default:
            cout << setw(40) << "" << "Invalid choice. Please try again." << endl;
            cout << setw(40) << "" << "Press any key to continue...";
            cin.ignore();
            cin.get();
        }
    }
}

void displayStaffDashboard() {
    system("CLS");
    ascii();
    cout << setw(40) << "" << "Staff Dashboard" << endl;
    cout << endl;
    cout << setw(40) << "" << "Hello World!" << endl;
    cout << endl;
    cout << setw(40) << "" << "Press any key to return to main menu...";
    cin.ignore();
    cin.get();
}

void dashboard() {
    while (true) {
        system("CLS");
        ascii();
        cout << setw(40) << "" << "Dashboard" << endl;
        cout << endl;
        cout << setw(40) << "" << "1. User Dashboard" << endl;
        cout << setw(40) << "" << "2. Staff Dashboard" << endl;
        cout << setw(40) << "" << "3. Return to Main Menu" << endl;
        cout << endl;
        int choice;
        cout << setw(38) << "" << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displayUserDashboard();
            break;
        case 2: {
            string username, password;
            cout << setw(40) << "" << "Enter username: ";
            cin >> username;
            cout << setw(40) << "" << "Enter password: ";
            cin >> password;

            if (username == "admin" && password == "1-8") {
                displayStaffDashboard();
            }
            else {
                cout << setw(40) << "" << "Invalid credentials. Access denied." << endl;
                cout << setw(40) << "" << "Press any key to continue...";
                cin.ignore();
                cin.get();
            }
            break;
        }
        case 3:
            return;
        default:
            cout << setw(40) << "" << "Invalid choice. Please try again." << endl;
            cout << setw(40) << "" << "Press any key to continue...";
            cin.ignore();
            cin.get();
        }
    }
}