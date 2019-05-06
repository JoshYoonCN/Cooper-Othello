#include "othello.h"

void clean(arr& Board){

	for (int row = 0; row < 10; row++){

		for (int col = 0; col < 10; col++){

			delete Board[row][col];
		}
	}

	return;

}

void possible(int id, arr& Board, arr& Board2){

	int row = 0, col = 0;

	for (row = 1; row < 9; row++){
		for (col = 1; col < 9; col++){

			copy_board(Board, Board2);

			if(space_valid(row, col, id, Board2, 0, 0)){

				Board[row][col]->p.unicode = "\33[0:35m\u25C7\33[0m";
			}
		}
	}

	return;
}

void clearPossible(arr&Board){

	int row = 0, col = 0;

	for (row = 1; row < 9; row++){
		for (col = 1; col < 9; col++){

			if (Board[row][col]->p.unicode == "\33[0:35m\u25C7\33[0m"){

				Board[row][col]->p.unicode = " ";
			}
		}
	}

	return;
}

int point(arr& Board){ // check how many points

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
	return (black - white);
}

int mid_points(arr& Board){

	int black = 0, white = 0;

	for (int i = 3; i < 7; i++){

		for (int j = 1; j < 7; j++){

			if (Board[i][j]->p.bOrW == 'B'){
				
				black++;
			}
			else if (Board[i][j]->p.bOrW == 'W'){
	
				white++;
			}
		}
	}

	return (black - white);
}

void points(arr& Board, int win){

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
	if (!win){

		cout << "       \33[0:36mBlack: " << black << "     " << "White: " << white << "\33[0m" << endl;
	}
	else {

		cout << "\33[0:36Black: " << black << ", White: " << white << endl;
		if (white > black){

			cout << "White Wins!!!" << endl;
		}
		else if (black > white){

			cout << "Black Wins!!!" << endl;
		}
		else {
			
			cout << "The Game is a Tie!!!" << endl;
		}
	}

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
	
	cout << "    1   2   3   4   5   6   7   8" << endl;	
	cout << "  \33[0:32m\u2553 \u2550 \u2566 \u2550 \u2566 \u2550 \u2566 \u2550 \u2566 \u2550 \u2566 \u2550 \u2566 \u2550 \u2566 \u2550 \u2557\33[0m" << endl;
	for (int i = 1; i < 8; i++){

		cout << i << " ";
		for (int j = 1; j < 9; j++){

			cout << "\33[0:32m\u2551\33[0m " << Board[i][j]->p.unicode << " ";
		}

		cout << "\33[0:32m\u2551\33[0m" << endl;

		cout << "  \33[0:32m\u2551 \u2550 \u256C \u2550 \u256C \u2550 \u256C \u2550 \u256C \u2550 \u256C \u2550 \u256C \u2550 \u256C \u2550 \u2551\33[0m" << endl;
	}

	cout << "8 ";

	for (int j = 1; j < 9; j++){

		cout << "\33[0:32m\u2551\33[0m " << Board[8][j]->p.unicode << " ";
	}

	cout << "\33[0:32m\u2551\33[0m" << endl;

	cout << "  \33[0:32m\u255A \u2550 \u2569 \u2550 \u2569 \u2550 \u2569 \u2550 \u2569 \u2550 \u2569 \u2550 \u2569 \u2550 \u2569 \u2550 \u255D\33[0m" << endl;

	return;
}


//2 board references - initialize 2nd board
// copy constructors to copy the spaces

void copy_board(arr& Board, arr& Board2){
	//cout << "initialize" << endl;
	init_board(Board2);
	for (int i = 1; i < 9; i++){

		for(int j = 1; j < 9; j++){

			*(Board2[i][j]) = *(Board[i][j]);
		}
	}

	//set boundary to easily check for edge of board
	for (int ii = 0; ii < 10; ii++){

		*(Board2[0][ii]) = (*(Board[0][ii]));
		*(Board2[9][ii]) = (*(Board[9][ii]));
	}

	for (int jj = 1; jj < 9; jj++){

		*(Board2[jj][0]) = (*(Board[jj][0]));
		*(Board2[jj][9]) = (*(Board[jj][9]));
	}
/*
	//set initial Board2 state
	Board2[4][4]->p.bOrW = 'W';
	Board2[4][4]->p.unicode = "\u25CF";
	Board2[4][5]->p.bOrW = 'B';
	Board2[4][5]->p.unicode = "\u25CB";
	Board2[5][4]->p.bOrW = 'B';
	Board2[5][4]->p.unicode = "\u25CB";
	Board2[5][5]->p.bOrW = 'W';
	Board2[5][5]->p.unicode = "\u25CF";
*/
	//print_board(Board2);
	return;

}
