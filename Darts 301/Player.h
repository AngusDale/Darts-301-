#pragma once
#include <string>
#include<iostream>

#define DEFAULT_ACCURACY 70;
#define STARTING_SCORE 301;

enum class State {
	neutral = 0,
	behind,
	final_shot,
	ahead
};

class Player
{
public:	
	Player(int a, std::string n);
	Player();
	~Player();
	State state;	

	void reset();
	std::string getStringState();

	// when a set is finished, the amount of rounds they won will be recorded except for 7 sets won. This keeps track of the amount of losses and how many sets were won during that loss
	int setLossTracker[6];

#pragma region Getters & Setters

	int getDartsThrown();
	void incDartsThrown();
	int getBullsHit();
	void incBullsHit();
	

	int getRoundsWon();
	void setRoundsWon(int);
	int getSetsWon();
	void setSetsWon(int);
	int getMatchesWon();
	void incMatchesWon();

	int getScore();
	void setScore(int);
	int getAccuracy();
	void setState(char);
	State getState();
	std::string getName();
	
#pragma endregion

private: 
	
	int dartsThrown;
	int bullsHit;
	int score;
	int roundsWon;
	int setsWon;
	int matchesWon;
	std::string name;
	int accuracy;
};

