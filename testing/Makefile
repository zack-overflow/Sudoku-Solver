# Makefile
# # CS50 Project
# # Team Git That Money


PROGS = randboard fuzzytesting
OBJS = ../creator/creator.o

CFLAGS = -Wall -pedantic -std=gnu11 -ggdb -I../creator -I../common 
CC = gcc
MAKE = make
PATHCOMMON = ../common

.PHONY: clean test all

all: $(PROGS)

randboard: randboard.c
	$(CC) $(CFLAGS) $^ -o $@

fuzzytesting: fuzzytesting.c $(OBJS)
	$(CC) $(CFLAGS) $(PATHCOMMON)/common.o $^ -o $@


clean:
	rm -rf *~ *.o *.dSYM
	rm -rf $(PROGS) core
