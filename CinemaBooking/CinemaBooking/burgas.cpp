#include <iomanip>
#include <map>
#include "../ProjectDll/login.h"
#include "../ProjectDll/front-end.h"
#include "../ProjectDll/main.h"
#include "../ProjectDll/movies.h"
#include "../ProjectDll/login.h"




void Burgas(string username) {

    system("cls");
    string address = "../../FrontEnd-Captions/BurgasCaption.txt";
    print(address);


    std::vector<Movie> movies = {
        {1, "Ghost Busters", {"13:30", "17:00", "21:15"}},
        {2, "Avengers", {"15:00", "18:30", "20:00"}},
        {3, "Dune", {"17:30", "20:40", "22:30"}},
        {4, "Titanic", {"10:00", "13:30", "15:00"}},
        {5, "Abagail", {"9:00", "11:00", "13:40"}}
    };

    std::map<char, std::vector<int>> seats = {
        {'A', {1, 2, 3, 4, 5, 6}},
        {'B', {1, 2, 3, 4, 5, 6}},
        {'C', {1, 2, 3, 4, 5, 6}},
        {'D', {1, 2, 3, 4, 5, 6}},
        {'E', {1, 2, 3, 4, 5, 6}}
    };



    std::string selectedMovie;
    std::string selectedShowtime;
    std::string selectedSeat;

    char continueBooking = 'Y';
    while (continueBooking == 'Y' || continueBooking == 'y') {
        int choice;

        while (true) {

            std::cin >> choice;

            if (choice >= 1 && choice <= movies.size()) {
                selectedMovie = movies[choice - 1].getName();
                std::cout << "You selected: " << selectedMovie << "\n";
                std::cout << "Show times are: ";
                int i = 1;
                for (const auto& time : movies[choice - 1].getShowTimes()) {
                    std::cout << i << ". " << time << " ";
                    i++;
                }
                std::cout << "\n";

                int showtimeChoice;
                std::cout << "Select a showtime by entering its number: ";
                std::cin >> showtimeChoice;

                if (showtimeChoice >= 1 && showtimeChoice <= movies[choice - 1].getShowTimes().size()) {
                    selectedShowtime = movies[choice - 1].getShowTimes()[showtimeChoice - 1];
                    std::cout << "You selected the showtime: " << selectedShowtime << "\n";

                    system("cls");
                    string address = "../../FrontEnd-Captions/seats.txt";
                    print(address);


                    char row;
                    int seatNumber;
                    while (true) {
                        std::cout << "Enter the row of seat you would like to book for [ROW : A,B,C...]: ";
                        std::cin >> row;
                        std::cout << "Enter the number of the seat you would like to book: ";
                        std::cin >> seatNumber;

                        if (seats[row].size() >= seatNumber && seats[row][seatNumber - 1] != 0) {
                            seats[row][seatNumber - 1] = 0;
                            selectedSeat = row + std::to_string(seatNumber);
                            std::cout << "You booked the seat: " << selectedSeat << "\n";
                            break;
                        }
                        else {
                            std::cout << "Invalid seat choice. Please try again.\n";
                        }
                    }
                    break;
                }
                else {
                    std::cout << "Invalid showtime choice. Please try again.\n";
                }
            }
            else {
                std::cout << "Invalid movie choice. Please try again.\n";
            }
        }

        std::cout << "Do you want to book another seat? (Y/N): ";
        std::cin >> continueBooking;

        // Print the seat map after each booking
        std::cout << "\nSeat Map:\n";
        for (const auto& row : seats) {
            for (int seat : row.second) {
                if (seat == 0) {
                    std::cout << "[" << row.first << ",X] ";
                }
                else {
                    std::cout << "[" << row.first << "," << seat << "] ";
                }
            }
            std::cout << "\n";
        }
    }


    std::cout << "\nReceipt:\n\n";
    std::cout << "To Mrs/Ms " << username <<  "\n\n";
    std::cout << "Seat selected: " << selectedSeat << "\n\n";
    std::cout << "Price of seat: $25\n\n";
    std::cout << "-----------------------------------------------\n\n";
    std::cout << "Amount to pay: $25\n\n";


// Ask for payment method
    int paymentMethod;
    while (true) {
        std::cout << "Select a payment method:\n";
        std::cout << "1. Card\n";
        std::cout << "2. Cash\n";
        std::cout << "Enter your choice (1 or 2): ";
        std::cin >> paymentMethod;

        if (paymentMethod == 1) {
            // Ask for card balance
            float cardBalance;
            while (true) {
                std::cout << "Enter the balance of your card: ";
                std::cin >> cardBalance;
                if (cardBalance < 25) {
                    std::cout << "You do not have enough balance. Please provide a card with sufficient balance.\n";
                }
                else {
                    std::cout << "Your remaining balance is: $" << cardBalance - 25 << "\n";
                    break;
                }
            }
            break;
        }
        else if (paymentMethod == 2) {
            // Ask for cash amount
            float cash;
            while (true) {
                std::cout << "Enter the amount of cash you have: ";
                std::cin >> cash;
                if (cash < 25) {
                    std::cout << "You do not have enough cash. Please provide a sufficient amount.\n";
                }
                else {
                    std::cout << "Your change is: $" << cash - 25 << "\n";
                    break;
                }
            }
            break;
        }
        else {
            std::cout << "Invalid choice. Please enter 1 for card or 2 for cash.\n";
        }
    }

    // Thank you message
    std::cout << "Payment successful. We wish you a great movie! Thank you for using our cinema booking system.\n";
    
}
