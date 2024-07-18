// PA 7: Final Project
// Author: Erin Keith
// Date: 7/17/2024
// half of battleship

#include <stdio.h>
#include <stdbool.h>
#define SIZE 10
#define EASY_FILE "easy.txt"

void clearBoard(char board[][SIZE]);
void displayBoard(char board[][SIZE]);
int loadShips(FILE* fin, char board[][SIZE]);
int playGame(char guesses[][SIZE], char ships[][SIZE]);
bool won(char guesses[][SIZE], char ships[][SIZE]);
bool validMove(int colMove, char rowMove);

int main(){
	char guesses[SIZE][SIZE], ships[SIZE][SIZE];
	FILE* fptr;
	char playAgain;
	int playerTurns, numShipSpots;

	fptr = fopen(EASY_FILE, "r");
	if(fptr == NULL){
		printf("Cannot load game. Exiting...\n");
		return 0;
	}

	numShipSpots = loadShips(fptr, ships);
	fclose(fptr);

	do{
		clearBoard(guesses);
		playerTurns = playGame(guesses, ships);

		displayBoard(guesses);
		printf("CONGRATULATIONS!!!!\n");
		printf("It took %d turns for you to hit %d "
			"spots and destroy all the ships\n", playerTurns, numShipSpots);
		printf("Your score is %d!\n", 100 - playerTurns + numShipSpots);

		printf("Play again? (Y/N) ");
		scanf(" %c", &playAgain);
	}while(playAgain == 'Y' || playAgain == 'y');
	
	return 0;
}

void clearBoard(char board[][SIZE]){
	for(int rowI = 0; rowI < SIZE; rowI++){
		for(int colI = 0; colI < SIZE; colI++){
			board[rowI][colI] = ' ';
		}
	}
}

void displayBoard(char board[][SIZE]){
	printf("   A B C D E F G H I J\n");
	for(int rowI = 0; rowI < SIZE; rowI++){
		if(rowI == SIZE - 1){
			printf("%d ", rowI + 1);
		}
		else{
			printf("%d  ", rowI + 1);
		}
		
		for(int colI = 0; colI < SIZE; colI++){
			printf("%c ", board[rowI][colI]);
		}
		printf("\n");
	}
}


int loadShips(FILE* fin, char board[][SIZE]){
	char pacman;
	int shipSpots = 0;

	for(int rowI = 0; rowI < SIZE; rowI++){
		for(int colI = 0; colI < SIZE; colI++){
			fscanf(fin, "%c", &board[rowI][colI]);
			if(board[rowI][colI] == 'S'){
				shipSpots++;
			}
		}
		fscanf(fin, "%c", &pacman);
	}
	return shipSpots;
}

int playGame(char guesses[][SIZE], char ships[][SIZE]){
	int moveRow, moveCol;
	int numFires = 0;
	char userCol;
	
	do{
		displayBoard(guesses);

		printf("Fire away!\n(enter a square in the grid like A1) ");
		scanf(" %c%d", &userCol, &moveRow);

		while(!validMove(userCol, moveRow)){
			printf("Try again!\n(enter a square in the grid like A1) ");
			scanf(" %c%d", &userCol, &moveRow);	
		}

		moveRow--;
		moveCol = userCol - 'A';

		if(ships[moveRow][moveCol] == 'S'){
			guesses[moveRow][moveCol] = 'X';
		}
		else{
			guesses[moveRow][moveCol] = 'O';
		}

		numFires++;
	}while(!won(guesses, ships));

	return numFires;
}

bool won(char guesses[][SIZE], char ships[][SIZE]){
	for(int rowI = 0; rowI < SIZE; rowI++){
		for(int colI = 0; colI < SIZE; colI++){
			if(ships[rowI][colI] == 'S' && guesses[rowI][colI] != 'X'){
				return false;
			}
		}
	}
	return true;
}

bool validMove(int colMove, char rowMove){
	if(colMove > 'J' || colMove < 'A'){
		printf("Invalid column letter.\n");
		return false;
	}
	else if(rowMove < 1 || rowMove > 10){
		printf("Invalid row number.\n");
		return false;
	}
	return true;
}