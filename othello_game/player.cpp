#include "othello.h"

//player move
void Player::player_move(int id, arr& Board){
//void player_move(int id, arr& Board){
	//initialize these to 0
	int row = 0, col = 0;
	do{
		do{
			cout << "Player " << id << ", please enter a row (0-7): ";			//read in row from user
			cin >> row;
/*
			//some useful protection against bad inputs
			if (cin.fail()){

				cout << "ERROR - You didn't enter an integer!" << endl;

				cin.clear();

				//ignore the evil new line character formed after user presses enter
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				//set row to 8 so that the loop will fail and continue
				row = 8;
			}
*/
		} while (!row_input_valid(row));
		do{
			cout << "Player " << id << ", please enter a column (0-7): ";      //read in column from user
			cin >> col;
/*
			//same protection
			if (cin.fail()){

				cout << "ERROR - You didn't enter an integer!" << endl;

				cin.clear();

				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				col = 8;
			}
*/
		} while (!col_input_valid(col));

	} while(!space_valid(row+1, col+1, id, Board));

	if (id == 1){	//assign proper space based on player
		Board[row+1][col+1]->p.bOrW = 'B';
	}
	else if (id == 2){
		Board[row+1][col+1]->p.bOrW = 'W';
	}
	return;
}
