#include "othello.h"

void Computer::computer_move(int id, arr& Board, arr& Board2){

	int row = 0, col = 0, i = 0, j, breakCond = 0;
	int space;
	int current_point = 0;
	int high_point = 0;
/*
	for(int row1 = 1; row1 < 9; row1 ++){ // check to see point values of its next move
		for(int col1 = 1; col1 < 9; col1++){
			if (!i){
				if(space_valid(row1, col1, id, Board2, 0, 1)){
					//fill in board with anticipated move, then check point value
					if (id == 1){
						Board[row+row1][col+col1]->p.bOrW = 'B';
						Board[row+row1][col+col1]->p.unicode = "\u25CB";
					}
					else if (id == 2){

						Board[row+row1][col+col1]->p.bOrW = 'W';
						Board[row+row1][col+col1]->p.unicode = "\u25CF";
					}
					current_point = point(Board);

					if (current_point > high_point){
						high_point = current_point;
					}
					//delete the anticipated move
					Board[row+row1][col+col1]->p.bOrW = '-';
					Board[row+row1][col+col1]->p.unicode = " ";

				}

			}

		}

	}
 *///AI testing
	if (!high_point){
		cout << "easy mode activated" << endl;
	/*easy mode*/
		for (i = 1; i < 9; i++){

			for (j = 1; j < 9; j++){

				if (space_valid(row+i, col+j, id, Board, 0, 1)){

					//found a good pair, yay!
					breakCond = 1;
				}
				if(breakCond){

					break;
				}
			}
			if(breakCond){

				break;
			}
		}
	}

	if (id == 1){

		Board[row+i][col+j]->p.bOrW = 'B';
		Board[row+i][col+j]->p.unicode = "\u25CB";
	}
	else if (id == 2){

		Board[row+i][col+j]->p.bOrW = 'W';
		Board[row+i][col+j]->p.unicode = "\u25CF";
	}

	cout << "Computer chose row: " << row+i << "!" << endl;
	cout << "Computer chose column: " << col+j << "!" << endl;

	return;
}
