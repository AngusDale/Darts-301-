#include "Game.h"

Game::Game(Player& J, Player& S) {	
	Joe = &J;
	Sid = &S;

	joesTurn = whoGoesFirst();
}

// simulates 3 turns for each player
void Game::simulateRound()
{
	for (int i = 0; i < turnsPerRound * 2; i++) {
		if (joesTurn) {
			simulateTurn(Joe);
			joesTurn = !joesTurn;
		}
		else {
			simulateTurn(Sid);
			joesTurn = !joesTurn;
		}
	}
}

void Game::simulateTurn(Player* player)
{

}

// decides who goes first at the beginning of each game
bool Game::whoGoesFirst()
{
	int jRoll, sRoll;

	do {
		// subtracting the accuracy from 100 here to weight the throw in favor of the highest accuracy 
		// because the radius of their possible throws will be between "0" (the bull)
		// and "100 - the accuracy". This gives the higher accuracy a better chance of hitting the bull and going first.
			sRoll = dartboard.roll(100 - Sid->getAccuracy());
			jRoll = dartboard.roll(100 - Joe->getAccuracy());
		if (jRoll < sRoll) { return true; }
	} while (jRoll == sRoll);
	
	return false;
}
	
