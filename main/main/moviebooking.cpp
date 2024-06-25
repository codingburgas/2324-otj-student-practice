#include "MainMenu.h"
#include "TicketPurch.h"
#include <vector>

const int ROWS = 5;
const int SEATS_PER_ROW = 10;

struct Ticket {
    bool isAdult;
    int row;
    int seat;
};

void displaySeats(bool seats[ROWS][SEATS_PER_ROW]) {
    std::cout << std::setw(40) << "" << "  1 2 3 4 5 6 7 8 9 10" << std::endl;
    for (int i = 0; i < ROWS; i++) {
        std::cout << std::setw(40) << "" << char('A' + i) << " ";
        for (int j = 0; j < SEATS_PER_ROW; j++) {
            std::cout << (seats[i][j] ? 'X' : 'O') << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::setw(40) << "" << "X: Occupied, O: Available" << std::endl;
}

bool selectSeat(bool seats[ROWS][SEATS_PER_ROW], int& row, int& seat) {
    char rowChar;
    std::cout << std::setw(40) << "" << "Enter row (A-E): ";
    std::cin >> rowChar;
    row = toupper(rowChar) - 'A';

    std::cout << std::setw(40) << "" << "Enter seat number (1-10): ";
    std::cin >> seat;
    seat--; // Convert to 0-based index

    if (row < 0 || row >= ROWS || seat < 0 || seat >= SEATS_PER_ROW) {
        std::cout << std::setw(40) << "" << "\033[1;31mInvalid seat selection.\033[0m" << std::endl;
        return false;
    }

    if (seats[row][seat]) {
        std::cout << std::setw(40) << "" << "\033[1;31mSeat already occupied.\033[0m" << std::endl;
        return false;
    }

    seats[row][seat] = true;
    return true;
}

void cinemaBook() {
    ascii();
    const double ADULT_PRICE = 12.0;
    const double CHILD_PRICE = 8.0;
    std::vector<Ticket> tickets;
    double totalPrice = 0.0;
    bool seats[ROWS][SEATS_PER_ROW] = { false };

    while (true) {
        std::cout << std::setw(40) << "" << "Select the category of the ticket:" << std::endl;
        std::cout << std::endl;
        std::cout << std::setw(40) << "" << "1. Adult - $" << ADULT_PRICE << std::endl;
        std::cout << std::setw(40) << "" << "2. Child - $" << CHILD_PRICE << std::endl;
        std::cout << std::setw(40) << "" << "3. Finish and calculate total" << std::endl;
        int choice;
        std::cin >> choice;
        if (choice == 3) break;
        if (choice != 1 && choice != 2) {
            std::cout << std::setw(40) << "" << "\033[1;31mInvalid choice. Please try again.\033[0m" << std::endl;
            continue;
        }
        system("CLS");
        std::cout << std::setw(40) << "" << "Enter the number of tickets: ";
        int count;
        std::cin >> count;
        if (count < 0) {
            std::cout << std::setw(40) << "" << "\033[1;31mInvalid number. Please enter a non-negative number.\033[0m" << std::endl;
            continue;
        }

        for (int i = 0; i < count; i++) {
            system("CLS");
            displaySeats(seats);
            int row, seat;
            while (!selectSeat(seats, row, seat)) {
                std::cout << std::setw(40) << "" << "Please try again." << std::endl;
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
    std::cout << std::endl;
    std::cout << std::setw(40) << "" << "Booking Summary" << std::endl;
    std::cout << std::endl;
    for (const auto& ticket : tickets) {
        std::cout << std::setw(40) << "" << (ticket.isAdult ? "Adult" : "Child") << " ticket: Row "
            << char('A' + ticket.row) << ", Seat " << (ticket.seat + 1)
            << " - $" << (ticket.isAdult ? ADULT_PRICE : CHILD_PRICE) << std::endl;
    }
    std::cout << std::setw(40) << "" << "Total Price: $" << totalPrice << std::endl;
}