KingdergartenProgrammer Lab 4
Group Member: 
1. Roger Wang( responsible for the tictactoe part)
2. Helen Jiang ( responsible for the gamebase part)
3. Andy Wang ( responsible for the gomoku part and extra credit)

Files Used in the final solution: 
GB.cpp
GB.h
gomoku.cpp
gomoku.h
Header.h
KGP-Lab4.cpp
TTT.cpp
TTT.h

Error We Encountered:
1. error caused by index out of bound of the vector in done method;
2. error caused by type mismatch: after changing the 'gameBoard' variable to type string we forgot to check the value it is comparing to in the if statement which were chars.

About Our Project:
	Generally, we followed the requirement of the lab instruction in delivering our implementations. 
	We declared a movesLeft instance variable in the gomoku class as a helper to the draw method.
	We are able to accomodate for the lower and upper case scenarios for gomoku and tictacto as well as the quit input. 




Test Case Scenarios we did: 

Case 1:
Input:	KGP-Lab4.exe
Output:	

--------------------------------------------
input is 1.Please enter Gomoku or TicTacToe.
--------------------------------------------

(Reasonalbe Behavior)
------------------------------------------------------------------------------------------------------------------------------------

Case 2:
Input: KGP-Lab4 gio
Output:

usage|KGP-Lab4.exe|: the name of the game (TicTacToe or Gomoku)

(Reasonalbe Behavior)
------------------------------------------------------------------------------------------------------------------------------------
Case 3:
Input: KGP-Lab4.exe
Output: 

19

 18

 17

 16

 15

 14

 13

 12

 11

 10

  9

  8

  7

  6

  5

  4

  3

  2

  1

  X  1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19

Please make your next move by inputting comma seperated coordinates such as 1,2 or 'quit' to end game
type 'quit' if you want to end game

(Reasonalbe Behavior)
------------------------------------------------------------------------------------------------------------------------------------

Case 4 : 
Input: KGP-Lab4.exe gomoku 
		19,19
Output:

 19                                                                          B

 18

 17

 16

 15

 14

 13

 12

 11

 10

  9

  8

  7

  6

  5

  4

  3

  2

  1

  X  1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19

player Black: |19,19|
-->-->-->-->-->-->-->-->-->-->-->-->-->-->
Player White's turn:
-->-->-->-->-->-->-->-->-->-->-->-->-->-->
Please make your next move by inputting comma seperated coordinates such as 1,2 or 'quit' to end game
type 'quit' if you want to end game


(reasonable behavior)
------------------------------------------------------------------------------------------------------------------------------------

Case 5:
Input: KGP-Lab4.exe gomoku 
		19,19
Output:

-----------------------------------------------
Invalid input: square is already occupied.
-----------------------------------------------

(reasonable behavior)
------------------------------------------------------------------------------------------------------------------------------------

Case 6: 

Input : KGP-Lab4.exe gomoku
		20,20
Output:

------------------------------------------------
Invalid input: out of bounds. Range from 1 to 19
------------------------------------------------

(reasonable behavior)
------------------------------------------------------------------------------------------------------------------------------------

Case 7:

Input: KGP-lab4.exe tictactoe
		0,0
Output: 
	coordinates out of bound, try with in range 1 to 3

(reasonable behavior)
------------------------------------------------------------------------------------------------------------------------------------

Case 8: 

Input: KGP-lab4.exe tictactoe
		1,1
Output: 
	4

3

2

1      X

0

   0   1   2   3   4
player X: |1,1|

(reasonable behavior)
------------------------------------------------------------------------------------------------------------------------------------

Case 9: 

Input: KGP-Lab4.exe gomoku
		10,1
Output:
19

 18

 17

 16

 15

 14

 13

 12

 11

 10

  9

  8

  7

  6

  5

  4

  3

  2

  1                                      B

  X  1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19

player Black: |10,1|
-->-->-->-->-->-->-->-->-->-->-->-->-->-->
Player White's turn:
-->-->-->-->-->-->-->-->-->-->-->-->-->-->

(reasonable behavior)
------------------------------------------------------------------------------------------------------------------------------------

Case 10:

Input :  KGP-Lab4.exe gomoku
		ab,1

Output:

	check for line format! please only put in number comma number!
Please make your next move by inputting comma seperated coordinates such as 1,2 or 'quit' to end game

(reasonable behavior)
------------------------------------------------------------------------------------------------------------------------------------
Case 11:

Input: KGP-Lab4.exe gomoku 
		1,,2,
Output:
	check for line format! please only put in number comma number!
Please make your next move by inputting comma seperated coordinates such as 1,2 or 'quit' to end game

(reasonable behavior)
------------------------------------------------------------------------------------------------------------------------------------




//extra credit features.
Design and implement:
We dynamically allocated the gameboard. 
Updated the maxLength to be adjusted with different boardsize.
Make a new constructors with passes in two integer parameters to adjust the size of the board.




Test cases:

1)

Gomoku 20 20
20
19
18
17
16
15
14
13
12
11
10
 9
 8
 7
 6
 5
 4
 3
 2
 1
 X 1 2 3 4 5 6 7 8 91011121314151617181920

Please make your next move by inputting comma seperated coordinates such as 1,2 or 'quit' to end game
type 'quit' if you want to end game



2) 
-------------------------------------------
We were questionable on req 37 which says " that the Gomoku game still plays as before the extra credit portion was added"
We thought "before the extra credit portion " means the origional gomoku gameboard with size 19.
-------------------------------------------
input: Gomoku 3
19
18
17
16
15
14
13
12
11
10
 9
 8
 7
 6
 5
 4
 3
 2
 1
 X 1 2 3 4 5 6 7 8 910111213141516171819


 3)
input: Gomoku 3 4
Error: winning length should be smaller than board size.
usage|H:\cse332\lab4-kindergartenprogrammer\KGP-Lab4\x64\Debug\KGP-Lab4.exe|: the name of the game (TicTacToe or Gomoku) (optional) board_size (optional) winning_length


4)
input:  gomoku 1,1
Error: board size is invalid.
usage|H:\cse332\lab4-kindergartenprogrammer\KGP-Lab4\x64\Debug\KGP-Lab4.exe|: the name of the game (TicTacToe or Gomoku) (optional) board_size (optional) winning_length


