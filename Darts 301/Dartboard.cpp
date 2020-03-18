#include "Dartboard.h"

Dartboard::Dartboard() {
	gameIsWon = false;
}

// throws for the bullseye
int Dartboard::bull(int accuracy) {	
	int rand = roll(100);
	if (rand <= accuracy) { return BULLSEYE; }
	// if the player misses the bullseye we check to see if their random roll was lower than the half way point between 100 and their accuracy
	else if(rand <= accuracy + 10){
		return RING;
	}
	else if (rand <= accuracy + 20) {
		return numsOnBoard[roll(20)];
	}
	return 0;
}

// throws for a single number excluding the bullseye
int Dartboard::single(int accuracy, int throwFor) {
	int rand = roll(100);
	if (rand < accuracy) {
		return throwFor;
	}
	else { 		
		// if the player misses we check the position of the number they were throwing for
		int position = getThrowPosition(throwFor);
		
		// we see if the random num generated earlier was even or odd to dictate which side the player missed to
		if (rand % 2 == 0) {
			// we check if we're at either end of the array and react accordingly
			if (position == numsOnBoard[NUMBER_OF_SCORES]) { return numsOnBoard[0]; }
			else { return numsOnBoard[position + 1]; }
		}else {
			if (position == numsOnBoard[0]) { return numsOnBoard[NUMBER_OF_SCORES]; }
			else { return numsOnBoard[position - 1]; }
		}
	}

	return 0;
}

int Dartboard::_double(int, int)
{
	return 0 * 2;
}

int Dartboard::triple(int, int)
{
	return 0;
}

// finds the number we threw for on the board
int Dartboard::getThrowPosition(int x) {
	for (int i = 0; i < NUMBER_OF_SCORES; i++) {
		if (x = numsOnBoard[i]) {
			return i;
		}
	}
}

// roll a random number
int Dartboard::roll(int x) {
	int roll = rand() % x + 1;
	return roll;
}

bool Dartboard::validFinisher(int score)
{
	for (int x = 2; x <= 3; x++) {
		for (int i = 0; i < NUMBER_OF_SCORES; i++) {
			if (score == numsOnBoard[i] * x || score == 50) {
				return true;
			}
		}
	}
	return false;
}

// gets the highest possible throw the player can make 
int Dartboard::getHighestThrow(int score)
{
	int temp = score;
	int multiplier;
	for (multiplier = 1; multiplier <= 3; multiplier++) {
		for (int i = 0; i < NUMBER_OF_SCORES; i++) {
			if (score - numsOnBoard[i] * multiplier < temp && score - numsOnBoard[i] * multiplier > 1) {
				temp = score - numsOnBoard[i] * multiplier;
			}
		}
	}
	return temp * multiplier;
}
