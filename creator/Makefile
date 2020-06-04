PROG = creatortest
PATHCOMMON = ../common
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I$(PATHCOMMON)
CC = gcc
MAKE = make
UNITTEST = -DMYTEST


# Dependencies: object files depend on header files
creator.o: creator.h $(PATHCOMMON)/common.o

$(PROG): $(PATHCOMMON)/common.o creator.c
	$(CC) $(CFLAGS) $(UNITTEST) $^ -o $@

.PHONY: clean test

test: $(PROG)
	./$(PROG)
	

# clean up after our compilation
clean:
	rm -rf *~ *.o *.dSYM
	rm -rf $(PROG)
