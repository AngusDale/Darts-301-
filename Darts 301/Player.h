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
	Player(int a, std::string n, int c);
	Player();
	~Player();
	State state;	

	void resetScore();
	std::string getStringState();

#pragma region Getters & Setters
	int getDartsThrown();
	void incDartsThrown();
	int getBullsHit();
	void incBullsHit();
	int getScore();
	void setScore(int);
	int getRoundsWon();
	void setRoundsWon(int);
	int getGamesWon();
	void setGamesWon(int);
	int getAccuracy();
	void setState(char);
	State getState();

	std::string getName();
#pragma endregion

private: 
	int cursorPos;
	int dartsThrown;
	int bullsHit;
	int score;
	int roundsWon;
	int gamesWon;
	std::string name;
	int accuracy;
};

