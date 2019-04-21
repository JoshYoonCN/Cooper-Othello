#include <iostream>
#include <string>
#include <vector>

using namespace std;

//piece class that each "space" class will have an instance of - will determine which piece will be placed on board
class Piece{
public:
	
	//define member public for now - will change later
	char bOrW;

	//default constructor so compiler won't yell at me
	Piece () {}

	//constructor that will initialize bOrW with some input we decide
	Piece (char input) : bOrW(input) {}

	//assignment operator overload
	Piece& operator= (const Piece& p){

		bOrW = p.bOrW;
		return *this;
	}	

	//copy constructor
	Piece (const Piece& p){

		bOrW = p.bOrW;
	}
	
	//destructor - note that I THINK this will also clear the memory created by "new"
	~Piece () {}
};

//I don't see a need for inheritance just yet
class Space{
public:
	
	//members for Space class - public for now
	Piece p;
	int isFilled;
		
	//default constructor
	Space () {}

	//constructor that will initialize with correct values
	Space (int input, char p) : isFilled(input), p(p) {}

	//assignment operator overload
	Space& operator= (const Space& s){
		
		isFilled = s.isFilled;
		return *this;
	}

	//copy constructor
	Space (const Space& s){

		isFilled = s.isFilled;
	}

	//destructor
	~Space () {}

};

//not sure if this is necessary just yet
/*
class Board{
public:

	Board () {}

	~Board () {}


}*/

//some useful typedef aliases
typedef vector<Space*> row;
typedef vector<row> arr;
 
//vector<vector<Space*> > Board (10, vector<Space*>(10));
arr Board (10, row(10));

//initialize board
void init_board(){

	//create objects on heap, prevent overflow with "new"
	//initiliazing the board
	for(int i = 0; i < 10; i++){
		
		for(int j = 0; j < 10; j++){

			Board[i][j] = new Space(0, '-');
		}
	}

	//set initial board state
	Board[4][4]->p.bOrW = 'W';	
	Board[4][5]->p.bOrW = 'B';	
	Board[5][4]->p.bOrW = 'B';	
	Board[5][5]->p.bOrW = 'W';	
	
	return;
}

//print out board
void print_board(){
	
	for(int j = 0; j < 8; j++){
		
		for(int k = 0; k < 8; k++){

			cout << Board[j+1][k+1]->p.bOrW;
		}

		printf("\n");
	}

	return;
}

//check if space is valid
int space_valid(char c){

	if (c == 'B' || c == 'W'){
		
		cout << "That space is not valid!" << endl;
		return 0;
	}
	
	return 1;
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

//player move
void player_move(int id){

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
	
	//assign proper space based on which player
	} while(!space_valid(Board[row+1][col+1]->p.bOrW));

	if (id == 1){
		
		Board[row+1][col+1]->p.bOrW = 'W';	
	}
	else if (id == 2){

		Board[row+1][col+1]->p.bOrW = 'B';
	}

	return;
}

int main(){

	int turnCount = 0;

	//need to add a "moves left" function that tests for end of game, but for now will assume 60 turns
	init_board();

	while (turnCount < 60) {

		print_board();

		player_move((turnCount%2)+1);

		turnCount++;
	}

	return 0;
}
