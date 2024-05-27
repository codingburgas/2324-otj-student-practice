#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "MainMenu.h"
using namespace std;


void movie1() {
    system("CLS");
    ascii();
    int selection;
    cout << setw(100) << "" << "The Super Mario Bros.Movie" << endl;
    cout << setw(100) << "" << "2D" << endl;
    cout << setw(100) << "" << "Projection Time: Every Monday at 4 p.m untill August" << endl;
    cout << setw(100) << "" << "Release Date: April 5, 2023" << endl;
    cout << setw(100) << "" << "Directors: Aaron Horvath, Michael Jelenic" << endl;
    cout << setw(100) << "" << "Main Actor: Chris Pratt (voice)" << endl;
    cout << setw(100) << "" << "A plumber named Mario travels through an underground labyrinth" << endl;
    cout << setw(100) << "" << "with his brother, Luigi, trying to save a captured princess." << endl;
    cout << endl;
    cout << endl;
    cout << setw(60) << "" << "Press 0 to go back: ";
    cin >> selection;
    if (selection == 0) {
        system("CLS");
        main();
    }
}

int currentmovies() {
    int screenWidth = 80;
    ascii();
    cout << setw(screenWidth / 1.6) << "Current movies ";
    cout << endl;
    vector<string> movies = {
        "1. The Super Mario Bros. Movie",
        "2. John Wick: Chapter 4",
        "3. Shazam! Fury of the Gods",
        "4. Creed III",
        "5. Scream VI",
        "6. 65",
        "7. Dungeons & Dragons: Honor Among Thieves",
    };


    int maxMovieLength = 0;
    int choice;

    // Find the maximum length of the movie choices
    for (const string& movie : movies) {
        maxMovieLength = max(maxMovieLength, static_cast<int>(movie.length()));
    }

    // Calculate the spacing required to center the movie choices
    int movieSpacing = (screenWidth - maxMovieLength) / 1.5;

    cout << endl;

    // Print the movie choices with the calculated spacing
    for (const string& movie : movies) {
        cout << setw(movieSpacing) << " " << movie << endl;
    }
    cout << endl;
    cout << endl;
    cout << setw(screenWidth / 3) << "Select your choice or enter 0 to go back: ";
    cin >> choice;

    // Process the user's choice
    if (choice == 0) {
        system("CLS");
        main();
    }
    else if (choice == 1) {
        movie1();
    }
    else if (choice == 2) {
        movie1();
    }
    else if (choice == 3) {
        movie1();
    }
    else if (choice == 4) {
        movie1();
    }
    else if (choice == 5) {
        movie1();
    }
    else if (choice == 6) {
        movie1();
    }
    else if (choice == 7) {
        movie1();
    }
    else {
        cout << "Invalid choice!" << endl;

    }

    return 0;
}