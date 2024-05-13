#include "../ProjectDll/front-end.h"
#include "../ProjectDll/main.h"

using namespace std;

void menu() {
    int choice;

    system("cls");
    string address = "../../FrontEnd-Captions/CinemaCaption.txt";
    print(address);

    cin >> choice;

    switch (choice) {
    case 1:
        Burgas();
        break;
    case 2:
        Varna();
        break;
    case 3:
       //Sofia();
        cout << endl;
      
        break;
    default:

        cout << "Invalid choice. Please enter a number between [1, 2, 3 ...]";
        break;
    }

}