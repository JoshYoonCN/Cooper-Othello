#include "othello.h"

//check if space is valid
int space_valid(int row, int col, int id, arr& Board){

	//this initial statement checks for whether the space player chose is occupied
	char c = Board[row][col]->p.bOrW;
	
	if (c == 'B' || c == 'W'){
		
		cout << "That space is occupied!" << endl;
		return 0;
	}

	//these series of if statements (try to optimize later!) check around the player's input in order to check for a legal move
	if (id == 1){

		if (Board[row+1][col]->p.bOrW == 'W'){
			
			if(propagate(row, col, 1, 0, id, Board)){
				
				return 1;	
			}
		}
		if (Board[row][col-1]->p.bOrW == 'W'){
		
			if(propagate(row, col, 0, -1, id, Board)){
				
				return 1;	
			}
		}
		if (Board[row][col+1]->p.bOrW == 'W'){
			
			if(propagate(row, col, 0, 1, id, Board)){
				
				return 1;	
			}
		}
		if (Board[row-1][col]->p.bOrW == 'W'){
		
			if(propagate(row, col, -1, 0, id, Board)){
				
				return 1;	
			}
		}
		if (Board[row-1][col-1]->p.bOrW == 'W'){
		
			if(propagate(row, col, -1, -1, id, Board)){
				
				return 1;	
			}
		}
		if (Board[row-1][col+1]->p.bOrW == 'W'){

			if(propagate(row, col, -1, 1, id, Board)){
				
				return 1;	
			}
		}
		if (Board[row+1][col-1]->p.bOrW == 'W'){
		
			if(propagate(row, col, 1, -1, id, Board)){
				
				return 1;	
			}
		}
		if (Board[row+1][col+1]->p.bOrW == 'W'){
		
			if(propagate(row, col, 1, 1, id, Board)){
				
				return 1;	
			}
		}

	}

	//if player 2, switch to checking for black pieces
	if (id == 2){

		if (Board[row+1][col]->p.bOrW == 'B'){
			
			if(propagate(row, col, 1, 0, id, Board)){
				
				return 1;	
			}
		}
		if (Board[row][col-1]->p.bOrW == 'B'){
		
			if(propagate(row, col, 0, -1, id, Board)){
				
				return 1;	
			}
		}
		if (Board[row][col+1]->p.bOrW == 'B'){
			
			if(propagate(row, col, 0, 1, id, Board)){
				
				return 1;	
			}
		}
		if (Board[row-1][col]->p.bOrW == 'B'){
		
			if(propagate(row, col, -1, 0, id, Board)){
				
				return 1;	
			}
		}
		if (Board[row-1][col-1]->p.bOrW == 'B'){
		
			if(propagate(row, col, -1, -1, id, Board)){
				
				return 1;	
			}
		}
		if (Board[row-1][col+1]->p.bOrW == 'B'){

			if(propagate(row, col, -1, 1, id, Board)){
				
				return 1;	
			}
		}
		if (Board[row+1][col-1]->p.bOrW == 'B'){
		
			if(propagate(row, col, 1, -1, id, Board)){
				
				return 1;	
			}
		}
		if (Board[row+1][col+1]->p.bOrW == 'B'){
		
			if(propagate(row, col, 1, 1, id, Board)){
				
				return 1;	
			}
		}

	}

	//if all the above fails, means the move is not valid
	cout << "That space is not valid!" << endl;
	return 0;
}

//check if the user row input is valid
int row_input_valid(int input){

	if (input < 0 || input > 7){
		
		cout << "Please enter a valid row!" << endl;
		return 0;
	}

	return 1;

}

//check if the user column input is valid
int col_input_valid(int input){

	if (input < 0 || input > 7){

		cout << "Please enter a valid column!" << endl;
		return 0;
	}
	
	return 1;
}
