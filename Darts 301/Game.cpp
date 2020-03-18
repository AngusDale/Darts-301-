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

// simulates 3 throws for a player
void Game::simulateTurn(Player* player, Player* oponent)
{
	// we save the player's score incase they go below 0 and need to reset their score to before their turn
	player->setScoreBefore();

	for (int i = 0; i < turnsPerRound; i++){
		std::cout << player->getName() << " " << player->getScore() << std::endl;
		player->incDartsThrown();	

		if (player->getScore() >= 60) {
			numThrown = dartboard.triple(player->getAccuracy(), 20);
			player->setScore(player->getScore() - numThrown);
			isGameWon(player);
		}
		else {
			if (player->getScore() > 50) {
				numThrown = dartboard.single(player->getAccuracy(), player->getScore() % 50);
				player->setScore(player->getScore() - numThrown);
			}
			else if (player->getScore() == 50) {
				numThrown = dartboard.bull(player->getAccuracy());
				player->incBullsHit();
				player->setScore(player->getScore() - numThrown);
			}
			else {
				if (player->getScore() > 40) {
					numThrown = dartboard.single(player->getAccuracy(), player->getScore() % 40);
					player->setScore(player->getScore() - numThrown);
				}
				else {
					if (player->getScore() % 2 == 0) {
						numThrown = dartboard._double(player->getAccuracy(), player->getScore() / 2);
						player->setScore(player->getScore() - numThrown);
					}
					else {
						numThrown = dartboard.single(player->getAccuracy(), 1);
						player->setScore(player->getScore() - numThrown);
					}
				}
			}
		}
	}

	if (player->getScore() < 0 || player->getScore() == 1) {
		player->setScore(player->getScoreBefore());
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

bool Game::isGameWon(Player* _player)
{
	if (_player->getScore() - numThrown == 0) {
		return true;
	}
	return false;
}
	
