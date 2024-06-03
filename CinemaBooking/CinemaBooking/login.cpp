#include "../ProjectDll/login.h"
#include "../ProjectDll/front-end.h"
#include "../ProjectDll/main.h"

void login() {
    UserManager userManager;
    int choice;
    string username, password;

    while (true) {
        system("cls");
        string address = "../../FrontEnd-Captions/LoginCaption.txt";
        string address1 = "../../FrontEnd-Captions/LoginCaption1.txt";
        print(address);

        cin >> choice;

        if (choice == 1) {
            system("cls");
            print(address1);
            cout << setw(124)<< "Enter username: ";
            cin >> username;
            cout << setw(124) << "Enter password: ";
            cin >> password;

            if (userManager.registerUser(username, password)) {
                system("cls");
                print(address);
                cout << "Registration successful!" << endl;
            }
            else if (!userManager.loginUser(username, password)) {
                cout << "Username already exists. Try again." << endl;

            }
        }
        else if (choice == 2) {
            system("cls");
            print(address1);
            cout << setw(124) << "Enter username: ";
            cin >> username;
            cout << setw(124) << "Enter password: ";
            cin >> password;

            if (userManager.loginUser(username, password)) {
                menu();
                
            }
            else {
                cout << "Invalid username or password. Try again." << endl;
           
            }
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
            
        }
    }
}