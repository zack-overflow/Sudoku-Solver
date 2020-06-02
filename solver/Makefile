# object files, and the target library
#L=../libcs50


PROG = solver
OBJS = solver.o #../common/pagedir.o
#LIB = $(L)/libcs50.a
LIBS = 

# add -DNOSLEEP to disable the automatic sleep after web-page fetches
#               (students, please do not use -DNOSLEEP!)
# add -DMEMTEST for memory tracking report in indexer
# (and run `make clean; make` whenever you change this)
FLAGS = # -DMEMTEST  # -DNOSLEEP

CFLAGS = -Wall -pedantic -std=c11 -ggdb -c #-I$(PATHCOMMON) -I$(L)
CC = gcc
MAKE = make
#PATHCOMMON = ../common


$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@


# Dependencies: object files depend on header files
creator.o: #common.a #crawler.h

.PHONY: all clean test

all: solver #pagedir

test: 
	bash -v testing.sh

# clean up after our compilation
clean:
	rm -rf *~ *.o *.dSYM
	rm -rf $(PROG)