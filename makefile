CC = gcc
AR = ar -rcs
CFLAGS = -Wall -g 

.PHONY: clean all
 

# Making the o files
main.o: main.c my_mat.h
	$(CC) $(CFLAGS) -c main.c

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c my_mat.c 

## Making the main file
connections: my_mat.o main.o
	$(CC) $(CFLAGS) main.o my_mat.o -o connections -lm

all: connections

clean:
	rm -f *.o *.a connections