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
private:
	int roundsSimulated;
	const int turnsPerRound = 3;
	bool joesTurn;
};

