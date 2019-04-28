#include "othello.h"

void ask_opponent(Player &p1, Player &p2, Computer& c){
	
	char input;
	char input2;

	do {
		
		cout << "Would you like to play against a computer (Y/N)?";
		cin >> input;

	} while (!yes_no_valid(input));


	if (input == 'Y' || input == 'y'){

		p1.playing = 1;
		c.playing = 1;
		
		do{
		
			cout << "Would you like to go first (Y/N)?";
			cin >> input2;
		
		} while (!yes_no_valid(input2));

		if (input2 == 'N' || input2 == 'n'){

			p1.id = 2;
			c.id = 1;
		}	
	}
	else if (input == 'N' || input == 'n'){

		p1.playing = 1;
		p2.playing = 1;
	}
	
	return;
}

//player move
void Player::player_move(int id, arr& Board){

	//initialize these to 0
	int row = 0, col = 0;
	
	do{

		do{
			//read in row from user
			cout << "Player " << id << ", please enter a row (1-8): ";
			cin >> row;
			
			//some useful protection against bad inputs		
			if (cin.fail()){
				
				cout << "ERROR - You didn't enter an integer!" << endl;

				cin.clear();

				//ignore the evil new line character formed after user presses enter
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				
				//set row to 8 so that the loop will fail and continue
				row = 9;
			}

		} while (!row_input_valid(row));

		do{
			//read in column from user
			cout << "Player " << id << ", please enter a column (1-8): ";
			cin >> col;
			
			//same protection
			if (cin.fail()){
				
				cout << "ERROR - You didn't enter an integer!" << endl;

				cin.clear();

				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				
				col = 9;
			}

		} while (!col_input_valid(col));

	//last term there is for the int c_or_p argument, which is to determine if the instance using the function is the computer or a player	
	} while(!space_valid(row, col, id, Board, 1, 1));

	//assign proper space based on player
	if (id == 1){
		
		Board[row][col]->p.bOrW = 'B';	
		Board[row][col]->p.unicode = "\u25CB";
	}
	else if (id == 2){

		Board[row][col]->p.bOrW = 'W';
		Board[row][col]->p.unicode = "\u25CF";
	}

	return;
}

