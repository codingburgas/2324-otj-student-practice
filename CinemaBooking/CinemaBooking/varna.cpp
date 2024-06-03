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
        //TheGodfather();
        break;
    case 2:
        //AngryMen();
        break;
    case 3:
        //TheDarkKnight();
    case 4:
        //PulpFiction();   
        break;
    case 5:
        //FightClub();
    case 6:
        menu();
        break;
    default:

        cout << "Invalid choice. Please enter a number between [1, 2, 3 ...]";
        break;
    }

}
