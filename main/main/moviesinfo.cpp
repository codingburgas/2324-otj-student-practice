#include "MainMenu.h"
#include "Movies.h"


void movie1() {
    system("CLS");
    int screenWidth = 80;
    ascii();
    cout << setw(55) << "Selected movie:";
    cout << endl;
    cout << endl;
    ifstream file("../movie1.txt");

    string line;
    while (getline(file, line)) {
        cout << line << std::endl;
    }
    file.close();
    cout << endl;
    cout << setw(35) << " " << "Press any button to go back: ";
    int choicen;
    cin >> choicen;
    if (choicen == 0) {
        system("CLS");
        currentmovies();
    }
    else {
        system("CLS");
        currentmovies();
    }
}