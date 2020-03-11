#include "Player.h"

Player::Player(int a, std::string n) {
	accuracy = a;
	name = n;	
	gamesWon = 0;
	bullsHit = 0;
	dartsThrown = 0;

	State state;
	state = State::neutral;

	resetScore();
}

Player::Player() {
	accuracy = DEFAULT_ACCURACY;
	name = " ";	
	gamesWon = 0;
	bullsHit = 0;
	dartsThrown = 0;

	State state;
	state = State::neutral;

	resetScore();
}

Player::~Player() {

}

void Player::resetScore() { score = STARTING_SCORE; }

std::string Player::printState()
{
	switch (state) {
	case State::behind: return "BEHIND";
		break;
	case State::neutral: return "NEUTRAL";
		break;
	case State::final_shot: return "FINAL SHOT";
		break;
	default: return "NO STATE SET";
		break;
		return std::string();
	}
}

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
int Player::getScoreBefore()	{ return scoreBefore; }
void Player::setScoreBefore()	{ scoreBefore = getScore(); }
int Player::getScore()				{ return score; }
void Player::setScore(int hits)		{ score = hits; }
int Player::getBullsHit()			{ return bullsHit; }
void Player::incBullsHit()			{ bullsHit++; }
int Player::getDartsThrown()		{ return dartsThrown; }
void Player::incDartsThrown()		{ dartsThrown++; }
int Player::getGamesWon()			{ return gamesWon; }
void Player::setGamesWon(int games)	{ gamesWon = games; }
int Player::getAccuracy()			{ return accuracy; }
State Player::getState()			{ return state; }
std::string Player::getName()		{ return name; }
#pragma endregion