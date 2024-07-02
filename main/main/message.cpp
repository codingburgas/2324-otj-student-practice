#include "MainMenu.h"

void message() {
    do {
        ascii();
        int newPos = (WIDTH - 4) / 1.5;

        cout << setw(choicePos) << "" << "Our available support" << endl;
        cout << endl;
        cout << setw(centerPos) << "" << "1. Teodor Madzharov - App Support" << endl;

        cout << endl;
        cout << setw(35) << "" << "Enter your choice or press 0 to return: ";
        cin >> choice;

        switch (choice) {
        case 0:
            system("CLS");
            main();
            break;
        case 1:
            system("start mailto:tsmadzharov21@codingburgas.bg");
            system("CLS");
            message();
            break;
        default:
            system("CLS");
            cout << "\x1b[31m" << setw(centerPos) << "" << "Invalid choice. Try again." << "\x1b[37m" << endl;
            cout << endl;
            break;
            message();
        }
    } while (choice != 8);
}