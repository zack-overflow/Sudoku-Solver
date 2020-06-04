# CS50 Project - Sudoku
## Team "git that money"

### Sudoku
This Sudoku is a standalone program that can either create or solve a valid sudoku puzzle. A valid sudoku puzzle is a grid of 9x9 squares divided into 9 smaller 3x3 grids. Each row, column, and smaller grid in the puzzle contains the digits 1 - 9 without overlap.

### Usage
* The Sudoku solver is implemented in `solver.c`.
* The Sudoku creator is implemented in `creator.c`.


To run, **from the sudoku directory** (*not* the root directory), use syntax
```
./sudoku create
```
or
```
./ sudoku solve
```

* The `solver` also reads in a board from `stdin` in a format containing 81 numbers from 0-9, where 0's represent blanks and 1 - 9 represent pre-filled squares
* The `creator` creates a randomized board of 81 numbers from 0 - 9. At least 40 of these numbers will be `0`, which represents a missing number 
* It will print the ind products to stdout

### Exit Status
* Change as more are added
* 0: Ran successfully
* 1: Incorrect number of arguments
* 2: Unrecognized command

### Assumptions
Sudoku will assume that
* Input sudoku puzzles have at least one valid solution
* Input puzzles are in a format containing 81 numbers from 0 - 9
* Given numbers from input boards will not be changed 


### Non-Assumptions
Sudoku will check:
* whether the argument is a valid command, either `solve` or `create`
* for `solve`, whether the solution is unique or just one possibility of multiple

### Implementation
* See `IMPLEMENTATION.md` and `DESIGN.md`
* We implement the `solver` and `creator` separately in their own modules, and put shared code in a `common` module

### Compilation
* To compile creator, solver, and sudoku, simply `make`
* To test all, `make test`
* To clean all, `make clean`
* Each of the above commands also works within the individual directories for all three components
* Note: you will get a warning when compiling creator and solver since they do not have a `main` function. They are written in separate files purely for organizational purposes and not intended to be run, hence why they do not have `main`.

### Project Structure for Main Files
```
.
├── common
│   ├── common.c
│   ├── common.h
│   └── Makefile
├── core
├── creator
│   ├── creator.c
│   ├── creator.h
│   ├── Makefile
│   └── multSolutionTest
├── documentation
│   ├── DESIGN.md
│   ├── IMPLEMENTATION.md
│   └── TESTING.md
├── Makefile
├── README.md
├── solver
│   ├── Makefile
│   ├── solver.c
│   ├── solver.h
│   └── testBoard
├── sudoku
│   ├── Makefile
│   └── sudoku.c
└── testing
    ├── fuzzytesting.c
    ├── Makefile
    ├── randboard.c
    └── testing.sh

6 directories, 24 files

```

