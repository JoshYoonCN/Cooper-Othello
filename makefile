CC=g++
CFLAGS=-I.

# This will create your final output using .o compiled files
make: main.o
	$(CC) $(CFLAGS) -o main main.o
# This will compile board.c

# This will compile main.c with its dependency
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

# This will clean or remove compiled files so you can start fresh
clean:
	rm -f *.o *.exe *.stackdump
