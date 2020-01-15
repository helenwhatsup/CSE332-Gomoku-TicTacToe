#include "TTT.h"

TicTacToe::TicTacToe() {
	steps = 0;
	width = 5;
	height = 5;
	maxLength = 1;
	gameBoard = new string * [width];
	for (unsigned int i = 0; i < height; ++i) {
		gameBoard[i] = new string[height];
	}

	for (unsigned int i = 0; i < this->width; ++i) {
		for (unsigned int j = 0; j < this->height; ++j) {
			gameBoard[i][j] = " ";
		}
	}
	
	print();
}

void TicTacToe::print() {
	cout << *this;
}

//done method in pt.3

bool TicTacToe::done() {
	bool done = false;
	for (unsigned int x = 1; x < this->width - 1; x++) {
		for (unsigned int y = 1; y < this->height - 1; y++) {
			string temp = this->gameBoard[x][y];
			if (temp != " ") {
				if (temp == gameBoard[x - 1][y] && temp == gameBoard[x + 1][y]) {
					done = true;
				}
				else if (temp == gameBoard[x][y - 1] && temp == gameBoard[x][y + 1]) {
					done = true;
				}
				else if (temp == gameBoard[x - 1][y - 1] && temp == gameBoard[x + 1][y + 1]) {
					done = true;

				}
				else if (temp == gameBoard[x - 1][y + 1] && temp == gameBoard[x + 1][y - 1]) {
					done = true;
				}
			}

		}
	}

	return done;
}


//draw mthod in pt.3
bool TicTacToe::draw() {

	if (this->done()) {
		return false;
	}
	for (unsigned int y = 1; y < this->height - 1; y++) {
		for (unsigned int x = 1; x < this->width - 1; x++) {
			if (gameBoard[x][y] == " ") {
				return false;

			}
		}
	}
	return true;
}

//turn method in pt.3
int TicTacToe::turn() {
	unsigned int x, y;
	while (true) {
		int result = prompt(x, y);
		if (result == finished) {
			return finished;

		}
		if (x > width - 2 || y > height - 2 || x < 1 || y < 1) {
			print();//This is supposed to be in play()
			cout << endl << "coordinates out of bound, try with in range 1 to 3" << endl;

		}
		else if (gameBoard[x][y] != " ") {
			print();//This is supposed to be in play()
			cout << endl << "this spot has already been taken,try another one!" << endl;


		}
		else {
			break;
		}

	}
	if (steps % 2 == 0) {


		gameBoard[x][y] = "X";


		++this->steps;
		print();//This is supposed to be in play()
		cout << "player X: |";
		for (unsigned int i = 1; i < width - 1; ++i) {
			for (unsigned int c = 1; c < height - 1; ++c) {
				if (gameBoard[i][c] == "X") {

					cout << i << "," << c << "|";

				}
			}
		}
		cout << endl;

	}
	else {
		gameBoard[x][y] = "O";
		++this->steps;
		cout << *this << endl;
		cout << "player O: |";
		for (unsigned int i = 1; i < width - 1; ++i) {
			for (unsigned int c = 1; c < height - 1; ++c) {
				if (gameBoard[i][c] == "O") {

					cout << i << "," << c << "|";

				}
			}
		}
		cout << endl;
	}

	return succ;


}

//print the board
ostream& operator<<(ostream& out, const TicTacToe& t) {
	unsigned int seperation = t.maxLength + int(spacing);
	for (int i = t.height - 1; i >= 0; --i) {
		out << i;
		for (unsigned int c = 0; c < t.width; c++) {
			out.width(seperation); //formatting output
			out << t.gameBoard[c][i] << " ";
		}
		for (unsigned int line = 0; line < seperation - 1; ++line) {
			cout << endl; // shift line	
		}
	}
	out << " "; // left bottom 
	for (unsigned int i = 0; i < t.width; ++i) {
		out.width(seperation); //formatting output
		out << i << " ";
	}
	out << endl;

	return out;
}