#define ROW 9
#define COL 9
#define N 9

int boardFillCreator(int board[ROW][COL]);
int boardCheckCreator(int board[ROW][COL], int *numofpuzzles);
void printBoardCreator(int board[ROW][COL]);
int generateMissing(int board[ROW][COL], int finalboard[ROW][COL]);