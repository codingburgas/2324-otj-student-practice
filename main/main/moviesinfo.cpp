#include "MainMenu.h"
#include "Movies.h"


void movie1() {
    system("CLS");
    int screenWidth = 80;
    ascii();
    cout << setw(55) << "Selected movie:";
    cout << endl;
    cout << endl;
    ifstream file("../moviesinfo/movie1.txt");

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

void movie2() {
    system("CLS");
    int screenWidth = 80;
    ascii();
    cout << setw(55) << "Selected movie:";
    cout << endl;
    cout << endl;
    ifstream file("../../movie2.txt");

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
void movie3() {
    system("CLS");
    int screenWidth = 80;
    ascii();
    cout << setw(55) << "Selected movie:";
    cout << endl;
    cout << endl;
    ifstream file("../movie3.txt");

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
void movie4() {
    system("CLS");
    int screenWidth = 80;
    ascii();
    cout << setw(55) << "Selected movie:";
    cout << endl;
    cout << endl;
    ifstream file("../movie4.txt");

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
void movie5() {
    system("CLS");
    int screenWidth = 80;
    ascii();
    cout << setw(55) << "Selected movie:";
    cout << endl;
    cout << endl;
    ifstream file("../movie5.txt");

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

void movie6() {
    system("CLS");
    int screenWidth = 80;
    ascii();
    cout << setw(55) << "Selected movie:";
    cout << endl;
    cout << endl;
    ifstream file("../movie6.txt");

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


void movie7() {
    system("CLS");
    int screenWidth = 80;
    ascii();
    cout << setw(55) << "Selected movie:";
    cout << endl;
    cout << endl;
    ifstream file("../movie7.txt");

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