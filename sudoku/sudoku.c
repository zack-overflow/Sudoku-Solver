#include <stdio.h>
#include <string.h>
#include "common.h"
#include "creator.h"
#include "solver.h"

#define ROW 9
#define COL 9
#define N 9

int main(int argc, char *argv[]) {
    if(argc != 2){
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

        sprintf(input, "%s", argv[1]); // save type of action
        if(strcmp(input, "create") == 0) {
            int numofpuzzles = 0;
            boardFillCreator(board);
            ret = generateMissing(board, finalboard);
            boardCheckCreator(board, &numofpuzzles);
            while((ret < 40) && (numofpuzzles !=1)){
                ret = generateMissing(board, finalboard);
                boardCheckCreator(board, &numofpuzzles);
            }
            printBoardCreator(finalboard);
        } else if(strcmp(input, "solve") == 0) {
            fprintf(stdout, "reading in sudoku puzzle . . .\n");
            for(int i = 0; i < 9; i++){
                for(int j = 0; j < 9; j++){
                    scanf("%d", &board[i][j]);
                }
            }
            for(int i = 0; i < 9; i++){
                for(int j = 0; j < 9; j++){
                    originalboard[i][j] = board[i][j];
                }
            }
            fprintf(stdout, "solving sudoku puzzle . . .\n\n");
            boardFillSolver(board);
            printBoardSolver(board);
            for(int i = 0; i < 9; i++){
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
