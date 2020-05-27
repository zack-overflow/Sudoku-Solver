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

#define ROW 9
#define COL 9

int checkMove(int board[ROW][COL], int row, int col, int value);
void boardFill(int board[ROW][COL]);
int checkBoard(int board[ROW][COL], int row, int col, int value);

/* **************************************** */

int checkBoard(int board[ROW][COL], int row, int col, int value){
    return 1;
}

int checkMove(int board[ROW][COL], int row, int col, int value){
    int i, j;
    int rowmod;
    int rowstart;
    int colmod;
    int colstart;

    //check column
    for(i = 0; i < 9; i++){
        if(board[row][i] == value){
            return 0;
        }
    }

    //check row
    for(i = 0; i < 9; i++){
        if(board[i][col] == value){
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


void boardFill(int board[ROW][COL]){
    int i;
    int j;
    int valid;
    srand(time(NULL));   // Initialization, should only be called once.
    int randomnum;


    for (i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            //fprintf(stdout, "position: %d %d \n", i, j);
            randomnum = rand() % 10;
            if(randomnum < 5){
                board[i][j] = 0;
            }
            else{
                randomnum = rand() % 10;
                valid = checkMove(board, i, j, randomnum);
                //fprintf(stdout, "valid move\n");
                while(valid != 1){
                    randomnum = rand() % 10;
                    valid = checkMove(board, i, j, randomnum);
                }
                board[i][j] = randomnum;
            }
        }
    }

    for (i = 0; i < 9; i++){
        fprintf(stdout, "\n");
        for(j = 0; j < 9; j++){
            fprintf(stdout, "%d ", board[i][j]);
        }
    }
    fprintf(stdout, "\n");

    // for (i = 0; i < 9; i++){
    //     for(j = 0; j < 9; j++){
    //         randomnum = rand() % 10;
    //         if(randomnum < 5){
    //             board[i][j] = 0;
    //         }
    //     }
    // }

    // for (i = 0; i < 9; i++){
    //     fprintf(stdout, "\n");
    //     for(j = 0; j < 9; j++){
    //         fprintf(stdout, "%d ", board[i][j]);
    //     }
    // }
    // fprintf(stdout, "\n");
}

int main(int argc, char *argv[]){

    char input[200]; 
    int board[ROW][COL] = {0};

    if(argc != 2){ //command line does not match required input
        fprintf(stderr, "Error: incorrect number of arguments.\nExpected usage: ./creator create\n");
    }
    else{
        sprintf(input, "%s", argv[1]); //save first argument to pageDirectory
        if(strcmp(input, "create") == 0){
            fprintf(stdout, "creating sodoku puzzle . . .\n");
            boardFill(board);
            //printBoard(board);
        }
        else{
            fprintf(stderr, "unrecognized command. recognized commands: [create]\n");
        }

        return 0;
    }

}

