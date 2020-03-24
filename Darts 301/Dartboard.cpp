#include "Dartboard.h"

Dartboard::Dartboard() {
	gameIsWon = false;
	threwDouble = false;
}

// throws for the bullseye
int Dartboard::bull(int accuracy) {	
	threwDouble = false;
	int rand = roll(100);
	if (rand <= accuracy) { return BULLSEYE; }
	// if the player misses the bullseye we check to see if their random roll was lower than the half way point between 100 and their accuracy
	else if(rand <= accuracy + 10){
		return RING;
	}
	else if (rand <= accuracy + 25) {
		return numsOnBoard[roll(20)];
	}
	
	return 0;	
}

// throws for a single number excluding the bullseye
int Dartboard::single(int accuracy, int throwFor) {
	threwDouble = false;
	int rand = roll(100);
	if (rand <= accuracy) {
		return throwFor;
	}
	else { 		
		return getNeighbor(throwFor, rand);
	}
	
	return 0;
}

// accuracy is halved in this function to illustrate that roughly half of the accuracy circle is off the board on and actual dart board
int Dartboard::_double(int accuracy, int throwFor)
{
	int rand = roll(100);
	if (throwFor <= 20) {
		if (rand <= accuracy / 2) {
			threwDouble = true;
			return throwFor * 2;			
		}
		else if (rand <= (accuracy / 2) + 15) {
			threwDouble = false;
			return throwFor;
		}
		else if (rand <= (accuracy / 2) + 20) {
			if (rand % 4 == 0) {
				threwDouble = false;
				return getNeighbor(throwFor, rand) * 2;
			}
			else {
				threwDouble = false;
				return getNeighbor(throwFor, rand);
			}
		}		
	}
	return 0;
}

int Dartboard::triple(int accuracy, int throwFor)
{
	threwDouble = false;
	int rand = roll(100);
	// accuracy is devided by 2 only for the triple tile due to it's physical size
	if (rand <= accuracy / 2) {
		return throwFor * 3;
	}
	else if (rand <= accuracy) {
		return throwFor;
	}
	else if (rand <= accuracy + 20) {
		if (rand % 4 == 0) {
			return getNeighbor(throwFor, rand) * 3;
		}
		else {
			return getNeighbor(throwFor, rand);
		}
	}
	return 0;
}

// returns one number either side of the tile the player was aiming for
int Dartboard::getNeighbor(int num, int rand)
{
	int position;

	// finds the position of the intended throw on the dartboard
	for (int i = 0; i < NUMBER_OF_SCORES; i++) {
		if (num == numsOnBoard[i]) {
			position = i;
			break;
		}
	}

	// we see if the random num generated earlier was even or odd to dictate which side the player missed to
	if (rand % 2 == 0) {
		// we check if we're at either end of the array and react accordingly before returning a neighbor
		if (position == numsOnBoard[NUMBER_OF_SCORES]) { return numsOnBoard[0]; }
		else { return numsOnBoard[position + 1]; }
	}
	else {
		if (position == numsOnBoard[0]) { return numsOnBoard[NUMBER_OF_SCORES]; }
		else { return numsOnBoard[position - 1]; }
	}
	return 0;
}



// roll a random number
int Dartboard::roll(int x) {
	int roll = rand() % x + 1;
	return roll;
}

bool Dartboard::validFinisher(int score)
{
	for (int i = 0; i < NUMBER_OF_SCORES; i++) {
		if (score == numsOnBoard[i] * 2 || score == 50) {
			return true;
		}
	}
	
	return false;
}


