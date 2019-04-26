#include "othello.h"

arr Board (10, row(10));

int main(){

	int turnCount = 0;

	Player p1(1, 0);
	Player p2(2, 0);
	Computer c(2, 0);
	//need to add a "moves left" function that tests for end of game, but for now will assume 60 turns
	init_board(Board);

	ask_opponent(p1, p2, c);

	while (turnCount < 60) {

		print_board(Board);
	
		if (!c.playing){

			if (((turnCount%2)+1) == 1){

				p1.player_move(p1.id, Board);
			}
			else{
	
				p2.player_move(p2.id, Board);
			}
		}
		else{

			if (((turnCount%2)+1) == 1){

				if (p1.id == 1){
					
					p1.player_move(p1.id, Board);
				}
				else{
					
					c.computer_move(c.id, Board);
				}
			}
			else{
				if (p1.id == 1){

					c.computer_move(c.id, Board);
				}
				else{
					
					p1.player_move(p1.id, Board);
				}

			}
		}
			
		turnCount++;
	}

	return 0;
}
