#include "othello.h"

//main file
arr Board (10, row(10));
arr Board2 (10, row(10));

int main(){

	int turnCount = 0;

	Player p1(1, 0);
	Player p2(2, 0);
	Computer c(2, 0);
	//need to add a "moves left" function that tests for end of game, but for now will assume 60 turns
	init_board(Board);

	ask_opponent(p1, p2, c);

	while (end_condition(Board)) {

		if (!c.playing){

			if (((turnCount%2)+1) == 1){

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

			if (((turnCount%2)+1) == 1){

				if (p1.id == 1){
				
					possible(p1.id, Board, Board2);
					print_board(Board);
					p1.player_move(p1.id, "\u25CB", Board);
					clearPossible(Board);
				}
				else{
					c.computer_move(c.id, Board, Board2, c.difficulty);
					print_board(Board);
				}
			}
			else{
				if (p1.id == 1){
					c.computer_move(c.id, Board, Board2, c.difficulty);
					print_board(Board);
				}
				else{
				
					possible(p1.id, Board, Board2);
					print_board(Board);
					p1.player_move(p1.id, "\u25CF", Board);
					clearPossible(Board);
				}

			}
		}

		points(Board, 0);

		turnCount++;
	}

	points(Board, 1);

	clean(Board);
	clean(Board2);

	return 0;
}
