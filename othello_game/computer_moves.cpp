#include "othello.h"

void Computer::computer_move(int id, arr& Board, arr& Board2){

	int row = 0, col = 0, i = 0, j, breakCond = 0;
	int space;
	int current_point = 0;
	int high_point = 0;
	int high_row = 0;
	int high_col = 0;

 	for(int row1 = 1; row1 < 9; row1 ++){ // check to see point values of its next move
	 	for(int col1 = 1; col1 < 9; col1++){
			copy_board(Board, Board2);
			//cout << "testing" << endl;
			//print_board(Board2);

			if(space_valid(row1, col1, id, Board2, 0, 1)){
				//fill in board with anticipated move, then check point value
				if (id == 1){
					Board2[row+row1][col+col1]->p.bOrW = 'B';
					Board2[row+row1][col+col1]->p.unicode = "\u25CB";
				}
				else if (id == 2){
					Board2[row+row1][col+col1]->p.bOrW = 'W';
					Board2[row+row1][col+col1]->p.unicode = "\u25CF";
				}
				//print_board(Board2);
				current_point = point(Board2);
				//cout << "Current Point: " << current_point << endl;
				if (current_point > high_point){
					high_point = current_point;
					high_row = row1;
					high_col = col1;
					//cout << high_point << endl;
				}

			}

	 	}
	}

	i = high_row;
	j = high_col;

	if(high_point){
		space_valid(row+i, col+j, id, Board, 0, 1);
	}

	if (!high_point){
		//cout << "easy mode activated" << endl;
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
