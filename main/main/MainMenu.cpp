#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    vector<string> mainMenu;
    mainMenu.push_back("1. Search Cinema");
    mainMenu.push_back("2. Current Movies");
    mainMenu.push_back("3. Cancel Booking");
    mainMenu.push_back("4. Admin Panel");
    mainMenu.push_back("5. Exit");

    int choice;
    int screenWidth = 90; // Adjust this value according to your desired screen width
    int maxOptionLength = 0;



    do {
        // Set the text color to bright blue using ANSI escape sequence
        cout << "\033[1;94m";

        cout << setw(screenWidth / 2 + 34) << "     ________  _____  _____     ____    ____  _________     _       ______   _________  _____   ______  " << endl;
        cout << setw(screenWidth / 2 + 34) << "    |_   __  ||_   _||_   _|   |_   \\  /   _||  _   _  |   / \\    .' ____ \\ |  _   _  ||_   _|.' ___  | " << endl;
        cout << setw(screenWidth / 2 + 34) << "      | |_ \\_|  | |    | |       |   \\/   |  |_/ | | \\_|  / _ \\   | (___ \\_||_/ | | \\_|  | | / .'   \\_| " << endl;
        cout << setw(screenWidth / 2 + 34) << "      |  _|     | |    | |   _   | |\\  /| |      | |     / ___ \\   _.____`.     | |      | | | |        " << endl;
        cout << setw(screenWidth / 2 + 34) << "     _| |_     _| |_  _| |__/ | _| |_\\/_| |_    _| |_  _/ /   \\ \\_| \\____) |   _| |_    _| |_\\ `.___.'\\ " << endl;
        cout << setw(screenWidth / 2 + 34) << "    |_____|   |_____||________||_____||_____|  |_____||____| |____|\\______.'  |_____|  |_____|\`.____ .'" << endl;

        // Reset the text color to the default
        cout << "\033[0m";

        cout << endl;
        cout << endl;
        cout << endl;

        cout << setw(screenWidth / 1.5) << "Please select an option:" << endl;
        cout << endl;
        cout << setw(screenWidth / 1 + maxOptionLength /1) << left; // Shift menu options to the center and align to the left
        for (const string& option : mainMenu) {
            cout << option << endl;
        }
        cout << endl;
        cout << setw(screenWidth / 1.6) << right<< "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            // Code for searching movies
            break;
        case 2:
            system("cls");
            // Code for booking tickets
            break;
        case 3:
            system("cls");
            // Code for canceling booking
            break;
        case 4:
            system("cls");
            // Code for admin panel
            break;
        case 5:
            cout << setw(screenWidth / 2) << "Exiting the program..." << endl;
            break;
        default:
            cout << setw(screenWidth / 2) << "Invalid choice! Please try again." << endl;
            break;
        }

        cout << endl;
    } while (choice != 5);

    return 0;
}