#include "Game.h"

Game::Game(Player& J, Player& S) {	
	Joe = &J;
	Sid = &S;
	roundsSimulated = 0;	

	roundIsWon = false;
	joesTurn = false;
	matchesSimulated = 0;
	setsSimulated = 0;
	numThrown = 0;
	scoreBefore = 0;
}

void Game::simulateMatch()
{
	joesTurn = whoGoesFirst();

	// loops until the player has reached 7 sets won (best of 13)
	do {
		simulateSet();
		incSetsSimulated();
	} while (!matchIsWon());


	updateSetCounters(Joe);
	updateSetCounters(Sid);
}

void Game::simulateSet() {
	Joe->setRoundsWon(0);
	Sid->setRoundsWon(0);

	// loops until a player reaches 3 rounds won (best of 5)
	do {	
		simulateRound();

		// resets the player's score back to the starting number
		Joe->resetScore();
		Sid->resetScore();
	} while (!setIsWon());	

	Joe->setTotalRoundsWon();
	Sid->setTotalRoundsWon();
}

// simulates a round
void Game::simulateRound()
{
	roundIsWon = false;
	do {
		// simulates a turn for each player and flip flops between them
		for (int i = 0; i < 2; i++) {
			if (joesTurn) {
				// passes in Joe as the player
				simulateTurn(Joe);
				joesTurn = !joesTurn;
				
				// breaks the loop if the round is won
				if (roundIsWon)
					i = 3;
			}
			else {
				// passes in Sid as the player
				simulateTurn(Sid);
				joesTurn = !joesTurn;

				// breaks the loop if the round is won
				if (roundIsWon)
					i = 3;
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
		
		if (numThrown == 50) { player->incBullsHit(); } // increments bullsHit if the player hits a bullseye
		player->setScore(player->getScore() - numThrown); // decreases the player's score		

		//std::cout << player->getName() << " " << numThrown << " " << player->getScore() << std::endl;

		// checks to see if the player's score needs to be reset
		if (player->getScore() < 0 || player->getScore() == 1) {
			player->setScore(scoreBefore);
			// ends the player's turn
			i = 5;
		} else if (player->getScore() == 0){ // if it doesn't need to be reset then it checks to see if they won the round			
			roundIsWon = isRoundWon(player);
			if (roundIsWon) { i = 5; }
		}		
	}	
	//std::cout << std::endl;
}

// returns the number the player threw
int Game::getThrow(Player* player)
{
	if (player->getScore() > 71) {
		return dartboard.triple(player->getAccuracy(), 20);
	}
	else if (player->getScore() > 50) {
		return dartboard.single(player->getAccuracy(), player->getScore() % 50);
	}
	else if (player->getScore() == 50) {
		return dartboard.bull(player->getAccuracy());
	}
	else if (player->getScore() > 40) {
		return dartboard.single(player->getAccuracy(), player->getScore() % 40);
	}
	else if (player->getScore() % 2 == 0) {
		return dartboard._double(player->getAccuracy(), player->getScore() / 2);
	}
	else { return dartboard.single(player->getAccuracy(), 1); }
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

bool Game::isRoundWon(Player* player)
{
	if (dartboard.winningThrow) {
		player->setRoundsWon(player->getRoundsWon() + 1);
		return true;
	}
	return false;	
}

// checks to see if a player has reached 3 rounds won, and increments the sets won counter
bool Game::setIsWon()
{
	if (Joe->getRoundsWon() == ROUNDS_TO_WIN_SET) {
		Joe->setSetsWon(Joe->getSetsWon() + 1);
		return true;
	}
	else if (Sid->getRoundsWon() == ROUNDS_TO_WIN_SET) {
		Sid->setSetsWon(Sid->getSetsWon() + 1);
		return true;
	}
	return false;
}

// checks if a player has reached 7 sets won
bool Game::matchIsWon() {
	if (Joe->getSetsWon() == SETS_TO_WIN_MATCH) {
		return true;
	}
	else if (Sid->getSetsWon() == SETS_TO_WIN_MATCH) {
		return true;
	}
	return false;
}

// increments matches won if setsWon = 7 and records how many sets were won if a match is lost
void Game::updateSetCounters(Player* player)
{	
	player->recordSetsWon();
	player->setTotalSetsWon();
	player->setSetsWon(0);
}

int Game::getMatchesSimulated(){ return matchesSimulated; }
void Game::incMatchesSimulated(){ matchesSimulated++; }
int Game::getSetsSimulated(){ return setsSimulated; }
void Game::incSetsSimulated(){ setsSimulated++; }
	
