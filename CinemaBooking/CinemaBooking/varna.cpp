#include <iomanip>
#include <map>
#include "../ProjectDll/front-end.h"
#include "../ProjectDll/main.h"
#include "../ProjectDll/movies.h"





void Varna(string username) {

    system("cls");
    string address = "../../FrontEnd-Captions/VarnaCaption.txt";
    print(address);


    vector<Movie> movies = {
        {1, "The Godfather", {"15:30", "17:00", "22:15"}},
        {2, "Angry Men", {"16:00", "18:30", "19:00"}},
        {3, "The Dark Knight", {"13:30", "14:40", "15:30"}},
        {4, "Pulp Fiction", {"11:00", "15:30", "18:00"}},
        {5, "Fight Club", {"13:00", "15:00", "17:40"}}
    };

    map<char, vector<int>> seats = {
        {'A', {1, 2, 3, 4, 5, 6}},
        {'B', {1, 2, 3, 4, 5, 6}},
        {'C', {1, 2, 3, 4, 5, 6}},
        {'D', {1, 2, 3, 4, 5, 6}},
        {'E', {1, 2, 3, 4, 5, 6}}
    };



    string selectedMovie;
    string selectedShowtime;
    string selectedSeat;

    int choice;

    while (true) {

        cin >> choice;

        if (choice >= 1 && choice <= movies.size()) {
            selectedMovie = movies[choice - 1].getName();
            cout << "You selected: " << selectedMovie << "\n";
            cout << "Show times are: ";
            int i = 1;
            for (const auto& time : movies[choice - 1].getShowTimes()) {
                cout << i << ". " << time << " ";
                i++;
            }
            cout << "\n";

            int showtimeChoice;
            cout << "Select a showtime by entering its number: ";
            cin >> showtimeChoice;

            if (showtimeChoice >= 1 && showtimeChoice <= movies[choice - 1].getShowTimes().size()) {
                selectedShowtime = movies[choice - 1].getShowTimes()[showtimeChoice - 1];
                cout << "You selected the showtime: " << selectedShowtime << "\n";

                system("cls");
                string address = "../../FrontEnd-Captions/SeatMap.txt";
                print(address);


                char continueBooking = 'Y';
                while (continueBooking == 'Y' || continueBooking == 'y') {
                    // Code for selecting a seat
                    while (true) {
                        char row;
                        int seatNumber;
                        cout << endl;
                        cout << "Enter the row of seat you would like to book for [ROW : A,B,C...]: ";
                        cin >> row;
                        cout << "Enter the number of the seat you would like to book: ";
                        cin >> seatNumber;

                        if (seats[row].size() >= seatNumber && seats[row][seatNumber - 1] != 0) {
                            seats[row][seatNumber - 1] = 0;
                            selectedSeat = row + to_string(seatNumber);
                            cout << "You booked the seat: " << selectedSeat << endl;
                            break;
                        }
                        else {
                            cout << "Invalid seat choice. Please try again." << endl;
                        }
                    }

                    // Print the seat map after a seat has been booked
                    cout << "\nSeat Map:" << endl;
                    for (const auto& row : seats) {
                        for (int seat : row.second) {
                            if (seat == 0) {
                                cout << "[" << string(1, row.first) << ",X] ";
                            }
                            else {
                                cout << "[" << string(1, row.first) << "," << to_string(seat) << "] ";
                            }
                        }
                        cout << "" << endl;
                    }
                    cout << endl;
                    cout << "Do you want to book another seat? (Y/N): ";
                    cin >> continueBooking;
                }
            }

        }

        system("cls");
        string address = "../../FrontEnd-Captions/ReceiptCaption.txt";
        print(address);
       
        cout << "To Mrs/Ms " << username << "\n\n";
        cout << "Movie selected: " << selectedMovie << "\n\n";
        cout << "Seat selected: " << selectedSeat << "\n\n";
        cout << "Price of seat: $25\n\n";
        cout << "-----------------------------------------------\n\n";
        cout << "Amount to pay: $25\n\n";


        // Ask for payment method
        int paymentMethod;
        while (true) {
            cout << "Select a payment method:\n";
            cout << "1. Card\n";
            cout << "2. Cash\n";
            cout << "Enter your choice (1 or 2): ";
            cin >> paymentMethod;

            if (paymentMethod == 1) {
                // Ask for card balance
                float cardBalance;
                while (true) {
                    cout << "Enter the balance of your card: ";
                    cin >> cardBalance;
                    if (cardBalance < 25) {
                        cout << "You do not have enough balance. Please provide a card with sufficient balance.\n";
                    }
                    else {
                        cout << "Your remaining balance is: $" << cardBalance - 25 << "\n";
                        break;
                    }
                }
                break;
            }
            else if (paymentMethod == 2) {
                // Ask for cash amount
                float cash;
                while (true) {
                    cout << "Enter the amount of cash you have: ";
                    cin >> cash;
                    if (cash < 25) {
                        cout << "You do not have enough cash. Please provide a sufficient amount.\n";
                    }
                    else {
                        cout << "Your change is: $" << cash - 25 << "\n";
                        break;
                    }
                }
                break;
            }
            else {
                cout << "Invalid choice. Please enter 1 for card or 2 for cash.\n";
            }
        }

        // Thank you message
        cout << "Payment successful. We wish you a great movie! Thank you for using our cinema booking system.\n";

        return;
    }
}
