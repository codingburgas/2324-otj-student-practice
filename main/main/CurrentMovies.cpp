#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "MainMenu.h"
using namespace std;
    
int currentmovies() {
    int screenWidth = 80; // Adjust this value according to your desired screen width
    ascii();
    cout << setw(screenWidth / 1.5) << "Current movies ";
    cout << endl;
    vector<string> movies = {
        "1. The Super Mario Bros. Movie",
        "2. John Wick: Chapter 4",
        "3. Shazam! Fury of the Gods",
        "4. Creed III",
        "5. Scream VI",
        "6. 65",
        "7. Dungeons & Dragons: Honor Among Thieves",
        "8. Ant-Man and the Wasp: Quantumania",
        "9. Renfield",
        "10. Air"
    };

    
    int maxMovieLength = 0;
    int choice;

    // Find the maximum length of the movie choices
    for (const string& movie : movies) {
        maxMovieLength = max(maxMovieLength, static_cast<int>(movie.length()));
    }

    // Calculate the spacing required to center the movie choices
    int movieSpacing = (screenWidth - maxMovieLength) / 2;

    cout << endl;

    // Print the movie choices with the calculated spacing
    for (const string& movie : movies) {
        cout << setw(movieSpacing) << " " << movie << endl;
    }

    cout << endl;
    cout << setw(screenWidth / 1.4) << "Enter 0 to go back: ";
    cin >> choice;

    // Process the user's choice
    if (choice == 0) {
        system("CLS");
        main();
    }
    else {
        cout << "Invalid choice!" << endl;

    }

    return 0;
}