#include "othello.h"

//computer move function
void Computer::computer_move(int id, arr& Board, arr& Board2, char difficulty){

	//initialize all members
	int row = 0, col = 0, breakCond = 0;
	int current_point = 0;
	int high_point = 0;
	int high_row = 0;
	int high_col = 0;
	int mid_point = 0;	
	int side_point = 0;
	int corner;
	
	//initialize move evctor
	vector<Move> cmp;

	//runs through the board and checks for a valid space
	if (difficulty == '1'){
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
					
					current_point = point(Board2);
				
					//this checks for the first instance of running through this loop	
					if(!high_point){
						
						high_point = current_point;
						high_row = row1;
						high_col = col1;	
					}
					//assigns current row to high row
					else if (current_point > high_point){
						high_point = current_point;
						high_row = row1;
						high_col = col1;
					}

				}

	 		}
		}
		//perform flipping
		space_valid(high_row, high_col, id, Board, 0, 1);

		//set overall row and col
		row = high_row;
		col = high_col;
	}
	else if (difficulty == '3'){
		for(int row1 = 1; row1 < 9; row1++){ // check to see point values of its next move
	 		for(int col1 = 1; col1 < 9; col1++){
				copy_board(Board, Board2);

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
				
					//calculate all necessary values	
					current_point = point(Board2);
					mid_point = mid_points(Board2);	
					corner = checkCorners(row1, col1);	
					side_point = side_points(Board2);
									
					Move current(row1, col1, mid_point, current_point, corner, side_point);
					
					cmp.push_back(current); 
				}

	 		}
		}

		//sort based on struct, with corner being the highest
		sort(cmp.begin(), cmp.end(), Cmp);

		//perform flipping
		space_valid(cmp[0].row, cmp[0].col, id, Board, 0, 1);

		//set row and col
		row = cmp[0].row;
		col = cmp[0].col;
	}

	//set the piece after all computer logic	
	if (id == 1){

		Board[row][col]->p.bOrW = 'B';
		Board[row][col]->p.unicode = "\u25CB";
	}
	else if (id == 2){

		Board[row][col]->p.bOrW = 'W';
		Board[row][col]->p.unicode = "\u25CF";
	}

	//print out computer choice
	cout << "Computer chose row: " << row << "!" << endl;
	cout << "Computer chose column: " << col << "!" << endl;

	return;
}

//check the corners
int checkCorners(int col, int row){

	if ((row == 1 && col == 1) || (row == 1 && col == 8) || (row == 8 && col == 1) || (row == 8 && col == 8)){

		return 1;
	}

	return 0;
}



