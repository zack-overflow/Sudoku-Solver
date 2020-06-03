# Makefile
# CS50 Project
# Team Git That Money


# add -DNOSLEEP to disable the automatic sleep after web-page fetches
#               (students, please do not use -DNOSLEEP!)
# add -DMEMTEST for memory tracking report in indexer
# (and run `make clean; make` whenever you change this)
FLAGS = # -DMEMTEST  # -DNOSLEEP

CFLAGS = -Wall -pedantic -std=gnu11 -ggdb
CC = gcc
MAKE = make

.PHONY: clean test# all

common.o: common.h

test: 
	bash -v testing.sh

fuzzytesting: fuzzytesting.c
	$(CC) $(CFLAGS) $^ -o $@

# clean up after our compilation
clean:
	rm -rf *~ *.o *.dSYM
	rm -rf fuzzytesting
