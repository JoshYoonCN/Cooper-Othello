#include "othello.h"

//helps the propagate function by checking for B or W, reduces clutter
int prop_valid(char c, int id){

	if (id == 1){

		if (c == 'B'){

			return 1;
		}

		return 0;
	}

	else if (id == 2){

		if (c == 'W'){

			return 1;
		}

		return 0;
	}

	return 0;
}

//this function checks along a diagonal, horizontal, or vertical line to check for valid moves
int propagate(int row, int col, signed int row_increment, signed int col_increment, int id, arr& Board){

	int cond = 0;
	int row_copy = row;
	int col_copy = col;

	while (1){

		//increment depending on what direction was specified by function call
		row += row_increment;
		col += col_increment;

		//check if the player's color terminates the line
		if (prop_valid(Board[row][col]->p.bOrW, id)){

			cond++;
			break;
		}

		//check for end of board
		if(Board[row][col]->p.bOrW == '+'){

			break;
		}
	}

	if (cond == 1){

		//cout << "flipping mechanism called" << endl;
		row_copy += row_increment;
		col_copy += col_increment;

		//this while loop flips pieces
		while (!prop_valid(Board[row_copy][col_copy]->p.bOrW, id)){

			if (Board[row_copy][col_copy]->p.bOrW == 'B'){

				Board[row_copy][col_copy]->p.bOrW = 'W';
			}
			else if (Board[row_copy][col_copy]->p.bOrW == 'W'){

				Board[row_copy][col_copy]->p.bOrW = 'B';
			}

			row_copy += row_increment;
			col_copy += col_increment;
		}

		return 1;
	}

	return 0;
}
