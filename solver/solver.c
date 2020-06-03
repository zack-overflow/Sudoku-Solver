/* 
 * solver.c - CS50 'solver' module
 *
 * Module to solve a sudoku puzzle and print the solution.
 * see README.md and DESIGN.md for more information.
 *
 * Stuart Hayes, Sherry Liu, Natalie Ogbuagu, Zack Gottesman, June 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include "common.h"
#include "solver.h"

#define ROW 9
#define COL 9
#define N 9

// local functions
int findMoveSolver(int board[ROW][COL], int *row, int *col);

/* **************************************** */

void printBoardSolver(int board[ROW][COL]){
    int i,j;
    for (i = 0; i < 9; i++){
        if((i % 3) == 0){
            fprintf(stdout, "-------------------------");
        }
        fprintf(stdout, "\n");
        for(j = 0; j < 9; j++){
            if((j % 3) == 0){
                fprintf(stdout, "| ");
            }
            fprintf(stdout, "%d ", board[i][j]);
        }
        fprintf(stdout, "|\n");
    }
    fprintf(stdout, "-------------------------");
    fprintf(stdout, "\n");
}

int findMoveSolver(int board[ROW][COL], int *row, int *col){
    int listofoptions[N+1] = {0};
    int listofnums[N+1] = {0};
    int k;
    int count = 0;
    int min = 10;
    int bestrow;
    int bestcol;
    int flag = 0;

    for((*row) = 0; (*row) < 9; (*row)++){
        for((*col) = 0; (*col) < 9; (*col)++){
            if(board[*row][*col] == 0){
                flag = 1;
                checkMove(board, *row, *col, listofnums);
                for(k = 0; k <= 9; k++){
                    if(listofnums[k] != 0){
                        listofoptions[count] = listofnums[k];
                        count++;
                    }
                }
                if(count < min){
                    bestrow = *row;
                    bestcol = *col;
                }
            }
        }
    }
    *row = bestrow;
    *col = bestcol;
    return flag;
}

int boardFillSolver(int board[ROW][COL]){
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

    if(findMoveSolver(board, &row, &col) == 0){
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
            if(boardFillSolver(board) == 1){
                return 1;
            }
        }
    }
    board[row][col] = 0;
    return 0;
}
