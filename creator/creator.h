/* 
 * creator.h - CS50 'creator' header
 *
 * Defines interface for the creator module of the sudoku game
 *
 * Stuart Hayes, Sherry Liu, Natalie Ogbuagu, Zack Gottesman, June 2020
 */

#define ROW 9
#define COL 9
#define N 9

/********** boardFillCreator **********/
/* The boardFill function for the creator. It takes an empty board and fills it
 * with randomly generated numbers to make a valid sudoku board. Also, it fills
 * the board with a unique solution, not finsihing until such a solution
 * is generated.
 */
int boardFillCreator(int board[ROW][COL]);

/********** boardCheckCreator **********/
/* The boardCheck function for the creator. It takes in an unsolved board and
 * a pointer to an integer and changes the integer to the number of solutions
 * possible for that board.
 */
int boardCheckCreator(int board[ROW][COL], int *numofpuzzles);

/********** printBoardCreator **********/
/* The printBoard function for the creator. It prints nine lines to stdout,
 * one for each row of the sudoku board. Each row has nine numbers separated
 * by spaces.
 */
void printBoardCreator(int board[ROW][COL]);

/********** generateMissing **********/
/* The function to generate missing cells in a previously full board. Unique to
 * the creator, it takes a filled baord and then randomly picks spots to
 * place zeros. Given a full board, zeros are placed in different places until
 * the unsolved board generated has a unique solution (the one you made).
 */
int generateMissing(int board[ROW][COL], int finalboard[ROW][COL]);