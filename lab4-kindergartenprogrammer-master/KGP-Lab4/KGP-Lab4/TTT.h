#pragma once
#include "GB.h"

using namespace std;

class TicTacToe : public GameBase {
	friend ostream& operator<<(ostream& out, const TicTacToe& t);

public:
	TicTacToe();
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	virtual void print();
	
private:

	//string gameBoard[tttsize][tttsize];
	
	string display[displayP] = { "X","O" };

};
ostream& operator<<(ostream& out, const TicTacToe& t);
