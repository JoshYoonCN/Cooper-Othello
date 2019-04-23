CC=g++
CFLAGS=-I.

# This will create your final output using .o compiled files
make: main.o board.o
	$(CC) $(CFLAGS) -o main main.o board.o
# This will compile board.cpp
board.o: board.cpp header.h
	$(CC) $(CFLAGS) -c board.cpp

# This will compile main.c with its dependency
main.o: main.cpp header.h
	$(CC) $(CFLAGS) -c main.cpp

# This will clean or remove compiled files so you can start fresh
clean:
	rm -f *.o *.exe *.stackdump
