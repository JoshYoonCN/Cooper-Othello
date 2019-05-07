#include "othello.h"

void Computer::computer_move(int id, arr& Board, arr& Board2, char difficulty){

	int row = 0, col = 0, breakCond = 0;
	int current_point = 0;
	int high_point = 0;
	int high_row = 0;
	int high_col = 0;
	int mid_point = 0;	
	int side_point = 0;
	int corner;

	vector<Move> cmp;

	if (difficulty == '1'){
		//cout << "easy mode activated" << endl;
		/*easy mode*/
		for (row = 1; row < 9; row++){

			for (col = 1; col < 9; col++){

				if (space_valid(row, col, id, Board, 0, 1)){

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
	else if (difficulty == '2'){
 		for(int row1 = 1; row1 < 9; row1++){ // check to see point values of its next move
	 		for(int col1 = 1; col1 < 9; col1++){
				copy_board(Board, Board2);
				//cout << "testing" << endl;
				//print_board(Board2);

				if(space_valid(row1, col1, id, Board2, 0, 1)){
					//fill in board with anticipated move, then check point value
					if (id == 1){
						Board2[row1][col1]->p.bOrW = 'B';
						Board2[row1][col1]->p.unicode = "\u25CB";
					}
					else if (id == 2){
						Board2[row1][col1]->p.bOrW = 'W';
						Board2[row1][col1]->p.unicode = "\u25CF";
					}
					//print_board(Board2);
					current_point = point(Board2);
					//cout << "Current Point: " << current_point << endl;
					//cout << row1 << endl;
					//cout << col1 << endl;
					
					if(!high_point){
						
						high_point = current_point;
						high_row = row1;
						high_col = col1;	
					}
					else if (current_point > high_point){
						high_point = current_point;
						high_row = row1;
						high_col = col1;
						//cout << high_point << endl;
					}

				}

	 		}
		}
		space_valid(high_row, high_col, id, Board, 0, 1);

		row = high_row;
		col = high_col;
	}
	else if (difficulty == '3'){
		for(int row1 = 1; row1 < 9; row1++){ // check to see point values of its next move
	 		for(int col1 = 1; col1 < 9; col1++){
				copy_board(Board, Board2);
				//cout << "testing" << endl;
				//print_board(Board2);

				if(space_valid(row1, col1, id, Board2, 0, 1)){
				
					//fill in board with anticipated move, then check point value
					if (id == 1){
						Board2[row1][col1]->p.bOrW = 'B';
						Board2[row1][col1]->p.unicode = "\u25CB";
					}
					else if (id == 2){
						Board2[row1][col1]->p.bOrW = 'W';
						Board2[row1][col1]->p.unicode = "\u25CF";
					}
					//print_board(Board2);
					current_point = point(Board2);
					mid_point = mid_points(Board2);	
					corner = checkCorners(row1, col1);	
					side_point = side_points(Board2);
									
					/*
					cout << row1 << endl;
					cout << col1 << endl;	
					cout << mid_point << endl;
					cout << current_point << endl;
					cout << corner << endl;
					*/

					Move current(row1, col1, mid_point, current_point, corner, side_point);
					
					cmp.push_back(current); 
					//cout << "cmp[0].row: " << cmp[0].row << endl;
					//cout << "cmp[0].col: " << cmp[0].col << endl; 
				}

	 		}
		}

		sort(cmp.begin(), cmp.end(), Cmp);
		
		//cout << "cmp[0].row: " << cmp[0].row << endl;
		//cout << "cmp[0].col: " << cmp[0].col << endl; 

		space_valid(cmp[0].row, cmp[0].col, id, Board, 0, 1);

		row = cmp[0].row;
		col = cmp[0].col;
	}

	
	if (id == 1){

		Board[row][col]->p.bOrW = 'B';
		Board[row][col]->p.unicode = "\u25CB";
	}
	else if (id == 2){

		Board[row][col]->p.bOrW = 'W';
		Board[row][col]->p.unicode = "\u25CF";
	}

	cout << "Computer chose row: " << row << "!" << endl;
	cout << "Computer chose column: " << col << "!" << endl;

	return;
}

int checkCorners(int col, int row){

	if ((row == 1 && col == 1) || (row == 1 && col == 8) || (row == 8 && col == 1) || (row == 8 && col == 8)){

		return 1;
	}

	return 0;
}



