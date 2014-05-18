# makefile
CC=gcc
PROGRAM=math_demo
BIN=bin
CFLAGS := -g -Wall -std=c99 -lm

all: main.o mathf.o
	@$(CC) $(CFLAGS) -o $(PROGRAM) main.o mathf.o

main.o: main.c
	@$(CC) $(CFLAGS) -c main.c

mathf.o: mathf.h mathf.c
	@$(CC) $(CFLAGS) -c mathf.c

clean: $(PROGRAM) *.o
	@$(RM) -f $(PROGRAM) *.o *~
