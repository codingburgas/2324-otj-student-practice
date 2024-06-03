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
        //GhostBusters();
        break;
    case 2:
        //Avengers();
        break;
    case 3:
        //Dune();
    case 4:
        //Titanic();   
        break;
    case 5:
        //Abagail();
    case 6:
        menu();
        break;
    default:

        cout << "Invalid choice. Please enter a number between [1, 2, 3 ...]";
        break;
    }

}


