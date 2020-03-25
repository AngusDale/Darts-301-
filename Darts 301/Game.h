#pragma once
#include "Dartboard.h"
#include "Player.h"
#include <iostream>
#include <windows.h>

#define SETS_TO_WIN_MATCH 7
#define ROUNDS_TO_WIN_SET 3 

class Game
{
public:
	Game(Player&, Player&);
	Player* Joe;
	Player* Sid;
	Dartboard dartboard;	

	void simulateMatch(); // one match is first to 7 sets won
	void simulateSet(); // one set is first to 3 rounds won
	void simulateRound(); // one round is 3 turns per player from 501 to 0
	void simulateTurn(Player*);

	int getThrow(Player*);
	bool whoGoesFirst();

	bool isRoundWon(Player*);
	bool setIsWon();	
	bool matchIsWon();

	void updateCounters(Player*);
	void printStats(Player*);

private:
	int numThrown;
	int scoreBefore;
	int roundsSimulated;
	int setsSimulated;
	int matchesSimulated;
	static const int turnsPerRound = 3;
	bool roundIsWon;
	bool joesTurn;								
};

