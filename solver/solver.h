/* 
 * solver.h - CS50 'solver' header file
 *
 * Defines interface for solver module
 *
 * Stuart Hayes, Sherry Liu, Natalie Ogbuagu, Zack Gottesman, June 2020
 */


#define ROW 9
#define COL 9
#define N 9

/********** boardFillSolver **********/
/* The boardFill function for the solver. It takes an empty board and fills it
 * with randomly generated numbers until it is a valid (solved sudoku board.
 * It differs from the creator version in that it doesn't look to fill
 * the board such that there is a unqiue solution, instead just looking
 * for any solution.
 */
int boardFillSolver(int board[ROW][COL]);

/********** printBoardSolver **********/
/* The printBoard function for the solver. It prints out a sudoku board from
 * memory and differs from the creator's printBoard because
 * it formats the output.
 */
void printBoardSolver(int board[ROW][COL]);
