#include <iostream>
#include <string>
#include <iomanip>
#include "../ProjectDll/front-end.h"
#include "../ProjectDll/burgas.h"
#include "../ProjectDll/varna.h"
#include "../ProjectDll/sofia.h"



using namespace std;

int main() {
    int choice;

    system("cls");
    string address = "../../FrontEnd-Captions/CinemaCaption.txt";
    print(address);

    cout << setw(120) << "1. Burgas\n";
    cout << setw(120) << "2. Varna\n";
    cout << setw(120) << "3. Sofia\n";
    cout << setw(129) << "Enter your choice (1-3): ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "You selected Burgas.\n";
        Burgas();
        break;
    case 2:
        cout << "You selected Varna.\n";
        Varna();
        break;
    case 3:
        cout << "You selected Sofia.\n";
        Sofia();
        cout << endl;
      
        break;
    default:

        cout << "Invalid choice. Please enter a number between 1 and 3";
        break;
    }

}