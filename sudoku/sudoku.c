#include <stdio.h>
#include <creator.h>
#include <solver.h>

int main(int argc, char *argv[]){

    if(argc != 2){ //command line does not match required input
        fprintf(stderr, "Error: incorrect number of arguments.\n
                         Expected usage: ./sudoku [create/solve]\n");
    }
    else{
        sprintf(input, "%s", argv[1]); //save first argument to pageDirectory
        if(strcmp(input, "create") == 0) {
            fprintf(stdout, "creating sodoku puzzle . . .\n");
            //while((ret = boardFill(board)) != 1){}
            boardFill(board);
            printBoard(board);
            ret = generateMissing(board, finalboard);
            while(ret < 40){
                ret = generateMissing(board, finalboard);
                fprintf(stdout, "Missing numbers: %d", ret);
            }
            printBoard(finalboard);
        }
        else if(strcmp(input, "solve") == 0) {
            fprintf(stdout, "solving given puzzle . . . \n");
            int board[ROW][COL] = readBoard();
            solveBoard(board);
        }
        else{
            fprintf(stderr, "unrecognized command. recognized commands: [create/solve]\n");
        }

        return 0;
    }

}
