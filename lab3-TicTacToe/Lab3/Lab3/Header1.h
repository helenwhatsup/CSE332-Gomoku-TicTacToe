#pragma once
#include <vector>
#include <string>
#include <fstream>
using namespace std;


enum hello { program = 0, inputfile = 1, numofcommand = 2, wrongargument = 3, wrongname = 4 };


enum status {
	success = 0,
	failure = 1,
	quitgame = 2,
	fail_to_draw = 2,
	invalid_input = 3,
	draw_case = 4,

};

enum gamepram {
	corner = 3, dimension = 5, totalmoves = 9, 
};

class TicTacToe {
private:
	char board[5][5];
	int moves=9;
	char px = 'X';
	char po = 'O';
	char empty = ' ';
	bool xvictory = false;
	bool ovictory = false;
	bool quit = false;
	bool validmove=false;

public:
	TicTacToe();
	bool done();
	bool draw();
	int turn();
	int play(); 
	int prompt(unsigned int&, unsigned int&);

	friend ostream& operator<< (ostream& output, const TicTacToe& game);

};

ostream& operator<< (ostream& output, const TicTacToe& game);

int usageMessage(char* program);
