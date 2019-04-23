#include <iostream>
#include <string>
#include <vector>
#include <header.h>

using namespace std;

//not sure if this is necessary just yet
/*
class Board{
public:

	Board () {}

	~Board () {}


}*/

//initialize board
void init_board(){
	//create objects on heap, prevent overflow with "new"
	//initiliazing the board
	for (int i = 1; i < 9; i++){
		for(int j = 1; j < 9; j++){
			Board[i][j] = new Space(0, '-');
		}
	}

	//set boundary to easily check for edge of board
	for (int ii = 0; ii < 10; ii++){
		Board[0][ii] = new Space(0, '+');
		Board[9][ii] = new Space(0, '+');
	}

	for (int jj = 1; jj < 9; jj++){
		Board[jj][0] = new Space(0, '+');
		Board[jj][9] = new Space(0, '+');
	}

	//set initial board state
	Board[4][4]->p.bOrW = 'W';
	Board[4][5]->p.bOrW = 'B';
	Board[5][4]->p.bOrW = 'B';
	Board[5][5]->p.bOrW = 'W';

	return;
}

//print out board
void print_board(){
	for(int j = 0; j < 8; j++){
		for(int k = 0; k < 8; k++){
			cout << Board[j+1][k+1]->p.bOrW;
		}
		printf("\n");
	}
	return;
}
