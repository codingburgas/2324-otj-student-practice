#include "../ProjectDll/front-end.h"
#include "../ProjectDll/main.h"

void menu(string username) {
    int choice;

    system("cls");
    string address = "../../FrontEnd-Captions/CinemaCaption.txt";
    print(address);

    cin >> choice;

    switch (choice) {
    case 1:
        Burgas(username);
        break;
    case 2:
        Varna(username);
        break;
    case 3:
       Sofia(username);
        cout << endl;
      
        break;
    default:

        cout << setw(150) << "Invalid choice. Please enter a number between [1, 2, 3 ...]";
        
        menu(username);
    }

}


