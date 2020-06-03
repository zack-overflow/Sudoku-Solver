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
#include <common.h>

#define ROW 9
#define COL 9
#define N 9

int findMoveCreator(int board[ROW][COL], int *row, int *col);
int boardFillCreator(int board[ROW][COL]);
int boardCheckCreator(int board[ROW][COL], int *numofpuzzles);
void printBoardCreator(int board[ROW][COL]);
int generateMissing(int board[ROW][COL], int finalboard[ROW][COL]);

/* **************************************** */

void printBoardCreator(int board[ROW][COL]){
    int i,j;
    for (i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            fprintf(stdout, "%d ", board[i][j]);
        }
         fprintf(stdout, "\n");
    }
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

    checkMove(board, row, col, listofnums);

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
        if(isSafe(board, row, col, randomizedlist[i])){
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

    checkMove(board, row, col, listofnums);

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
        if(isSafe(board, row, col, randomizedlist[i])){
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


int generateMissing(int board[ROW][COL], int finalboard[ROW][COL]){
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
