#include "Player.h"

Player::Player(int a, std::string n) {
	accuracy = a;
	name = n;
	resetScore();
	gamesWon = 0;
	bullsHit = 0;
	dartsThrown = 0;

	State state;
}

Player::Player() {
	accuracy = DEFAULT_ACCURACY;
	name = " ";
	resetScore();
	gamesWon = 0;
	bullsHit = 0;
	dartsThrown = 0;
	State state;
}

Player::~Player() {

}

void Player::resetScore() { score = STARTING_SCORE; }

void Player::setState(char i) {
	switch (i) {	
	case 'n': state = State::neutral;
		break;
	case 'b': state = State::behind;
		break;
	case 'f': state = State::final_shot;
		break;
	default: state = State::neutral;
		break;
	}
}

#pragma region Getters & Setters
int Player::getScore()					{ return score; }
void Player::setScore(int hits)			{ score = hits; }
int Player::getScoreBefore()
{
	return 0;
}
void Player::setScoreBefore(int)
{
}
int Player::getBullsHit()				{ return bullsHit; }
void Player::incBullsHit()				{ bullsHit++; }
int Player::getDartsThrown()			{ return dartsThrown; }
void Player::incDartsThrown()			{ dartsThrown++; }
int Player::getGamesWon()				{ return gamesWon; }
void Player::setGamesWon(int games)		{ gamesWon = games; }
int Player::getAccuracy()				{ return accuracy; }
State Player::getState() { return state; }
std::string Player::getName()			{ return name; }
#pragma endregion