
#include "MainMenu.h"


int centerPos = (WIDTH - 5) / 2;
int choicePos = (WIDTH - 4) / 2;
int choice;


int main() {
    do {
        ascii();

        cout << setw(choicePos) << "" << "Select Your Option" << endl;
        cout << endl;
        cout << setw(centerPos) << "" << "1. Cinema Finder" << endl;
        cout << setw(centerPos) << "" << "2. Viral Movies" << endl;
        cout << setw(centerPos) << "" << "3. Register" << endl;
        cout << setw(centerPos) << "" << "4. Open Ticket" << endl;
        cout << setw(centerPos) << "" << "5. Dashboard" << endl;
        cout << setw(centerPos) << "" << "6. Exit" << endl;
        cout << endl;
        cout << setw(choicePos) << "" << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system("CLS");
            checkFile();
            void cinemafinder();
            break;
        case 2:
            system("CLS");
            currentmovies();
            break;
        case 3:
            system("CLS");
            reg();
            break;
        case 4:
            system("CLS");
            message();
            break;
        case 5:
            system("CLS");
            ascii();
            break;
        case 6:
            system("CLS");
            ascii();
            cout << setw(centerPos) << "" << "Exiting program..." << endl;
            exit(0);
            break;
        default:
            system("CLS");
            cout << "\x1b[31m" << setw(centerPos) << "" << "Invalid choice. Try again." << "\x1b[37m" << endl;
            cout << endl;
            main();
        }
    } while (choice != 5);
}