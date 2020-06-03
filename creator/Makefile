# add -DNOSLEEP to disable the automatic sleep after web-page fetches
#               (students, please do not use -DNOSLEEP!)
# add -DMEMTEST for memory tracking report in indexer
# (and run `make clean; make` whenever you change this)
FLAGS = # -DMEMTEST  # -DNOSLEEP

PATHCOMMON = ../common
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I$(PATHCOMMON)
CC = gcc
MAKE = make

# Dependencies: object files depend on header files
creator.o: creator.h $(PATHCOMMON)/common.o 

.PHONY: clean test

test: 
	bash -v testing.sh

# clean up after our compilation
clean:
	rm -rf *~ *.o *.dSYM
	rm -rf $(PROG)
