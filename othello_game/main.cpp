#include "othello.h"

//initialize two boards, one that holds game state, other that will be used in computer ai
arr Board (10, row(10));
arr Board2 (10, row(10));

int main(){

	//initialize turn count
	int turnCount = 0;

	//instantiate each of the player and computer
	Player p1(1, 0);
	Player p2(2, 0);
	Computer c(2, 0);
	
	//initialize board
	init_board(Board);

	//ask user what kind of opponent that they want
	ask_opponent(p1, p2, c);

	while (end_condition(Board)) {

		//this will only occur if the computer is not playing
		if (!c.playing){

			if (((turnCount%2)+1) == 1){

				//both players require the possible and clear possible moves
				possible(p1.id, Board, Board2);
				print_board(Board);
				p1.player_move(p1.id, "\u25CB", Board);
				clearPossible(Board);
			}
			else{

				possible(p2.id, Board, Board2);
				print_board(Board);
				p2.player_move(p2.id, "\u25CB", Board);
				clearPossible(Board);
			}
		}
		else{

			//this turncount tracks which player's turn it is
			if (((turnCount%2)+1) == 1){

				if (p1.id == 1){
				
					possible(p1.id, Board, Board2);
					print_board(Board);
					p1.player_move(p1.id, "\u25CB", Board);
					clearPossible(Board);
				}
				else{
					c.computer_move(c.id, Board, Board2, c.difficulty);
				}
			}
			else{
				if (p1.id == 1){
					c.computer_move(c.id, Board, Board2, c.difficulty);
				}
				else{
				
					possible(p1.id, Board, Board2);
					print_board(Board);
					p1.player_move(p1.id, "\u25CF", Board);
					clearPossible(Board);
				}

			}
		}

		//display points
		points(Board, 0);

		//increment turn count
		turnCount++;
	}

	//display final score
	points(Board, 1);

	//clean the boards
	clean(Board);
	clean(Board2);

	return 0;
}
