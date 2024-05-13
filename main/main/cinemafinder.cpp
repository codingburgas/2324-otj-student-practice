#include "MainMenu.h"

class CinemaFinder {
private:


    string firstName;

    string readFirstNameFromFile(const string& filename) {
        ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            cerr << "Error: Unable to open file " << filename << endl;
            return "";
        }

        string line;
        if (getline(inputFile, line)) {
            istringstream iss(line);
            string firstName;
            getline(iss, firstName, ',');
            inputFile.close();
            return firstName;
        }
        else {
            inputFile.close();
            return "";
        }
    }

public:
    CinemaFinder(const string& fName) : firstName(fName) {}

    void welcome() {
        system("CLS");
        ascii();
        cout << setw(choicePos) << "" << "Welcome, " << firstName << "!" << endl;
        cout << endl;
    }
    void showOptions() {

        cout << setw(choicePos) << "" << "Our Cinemas : " << firstName << endl;
        cout << endl;
        cout << setw(centerPos) << "" << "1. Sofia - Paradise Mall" << endl;
        cout << setw(centerPos) << "" << "2. Sofia - Sofia Mall" << endl;
        cout << setw(centerPos) << "" << "3. Plovdiv - Plovdiv Plaza" << endl;
        cout << setw(centerPos) << "" << "4. Varna - Varna Mall" << endl;
        cout << setw(centerPos) << "" << "5. Burgas - Mall Galeria" << endl;
        cout << setw(centerPos) << "" << "6. Burgas - Mall Strand" << endl;
        cout << setw(centerPos) << "" << "7. Ruse - Mall Rousse" << endl;
    }

    void cinemafinder() {
        welcome();
        showOptions();

        int choice;
        cout << endl;
        cout << setw(choicePos) << "" << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system("CLS");
            break;
        case 2:
            system("CLS");
            break;
        case 3:
            system("CLS");
            break;
        case 4:
            system("CLS");
            break;
        case 5:
            system("CLS");
            break;
        case 6:
            system("CLS");
            break;
        case 7:
            system("CLS");
            main();
            break;
        default:
            system("CLS");
            cout << setw(choicePos) << "" << "\x1b[31m" << "Invalid choice. Please try again." << "\x1b[0m" << endl;
            cinemafinder();
            break;
        }
    }

};
void checkFile() {
    ifstream inputFile("../students.txt");
    inputFile.seekg(0, ios::end);
    if (inputFile.tellg() == 0) {
        system("CLS");
        cout << setw(choicePos) << "" << "\x1b[31m" << "No user information available. Please register first." << "\x1b[0m" << endl;
        main();
    }
    else {
        system("CLS");
        string firstName;
        CinemaFinder cinemafinder(firstName);
        cinemafinder.cinemafinder();
    }
    inputFile.close();
}