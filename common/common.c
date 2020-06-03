#define ROW 9
#define COL 9
#define N 9
#include "common.h"

void checkMove(int board[ROW][COL], int row, int col, int *listofnums){
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
}

int isSafe(int board[ROW][COL], int row, int col, int value){
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
