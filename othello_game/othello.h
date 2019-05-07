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
	string unicode;

	//default constructor so compiler won't yell at me
	Piece () {}

	//constructor that will initialize bOrW with some input we decide
	Piece (char input, string u) : bOrW(input), unicode(u) {}

	Piece (char input) : bOrW(input) {}

	//assignment operator overload
	Piece& operator= (const Piece& p){

		bOrW = p.bOrW;
		unicode = p.unicode;
		return *this;
	}

	//copy constructor
	Piece (const Piece& p){

		bOrW = p.bOrW;
		unicode = p.unicode;
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

	Space (int input, char p, string u) : isFilled(input), p(p, u) {}
	//assignment operator overload
	Space& operator= (const Space& s){
		
		isFilled = s.isFilled;
		p.bOrW = s.p.bOrW;
		p.unicode = s.p.unicode;
		return *this;
	}

	//copy constructor
	Space (const Space& s){
		isFilled = s.isFilled;
		p.bOrW = s.p.bOrW;
		p.unicode = s.p.unicode;
	}

	//destructor
	~Space () {}

};

//some useful typedef aliases
typedef vector<Space*> row;
typedef vector<row> arr;

class Player {
	
public:

	int id;
	int playing;

	Player () {}
	
	Player (int id, int playing) : id(id), playing(playing) {}
	
	~Player(){}
	
	void player_move(int id, string unicode, arr& Board);
};

class Computer {
	
public:

	int id;
	int playing;
	char difficulty;

	Computer () {}
	
	Computer (int id, int playing) : id(id), playing(playing) {}

	~Computer () {}
	
	void computer_move(int id, arr& Board, arr& Board2, char difficulty);
};

class Move{

public:
	int row;
	int col;
	int mid_value;
	int high_value;
	int side_value;
	int corner;

	Move () {}

	Move (int r, int col, int m, int h, int c, int s) : row(r), col(col), mid_value(m), high_value(h), corner(c), side_value(s) {}

	Move& operator= (const Move& c){

		row = c.row;
		col = c.col;
		mid_value = c.mid_value;
		high_value = c.mid_value;
		corner = c.corner;
		side_value = c.side_value;
		return *this;
	}

	Move (const Move& c){
	
		row = c.row;
		col = c.col;
		mid_value = c.mid_value;
		high_value = c.mid_value;
		corner = c.corner;
		side_value = c.side_value;
	}

//	friend bool operator< (const Move &lhs, const Move &rhs);
};

struct {
	
	bool operator() (const Move &lhs, const Move &rhs){
	
		if (lhs.corner > rhs.corner){
		
			return true;
		}
		else if (lhs.corner < rhs.corner){
		
			return false;
		}
		else{
			if (lhs.side_value > rhs.side_value){

				return true;
			}
			else if (lhs.side_value < rhs.side_value){

				return false;
			}
			else {

				if (lhs.mid_value > rhs.mid_value){

					return true;
				}
				else if (lhs.mid_value < rhs.mid_value){
			
					return false;
				}
				else {
					if (lhs.high_value > rhs.high_value){
		
						return true;
					}
					else if (lhs.high_value < rhs.high_value){

						return false;
					}
					else {
				
						return false;
					}
				}
			}
		}
	}
} Cmp;
/*
class Board {

public:
	arr gameBoard (10, row(10));

	Board () {
		
		gameBoard = new arr (10, row(10));	
	};

	~Board () {};
};*/



//vector<vector<Space*> > Board (10, vector<Space*>(10));
//arr Board (10, row(10));

void ask_opponent(Player &p1, Player &p2, Computer& c);
void init_board(arr& Board);
void print_board(arr& Board);
int prop_valid(char c, int id);
int propagate(int row, int col, signed int row_increment, signed int col_increment, int id, arr& Board, int flip);
int space_valid(int row, int col, int id, arr& Board, int c_or_p, int flip);
int row_input_valid(int input);
int col_input_valid(int input);
int yes_no_valid(char c);
int end_condition(arr& Board);
void points(arr& Board, int win);
void copy_board(arr& Board, arr& Board2);
int point(arr& Board);
void possible(int id, arr& board, arr& Board2);
void clearPossible(arr&Board);
void clean(arr& Board);
int diff_valid(char c);
int mid_points(arr& Board);
int checkCorners(int col, int row);
int side_points(arr& Board);

#endif
