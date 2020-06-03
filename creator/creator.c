/* 
 * creator.c - CS50 'creator' module
 *
 * Module to generate a sudoku puzzle with a unique solution.
 * see README.md and DESIGN.md for more information.
 *
 * Stuart Hayes, Sherry Liu, Natalie Ogbuagu, Zack Gottesman, June 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include <unistd.h>
#include "common.h"
#include "creator.h"

#define ROW 9
#define COL 9
#define N 9

// local functions
int findMoveCreator(int board[ROW][COL], int *row, int *col);

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
    srand(time(NULL));
    for(i = 0; i < count; i++){
        randomnum = rand() % count;  
        srand(rand()+(row*9)+col); 
        while(randomizedindexes[randomnum] != 0){
            randomnum = rand() % count;
        }
        randomizedindexes[randomnum] = 1;
        randomizedlist[i] = listofoptions[randomnum];
    }

    for(i = 0; i < count; i++){
        if(isSafe(board, row, col, randomizedlist[i])){
            board[row][col] = randomizedlist[i];
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
    srand(time(NULL));
    for(i = 0; i < count; i++){
        randomnum = rand() % count;  
        srand(rand()+(row*9)+col);
        while(randomizedindexes[randomnum] != 0){
            randomnum = rand() % count;
        }
        randomizedindexes[randomnum] = 1;
        randomizedlist[i] = listofoptions[randomnum];
    }

    for(i = 0; i < count; i++){
        if(isSafe(board, row, col, randomizedlist[i])){
            board[row][col] = randomizedlist[i];
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
