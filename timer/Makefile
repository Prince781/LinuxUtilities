# makefile
CC=gcc
PROGRAM=gplotter
BIN=bin
CFLAGS := -g -Wall -std=c99 -lm
# resources
CFILES=$(shell find . -type f -name '*.c')

all: timer.o stopwatch.o
	$(CC) $(CFLAGS) -o timer timer.o stopwatch.o

timer.o: timer.c stopwatch.h options.h
	$(CC) $(CFLAGS) -c timer.c

stopwatch.o: stopwatch.c stopwatch.h
	$(CC) $(CFLAGS) -c stopwatch.c

clean: 
	$(RM) timer *.o *~
