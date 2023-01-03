
# Define the compiler and flags
CC = gcc
CFLAGS = -Wall -g


# Define the default target
all: isort txtfind

# Define the target program
isort: isort.o
	$(CC) $(CFLAGS) -o isort isort.o

txtfind: txtfind.o
	$(CC) $(CFLAGS) -o txtfind txtfind.o

# Define the object file dependencies
isort.o: isort.c isort.h
	$(CC) $(CFLAGS) -c isort.c

txtfind.o: txtfind.c txtfind.h
	$(CC) $(CFLAGS) -c txtfind.c

# Define the clean target
clean:
	rm -f *o  txtfind isort
