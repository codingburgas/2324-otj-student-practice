#include "../ProjectDll/login.h"
#include "../ProjectDll/front-end.h"
#include "../ProjectDll/main.h"

void pause() {
    cout << setw(131) << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}

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
        cin.ignore();

        switch (choice) {
        case 1:
            system("cls");
            print(address1);
            cout << setw(124) << "Enter username: ";
            cin >> username;
            cout << setw(124) << "Enter password: ";
            cin >> password;
            if (userManager.registerUser(username, password)) {
                cout << setw(130) << "Registration successful!" << endl;
            }
            else {
                cout << setw(129) << "Username already exists!" << endl;
            }
            pause();
            break;

        case 2:
            system("cls");
            print(address1);
            cout << setw(124) << "Enter username: ";
            cin >> username;
            cout << setw(124) << "Enter password: ";
            cin >> password;
            if (userManager.loginUser(username, password)) {
                cout << setw(126) << "Login successful!" << endl;
                pause();
                menu();
            }
            else {
                cout << setw(133) << "Invalid username or password!" << endl;
            }
            pause();
            break;

        case 3:
            return;

        default:
            cout << setw(134) << "Invalid choice! Please try again." << endl;
            pause();
        }
    }
}