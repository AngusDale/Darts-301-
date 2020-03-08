#include "Player.h"

Player::Player(int a, std::string n) {
	accuracy = a;
	name = n;
}

Player::Player() {
	accuracy = DEFAULT_ACCURACY;
	name = " ";
}

Player::~Player() {

}

void Player::resetScore() { score = STARTING_SCORE; }

#pragma region Getters & Setters
int Player::getScore()					{ return score; }
void Player::setScore(int hits)			{ score = hits; }
int Player::getBullsHit()				{ return bullsHit; }
void Player::setBullsHit(int bulls)		{ bullsHit = bulls; }
int Player::getDartsThrown()			{ return dartsThrown; }
void Player::setDartsThrown(int darts)	{ dartsThrown = darts; }
int Player::getGamesWon()				{ return gamesWon; }
void Player::setGamesWon(int games)		{ gamesWon = games; }
int Player::getAccuracy()				{ return accuracy; }
std::string Player::getName()			{ return std::string(); }
#pragma endregion