#pragma once
#include "GB.h"
#include "Header.h"

class Gomoku : public GameBase {
	friend ostream& operator<<(ostream& out, const Gomoku& t);

public:

	Gomoku();
	Gomoku(int, int);
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	virtual void print();

private:

	unsigned int wins;

	unsigned int movesLeft = gmkMoves;	

	string gDisplay[displayP] = { "B","W" };

};

ostream& operator<<(ostream& out, const Gomoku& t);



