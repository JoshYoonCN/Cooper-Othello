#include <iostream>
#include <string>
#include <vector>
using namespace std;

//piece class that each "space" class will have an instance of - will determine which piece will be placed on board
class Piece{
public:
	char bOrW;	//define member public for now - will change later
	Piece () {}	//default constructor so compiler won't yell at me
	Piece (char input) : bOrW(input) {}	//constructor that will initialize bOrW with some input we decide
	Piece& operator= (const Piece& p){	//assignment operator overload
		bOrW = p.bOrW;
		return *this;
	}
	Piece (const Piece& p){	//copy constructor
		bOrW = p.bOrW;
	}
	~Piece () {}	//destructor - note that I THINK this will also clear the memory created by "new"
};

//I don't see a need for inheritance just yet
class Space{
public:
	Piece p; 	//members for Space class - public for now
	int isFilled;
	Space () {}	//default constructor
	Space (int input, char p) : isFilled(input), p(p) {}	//constructor that will initialize with correct values
	Space& operator= (const Space& s){ 	//assignment operator overload
		isFilled = s.isFilled;
		return *this;
	}
	Space (const Space& s){	//copy constructor
		isFilled = s.isFilled;
	}
	~Space () {}	//destructor
};

//some useful typedef aliases
typedef vector<Space*> row;
typedef vector<row> arr;

//vector<vector<Space*> > Board (10, vector<Space*>(10));
arr Board (10, row(10));

//function definitions
void init_board();
void print_board();
