#include "../ProjectDll/front-end.h"
#include "../ProjectDll/main.h"

void Sofia() {
    int choise;

    system("cls");
    string address = "../../FrontEnd-Captions/SofiaCaption.txt";
    print(address);

    cin >> choise;

    switch (choise) {
    case 1:
        //Godzilla();
        break;
    case 2:
        //ColorsOfEvil();
        break;
    case 3:
        //Ouija();
    case 4:
        //IrishWish();   
        break;
    case 5:
        //TheCroods();
    case 6:
        menu();
        break;
    default:

        cout << "Invalid choice. Please enter a number between [1, 2, 3 ...]";
        break;
    }

}
