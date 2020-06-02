# object files, and the target library

PROG = sudoku
OBJS = sudoku.o ../creator/creator.o ../solver/solver.o

# add -DNOSLEEP to disable the automatic sleep after web-page fetches
#               (students, please do not use -DNOSLEEP!)
# add -DMEMTEST for memory tracking report in indexer
# (and run `make clean; make` whenever you change this)
FLAGS = # -DMEMTEST  # -DNOSLEEP

CFLAGS = -Wall -pedantic -std=gnu11 -ggdb -I../solver -I../creator
CC = gcc
MAKE = make


$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@


# Dependencies: object files depend on header files
sudoku.o: sudoku.c

.PHONY: all clean test

all: sudoku

test:
	bash -v testing.sh

# clean up after our compilation
clean:
	rm -rf *~ *.o *.dSYM
	rm -rf $(PROG)