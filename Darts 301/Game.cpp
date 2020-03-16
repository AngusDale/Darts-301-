#include "Game.h"

Game::Game(Player& J, Player& S) {	
	Joe = &J;
	Sid = &S;
	roundsSimulated = 0;
	joesTurn = whoGoesFirst();
}

// simulates a round
void Game::simulateRound()
{
	// simulates a turn for each player and flip flops between them
	for (int i = 0; i < 2; i++) {
		if (joesTurn) {
			// passes in Joe as the player and Sid as the oponent
			simulateTurn(Joe, Sid);
			joesTurn = !joesTurn;
		}
		else {
			// passes in Sid as the player and Joe as the oponent
			simulateTurn(Sid, Joe);
			joesTurn = !joesTurn;
		}
	}
}

// simulates 3 turns for a player
void Game::simulateTurn(Player* player, Player* oponent)
{
	// we save the player's score incase they go below 0 and need to reset their score to before their turn
	player->setScoreBefore();
	// sets the player's behaviour for the turn
	player->setState(checkStandings(player, oponent));

	setThrows(player);

	for (int i = 0; i < turnsPerRound; i++){
		std::cout << player->getName() << " " << player->printState() << std::endl;
		player->incDartsThrown();
						
	}
}

// decides who goes first at the beginning of each game
bool Game::whoGoesFirst()
{
	int jRoll, sRoll;

	/*	subtracting the accuracy from 100 here to weight the throw in favor of the highest accuracy 
		because the lowest number rolled wins. You could think of this as each throw being a radius "0" (the bull) and "100 - the accuracy" being the outer circle. 
		This gives the higher accuracy a better chance of hitting the bull and going first because it's more likely they'll roll a smaller number. */

	do {		
		sRoll = dartboard.roll(100 - Sid->getAccuracy());
		jRoll = dartboard.roll(100 - Joe->getAccuracy());
		if (jRoll < sRoll) { return true; }
	} while (jRoll == sRoll);
	
	return false;
}

// sets the players state
char Game::checkStandings(Player* _player, Player* _oponent)
{
	std::cout << _player->getScore() << " " << _oponent->getScore() << std::endl;

	if (_player->getScore() - _oponent->getScore() > 80) { return 'b'; }
	else if (_oponent->getScore() - _player->getScore() > 80) { return 'a'; }
	else if ((_player->getScore() <= 40 && _player->getScore() % 2 == 0) || _player->getScore() == 50) { return 'f';	}
	return 'n';
}

// sets what each player is going to throw for each turn
void Game::setThrows(Player* _player) {
	switch (_player->getState()) {
	case State::neutral:
		if()
			break;
	}
}

bool Game::isGameWon(Player* _player)
{
	if (_player->getScore() == 0) {
		return true
	}
	return false;
}
	
