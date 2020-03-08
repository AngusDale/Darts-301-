#pragma once
#include <string>

#define DEFAULT_ACCURACY 70;
#define STARTING_SCORE 301;

class Player
{
public:	
	Player(int a, std::string n);
	Player();
	~Player();

	void resetScore();

#pragma region Getters & Setters
	int getDartsThrown();
	void setDartsThrown(int);
	int getBullsHit();
	void setBullsHit(int);
	int getScore();
	void setScore(int);
	int getGamesWon();
	void setGamesWon(int);
	int getAccuracy();
	std::string getName();
#pragma endregion

private: 		
	int dartsThrown;
	int bullsHit;
	int score;
	int gamesWon;
	std::string name;
	int accuracy;
};

