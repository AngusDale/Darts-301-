#pragma once
#include "Dartboard.h"
#include "Player.h"
#include <iostream>

class Game
{
public:
	Game(Player&, Player&);
	Player* Joe;
	Player* Sid;
	Dartboard dartboard;

	void simulateRound();
	void simulateTurn(Player*, Player*);
	bool whoGoesFirst();
	char checkStandings(Player*, Player*);
	void setThrows(Player*);
	bool isGameWon(Player*);

private:
	int numThrown;
	int roundsSimulated;
	const int turnsPerRound = 3;
	bool joesTurn;
};

