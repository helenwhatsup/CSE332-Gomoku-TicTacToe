#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "Header1.h"

using namespace std;


//usageMessage
int usageMessage(char* program) {
	cout << "error" << "<numofcommand>" << endl;
	cout << "usage: " << program << "<TicTacToe>" << endl;
	return hello::wrongargument;
}

// insertion operator (operator<<)
ostream& operator<<(ostream& result, const TicTacToe& game) {
	cout << endl;
	for (int j = dimension - 1; j >= 0; --j) {
		if ((j > 0) && (j < dimension - 1)) {
			result << j << "   ";
			for (int i = 1; i < dimension - 1; ++i) {
				if (game.board[i][j] != ' ') {
					result << game.board[i][j] << " ";
				}
				else {
					result << "  ";
				}
			}
			result << endl;
		}
		else {
			result << j << endl;
		}
	}
	result << "  ";
	for (int i = 0; i < dimension; ++i) {
		result << i << " ";
	}
	result << endl;
	return result;
}

//Constructor
TicTacToe::TicTacToe() {
	for (int row = 0; row <= gamepram::dimension - 1; row++) {// print out the  board
		for (int column = 0; column <= gamepram::dimension - 1; column++) {
			board[row][column] = empty;
		}
	}
	cout << "Tic Tac Toe start" << endl;
	cout << *this << endl;
}
// 6.5 This method should return true if 3-Xs or Os are in a vertical, horizontal or diagonal line; 
//otherwise the method should return false.
bool TicTacToe::done() {
	if (board[1][1] != empty && board[2][2] != empty && board[3][3] != empty) {
		if ((board[1][1] == board[2][2]) && (board[2][2] == board[3][3])) {
			if (board[1][1] == px) {
				xvictory = true;
				return xvictory;
			}
			else if (board[1][1] == po) {
				
				ovictory = true;
				return ovictory;
			}
		}
	}
	// 13,22,31
	if (board[1][3] != empty && board[2][2] != empty && board[3][1] != empty) {
		if ((board[1][3] == board[2][2]) && (board[2][2] == board[3][1])) {
			if (board[1][3] == px) {
				xvictory = true;
				return xvictory;
				cout << "player x wins!" << endl;
			}
			else if (board[1][3] == po) {
				ovictory = true;
				return ovictory;
				cout << "player o wins!" << endl;
			}
		}
	}
	//check rows
	for (int row = 1; row < gamepram::dimension - 1; row++) {
		if (board[row][1] != empty && board[row][2] != empty && board[row][3] != empty) {
			if ((board[row][1] == board[row][2]) && (board[row][2] == board[row][3])) {
				if (board[row][1] == px) {
					xvictory = true;
					return xvictory;
					cout << "player x wins!" << endl;
				}
				else if (board[row][1] == po) {
					ovictory = true;
					return ovictory;
					cout << "player o wins!" << endl;
				}
			}
		}
	}
		//check columns
		for (int col = 1; col < gamepram::dimension - 1; col++) {
			if (board[1][col] != empty && board[2][col] != empty && board[3][col] != empty) {
				if (board[1][col] == board[2][col] && board[2][col] == board[3][col]) {
					if (board[1][col] == px) {
						xvictory = true;
						return xvictory;
						cout << "player x wins!" << endl;
					}
					else if (board[1][col] == po) {
						ovictory = true;
						return ovictory;
						cout << "player o wins!" << endl;
					}
				}
			}
		}
	
	return success;
}
//6.6 
// return false if there are moves remaining in the game(as defined below) or if the done() method returns true;
//otherwise the draw() method should return true.
bool TicTacToe::draw() {
	bool status = true;
	if (done() == true) {
		return false;
	}
	else if (moves != 0) {
		return false;
	}
	else {
		return true;
	}
}


//6.7 
int TicTacToe::prompt(unsigned int& row, unsigned int& col) {
	string input;
	bool valid = false;
	bool quit = false;
	//wrap the string
	
	while (valid == false) {
		cout << "quit the game by entering 'quit' or enter a valid coordinate of the format 'a,b'" << endl;
		cin >> input;
		//replace comma with space
		for (unsigned int i = 0; i < input.size(); i++) {
			if (input[i] == ',') {
				input[i] = ' ';
			}
		}
		istringstream iss(input);

		if (input == "quit") {
			this->quit = true;
			return status::quitgame;
		}

		else {
			if (iss >> row) {
				if (iss >> col) {
					if ( (row > gamepram::dimension - 1)&& (col > gamepram::dimension - 1)|| (row<1)&&(col<1)|| (row<1)&&(col>1) ||(row>1)&&(col<1)) {
						cout << "both row and column index out of bound" << endl;
					}
					
					else if (row > 0 && row < gamepram::dimension - 1) {
						if (col > 0 && col < gamepram::dimension - 1) {
							if (board[row][col] == empty) {
								valid = true;
								return valid;
								cout << "the string is valid" << endl;
							}
							else {
								cout << "the position is already taken" << endl;
							}
						}
						else {
							cout << "column index out of bound" << endl;
						}
					}
					else {
						cout << "row index out of bound" << endl;
					}
				}
				else {
					cout << "can not receive column information" << endl;
				}
			}
			else {
				cout << "can not receive row information " << endl;
			}
		}
		
	}
	return status::success;
}




// 6.7 Turn

int TicTacToe::turn() {
	bool validmove = false;
	unsigned int row1;
	unsigned int col1;

	while (done() == false && moves != 0) {
		if (prompt(row1, col1) == status::quitgame) {
			return status::quitgame;
		}

		//O turn
		if (moves % 2 == 0) {
			board[row1][col1] = 'O';
			cout << *this;
			cout << "Current Player: player O's turn" << endl;
		for (int row1 = 1; row1 <= corner; row1++) {
				for (int col1 = 1; col1 <= corner; col1++){
					if (board[row1][col1] == 'O') {	
						cout << row1 << ',' << col1 << endl;	
					}
					}
				}
			if (done() == true) {
				return status::success;
			}
			moves--;	
		}
		// X turn
		else if (moves % 2 == 1) {
			board[row1][col1] = 'X';
			cout << *this;
			cout << "Current Player: player X's turn" << endl;
			for (int row1 = 1; row1 <= corner; row1++) {
				for (int col1 = 1; col1 <= corner; col1++) {
					if (board[row1][col1] == 'X') {
						cout << row1 << ',' << col1 << endl;
					}
				}
			}
			if (done() == true) {
				return status::success;
			}
			moves--;
		}
	}
	return success;
}
//6.7
int TicTacToe::play() {
	
	while (done() != true && draw() != true && quit!= true) {
		turn();
	}
	int turns = totalmoves - moves;
	//check done method
	if (done() == true) {
		if (xvictory == true) {
			cout << "player X wins" << endl;
			return status::success;
		}
		else if (ovictory == true) {
			cout << "player O wins" << endl;
			return status::success;
		}
	}
	//someone quit
	else if (draw() == true) {
		cout << "The game is a draw, the turns is " << turns << endl;
		return status::draw_case;
	}
	else if (quit == true) {
		
			cout << "someone quit the game,the turns is " << turns << endl;
		
		return status::quitgame;
	}
	return success;
}





