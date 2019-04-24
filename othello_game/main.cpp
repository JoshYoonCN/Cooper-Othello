#include "othello.h"

arr Board (10, row(10));

//not sure if this is necessary just yet
/*
class Board{
public:

	Board () {}

	~Board () {}


}*/

/*
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
*/
/*
//check if space is valid
int space_valid(int row, int col, int id){

	//this initial statement checks for whether the space player chose is occupied
	char c = Board[row][col]->p.bOrW;
	
	if (c == 'B' || c == 'W'){
		
		cout << "That space is occupied!" << endl;
		return 0;
	}

	//these series of if statements (try to optimize later!) check around the player's input in order to check for a legal move
	if (id == 1){

		if (Board[row+1][col]->p.bOrW == 'W'){
			
			if(propagate(row, col, 1, 0, id)){
				
				return 1;	
			}
		}
		if (Board[row][col-1]->p.bOrW == 'W'){
		
			if(propagate(row, col, 0, -1, id)){
				
				return 1;	
			}
		}
		if (Board[row][col+1]->p.bOrW == 'W'){
			
			if(propagate(row, col, 0, 1, id)){
				
				return 1;	
			}
		}
		if (Board[row-1][col]->p.bOrW == 'W'){
		
			if(propagate(row, col, -1, 0, id)){
				
				return 1;	
			}
		}
		if (Board[row-1][col-1]->p.bOrW == 'W'){
		
			if(propagate(row, col, -1, -1, id)){
				
				return 1;	
			}
		}
		if (Board[row-1][col+1]->p.bOrW == 'W'){

			if(propagate(row, col, -1, 1, id)){
				
				return 1;	
			}
		}
		if (Board[row+1][col-1]->p.bOrW == 'W'){
		
			if(propagate(row, col, 1, -1, id)){
				
				return 1;	
			}
		}
		if (Board[row+1][col+1]->p.bOrW == 'W'){
		
			if(propagate(row, col, 1, 1, id)){
				
				return 1;	
			}
		}

	}

	//if player 2, switch to checking for black pieces
	if (id == 2){

		if (Board[row+1][col]->p.bOrW == 'B'){
			
			if(propagate(row, col, 1, 0, id)){
				
				return 1;	
			}
		}
		if (Board[row][col-1]->p.bOrW == 'B'){
		
			if(propagate(row, col, 0, -1, id)){
				
				return 1;	
			}
		}
		if (Board[row][col+1]->p.bOrW == 'B'){
			
			if(propagate(row, col, 0, 1, id)){
				
				return 1;	
			}
		}
		if (Board[row-1][col]->p.bOrW == 'B'){
		
			if(propagate(row, col, -1, 0, id)){
				
				return 1;	
			}
		}
		if (Board[row-1][col-1]->p.bOrW == 'B'){
		
			if(propagate(row, col, -1, -1, id)){
				
				return 1;	
			}
		}
		if (Board[row-1][col+1]->p.bOrW == 'B'){

			if(propagate(row, col, -1, 1, id)){
				
				return 1;	
			}
		}
		if (Board[row+1][col-1]->p.bOrW == 'B'){
		
			if(propagate(row, col, 1, -1, id)){
				
				return 1;	
			}
		}
		if (Board[row+1][col+1]->p.bOrW == 'B'){
		
			if(propagate(row, col, 1, 1, id)){
				
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
}*/

//player move
void player_move(int id, arr& Board){

	//initialize these to 0
	int row = 0, col = 0;
	
	do{

		do{
			//read in row from user
			cout << "Player " << id << ", please enter a row (0-7): ";
			cin >> row;
			
			//some useful protection against bad inputs		
			if (cin.fail()){
				
				cout << "ERROR - You didn't enter an integer!" << endl;

				cin.clear();

				//ignore the evil new line character formed after user presses enter
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				
				//set row to 8 so that the loop will fail and continue
				row = 8;
			}

		} while (!row_input_valid(row));

		do{
			//read in column from user
			cout << "Player " << id << ", please enter a column (0-7): ";
			cin >> col;
			
			//same protection
			if (cin.fail()){
				
				cout << "ERROR - You didn't enter an integer!" << endl;

				cin.clear();

				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				
				col = 8;
			}

		} while (!col_input_valid(col));
	
	} while(!space_valid(row+1, col+1, id, Board));

	//assign proper space based on player
	if (id == 1){
		
		Board[row+1][col+1]->p.bOrW = 'B';	
	}
	else if (id == 2){

		Board[row+1][col+1]->p.bOrW = 'W';
	}

	return;
}

int main(){

	int turnCount = 0;

	//need to add a "moves left" function that tests for end of game, but for now will assume 60 turns
	init_board(Board);

	//ask_opponent();

	while (turnCount < 60) {

		print_board(Board);

		player_move((turnCount%2)+1, Board);

		turnCount++;
	}

	return 0;
}
