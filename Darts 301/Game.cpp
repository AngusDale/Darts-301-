#include "Game.h"

Game::Game(Player& J, Player& S) {	
	Joe = &J;
	Sid = &S;
	roundsSimulated = 0;
	joesTurn = whoGoesFirst();

	roundIsWon = false;
	_numThrown = &numThrown;
}

void Game::simulateGame() {
	do {		
		simulateRound();
	} while (/*gameIsWon()*/ false);
}

// simulates a round
void Game::simulateRound()
{
	std::cout << Joe->getName() << " - " << Sid->getName() << std::endl;
	do {
		// simulates a turn for each player and flip flops between them
		for (int i = 0; i < 2; i++) {
			if (joesTurn) {
				// passes in Joe as the player
				simulateTurn(Joe);
				joesTurn = !joesTurn;

				if (roundIsWon)
					break;
			}
			else {
				// passes in Sid as the player
				simulateTurn(Sid);
				joesTurn = !joesTurn;

				if (roundIsWon)
					break;
			}
		}

	} while (!roundIsWon);
}

// simulates 3 throws for a player
void Game::simulateTurn(Player* player)
{
	// we save the player's score incase they go below 0 and need to reset their score to before their turn
	scoreBefore = player->getScore();

	for (int i = 0; i < turnsPerRound; i++){
		
		player->incDartsThrown(); // increments dartsThrown

		numThrown = getThrow(player);
		
		if (numThrown == 50) { player->incBullsHit(); } //increments bullsHit if the player hits a bullseye
		player->setScore(player->getScore() - numThrown); // decreases the player's score		

		// checks to see if the player's score needs to be reset
		if (player->getScore() < 0 || player->getScore() == 1) {
			player->setScore(scoreBefore);
			// ends the player's turn but allows the loop to finish its iteration
			i = turnsPerRound + 1;
		} // if it doesn't need to be reset then it checks to see if they won the round
		else {
			isRoundWon(player);
		}
		std::cout << i + 1 << ": " << player->getName() << " " << numThrown << " " << player->getScore() << std::endl;
	}
	std::cout << std::endl;	
}

// returns the number the player threw
int Game::getThrow(Player* player)
{
	if (player->getScore() > 60) {
		return dartboard.triple(player->getAccuracy(), 20);
	}
	else {
		if (player->getScore() > 50) {
			return dartboard.single(player->getAccuracy(), player->getScore() % 50);
		}
		else if (player->getScore() == 50) {
			return dartboard.bull(player->getAccuracy());
		}
		else {
			if (player->getScore() > 40) {
				return dartboard.single(player->getAccuracy(), player->getScore() % 40);
			}
			else {
				if (player->getScore() % 2 == 0) {
					return dartboard._double(player->getAccuracy(), player->getScore() / 2);
				}
				else { return dartboard.single(player->getAccuracy(), 1); }
			}
		}
	}
}

// decides who goes first at the beginning of each game
bool Game::whoGoesFirst()
{
	int jRoll, sRoll;
	
	/*	subtracting the accuracy from 100 here to weight the throw in favor of the highest accuracy
	because the lowest number rolled wins. You could think of this as each throw being a radius "0" (the bull) and "100 - the accuracy" being the outer circle. 
	This gives the higher accuracy a better chance of hitting the bull and going first because it's more likely they'll roll a smaller number. 
*/
	do {		
		sRoll = dartboard.roll(100 - Sid->getAccuracy());
		jRoll = dartboard.roll(100 - Joe->getAccuracy());
		if (jRoll < sRoll) { return true; }
	} while (jRoll == sRoll);
	
	return false;
}

void Game::isRoundWon(Player* player)
{
	if (player->getScore() == 0 && dartboard.threwDouble) {
		roundIsWon = true;
	}
}

bool Game::gameIsWon()
{
	return false;
}
	
