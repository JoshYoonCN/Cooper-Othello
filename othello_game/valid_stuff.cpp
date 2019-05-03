#include "othello.h"

//white is player 1, black is player 2
//check if space is valid
int space_valid(int row, int col, int id, arr& Board, int c_or_p, int flip){

	int valid = 0;

	//this initial statement checks for whether the space player chose is occupied
	char c = Board[row][col]->p.bOrW;

	if (c == 'B' || c == 'W'){

		if (c_or_p == 1){
			cout << "That space is occupied!" << endl;
		}

		return 0;
	}

	//these series of if statements (try to optimize later!) check around the player's input in order to check for a legal move
	//can optimize by returning the result of propagate directly
	if (id == 1){

		if (Board[row+1][col]->p.bOrW == 'W'){

			if(propagate(row, col, 1, 0, id, Board, flip)){

				valid++;
			}
		}
		if (Board[row][col-1]->p.bOrW == 'W'){

			if(propagate(row, col, 0, -1, id, Board, flip)){

				valid++;
			}
		}
		if (Board[row][col+1]->p.bOrW == 'W'){

			if(propagate(row, col, 0, 1, id, Board, flip)){

				valid++;
			}
		}
		if (Board[row-1][col]->p.bOrW == 'W'){

			if(propagate(row, col, -1, 0, id, Board, flip)){

				valid++;
			}
		}
		if (Board[row-1][col-1]->p.bOrW == 'W'){

			if(propagate(row, col, -1, -1, id, Board, flip)){

				valid++;
			}
		}
		if (Board[row-1][col+1]->p.bOrW == 'W'){

			if(propagate(row, col, -1, 1, id, Board, flip)){

				valid++;
			}
		}
		if (Board[row+1][col-1]->p.bOrW == 'W'){

			if(propagate(row, col, 1, -1, id, Board, flip)){

				valid++;
			}
		}
		if (Board[row+1][col+1]->p.bOrW == 'W'){

			if(propagate(row, col, 1, 1, id, Board, flip)){

				valid++;
			}
		}

	}

	//if player 2, switch to checking for black pieces
	//check all 8 spaces around the space you are in
	if (id == 2){

		if (Board[row+1][col]->p.bOrW == 'B'){

			if(propagate(row, col, 1, 0, id, Board, flip)){

				valid++;
			}
		}
		if (Board[row][col-1]->p.bOrW == 'B'){

			if(propagate(row, col, 0, -1, id, Board, flip)){

				valid++;
			}
		}
		if (Board[row][col+1]->p.bOrW == 'B'){

			if(propagate(row, col, 0, 1, id, Board, flip)){

				valid++;
			}
		}
		if (Board[row-1][col]->p.bOrW == 'B'){

			if(propagate(row, col, -1, 0, id, Board, flip)){

				valid++;
			}
		}
		if (Board[row-1][col-1]->p.bOrW == 'B'){

			if(propagate(row, col, -1, -1, id, Board, flip)){

				valid++;
			}
		}
		if (Board[row-1][col+1]->p.bOrW == 'B'){

			if(propagate(row, col, -1, 1, id, Board, flip)){

				valid++;
			}
		}
		if (Board[row+1][col-1]->p.bOrW == 'B'){

			if(propagate(row, col, 1, -1, id, Board, flip)){

				valid++;
			}
		}
		if (Board[row+1][col+1]->p.bOrW == 'B'){

			if(propagate(row, col, 1, 1, id, Board, flip)){

				valid++;
			}
		}
	}

	if (valid){

		return 1;
	}
	//if all the above fails, means the move is not valid
	if (c_or_p == 1){
		cout << "That space is not valid!" << endl;
	}

	return 0;
}

//check if the user row input is valid
int row_input_valid(int input){

	if (input < 1 || input > 8){

		cout << "Please enter a valid row!" << endl;
		return 0;
	}

	return 1;

}

//check if the user column input is valid
int col_input_valid(int input){

	if (input < 1 || input > 8){

		cout << "Please enter a valid column!" << endl;
		return 0;
	}

	return 1;
}

int yes_no_valid(char c){

	if (c == 'Y' || c == 'y' || c == 'N' || c == 'n'){

		return 1;
	}

	cout << "Please enter a valid input!" << endl;
	return 0;
}
