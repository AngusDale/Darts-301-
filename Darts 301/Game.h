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

	void reset();

	void simulateMatch(); // one match is first to 7 sets won
	void simulateSet(); // one set is first to 3 rounds won
	void simulateRound(); // one round is 3 turns per player from 501 to 0
	void simulateTurn(Player*); // three throws for one player

	
	int getThrow(Player*); // returns the number thrown
	bool whoGoesFirst();

	//checks win conditions for each stage of a match
	bool isRoundWon(Player*);
	bool setIsWon();	
	bool matchIsWon();
	
	// calls recordSetsWon, setTotalSetsWon and puts setsWon to 0 for the player
	void updateSetCounters(Player*);

	// functions prefixed with "inc" increment the variable
	int getMatchesSimulated();
	void incMatchesSimulated();

	int getSetsSimulated();
	void incSetsSimulated();

private:
	static const int turnsPerRound = 3;

	bool joesTurn;
	int numThrown;

	int roundsSimulated;
	int setsSimulated;
	int matchesSimulated;
	// an individual variable for roundIsWon is necessary because a round can be won during a turn
	bool roundIsWon;
	// keeps track of the players score before their turn in case they go bust
	int scoreBefore;
};

