#include "Player.h"

Player::Player(int a, std::string n) {
	accuracy = a;
	name = n;		

	reset();
}

Player::Player() {
	accuracy = DEFAULT_ACCURACY;
	name = " ";		

	reset();
}

Player::~Player() {

}

void Player::reset() { 
	score = STARTING_SCORE; 
	setsWon = 0;
	bullsHit = 0;
	dartsThrown = 0;
	roundsWon = 0;
	setsWon = 0;
	matchesWon = 0;
}

std::string Player::getStringState()
{
	switch (state) {
	case State::ahead: return "AHEAD";
		break;
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
	case 'a': state = State::ahead;
		break;
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
int Player::getSetsWon()		{ return setsWon; }
void Player::setSetsWon()		{ setsWon++; }
int Player::getRoundsWon()		{ return roundsWon; }
void Player::setRoundsWon()		{ roundsWon++; }

int Player::getScore()			{ return score; }
void Player::setScore(int hits)	{ score = hits; }
int Player::getBullsHit()		{ return bullsHit; }
void Player::incBullsHit()		{ bullsHit++; }
int Player::getDartsThrown()	{ return dartsThrown; }
void Player::incDartsThrown()	{ dartsThrown++; }

int Player::getAccuracy()		{ return accuracy; }
State Player::getState()		{ return state; }
std::string Player::getName()	{ return name; }
#pragma endregion