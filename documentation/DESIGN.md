# Sudoku Design -- Team "git that money"

## User Interface

Our Sudoku game will have a command-line interface (CLI) as well as a graphical user interface (GUI).

The **CLI** will take one command-line argument, which will either be `create` to generate a random Sudoku board to `stdout` or `solve` to solve a board provided via `stdin`. For example:
```bash
./sudoku create > sudokuBoardExample

OR

sudokuBoardExample | ./sudoku solve
```

The **GUI** will allow users to press either `c` to create a new game, which will then be displayed on the screen, or `s` to solve the game currently displayed on the screen.

## Inputs and Outputs

### Creator I/O

#### Inputs

There are no inputs for creation other than the `create` keyword command-line argument in the **CLI** and the keypress of `c` in the **GUI**. The current date and time is used as a seed for the random creation of the board, but this is not technically inputted by the user.

#### Outputs

The randomly created board is outputted to `stdout` in the following format:

* The grid is represented as nine (9) lines of text which correspond to rows of the board
* Each line contains nine (9) integers from 0-9, separated by whitespace
* 0 represents an empty square in the grid

### Solver I/O

#### Inputs

The solver reads a Sudoku board from `stdin` in the format specified above as an input. The solver outputs *only one* solution for a given puzzle, even if multiple solutions are possible. The solution is in the same form in the input except that the 0 squares from the input have been replaced with the integers that produce a solution. Nothing else is changed.

#### Outputs

The solver outputs a solved Sudoku board to `stdout` in the previously specified board text format.

## Functional decomposition into modules

### Common
We anticipate the following modules to be common for creator/solver:
* `checkBoard`, which checks if a board is valid given Sudoku rules
* `printBoard`, which prints a Sudoku board to `stdout`
* `readBoard`, which reads in a Sudoku file stored in the specified format and generates a data structure to hold it
* `Fuzzytesting`, which creates random numbers to fill a board and check for memory leaks

We also anticipate using a custom `sudokuCell` structure to store key information about a particular cell in the Sudoku board

### Creator
We anticipate the following modules for our creator:
* `main`, which parses command-line arguments and intializes/calls the other modules
* `boardUnique`, checks if a valid Sudoku board has a unique solution
* `boardFill`, creates a Sudoku board with 40 blank cells

### Solver
We anticipate the following modules for our solver:
* `main`, which parses command-line arguments and intializes/calls the other modules
* `findMissing`, which locates the next missing cell (cell value equal to 0)
* `solveBoard`, implements algorithm to go through board and fill in each value

## Psuedocode for logical/algorithmic flow

### Creator

* execute from the commandline and make sure commandline parameters are correct (should only be one)
* while the board does not yet have 40 blank cells
    * attempt to make a new blank cell
    * check if this board is valid with a unique solution (basically solve it)
        * if so, continue by making another blank
        * if not, backtrack to pick another option to make a blank space


### Solver

* execute from the commandline and make sure commandline parameters are correct (should only be one)
* while there is still an empty space on the board (it is not solved)
    * find an empty space (0) on the board
    * try one of the remaining values from the "possibilities" array and attempt to solve puzzle
    * if a guess works, update the value of that cell and update the "possibilities" arrays of impacted nodes
    * if at any point that guess causes failure, instead try the above with the next item that was in the "possibilities" array. Be sure to change back any "possibilities" array of nodes that were affected earlier

## Dataflow Through Modules

#### Creator
1. `Main` parses parameters, checks validity, and calls `boardFill`
2. `boardFill` generates random numbers and calls `checkMove` 
3. `checkMove` checks for valid moves and returns
4. `checkBoard` makes sure generated board is valid
5. `printBoard` takes generated board from `boardFill` and prints to `stdout` or to a file

#### Solver
1. `Main` parses parameters and passes them to `readBoard`
2. `readBoard` reads parameters, creates a sudoku board structure, and passes the board to `findMissing`
3. `findMissing` checks board for zeroes and returns
4. `solveBoard` implements algorithm to solve board
5. `checkBoard` recieves solutions from `solveBoard` and checks to see if the solutions found are accurate
6. `printBoard` takes solutions from `solveBoard` and prints to `stdout` or to a file

### Major Data Structures
* sudokuCell structure - stores information about each cell including current value and "possibilities" array of remaining possible values for that cell based on the other cells in its row, column, and 3x3 box
* sudokuBoard - a 2d array that stores the 81 cells in the game

### Testing Plan
* Unit Testing
    * A test program in testing.sh that tests each function from each module to make sure they all work properly

* Fuzzytesting
    * Using the fuzzytesting module we will create in `Common`, we will generate many sets of numbers to input into solver to test for memory leaks and crashes

* Regression Testing
    * After each major change, we will run test code that worked for the previous set of code and make sure the new changes do not prevent the program from running

* Other testing
    * Test various forms of invalid command line arguments
    * Test the `solver` with a puzzle with no solution
    * Test the `solver` with a puzzle with multiple solutions
    * Test the `solver` with the output created by the `creator`
