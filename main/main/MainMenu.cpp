
#include "MainMenu.h"

using namespace std;

int main() {
    vector<string> mainMenu;
    mainMenu.push_back("1. Search Cinema");
    mainMenu.push_back("2. Current Movies");
    mainMenu.push_back("3. Cancel Booking");
    mainMenu.push_back("4. Account Settings");
    mainMenu.push_back("5. Exit");

    int choice;
    int screenWidth = 90; // Adjust this value according to your desired screen width
    int maxOptionLength = 0;



    do {
        ascii();

        cout << setw(screenWidth / 1.5) << "Please select an option:" << endl;
        cout << endl;

        // Find the maximum length of the menu options
        for (const string& option : mainMenu) {
            maxOptionLength = max(maxOptionLength, static_cast<int>(option.length()));
        }

        // Calculate the spacing required to center the menu options
        int optionSpacing = (screenWidth - maxOptionLength) / 2;

        // Print the menu options with the calculated spacing
        for (const string& option : mainMenu) {
            cout << setw(optionSpacing) << " " << option << endl;
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
            currentmovies();
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
            system("CLS");
            ascii();
            cout << setw(screenWidth / 1.5) << "Exiting the program..." << endl;
            break;
        default:
            cout << setw(screenWidth / 1.5) << "Invalid choice! Please try again." << endl;
            break;
        }

        cout << endl;
    } while (choice != 5);

    return 0;
}