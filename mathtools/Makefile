# makefile
CC=gcc
PROGRAM=gplotter
BIN=bin
CFLAGS := -g -Wall -std=c99 -lm

all: main.c
	@$(CC) $(CFLAGS) -o mathf mathf.o

mathf.o: mathf.h mathf.c
	@$(CC) $(CFLAGS) -c mathf.c
