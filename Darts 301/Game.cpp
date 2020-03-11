#include "Game.h"

Game::Game(Player& J, Player& S) {	
	Joe = &J;
	Sid = &S;
	roundsSimulated = 0;
	joesTurn = whoGoesFirst();
}

// simulates 3 turns for each player
void Game::simulateRound()
{
	// simulates a turn for each player and flip flops between them
	for (int i = 0; i < 2; i++) {
		if (joesTurn) {
			Joe->setScore(199);
			simulateTurn(Joe, Sid);
			joesTurn = !joesTurn;
		}
		else {
			simulateTurn(Sid, Joe);
			joesTurn = !joesTurn;
		}
	}
}

void Game::simulateTurn(Player* player, Player* oponent)
{
	// we save the player's score incase they go below 0 and need to reset their score to before their turn
	player->setScoreBefore();
	// sets the player's behaviour for the turn
	player->setState(checkStandings(player, oponent));
	for (int i = 0; i < turnsPerRound; i++){
		player->incDartsThrown();
		std::cout << player->getName() << " " << player->printState() << std::endl;
		
		if (player->getScore() % 2 != 0) {

		}
		else {
			switch (player->getState()) {
			case State::behind: //dartboard.triple(player->getAccuracy())
				break;
			case State::neutral: dartboard.bull(player->getAccuracy());
				break;
			}
			
		}
	}
}

// decides who goes first at the beginning of each game
bool Game::whoGoesFirst()
{
	int jRoll, sRoll;

	/*	subtracting the accuracy from 100 here to weight the throw in favor of the highest accuracy 
		because the radius of their possible throws will be between "0" (the bull) and "100 - the accuracy". 
		This gives the higher accuracy a better chance of hitting the bull and going first. */

	do {		
		sRoll = dartboard.roll(100 - Sid->getAccuracy());
		jRoll = dartboard.roll(100 - Joe->getAccuracy());
		if (jRoll < sRoll) { return true; }
	} while (jRoll == sRoll);
	
	return false;
}

char Game::checkStandings(Player* p, Player* o)
{
	std::cout << p->getScore() << " " << o->getScore() << std::endl;
	if (p->getScore() - o->getScore() > 100) { return 'b'; }
	else if ((p->getScore() <= 40 && p->getScore() % 2 == 0) || p->getScore() == 50) { return 'f';	}
	return 'n';
}
	
