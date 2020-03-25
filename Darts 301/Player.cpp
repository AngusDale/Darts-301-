#include "Player.h"

Player::Player(int a, std::string n) {
	accuracy = a;
	name = n;		
	matchesWon = 0;
	totalSetsWon = 0;
	totalRoundsWon = 0;
	reset();
	
}

Player::Player() {
	accuracy = DEFAULT_ACCURACY;
	name = " ";		

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
}

void Player::resetScore(){
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

std::string Player::getStringState() {
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
State Player::getState()		{ return state; }
std::string Player::getName()	{ return name; }
#pragma endregion