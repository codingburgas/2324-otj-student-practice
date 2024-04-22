#include "MainMenu.h"
void ascii() {


	// Set the text color to bright blue using ANSI escape sequence
	cout << "\u001b[34;1m";
	

	ifstream file("../ascii.txt");

	string line;
	while (getline(file, line)) {
		cout << line << std::endl;
	}
	cout << "\033[0m";
	file.close();
	cout << endl;
	cout << endl;
	cout << endl;
}
