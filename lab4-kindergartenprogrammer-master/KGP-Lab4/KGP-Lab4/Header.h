#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;

enum sf { succ = 0, argumenterr, outOfValidRange, finished, spotNotAva, draw, badAlloc, noValue = 0, drawed = 8 };

enum index { projectName, inputName, expN, cusN = 3, customN = 4, dimInput = 2, winInput = 3, firstNum = 0, secNum = 1 };

enum format { spacing = 1, tttDim = 3, input = 2, gmkDim = 5 };


enum boardSize {
	first = 1,
	tttsize = 5,
	tttmoves = 9,
	gomokusize = 19,
	gmkMoves = 361
};

int usageHelper(char* name);

string toLowerCase(string& str);

bool checkNum(const string& a);

const string gmk = "gomoku";

const string titato = "tictactoe";