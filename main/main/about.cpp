#include "MainMenu.h"
void about() {
	ascii();
	cout << setw(55) << "" << "About Us" <<endl;
	cout << endl;

	ifstream file("../about.txt");

	string line;
	while (getline(file, line)) {
		cout << line << std::endl;
	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << setw(40) << "" << "Press any key to go back: ";
	int anykey;
	cin >> anykey;
	switch (anykey) {
	case 0:
		system("CLS");
		main();
		break;
	default:
		system("CLS");
		main();
	}

	
}