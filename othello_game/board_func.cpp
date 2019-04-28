#include "othello.h"

void points(arr& Board){

	int black = 0, white = 0;

	for (int i = 1; i < 9; i++){

		for (int j = 1; j < 9; j++){

			if (Board[i][j]->p.bOrW == 'B'){
				
				black++;
			}
			else if (Board[i][j]->p.bOrW == 'W'){

				white++;
			}
		}
	}

	cout << "Black has " << black << " points!" << endl;
	cout << "White has " << white << " points!" << endl;

	return;
}

int end_condition(arr& Board){

	int row = 0, col = 0, i, j;

	for (i = 1; i < 9; i++){
		
		for (j = 1; j < 9; j++){

			if (space_valid(row+i, col+j, 1, Board, 0, 0)){

				return 1;
			}
		}
	}
	
	for (i = 1; i < 9; i++){

		for (j = 1; j < 9; j++){

			if (space_valid(row+i, col+j, 1, Board, 0, 0)){

				return 1;
			}
		}
	}
	return 0;

}
//initialize board
void init_board(arr& Board){

	//create objects on heap, prevent overflow with "new"
	//initiliazing the board
	for (int i = 1; i < 9; i++){
		
		for(int j = 1; j < 9; j++){

			Board[i][j] = new Space(0, '-', " ");
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
	Board[4][4]->p.unicode = "\u25CF";	
	Board[4][5]->p.bOrW = 'B';	
	Board[4][5]->p.unicode = "\u25CB";
	Board[5][4]->p.bOrW = 'B';	
	Board[5][4]->p.unicode = "\u25CB";
	Board[5][5]->p.bOrW = 'W';	
	Board[5][5]->p.unicode = "\u25CF";
	return;
}

//print out board
void print_board(arr& Board){
	
	/*
	for(int j = 0; j < 8; j++){
		
		for(int k = 0; k < 8; k++){

			cout << Board[j+1][k+1]->p.unicode;
		}

		printf("\n");
	}*/

	cout << "\u2553 \u2550 \u2566 \u2550 \u2566 \u2550 \u2566 \u2550 \u2566 \u2550 \u2566 \u2550 \u2566 \u2550 \u2566 \u2550 \u2557" << endl;
	for (int i = 1; i < 8; i++){

		for (int j = 1; j < 9; j++){

			cout << "\u2551 " << Board[i][j]->p.unicode << " ";
		}
		
		cout << "\u2551" << endl;

		cout << "\u2551 \u2550 \u256C \u2550 \u256C \u2550 \u256C \u2550 \u256C \u2550 \u256C \u2550 \u256C \u2550 \u256C \u2550 \u2551" << endl;
	}

	for (int j = 1; j < 9; j++){

		cout << "\u2551 " << Board[8][j]->p.unicode << " ";
	}

	cout << "\u2551" << endl;

	cout << "\u255A \u2550 \u2569 \u2550 \u2569 \u2550 \u2569 \u2550 \u2569 \u2550 \u2569 \u2550 \u2569 \u2550 \u2569 \u2550 \u255D" << endl;

	return;
}
