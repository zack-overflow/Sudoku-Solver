/* Sudoku Project
 *
 * Team Git That Money
 *
 * CS 50 Spring 2020
 */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){


	// Checks for arguments
	if (argc != 3){
		fprintf(stderr, "usage: ./fuzzytesting numBoards randomSeed\n");
		return 1;
	}

	int numBoards;
	int randomSeed;
	if ((sscanf(argv[1], "%d", &numBoards) != 1) || (sscanf(argv[2], "%d", &randomSeed) != 1)){
		fprintf(stderr, "Error: Invalid format of input\n");
		return 2;
	} else if ((numBoards < 0) || (randomSeed < 0)){
		fprintf(stderr, "Error: Inputs must be greater than zero\n");
		return 3;
	}

	// Set random seed
	srand(randomSeed);
	int count = 0;
	
	while (count != numBoards){

		// For each number in a Sudoku board
		for (int i = 0; i < 81; i = i + 1){

			// Generate random numbers from 1 to 18
			int generatedRand = rand() % 18;

			// Sets the probability for a 0 to 50%, to mirror the number from 'creator'
			if (generatedRand >= 10){
				generatedRand = 0;
			}

			printf("%d ", generatedRand);
		}

		printf("\n");
		count = count + 1;
	}


	return 0;
}



