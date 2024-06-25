#include "MainMenu.h"
#include "TicketPurch.h"

void selectmovie() {
        int screenWidth = 80;
        ascii();
        cout << setw(55) << "Select Movie:";
        cout << endl;
        cout << endl;
        ifstream file("../movies.txt");

        string line;
        while (getline(file, line)) {
            cout << line << std::endl;
        }
        file.close();
        cout << endl;
        cout << setw(30) << " " << "Enter your choice or press 0 to go back: ";
        int choicen;
        cin >> choicen;

        if (choicen >= 1 && choicen <= 7) {
            system("CLS");
            cinemaBook();
        }
        if (choicen == 0) {
            system("CLS");
            main();
        }
        else{
            system("CLS");
            cout << setw(55) << "\033[91m" << "Invalid choice!" << "\033[0m" << endl;
            currentmovies();
        }
        }