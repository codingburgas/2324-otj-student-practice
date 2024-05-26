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
        print(address);
        cin >> choice;

        if (choice == 1) {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            if (userManager.registerUser(username, password)) {
                cout << "Registration successful!" << endl;
            }
            else {
                cout << "Username already exists. Try again." << endl;
            }
        }
        else if (choice == 2) {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            if (userManager.loginUser(username, password)) {
                cout << "Login successful!" << endl;
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