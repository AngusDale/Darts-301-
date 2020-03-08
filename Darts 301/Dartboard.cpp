#include "Dartboard.h"

Dartboard::Dartboard() {
	gameIsWon = false;
	numThrown = 0;
}

bool Dartboard::throwBull(int accuracy) {	
	if (roll(100) <= accuracy) { return true; }	
	return false;
}

int Dartboard::throwSingle(int accuracy, int throwFor)
{
	int rand = roll(100);
	if (rand < accuracy) {
		numThrown = throwFor;
	}
	else {
		int num;
		for (int i = 0; i < NUMBER_OF_SCORES; i++) {
			if (throwFor = numsOnBoard[i]) {
				num = i;
				break;
			}
		}

		if (rand % 2 == 0) {
			numThrown = numsOnBoard[num + 1];
		}
		else {
			numThrown = numsOnBoard[num - 1];
		}
	}
}

int Dartboard::roll(int x){
	int roll = rand() % x + 1;
	return roll;
}
