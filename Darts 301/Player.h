#pragma once
#include <string>
#include<iostream>

#define DEFAULT_ACCURACY 70;
#define STARTING_SCORE 501;

class Player
{
public:	
	Player(int a, std::string n);
	~Player();

	void reset();
	void resetScore();
	void recordSetsWon();

	// when a match is finished, the amount of sets they won will be recorded except for 7 sets won (this would be a win). 
	// this keeps track of the amount of losses and how many sets were won during that loss
	int setsWonDuringLoss[7];

#pragma region Getters & Setters

	int getScore();
	void setScore(int);
	int getAccuracy();
	std::string getName();

	// functions with the "inc" prefix increment the variable following "inc" by 1
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

	int getTotalRoundsWon();
	void setTotalRoundsWon();
	int getTotalSetsWon();
	void setTotalSetsWon();

#pragma endregion

private: 
	int score;
	int accuracy;
	std::string name;

	int dartsThrown;
	int bullsHit;	

	int roundsWon;
	int setsWon;
	int matchesWon;

	int totalRoundsWon;
	int totalSetsWon;	
};

