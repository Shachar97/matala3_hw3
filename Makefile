# Define the target program
TARGET = main

# Define the object files needed to build the target
OBJECTS = main.o libisort.a

# Define the compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Define the library path and flags
LDFLAGS = -L. -lisort

# Define the default target
all: $(TARGET)

# Define the target program
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

# Define the object file dependencies
main.o: main.c isort.h
	$(CC) $(CFLAGS) -c main.c

# Define the library dependencies
libisort.a: isort.o
	ar rcs libisort.a isort.o

# Define the object file dependencies
isort.o: isort.c isort.h
	$(CC) $(CFLAGS) -c isort.c

# Define the clean target
clean:
	rm -f $(TARGET) $(OBJECTS)
