# CS50 Sudoku
## Team Git That Money

### Detailled Pseudocode
#### Creator
int findMoveCreator(int board[ROW][COL], int *row, int *col);
void checkMoveCreator(int board[ROW][COL], int row, int col, int *listofnums);
int boardFillCreator(int board[ROW][COL]);
int boardCheckCreator(int board[ROW][COL], int *numofpuzzles);
int checkBoardCreator(int board[ROW][COL], int row, int col, int value);
int isSafeCreator(int board[ROW][COL], int row, int col, int value);
void printBoardCreator(int board[ROW][COL]);
int generateMissingCreator(int board[ROW][COL], int finalboard[ROW][COL]);

#### Solver

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
