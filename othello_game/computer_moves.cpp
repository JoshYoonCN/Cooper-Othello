#include "othello.h"

void Computer::computer_move(int id, arr& Board){

	int row = 0, col = 0, i, j, breakCond = 0;

	for (i = 1; i < 9; i++){

		for (j = 1; j < 9; j++){
			
			if (space_valid(row+i, col+j, id, Board, 0)){
				
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

	if (id == 1){

		Board[row+i][col+j]->p.bOrW = 'B';
	}
	else if (id == 2){

		Board[row+i][col+j]->p.bOrW = 'W';
	}
	
	cout << "Computer chose row: " << row+i << "!" << endl;
	cout << "Computer chose column: " << col+j << "!" << endl;
	
	return;
}
