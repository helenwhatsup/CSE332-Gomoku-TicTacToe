#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Header.h"
using namespace std;

enum boardDim{ width = 5, height = 5};

enum indexes {displayP = 2};


class GameBase {
public:

	virtual bool done() = 0;
	virtual bool draw() = 0;
	virtual int turn() = 0;
	virtual void print() = 0;
	int prompt(unsigned int& a, unsigned int& b);
	int play();
	bool checkValid(unsigned int xC, unsigned int yC);
	static GameBase* apple(int a, char* b[]);

protected:
	string** gameBoard;
	unsigned int width = 0;
	unsigned int height = 0;
	
		
	unsigned int steps = 0; // total steps taken in the game
	unsigned int maxLength = 1;	// update to be the longest display string length of any piece on board
	

};
