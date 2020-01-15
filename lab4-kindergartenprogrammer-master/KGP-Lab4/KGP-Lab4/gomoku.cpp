#include "gomoku.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
//gomoku constructor
Gomoku::Gomoku() {
	steps = 0;
	wins = 5;
	maxLength = this->width / 10 + 1;
	this->width = gomokusize; // boardSide is enum, not defineed yet
	this->height = gomokusize;
	gameBoard = new string * [width];
	for (unsigned int i = 0; i < height; ++i) {
		gameBoard[i] = new string[height];
	}
	for (unsigned x = 0; x < this->width; ++x) {
		for (unsigned y = 0; y < this->height; ++y) {
			gameBoard[x][y] = " ";
		}
	}
	cout << *this << endl;
}

Gomoku::Gomoku(int bDim, int winSize) {
	steps = 0;
	maxLength = this->width / 10 + 1;
	this->width = bDim;
	this->height = bDim;
	this->wins = winSize;
	gameBoard = new string * [width];
	for (unsigned int i = 0; i < height; ++i) {
		gameBoard[i] = new string[height];
	}
	
	for (unsigned x = 0; x < this->width; ++x) {
		for (unsigned y = 0; y < this->height; ++y) {
			gameBoard[x][y] = " ";
		}
	}
	cout << *this << endl;
}

//insertion operator
ostream& operator<<(ostream& out, const Gomoku& g) {
	unsigned int seperation = g.maxLength + int(spacing);
	for (int i = g.height - 1; i >= 0; --i) {
		out.width(seperation);
		out << i + 1;
		for (unsigned int c = 0; c < g.width; ++c) {
			out.width(seperation); //formatting output
			out << g.gameBoard[c][i];
		}
		for (unsigned int line = 0; line < seperation - 1; ++line) {
			cout << endl; // shift line	
		}
	}
	out.width(seperation);
	out << "X";  // left bottom 
	for (unsigned int i = 0; i < g.width; ++i) {
		out.width(seperation); //formatting output
		out << i + 1;
	}
	out << endl;

	return out;
}


//print method
void Gomoku::print() {
	cout << *this << endl;
}

//done method
bool Gomoku::done() {
	Gomoku* player = this;
	unsigned int xcoor = player->width;
	unsigned int ycoor = player->height;
	for (unsigned int a = 0; a < player->height; ++a) {
		for (unsigned int b = 0; b < player->width; ++b) {
			if (gameBoard[a][b] != " ") {
				string stone = gameBoard[a][b];
				unsigned int key = 1;
				//horizontal
				while ((a + key) < xcoor && gameBoard[a + key][b] == stone) {
					key = key + 1;
					if (key == wins) {
						return true;
					}
				}

				key = 1;
				//vertical
				while ((b + key) < ycoor && gameBoard[a][b + key] == stone) {
					key = key + 1;
					if (key == wins) {
						return true;
					}
				}

				key = 1;
				//left diagnoal
				while ((a + key) < xcoor && (b + key) < ycoor && gameBoard[a + key][b + key] == stone) {
					key++;
					if (key == wins) {
						return true;
					}
				}
				key = 1;

				// right diagonal
				while ((a - key + 1) > 0 && (b + key) < ycoor && gameBoard[a - key][b + key] == stone) {
					key++;
					if (key == wins) {
						return true;
					}
				}
			}
		}
	}
	return false;

}

//draw method
bool Gomoku::draw() {
	Gomoku* player = this;
	unsigned int xcoor = player->width;
	unsigned int ycoor = player->height;
	if (this->done() == true) {
		return false;
	}
	else if (movesLeft == 0) {

		return true;
	}
	return false;
}

//play method
int Gomoku::turn() {
	unsigned int x, y;
	unsigned int realX, realY;
	while (true) {
		int result = prompt(x, y);
		realX = x - 1;
		realY = y - 1;
		if (result == finished) {
			return finished;
		}
		if (x > this->width || y > this->height || x < 1 || y < 1) {
			print();//This is supposed to be in play()
			cout << "------------------------------------------------" << endl;
			cout << "Invalid input: out of bounds. Range from 1 to " << this->width << endl;
			cout << "------------------------------------------------" << endl;

		}
		else if (gameBoard[realX][realY] != " ") {
			print();//This is supposed to be in play()
			cout << "-----------------------------------------------" << endl;
			cout << "Invalid input: square is already occupied." << endl;
			cout << "-----------------------------------------------" << endl;
		}
		else {
			break;
		}

	}
	if (steps % 2 == 0) {
		gameBoard[realX][realY] = "B";
		--movesLeft; // decrease moves left to help draw()
		++this->steps;
		this->print(); // This is supposed to be in play()
		cout << "player Black: |";
		for (unsigned int i = 0; i < this->width; ++i) {
			for (unsigned int c = 0; c < this->height; ++c) {
				if (gameBoard[i][c] == "B") {

					cout << i + 1 << "," << c + 1 << "|";

				}
			}
		}
		cout << endl;
		if (!done()) {
			cout << "-->-->-->-->-->-->-->-->-->-->-->-->-->-->" << endl;
			cout << "Player White's turn:" << endl;
			cout << "-->-->-->-->-->-->-->-->-->-->-->-->-->-->" << endl;
		}
	}
	else {
		gameBoard[realX][realY] = "W";
		--movesLeft; // decrease moves left to help draw()
		++this->steps;
		this->print();
		cout << "player White: |";
		for (unsigned int i = 0; i < this->width; ++i) {
			for (unsigned int c = 0; c < this->height; ++c) {
				if (gameBoard[i][c] == "W") {

					cout << i + 1 << "," << c + 1 << "|";

				}
			}
		}
		cout << endl;
		if (!done()) {
			cout << "-->-->-->-->-->-->-->-->-->-->-->-->-->-->" << endl;
			cout << "Player Black's turn:" << endl;
			cout << "-->-->-->-->-->-->-->-->-->-->-->-->-->-->" << endl;
		}
	}

	return succ;


}

