# object files, and the target library
#L=../libcs50

OBJS = solver.o #../common/pagedir.o
#LIB = $(L)/libcs50.a
LIBS = 

# add -DNOSLEEP to disable the automatic sleep after web-page fetches
#               (students, please do not use -DNOSLEEP!)
# add -DMEMTEST for memory tracking report in indexer
# (and run `make clean; make` whenever you change this)
FLAGS = # -DMEMTEST  # -DNOSLEEP

CFLAGS = -Wall -pedantic -std=c11 -ggdb  #-I$(PATHCOMMON) -I$(L)
CC = gcc
MAKE = make
PATHCOMMON = ../common

solver.o: solver.c #$(PATHCOMMON)/common.o

.PHONY: clean test

test: 
	bash -v testing.sh

# clean up after our compilation
clean:
	rm -rf *~ *.o *.dSYM
	rm -rf $(PROG)
