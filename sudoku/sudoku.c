#include <stdio.h>
#include <string.h>
#include "common.h"
#include "creator.h"
#include "solver.h"

#define ROW 9
#define COL 9
#define N 9

int main(int argc, char *argv[]) {
    if(argc != 2){ //check for correct arguments
        fprintf(stderr, "Error: incorrect number of arguments.\nExpected usage: ./sudoku [create/solve]\n");
        return 1;
    } else {
        // values used by both creator and solver
        char input[200];
        int board[ROW][COL] = {0};
        int originalboard[ROW][COL] = {0};
        int finalboard[ROW][COL] = {0};
        int ret;
        int errorflag;
        int temp;

        sprintf(input, "%s", argv[1]); // save type of action
        if(strcmp(input, "create") == 0) {
            int numofpuzzles = 0;
            boardFillCreator(board); //create board
            ret = generateMissing(board, finalboard); //add zeros in
            boardCheckCreator(board, &numofpuzzles); //ensure board is still unique after adding in zeros
            while((ret < 40) && (numofpuzzles !=1)){ //run until number of zeros is greater than 40 and the only one solution
                ret = generateMissing(board, finalboard);
                boardCheckCreator(board, &numofpuzzles);
            }
            printBoardCreator(finalboard); //print board
        } else if(strcmp(input, "solve") == 0) {
            fprintf(stdout, "reading in sudoku puzzle . . .\n");
            for(int i = 0; i < 9; i++){ //read in board
                for(int j = 0; j < 9; j++){
                    scanf("%d", &board[i][j]);
		    
                }
            }
            for(int i = 0; i < 9; i++){ //check that board inputted is valid everywhere
                for(int j = 0; j < 9; j++){
                    if(board[i][j] != 0){
                        temp = board[i][j];
                        board[i][j] = 0;
                        if(isSafe(board, i, j, temp) == 0){
                            fprintf(stderr, "Error: board inputted is invalid\n");
                            return 0;
                        }
                        board[i][j] = temp;
                    }
                    originalboard[i][j] = board[i][j];
                }
            }
            fprintf(stdout, "solving sudoku puzzle . . .\n\n");
            boardFillSolver(board); //solve board
            printBoardSolver(board); //print board
            for(int i = 0; i < 9; i++){ //check that board was not changed by solver
                for(int j = 0; j < 9; j++){
                    if(originalboard[i][j] != 0){
                        if(originalboard[i][j] != board[i][j]){
                            errorflag = 1;
                        }
                    }
                }
            }
            if(errorflag == 1){
                fprintf(stdout, "Error: solver altered original puzzle\n");
            }
        } else {
            fprintf(stderr, "unrecognized command. recognized commands: [create/solve]\n");
            return 2;
        }

        return 0;
    }
}
