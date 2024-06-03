#include "MainMenu.h"
using namespace std;


void currentmovies() {
    int screenWidth = 80;
    ascii();
    cout << setw(55) << "Current movies:";
    cout << endl;
    cout << endl;
    ifstream file("../movies.txt");

    string line;
    while (getline(file, line)) {
        cout << line << std::endl;
    }
    file.close();
    cout << endl;
    cout  << setw(30) << " " << "Enter your choice or press 0 to go back: ";
    int choicem;
    cin >> choicem;

    if (choicem == 0) {
        system("CLS");
        main();
    }
    else if (choicem == 1) {
        //movie1();
    }
    else if (choicem == 2) {
        //movie2();
    }
    else if (choicem == 3) {
       // movie3();
    }
    else if (choicem == 4) {
       // movie4();
    }
    else if (choicem == 5) {
       // movie5();
    }
    else if (choicem == 6) {
       // movie6();
    }
    else if (choicem == 7) {
       // movie7();
    }
    else if (choicem == 0) {
        system("CLS");
        main();
    }
    else {
        system("CLS");
        cout << setw(55) << "\033[91m" << "Invalid choice!" << "\033[0m" << endl;
        currentmovies();


    }
}