# CS50 Sudoku
## Team Git That Money

### Detailled Pseudocode
### Creator
#### main
* Checks arguments to see if they match the format 
	i. Returns if error
* Checks argument to see if it is `create`
* Calls `boardFillCreator` and gives it an empty board, a 9x9 2d array of 0's

#### Start Recursion Here

#### boardFillCreator
* calls `findMoveCreator`, passes in board and pointers to the row and column 

#### findMoveCreator
* Takes in board and pointers integers row and col
* Loops over all rows and columns in the board
* It returns 1 once it finds the first blank in the board, represented with a '0'
* Otherwise, it returns 0

#### boardFillCreator
* Creates an array of 9 integers that represents possible moves, initialized to zero
* Calls `checkMove`, which takes board, row, col, and a list of 10 integers initialized to 0

#### checkMove
* Checks each row, column, and box of 3 x 3 to see if it has all numbers 1 - 9

#### boardFillCreator
* Generates a list of random numbers from 1 - 9
* Adds generated random numbers to list
* Calls `isSafe`

#### isSafe
* Checks each row, column, and box of 3 x 3 to see if the move that is being made is safe, or if that value is already there

#### boardFillCreator
* If `isSafe` confirms that it is a valid move, 
* Add the list of generated random numbers to the puzzle
* Recursively call `boardFillCreator` until `findmoveCreator` fails to find another blank space

#### End Recursion Here

#### main
* Passes `board`, which has been filled out, and `finalBoard`, an empty board, to `generateMissing`

#### generateMissing
* Takes two boards (9x9 arrays of integers) as parameters, one of which is filled out and one of which is not
* Set a random seed
* Copy all elements of `board`, which has been filled, into `finalBoard`, which is empty
* Loop over all elements of the `finalBoard`
* Generate a random number from 0 - 9
* If the value is less than five, make that element of the `finalBoard` a zero; this will delete half of the elements
* Returns number of zeroes created

#### main
* Passes board and a pointer to an integer to boardCheckCreator

#### boardCheckCreator
* Calls `findMoveCreator`, which loops over all elements of the board and checks for blanks
	i. Returns if there is a blank
* Calls `checkMove`, which checks each row and column to see if it has all elements 1 - 9
* Creates a list of 9 random numbers
* For each element of the list of random numbers
* Call `isSafe` to check if each move made is a valid move
* Recursively call `boardCheckCreator` until it provides a unique solution

#### main
* While the puzzle is not unique or there are less than 40 blank spaces
* Call `generateMissing` and `boardCheckCreator`
* Calls `printBoardCreator` to print the board

#### printBoardCreator
* Loops over each element of the board
* Prints out the value of each element
* Between the 3rd and 6th rows, prints a row of `--` to separate into blocks vertically
* Between the 3rd and 6th columns, prints a `|` to separate the blocks horizontally

### Solver

### Interface, Prototypes and Parameters
* User interfaces with function through command line, which takes one argument
* The command line argument is eitehr `solve` or `create`
* `Solver` also interfaces with the user through `stdin`, where the user provides the sudoku puzzle to be solved
* Function prototypes exist for all helper functions
* See README for more details


### Data Structures
* Both `solver` and `creator` use a 2D array data structure of `int`'s
* We did not use our own data structures


### Security and Privacy
* User has access to `main` in sudoku.c, which calls either `solver` or `creator`
* User has access to helper functions for `solver` and `creator`, many of which are safety checks for the respective files


### Error handling and recovery
* If there is a problem with command line arguments, prints error to `stderr` and returns an integer
* If an input board is invalid, it will print an error message to `stdout`


### Persistent Storage
* No persistent storage is created by either `solver` or `creator`.
* User may decide to redirect created sudoku puzzle to new file
