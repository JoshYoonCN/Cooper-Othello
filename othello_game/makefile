CC=g++ -std=c++11
CFLAGS=-I.

make: board_func.o main.o propagate.o valid_stuff.o player_moves.o computer_moves.o
	$(CC) $(CFLAGS) -o othello board_func.o main.o propagate.o valid_stuff.o player_moves.o computer_moves.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

board_func.o: board_func.cpp
	$(CC) $(CFLAGS) -c board_func.cpp

propagate.o: propagate.cpp
	$(CC) $(CFLAGS) -c propagate.cpp

valid_stuff.o: valid_stuff.cpp
	$(CC) $(CFLAGS) -c valid_stuff.cpp

player_moves.o: player_moves.cpp
	$(CC) $(CFLAGS) -c player_moves.cpp

computer_moves.o: computer_moves.cpp
	$(CC) $(CFLAGS) -c computer_moves.cpp

clean:
	rm -f *.o *.exe *.out othello
