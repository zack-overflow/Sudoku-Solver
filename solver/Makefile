
PROG = solvertest
PATHCOMMON = ../common
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I$(PATHCOMMON)
CC = gcc
MAKE = make
UNITTEST = -DMYTEST

solver.o: solver.h $(PATHCOMMON)/common.o

$(PROG): $(PATHCOMMON)/common.o solver.c
	$(CC) $(CFLAGS) $(UNITTEST) $^ -o $@

.PHONY: clean test valgrind

test: $(PROG)
	./$(PROG)

valgrind: $(PROG)
	valgrind --track-origins=yes ./$(PROG)

# clean up after our compilation
clean:
	rm -rf *~ *.o *.dSYM vgcore*
	rm -rf $(PROG)
