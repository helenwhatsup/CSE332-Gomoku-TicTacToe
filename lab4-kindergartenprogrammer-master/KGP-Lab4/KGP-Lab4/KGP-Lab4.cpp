// KGP-Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "TTT.h"
#include "GB.h"
using namespace std;

bool extra = true;

int usageHelper(char* name) {

	cout << "usage|" << name << "|: the name of the game (TicTacToe or Gomoku) (optional) board_size (optional) winning_length " << endl;
	return argumenterr;

}

bool checkNum(const string& a) {
	for (unsigned int i = 0; i < a.length(); i++) {
		if (!isdigit(a[i])) {
			return false;
		}
	}
	return true;
}

string toLowerCase(string& str) {

	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (str[i] <= 90 && str[i] >= 65) {
			str[i] = str[i] + 32;


		}
		else {
			continue;
		}
	}

	return str;

}

int main(int argc, char* argv[])

{

	GameBase* p = 0;

	try {
		p = GameBase::apple(argc, argv);
	}
	catch (...) { cout << "Error: Dynamic allocation malfunction." << endl; }
	if (p == nullptr) {
		if ((argc < expN) || (argc > customN)) {
			cout << "--------------------------------------------" << endl;
			cout << "Error: input number is invalid.Please enter Gomoku or TicTacToe with optional game board dimensions and winning length." << endl;
			cout << "--------------------------------------------" << endl;
			return argumenterr;
		}

		else {
			int result = usageHelper(argv[projectName]);
			return argumenterr;
		}


	}

	else {


		int result = p->play();
		delete p;
		return result;

	}


	return succ;


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
