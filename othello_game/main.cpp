#include "othello.h"

arr Board (10, row(10));

int main(){
	Player p;
	int turnCount = 0;
	init_board(Board); //need to add a "moves left" function that tests for end of game, but for now will assume 60 turns
	while (turnCount < 60) {	//ask_opponent();
		print_board(Board);
		p.player_move((turnCount%2)+1, Board);
		turnCount++;
	}
	return 0;
}
