#include "Game.h"
#include "Player.h"
#include <iostream>
#include <time.h> 
#include <windows.h>

// for controling cursor position
HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

// asks how many simulations to execute
int simCount() {
	std::cout << "How many simulations would you like to run?" << std::endl;
	int simcount = 0;
	std::cin >> simcount;
	system("cls");
	return simcount;
}

// prints the stats of each player
void printStats(Player p1, Player p2, Game g) {
	// keeps track of the cursor's y position
	SHORT line = 1;
	float setsWonRatio = 0;
	float totalPercent = 0;

	// prints ratio headers
	std::cout << p1.getName() << ":" << p2.getName();
	SetConsoleCursorPosition(hconsole, { 9, 0 }); 
	std::cout << "Frequency:" << std::endl;	
	
	// prints player one's stats
	for (int i = 6; i >= 0; i--) {
		setsWonRatio = float(p1.setsWonDuringLoss[i]) / float(g.getMatchesSimulated()) * 100;
		totalPercent += setsWonRatio;
		
		SetConsoleCursorPosition(hconsole, { 2, line });
		std::cout << i << ":7";
		SetConsoleCursorPosition(hconsole, { 11, line });
		std::cout << setsWonRatio << "%" << std::endl;
		line++;
	}

	line++;

	// prints player two's stats
	for (int i = 6; i >= 0; i--) {
		setsWonRatio = float(p2.setsWonDuringLoss[i]) / float(g.getMatchesSimulated()) * 100;
		totalPercent += setsWonRatio;

		SetConsoleCursorPosition(hconsole, { 2, line });
		std::cout << "7:" << i;
		SetConsoleCursorPosition(hconsole, { 11, line });
		std::cout << setsWonRatio << "%" << std::endl;
		line++;
	}

	// total matches simulated
	std::cout << std::endl << "Matches Simulated: " << g.getMatchesSimulated() << std::endl;

	// prints matches won per player
	std::cout << p1.getName() << " won: " << p1.getMatchesWon() << std::endl;
	std::cout << p2.getName() << " won: " << p2.getMatchesWon() << std::endl << std::endl;
}

// prints all stats for a single player
void printPlayerStats(Player player) {
	std::cout << player.getName() << "\n";
	std::cout << "Matches Won: " << player.getMatchesWon() << "\n";
	std::cout << "Rounds Won: " << player.getTotalRoundsWon() << "\n";
	std::cout << "Sets Won: " << player.getTotalSetsWon() << "\n";
	std::cout << "Darts Thrown: " << player.getDartsThrown() << "\n";
	std::cout << "Bulls Hit: " << player.getBullsHit() << "\n";
	std::cout << std::endl;
}

int main() {
	srand(time(NULL));
	Player Joe(75, "Joe"); // accuracy, name
	Player Sid(75, "Sid");	

	int sims = simCount();
	Game game(Joe, Sid);

	// simulates requested amount of matches
	for (game.getMatchesSimulated(); game.getMatchesSimulated() < sims; game.incMatchesSimulated()) {
		game.simulateMatch();
	}	
		
	printStats(Joe, Sid, game);
}



