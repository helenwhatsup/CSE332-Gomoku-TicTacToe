#pragma once
#include <iostream>
#include "Header1.h"

using namespace std;



int main(int argc, char* argv[]) {


	if (argc != numofcommand) {
		cout << "wrong number of command" << endl;
		return usageMessage(argv[hello::program]);

	}

	string secondstring=argv[inputfile];

	if (secondstring != "TicTacToe") {
		cout << "error name" << endl;
		return hello::wrongname;
	}
	// Declare an object of the TicTacToe game class
	TicTacToe ttt;
	//Call the object's play() method, and use the result returned by that method as the program's return value.
	
	
	
	
	int gameresult = ttt.play();
	return gameresult;

}


