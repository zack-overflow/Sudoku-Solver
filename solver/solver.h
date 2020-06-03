#define ROW 9
#define COL 9
#define N 9

int findMove(int board[ROW][COL], int *row, int *col);
void checkMove(int board[ROW][COL], int row, int col, int *listofnums);
int boardFill(int board[ROW][COL]);
int checkBoard(int board[ROW][COL], int row, int col, int value);
int isSafe(int board[ROW][COL], int row, int col, int value);
void printBoard(int board[ROW][COL]);
int generateMissing(int board[ROW][COL], int finalboard[ROW][COL]);
