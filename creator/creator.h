#define ROW 9
#define COL 9
#define N 9

int findMoveCreator(int board[ROW][COL], int *row, int *col);
void checkMoveCreator(int board[ROW][COL], int row, int col, int *listofnums);
int boardFillCreator(int board[ROW][COL]);
int boardCheckCreator(int board[ROW][COL], int *numofpuzzles);
int checkBoardCreator(int board[ROW][COL], int row, int col, int value);
int isSafeCreator(int board[ROW][COL], int row, int col, int value);
void printBoardCreator(int board[ROW][COL]);
int generateMissingCreator(int board[ROW][COL], int finalboard[ROW][COL]);