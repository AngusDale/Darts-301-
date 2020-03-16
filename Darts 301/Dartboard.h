#pragma once
#include <iostream>
#include <cstdlib>

#define NUMBER_OF_SCORES 21
#define BULLSEYE 50
#define RING 25

class Dartboard
{
public:
	Dartboard();

	int bull(int);
	int single(int, int);
	int _double(int, int);
	int getThrowPosition(int);
	int roll(int);
private:
	int numsOnBoard[NUMBER_OF_SCORES] = { 20, 1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5 };

	bool gameIsWon;	
};

