#ifndef othello_h
#define othello_h

#include <iostream>
#include <string>
#include <vector>

//I know this is dangerous,but for now...
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
		p.bOrW = s.p.bOrW;
		return *this;
	}

	//copy constructor
	Space (const Space& s){
		isFilled = s.isFilled;
	}

	//destructor
	~Space () {}

};

//some useful typedef aliases
typedef vector<Space*> row;
typedef vector<row> arr;
/*
class Board {

public:
	arr gameBoard (10, row(10));

	Board () {};

	~Board () {};
};*/


//vector<vector<Space*> > Board (10, vector<Space*>(10));
//arr Board (10, row(10));

void init_board(arr& Board);
void print_board(arr& Board);
int prop_valid(char c, int id);
int propagate(int row, int col, signed int row_increment, signed int col_increment, int id, arr& Board);
int space_valid(int row, int col, int id, arr& Board);
int row_input_valid(int input);
int col_input_valid(int input);
void player_move(int id, arr& Board);

#endif
