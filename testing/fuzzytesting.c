/* Sudoku Project
 *
 * Fuzzytesting
 *
 * Team Git That Money
 *
 * CS 50 Spring 2020
 */

#include <stdlib.h>
#include <stdio.h>
#include "common.h"
#include "creator.h"

int main(int argc, char* argv[]){


	// Checks for arguments
	if (argc != 2){
		fprintf(stderr, "usage: ./fuzzytesting numBoards\n");
		return 1;
	}

	int numBoards;

	if (sscanf(argv[1], "%d", &numBoards) != 1){
		fprintf(stderr, "Error: Invalid format of input\n");
		return 2;
	} else if (numBoards < 0){
		fprintf(stderr, "Error: Inputs must be greater than zero\n");
		return 3;
	}


	// Make 'numBoards' number of boards
	for (int i = 0; i < numBoards; i = i + 1){
		
		// Call creator
		int numofpuzzles = 0;
		int board[ROW][COL] = {0};
		int finalboard[ROW][COL] = {0};
		int ret;

		boardFillCreator(board);
		ret = generateMissing(board, finalboard);
		boardCheckCreator(board, &numofpuzzles);
		while((ret < 40) && (numofpuzzles !=1)){
			ret = generateMissing(board, finalboard);
			boardCheckCreator(board, &numofpuzzles);
		}
		printBoardCreator(finalboard);
	}
	return 0;
}


