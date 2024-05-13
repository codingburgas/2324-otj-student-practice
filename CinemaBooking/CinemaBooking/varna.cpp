#include "../ProjectDll/front-end.h"
#include "../ProjectDll/main.h"

void Varna() {
    int choise;

    system("cls");
    string address = "../../FrontEnd-Captions/VarnaCaption.txt";
    print(address);

    cin >> choise;

    switch (choise) {
    case 1:
        //The Godfather();
        break;
    case 2:
        //Angry Men();
        break;
    case 3:
        //The Dark Knight();
    case 4:
        //Pulp Fiction();   
        break;
    case 5:
        //Fight Club();
    case 6:
        menu();
        break;
    default:

        cout << "Invalid choice. Please enter a number between [1, 2, 3 ...]";
        break;
    }

}
