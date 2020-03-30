#include "Player.h"

Player::Player(int a, std::string n) {
	accuracy = a;
	name = n;
	reset();	
}

Player::~Player() {

}

// resets score, setsWon, roundsWon, bullsHit, dartsThrown
void Player::reset() { 
	score = STARTING_SCORE; 
	setsWon = 0;
	roundsWon = 0;
	bullsHit = 0;
	dartsThrown = 0;
	matchesWon = 0;
	totalSetsWon = 0;
	totalRoundsWon = 0;

	for (int i = 0; i < 7; i++) {
		setsWonDuringLoss[i] = 0;
	}
}

void Player::resetScore() {
	score = STARTING_SCORE;
}

// records how many sets the player won and increments the matches won if it's 7
void Player::recordSetsWon() {
	switch (setsWon) {
	case 0: setsWonDuringLoss[0]++;
		break;
	case 1: setsWonDuringLoss[1]++;
		break;
	case 2: setsWonDuringLoss[2]++;
		break;
	case 3: setsWonDuringLoss[3]++;
		break;
	case 4: setsWonDuringLoss[4]++;
		break;
	case 5: setsWonDuringLoss[5]++;
		break;
	case 6: setsWonDuringLoss[6]++;
		break;
	case 7: incMatchesWon();
	}
}

#pragma region Getters & Setters
int Player::getMatchesWon()			{ return matchesWon; }
void Player::incMatchesWon()		{ matchesWon++; }
int Player::getSetsWon()			{ return setsWon; }
void Player::setSetsWon(int sets)	{ setsWon = sets; }
int Player::getRoundsWon()			{ return roundsWon; }
void Player::setRoundsWon(int rnds)	{ roundsWon = rnds; }

int Player::getTotalRoundsWon()		{ return totalRoundsWon; }
void Player::setTotalRoundsWon()	{ totalRoundsWon += roundsWon; }
int Player::getTotalSetsWon()		{ return totalSetsWon; }
void Player::setTotalSetsWon()		{ totalSetsWon += setsWon; }

int Player::getScore()			{ return score; }
void Player::setScore(int hits)	{ score = hits; }
int Player::getBullsHit()		{ return bullsHit; }
void Player::incBullsHit()		{ bullsHit++; }
int Player::getDartsThrown()	{ return dartsThrown; }
void Player::incDartsThrown()	{ dartsThrown++; }

int Player::getAccuracy()		{ return accuracy; }
std::string Player::getName()	{ return name; }
#pragma endregion