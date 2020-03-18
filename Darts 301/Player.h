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
	
	void resetScore();
	std::string printState();

#pragma region Getters & Setters
	int getDartsThrown();
	void incDartsThrown();
	int getBullsHit();
	void incBullsHit();
	int getScore();
	void setScore(int);
	int getScoreBefore();
	void setScoreBefore();
	int getGamesWon();
	void setGamesWon(int);
	int getAccuracy();
	void setState(char);
	State getState();

	std::string getName();
#pragma endregion

private: 
	int dartsThrown;
	int bullsHit;
	int score;
	int scoreBefore;
	int gamesWon;
	std::string name;
	int accuracy;
};

