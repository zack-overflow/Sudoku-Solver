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
* `checkmove`, checks the row, column, and box for a cell and see what numbers are still available to put there 
* `isSafe`, checks if it is valid to input a certain value at a certain position in the board

### Creator
We anticipate the following modules for our creator:
* `boardCheckCreator`, checks if a valid Sudoku board has a unique solution
* `boardFillCreator`, creates a Sudoku board that follows sudoku rules
* `printBoardCreator`, prints formatted board
* `generateMissing`, replaces numbers on valid board with 0

### Solver
We anticipate the following modules for our solver:
* `boardFillSolver`, implements algorithm to go through board and fill in each value
* `printBoardSolver`, prints formatted board

### Solver
We anticipate the following modules for our solver:
* `main`, which parses arguments and initializes other modules

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
1. `boardFillCreator` generates random numbers using recursion and calls `checkMove`, `isSafe` and `findmovecreator`
2. `checkMove` checks for valid moves 
3. `isSafe` makes sure an input is valid
4. `findmovecreator` finds the next available move in the board
5. `boardCheckCreator` checks the uniqueness of the solution of the board using recursion and calls `checkMove`, `isSafe` and `findmovecreator`
6. `generateMissing` generates missing cells in the board
7. `printBoardCreator` prints board

#### Solver
1. `boardFillSolver` calls on `findMoveSolver`, `checkMove`, `isSafe` and uses recursion to solve the board 
2. `findMoveSolver` calls on `checkMove` and finds the next cell that needs to be solved
3. `printBoardSolver` prints board


#### Sudoku
1. `Main` parses parameters, checks validity of parameters, initializes modules

### Major Data Structures
* We use a 9 x 9 2D array of integers to store each value in the sudoku board.

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
    * Test the `solver` with the output created by the `creator
