#include "MainMenu.h"
#include "TicketPurch.h"
#include <fstream>

using namespace std;

const int ROWS = 6;
const int SEATS_PER_ROW = 10;
const double ADULT_PRICE = 12.0;
const double CHILD_PRICE = 8.0;

struct Ticket {
    bool isAdult;
    int row;
    int seat;
};

void displaySeats(bool seats[ROWS][SEATS_PER_ROW]) {
    ascii();
    cout << setw(40) << "" << "+----------------------------+" << endl;
    cout << setw(40) << "" << "|        CINEMA SCREEN       |" << endl;
    cout << setw(40) << "" << "+====+======================++" << endl;
    cout << setw(40) << "" << "|    | 1 2 3 4 5 6 7 8 9 10 ||" << endl;
    cout << setw(40) << "" << "+====+======================++" << endl;

    for (int i = 0; i < ROWS; i++) {
        cout << setw(40) << "" << "| " << char('A' + i) << "  | ";
        for (int j = 0; j < SEATS_PER_ROW; j++) {
            cout << (seats[i][j] ? "X" : "O") << " ";
        }
        cout << "||" << endl;
        if (i < ROWS - 1) {
            cout << setw(40) << "" << "+----+----------------------++" << endl;
        }
    }

    cout << setw(40) << "" << "+====+======================++" << endl;
    cout << setw(40) << "" << "   X: Occupied  O: Available " << endl;
}

bool selectSeat(bool seats[ROWS][SEATS_PER_ROW], int& row, int& seat) {
    cout << endl;
    char rowChar;
    cout << setw(45) << "" << "Enter row (A-F): ";
    cin >> rowChar;
    row = toupper(rowChar) - 'A';

    cout << setw(45) << "" << "Enter seat number (1-10): ";
    cin >> seat;
    seat--;

    if (row < 0 || row >= ROWS || seat < 0 || seat >= SEATS_PER_ROW) {
        system("CLS");
        cout << setw(40) << "" << "\033[1;31mInvalid seat selection.\033[0m" << endl;
        return false;
    }

    if (seats[row][seat]) {
        system("CLS");
        cout << setw(40) << "" << "\033[1;31mSeat already occupied.\033[0m" << endl;
        return false;
    }

    seats[row][seat] = true;
    return true;
}

void saveBookingToFile(const vector<Ticket>& tickets, double totalPrice) {
    ofstream outFile("booking_summary.txt");
    if (outFile.is_open()) {
        outFile << "Booking Summary\n\n";
        for (const auto& ticket : tickets) {
            outFile << (ticket.isAdult ? "Adult" : "Child") << " ticket: Row "
                << char('A' + ticket.row) << ", Seat " << (ticket.seat + 1)
                << " - $" << (ticket.isAdult ? ADULT_PRICE : CHILD_PRICE) << "\n";
        }
        outFile << "Total Price: $" << totalPrice << "\n";
        outFile.close();
        cout << setw(40) << "" << "Booking summary saved to booking_summary.txt\n";
    }
    else {
        cout << setw(40) << "" << "\033[1;31mError saving booking summary to file.\033[0m\n";
    }
}

void displaySummary(const vector<Ticket>& tickets, double totalPrice) {
    cout << endl;
    cout << setw(40) << "" << "Booking Summary" << endl;
    cout << endl;
    for (const auto& ticket : tickets) {
        cout << setw(40) << "" << (ticket.isAdult ? "Adult" : "Child") << " ticket: Row "
            << char('A' + ticket.row) << ", Seat " << (ticket.seat + 1)
            << " - $" << (ticket.isAdult ? ADULT_PRICE : CHILD_PRICE) << endl;
    }
    cout << setw(40) << "" << "Total Price: $" << totalPrice << endl;
    cout << endl;
    cout << setw(40) << "" << "Press any key to continue...";
    cin.ignore();
    cin.get();

    // Save booking summary to file
    saveBookingToFile(tickets, totalPrice);
}

void processPayment(double totalPrice, const vector<Ticket>& tickets) {
    while (true) {
        system("CLS");
        ascii();
        cout << setw(40) << "" << "Choose your payment method:" << endl;
        cout << endl;
        cout << setw(40) << "" << "1. Cash" << endl;
        cout << setw(40) << "" << "2. Card" << endl;
        cout << endl;
        int paymentChoice;
        cout << setw(40) << "" << "Enter your choice: ";
        cin >> paymentChoice;

        if (paymentChoice == 1) {
            system("CLS");
            displaySummary(tickets, totalPrice);
            break;
        }
        else if (paymentChoice == 2) {
            string cardNumber, expiryDate, cvv;

            while (true) {
                system("CLS");
                ascii();
                cout << setw(40) << "" << "Enter card details:" << endl;
                cout << endl;
                cout << setw(40) << "" << "Card Number (16 digits): ";
                cin >> cardNumber;
                cout << setw(40) << "" << "Expiry Date (MM/YY): ";
                cin >> expiryDate;
                cout << setw(40) << "" << "CVV (3 digits): ";
                cin >> cvv;

                bool isValid = true;
                if (cardNumber.length() != 16 || !all_of(cardNumber.begin(), cardNumber.end(), ::isdigit)) {
                    cout << setw(40) << "" << "\033[1;31mInvalid card number.\033[0m" << endl;
                    isValid = false;
                }
                if (expiryDate.length() != 5 || expiryDate[2] != '/' ||
                    !isdigit(expiryDate[0]) || !isdigit(expiryDate[1]) ||
                    !isdigit(expiryDate[3]) || !isdigit(expiryDate[4])) {
                    cout << setw(40) << "" << "\033[1;31mInvalid expiry date.\033[0m" << endl;
                    isValid = false;
                }
                if (cvv.length() != 3 || !all_of(cvv.begin(), cvv.end(), ::isdigit)) {
                    cout << setw(40) << "" << "\033[1;31mInvalid CVV.\033[0m" << endl;
                    isValid = false;
                }

                if (isValid) {
                    system("CLS");
                    cout << setw(40) << "" << "\033[1;32mPayment processed successfully.\033[0m" << endl;
                    displaySummary(tickets, totalPrice);
                    break;
                }
                else {
                    cout << endl;
                    cout << setw(40) << "" << "Press any key to try again...";
                    cin.ignore();
                    cin.get();
                }
            }
            break;
        }
        else {
            ascii();
            cout << setw(40) << "" << "\033[1;31mInvalid choice. Please try again.\033[0m" << endl;
            cout << endl;
            cout << setw(40) << "" << "Press any key to continue...";
            cin.ignore();
            cin.get();
        }
    }
}

void cinemaBook() {
    vector<Ticket> tickets;
    double totalPrice = 0.0;
    bool seats[ROWS][SEATS_PER_ROW] = { false };

    while (true) {
        system("CLS");
        ascii();
        cout << setw(40) << "" << "Select the category of the ticket:" << endl;
        cout << endl;
        cout << setw(40) << "" << "1. Adult - $" << ADULT_PRICE << endl;
        cout << setw(40) << "" << "2. Child - $" << CHILD_PRICE << endl;
        cout << setw(40) << "" << "3. Finish and calculate total" << endl;
        cout << endl;
        int choice;
        cout << setw(38) << "" << "Enter your choice or press 0 to home: ";
        cin >> choice;
        if (choice == 0) {
            system("CLS");
            main();
            return;
        }
        if (choice == 3) {
            break;
        }
        if (choice != 1 && choice != 2) {
            system("CLS");
            cout << setw(40) << "" << "\033[1;31mInvalid choice. Please try again.\033[0m" << endl;
            continue;
        }
        system("CLS");
        ascii();
        cout << setw(40) << "" << "Enter the number of tickets: ";
        int count;
        cin >> count;
        if (count < 0) {
            system("CLS");
            cout << setw(40) << "" << "\033[1;31mInvalid number. Please enter a non-negative number.\033[0m" << endl;
            continue;
        }

        for (int i = 0; i < count; i++) {
            system("CLS");
            displaySeats(seats);
            int row, seat;
            while (!selectSeat(seats, row, seat)) {
                cout << setw(40) << "" << "Please try again." << endl;
            }

            Ticket ticket;
            ticket.isAdult = (choice == 1);
            ticket.row = row;
            ticket.seat = seat;
            tickets.push_back(ticket);

            totalPrice += (choice == 1) ? ADULT_PRICE : CHILD_PRICE;
        }
    }

    processPayment(totalPrice, tickets);
}


void time() {
    ascii();
    cout << setw(40) << "" << "Select your time" << endl;
    cout << endl;
    cout << setw(40) << "" << "1. 14:00 / 3.07" << endl;
    cout << setw(40) << "" << "2. 16:00 / 3.07" << endl;
    cout << setw(40) << "" << "3. 18:00 / 3.07" << endl;
    cout << setw(40) << "" << "4. 20:00 / 3.07" << endl;
    cout << setw(40) << "" << "5. 22:00 / 3.07" << endl;
    cout << endl;
    cout << setw(40) << "" << "Enter your choice or enter any button to go back: ";

    int timesel;
    cin >> timesel;
    if (timesel == 1 || 2 || 3 || 4 || 5) {
        system("CLS");
        cinemaBook();
    }
    else {
        system("CLS");
        main();
    }
}