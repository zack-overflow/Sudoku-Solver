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
#define N 9

void checkMove(int board[ROW][COL], int row, int col, int *listofnums);
void boardFill(int board[ROW][COL]);
int checkBoard(int board[ROW][COL], int row, int col, int value);

/* **************************************** */

int checkBoard(int board[ROW][COL], int row, int col, int value){
    return 1;
}

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
    fprintf(stdout, "column list: ");
    for(i = 0; i <= 9; i++){
        fprintf(stdout, "%d ", listofnums[i]);
    }
    fprintf(stdout, "\n");

    //reset numstaken
    for(i = 0; i <= 9; i++){
        numstaken[i] = 0;
    }


    //check row
    for(i = 0; i < 9; i++){
        index = board[i][col];
        numstaken[index] = index;
    }
    fprintf(stdout, "check\n");
    for(i = 0; i <= 9; i++){
        if(listofnums[i] == numstaken[i]){
            listofnums[i] = 0;
        }
    }
    fprintf(stdout, "row list: ");
    for(i = 0; i <= 9; i++){
        fprintf(stdout, "%d ", listofnums[i]);
    }
    fprintf(stdout, "\n");

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
    fprintf(stdout, "box list: ");
    for(i = 0; i <= 9; i++){
        fprintf(stdout, "%d ", listofnums[i]);
    }
    fprintf(stdout, "\n");
}


void boardFill(int board[ROW][COL]){
    int i;
    int j;
    int k;
    int count = 0;
    srand(time(NULL));   // Initialization, should only be called once.
    int randomnum;
    int listofnums[N+1] = {0};
    int listofoptions[N+1] = {0};


    for (i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            fprintf(stdout, "position: %d %d\n", i, j);

            for(k = 0; k <= 9; k++){
                listofoptions[k] = 0;
            }


            checkMove(board, i, j, listofnums);
            fprintf(stdout, "list of options: ");
            for(k = 0; k <= 9; k++){
                fprintf(stdout, "%d ", listofnums[k]);
            }
            fprintf(stdout, "\n");

            for(k = 0; k <= 9; k++){
                if(listofnums[k] != 0){
                    listofoptions[count] = listofnums[k];
                    count++;
                }
            }
            fprintf(stdout, "final options: ");
            for(k = 0; k < count; k++){
                fprintf(stdout, "%d ", listofoptions[k]);
            }
            fprintf(stdout, "\n");

            randomnum = rand() % count;
            board[i][j] = listofoptions[randomnum];
            fprintf(stdout, "number chosen: %d\n\n", board[i][j]);
            count = 0;
        }
        if(i == 2){
            break;
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

