#include "MainMenu.h"
#include "TicketPurch.h"

const int ROWS = 6;
const int SEATS_PER_ROW = 10;

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
    seat--; // Convert to 0-based index

    if (row < 0 || row >= ROWS || seat < 0 || seat >= SEATS_PER_ROW) {
        system("CLS");
        cout << setw(40) << "" << "\033[1;31mInvalid seat selection.\033[0m" << endl;
        cinemaBook();
        return false;
    }

    if (seats[row][seat]) {
        system("CLS");
        cout << setw(40) << "" << "\033[1;31mSeat already occupied.\033[0m" << endl;
        cinemaBook();
        return false;
    }

    seats[row][seat] = true;
    return true;
}

void cinemaBook() {
    const double ADULT_PRICE = 12.0;
    const double CHILD_PRICE = 8.0;
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
        }
        if (choice == 3) {
            main();
        }
        if (choice != 1 && choice != 2) {
            system("CLS");
            cout << setw(40) << "" << "\033[1;31mInvalid choice. Please try again.\033[0m" << endl;
            cinemaBook();
        }
        system("CLS");
        ascii();
        cout << setw(40) << "" << "Enter the number of tickets: ";
        int count;
        cin >> count;
        if (count < 0) {
            system("CLS");
            cout << setw(40) << "" << "\033[1;31mInvalid number. Please enter a non-negative number.\033[0m" << endl;
            cinemaBook();
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
        system("CLS");
        cout << endl;
        cout << setw(40) << "" << "Booking Summary" << endl;
        cout << endl;
        for (const auto& ticket : tickets) {
            cout << setw(40) << "" << (ticket.isAdult ? "Adult" : "Child") << " ticket: Row "
                << char('A' + ticket.row) << ", Seat " << (ticket.seat + 1)
                << " - $" << (ticket.isAdult ? ADULT_PRICE : CHILD_PRICE) << endl;
        }
        cout << setw(40) << "" << "Total Price: $" << totalPrice << endl;
    }