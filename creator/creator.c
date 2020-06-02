/* 
 * creator.c - CS50 'creator' module
 *
 * see README.md for more information.
 *
 * Stuart Hayes, May 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include <unistd.h>

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

/* **************************************** */

int checkBoardCreator(int board[ROW][COL], int row, int col, int value){
    return 1;
}

void printBoardCreator(int board[ROW][COL]){
    int i,j;
    for (i = 0; i < 9; i++){
        // if((i % 3) == 0){
        //     fprintf(stdout, "-------------------------");
        // }
        for(j = 0; j < 9; j++){
            // if((j % 3) == 0){
            //     fprintf(stdout, "| ");
            // }
            fprintf(stdout, "%d ", board[i][j]);
        }
         fprintf(stdout, "\n");
        //fprintf(stdout, "|\n");
    }
    // fprintf(stdout, "-------------------------");
    fprintf(stdout, "\n");
}

int findMoveCreator(int board[ROW][COL], int *row, int *col){
    for((*row) = 0; (*row) < 9; (*row)++){
        for((*col) = 0; (*col) < 9; (*col)++){
            if(board[*row][*col] == 0){
                return 1;
            }
        }
    }
    return 0;
}

void checkMoveCreator(int board[ROW][COL], int row, int col, int *listofnums){
    int i, j;
    int rowmod;
    int rowstart;
    int colmod;
    int colstart;
    int index;
    int numstaken[N+1] = {0};

    for(i = 0; i <= 9; i++){
        listofnums[i] = 0;
    }

    //check column
    for(i = 0; i < 9; i++){
        index = board[row][i];
        numstaken[index] = index;
    }
    for(i = 0; i <= 9; i++){
        if(numstaken[i] == 0){
            listofnums[i] = i;
        }
    }
    // fprintf(stdout, "column list: ");
    // for(i = 0; i <= 9; i++){
    //     fprintf(stdout, "%d ", listofnums[i]);
    // }
    // fprintf(stdout, "\n");

    //reset numstaken
    for(i = 0; i <= 9; i++){
        numstaken[i] = 0;
    }


    //check row
    for(i = 0; i < 9; i++){
        index = board[i][col];
        numstaken[index] = index;
    }
    //fprintf(stdout, "check\n");
    for(i = 0; i <= 9; i++){
        if(listofnums[i] == numstaken[i]){
            listofnums[i] = 0;
        }
    }
    // fprintf(stdout, "row list: ");
    // for(i = 0; i <= 9; i++){
    //     fprintf(stdout, "%d ", listofnums[i]);
    // }
    // fprintf(stdout, "\n");

    //reset numstaken
    for(i = 0; i <= 9; i++){
        numstaken[i] = 0;
    }

    //check box
    rowmod = row % 3;
    colmod = col % 3;

    rowstart = row - rowmod;
    colstart = col - colmod;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            index = board[rowstart + i][colstart + j];
            numstaken[index] = index;
        }
    }
    for(i = 0; i <= 9; i++){
        if(listofnums[i] == numstaken[i]){
            listofnums[i] = 0;
        }
    }
    // fprintf(stdout, "box list: ");
    // for(i = 0; i <= 9; i++){
    //     fprintf(stdout, "%d ", listofnums[i]);
    // }
    // fprintf(stdout, "\n");
}

int isSafeCreator(int board[ROW][COL], int row, int col, int value){
    int i, j;
    int rowmod;
    int rowstart;
    int colmod;
    int colstart;

    //check column
    for(i = 0; i < 9; i++){
        if(board[i][col] == value){
            return 0;
        }
    }

    //check row
    for(i = 0; i < 9; i++){
        if(board[row][i] == value){
            return 0;
        }
    }

    //check box
    rowmod = row % 3;
    colmod = col % 3;
    rowstart = row - rowmod;
    colstart = col - colmod;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(board[rowstart + i][colstart + j] == value){
                return 0;
            }
        }
    }

    return 1;
}


int boardFillCreator(int board[ROW][COL]){
    int i;
    int k;
    int count = 0;
    int randomnum;
    //int multiplier;
    int listofnums[N+1] = {0};
    int listofoptions[N+1] = {0};
    int randomizedlist[N+1] = {0};
    int randomizedindexes[N+1] = {0};
    int row, col;

    if(findMoveCreator(board, &row, &col) == 0){
        return 1;
    }

    for(k = 0; k <= 9; k++){
        listofoptions[k] = 0;
    }

    checkMoveCreator(board, row, col, listofnums);

    for(k = 0; k <= 9; k++){
        if(listofnums[k] != 0){
            listofoptions[count] = listofnums[k];
            count++;
        }
    }
    // fprintf(stdout, "final options: ");    
    // for(k = 0; k < count; k++){
    //     fprintf(stdout, "%d ", listofoptions[k]);
    // }
    // fprintf(stdout, "\n");
    // fprintf(stdout, "randomized list: ");
    for(i = 0; i < count; i++){
        srand(time(NULL));
        randomnum = rand() % count;  
        srand(rand()+(row*9)+col); 
        while(randomizedindexes[randomnum] != 0){
            randomnum = rand() % count;
        }
        randomizedindexes[randomnum] = 1;
        //fprintf(stdout, "random number: %d\n", randomnum);
        randomizedlist[i] = listofoptions[randomnum];
        //fprintf(stdout, "%d ", randomizedlist[i]);
    }
    //fprintf(stdout, "\n");

    for(i = 0; i < count; i++){
        //fprintf(stdout, "position: %d %d\n", row, col);
        if(isSafeCreator(board, row, col, randomizedlist[i])){
            board[row][col] = randomizedlist[i];
            //fprintf(stdout, "number chosen: %d\n", randomizedlist[i]);
            if(boardFillCreator(board) == 1){
                return 1;
            }
        }
    }
    board[row][col] = 0;
    return 0;
}

int boardCheckCreator(int board[ROW][COL], int *numofpuzzles){
    int i;
    int k;
    int count = 0;
    int randomnum;
    //int multiplier;
    int listofnums[N+1] = {0};
    int listofoptions[N+1] = {0};
    int randomizedlist[N+1] = {0};
    int randomizedindexes[N+1] = {0};
    int row, col;

    if(findMoveCreator(board, &row, &col) == 0){
        (*numofpuzzles)++;
        return 0;
    }

    for(k = 0; k <= 9; k++){
        listofoptions[k] = 0;
    }

    checkMoveCreator(board, row, col, listofnums);

    for(k = 0; k <= 9; k++){
        if(listofnums[k] != 0){
            listofoptions[count] = listofnums[k];
            count++;
        }
    }
    // fprintf(stdout, "final options: ");    
    // for(k = 0; k < count; k++){
    //     fprintf(stdout, "%d ", listofoptions[k]);
    // }
    // fprintf(stdout, "\n");
    // fprintf(stdout, "randomized list: ");
    for(i = 0; i < count; i++){
        srand(time(NULL));
        randomnum = rand() % count;  
        srand(rand()+(row*9)+col);
        while(randomizedindexes[randomnum] != 0){
            randomnum = rand() % count;
        }
        randomizedindexes[randomnum] = 1;
        //fprintf(stdout, "random number: %d\n", randomnum);
        randomizedlist[i] = listofoptions[randomnum];
        //fprintf(stdout, "%d ", randomizedlist[i]);
    }
    //fprintf(stdout, "\n");

    for(i = 0; i < count; i++){
        //fprintf(stdout, "position: %d %d\n", row, col);
        if(isSafeCreator(board, row, col, randomizedlist[i])){
            board[row][col] = randomizedlist[i];
            //fprintf(stdout, "number chosen: %d\n", randomizedlist[i]);
            if(boardCheckCreator(board, numofpuzzles) == 1){
                return 1;
            }
        }
    }
    board[row][col] = 0;
    return 0;
}


int generateMissingCreator(int board[ROW][COL], int finalboard[ROW][COL]){
    int i, j, randomnum, count;
    srand(time(NULL));
    for (i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            finalboard[i][j] = board[i][j];
        }
    }
    for (i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            randomnum = rand() % 10;
            if(randomnum < 5){
                finalboard[i][j] = 0;
                count++;
            }
        }
    }
    return count;
}
