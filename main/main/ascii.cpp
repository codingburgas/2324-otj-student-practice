#include "MainMenu.h"
void ascii() {


	// Set the text color to bright blue using ANSI escape sequence
	cout << "\033[1;94m";
	int screenWidthASCII = 90; // Adjust this value according to your desired screen width
	cout << endl;

	cout << setw(screenWidthASCII / 2 + 34) << "     ________  _____  _____     ____    ____  _________     _       ______   _________  _____   ______  " << endl;
	cout << setw(screenWidthASCII / 2 + 34) << "    |_   __  ||_   _||_   _|   |_   \\  /   _||  _   _  |   / \\    .' ____ \\ |  _   _  ||_   _|.' ___  | " << endl;
	cout << setw(screenWidthASCII / 2 + 34) << "      | |_ \\_|  | |    | |       |   \\/   |  |_/ | | \\_|  / _ \\   | (___ \\_||_/ | | \\_|  | | / .'   \\_| " << endl;
	cout << setw(screenWidthASCII / 2 + 34) << "      |  _|     | |    | |   _   | |\\  /| |      | |     / ___ \\   _.____`.     | |      | | | |        " << endl;
	cout << setw(screenWidthASCII / 2 + 34) << "     _| |_     _| |_  _| |__/ | _| |_\\/_| |_    _| |_  _/ /   \\ \\_| \\____) |   _| |_    _| |_\\ `.___.'\\ " << endl;
	cout << setw(screenWidthASCII / 2 + 34) << "    |_____|   |_____||________||_____||_____|  |_____||____| |____|\\______.'  |_____|  |_____|\`.____ .'" << endl;

	// Reset the text color to the default
	cout << "\033[0m";

	cout << endl;
	cout << endl;
	cout << endl;
}