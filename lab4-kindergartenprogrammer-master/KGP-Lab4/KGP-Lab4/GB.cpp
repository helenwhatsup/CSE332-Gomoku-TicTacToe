

#include "GB.h"
#include "Header.h"
#include "stdio.h"
#include "gomoku.h"
#include "TTT.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//prompt method
int GameBase::prompt(unsigned int& x, unsigned int& y) {
	string act = "";
	while (true) {
		cout << "Please make your next move by inputting comma seperated coordinates such as 1,2 or 'quit' to end game" << endl;
		cout << "type 'quit' if you want to end game" << endl;

		getline(cin, act);
		act = toLowerCase(act);
		if (act == "quit")
		{
			return finished;
		}
		else
		{
			// check for "," position
			if ( (act.find(",") != string::npos)) {
				act[act.find(",")] = ' ';
				istringstream iss(act);
				unsigned int j;
				int c = 0;
				int ips[input]; // input is the dimension of the coordinate system
				while (c<input && iss >> j) {
					ips[c++] = j;

				}

				if (c == input) {
					x = ips[firstNum];
					y = ips[secNum];

					break;
				}
			}

			cout << endl;
			cout << "check for line format! please only put in number comma number!" << endl;


		}

	}



	return succ;

}


//play method in pt.2

int GameBase::play() {
	while (done() == false) {
		int status = turn();
		if (status != succ) {
			cout << "After " << this->steps << " turns, the user quit" << endl;
			for (unsigned int i = 0; i < height; ++i) {
				delete[] gameBoard[i];
			}
			delete[] gameBoard;
			return finished;
		}

		if (draw()) {
			cout << "After " << this->steps << " turns, the game ended with a draw" << endl;
			for (unsigned int i = 0; i < height; ++i) {
				delete[] gameBoard[i];
			}
			delete[] gameBoard;
			return drawed;
		}
		if (done()) {
			break;
		}
	}

	if (steps % 2 == 0) {
		cout << "After " << this->steps << " turns, the game ended with: " << endl;
		cout << "-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->" << endl;
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Player 2:White won!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		cout << "-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->" << endl;
	}
	else {
		cout << "After " << this->steps << " turns, the game ended with: " << endl;
		cout << "-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->" << endl;
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Player 1: Black won!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		cout << "-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->-->" << endl;
	}
	for (unsigned int i = 0; i < height; ++i) {
		delete[] gameBoard[i];
	}
	delete[] gameBoard;
	return succ;

}

bool GameBase::checkValid(unsigned int xC, unsigned int yC) {


	if (xC <= 0 || xC >= this->width - 1 || yC <= 0 || yC >= this->height - 1) {
		return false;
	}

	return true;

}

//main method
GameBase* GameBase::apple(int a, char* b[]) {
	GameBase* p = 0;
	if (a == argumenterr) {
		return p;
	}
	string gameName = toLowerCase(string(b[inputName]));
	if (a == expN) {
		if (gameName == titato) {
			TicTacToe* newGame = new TicTacToe();
			return newGame;
		}
		else if (gameName == gmk) {
			Gomoku* newGame = new Gomoku();
			return newGame;
		}

		return p;
	}

	else if (a == cusN) {
		unsigned int d = 0;
		if (checkNum(b[dimInput])) {
			istringstream dss(b[dimInput]);

			dss >> d;

			if (d < 3) {
				cout << "Error: board size is invalid." << endl;
				return p;
			}

			else if (d == 3) {
				Gomoku* newGame = new Gomoku();
				return newGame;
			}

			else if (gameName == gmk) {
				Gomoku* newGame = new Gomoku(d, tttsize);
				return newGame;
			}
		}
		return p;
	}

	else if (a == customN) {
		unsigned int d = 0;
		unsigned int w = 0;

		if (checkNum(b[dimInput]) && checkNum(b[winInput])) {
			istringstream dss(b[dimInput]);
			istringstream wss(b[winInput]);

			dss >> d;
			wss >> w;

			if (d < 3 || w > d) {
				if (d < 3) {
					cout << "Error: board size is invalid." << endl;
				}
				if (w > d) {
					cout << "Error: winning length should be smaller than board size." << endl;
				}
				return p;
			}

			if (d == 3 && w == 3) {
				Gomoku* newGame = new Gomoku();
				return newGame;
			}

			if (gameName == titato) {
				TicTacToe* newGame = new TicTacToe();
				return newGame;
			}
			else if (gameName == gmk) {
				Gomoku* newGame = new Gomoku(d, w);
				return newGame;
			}
		}
		return p;
	}
	else {
		return p;
	}


}