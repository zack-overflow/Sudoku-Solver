/* 
 * common.h - CS50 'common' header
 *
 * Defines interface for the collection of common functions between
 * the sudoku creator and solver
 *
 * Stuart Hayes, Sherry Liu, Natalie Ogbuagu, Zack Gottesman, June 2020
 */

#define ROW 9
#define COL 9
#define N 9

/********** checkMove **********/
/* A function to look at a particular place in the board and generate a list
 * of numbers that could possibly be placed there since they don't have
 * conflicts with neighboring rows, columns, or boxes.
 */
void checkMove(int board[ROW][COL], int row, int col, int *listofnums);

/********** isSafe **********/
/* A function to check in a particular value is valid at a specific
 * spot on the board/
 */
int isSafe(int board[ROW][COL], int row, int col, int value);