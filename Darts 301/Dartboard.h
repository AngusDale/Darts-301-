#pragma once
#include <iostream>
#include <cstdlib>

#define NUMBER_OF_SCORES 21

class Dartboard
{
public:
	Dartboard();

	bool throwBull(int);
	int throwSingle(int, int);
	
	int roll(int);
private:
	int numsOnBoard[NUMBER_OF_SCORES] = { 20, 1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5, 20 };

	bool gameIsWon;	
	int numThrown;
};

