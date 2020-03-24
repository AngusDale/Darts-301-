#pragma once
#include "Dartboard.h"
#include "Player.h"
#include <iostream>
#include <windows.h>

#define ROUNDS_TO_WIN 7

class Game
{
public:
	Game(Player&, Player&);
	Player* Joe;
	Player* Sid;
	Dartboard dartboard;	

	void simulateGame(); // one match is first to 7 games won
	void simulateRound(); // one round is 3 turns per player
	void simulateTurn(Player*);
	int getThrow(Player*);
	bool whoGoesFirst();
	void isRoundWon(Player*);
	bool gameIsWon();	

	// allows me to control cursor position and hide it
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

private:
	int* _numThrown;
	int numThrown;
	int scoreBefore;
	int roundsSimulated;
	static const int turnsPerRound = 3;
	bool roundIsWon;
	bool joesTurn;
};

