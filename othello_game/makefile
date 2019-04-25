CC=g++ -std=c++11
CFLAGS=-I.

make: board_func.o main.o propagate.o valid_stuff.o player.o
	$(CC) $(CFLAGS) -o othello board_func.o main.o propagate.o valid_stuff.o player.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

board_func.o: board_func.cpp
	$(CC) $(CFLAGS) -c board_func.cpp

propagate.o: propagate.cpp
	$(CC) $(CFLAGS) -c propagate.cpp

valid_stuff.o: valid_stuff.cpp
	$(CC) $(CFLAGS) -c valid_stuff.cpp

player.o: player.cpp
	$(CC) $(CFLAGS) -c player.cpp

clean:
	rm -f *.o *.exe *.out othello
