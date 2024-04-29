#include "../ProjectDll/main.h"
#include "../ProjectDll/front-end.h"

void Burgas() {
    int choise;

    system("cls");
    string address = "../../FrontEnd-Captions/BurgasCaption.txt";
    print(address);
    
    cin >> choise;

    switch (choise) {
    case 1:
        //Abagail();
        break;
    case 2:
        //Back to Black();
        break;
    case 3:
        //Ghost Busters();
        cout << endl;
        break;
    default:

        cout << "Invalid choice. Please enter a number between 1 and 3";
        break;
    }

}


