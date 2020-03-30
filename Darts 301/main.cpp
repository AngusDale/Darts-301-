#include "Game.h"
#include "Player.h"
#include <iostream>
#include <time.h> 

int simCount() {
	std::cout << "How many simulations would you like to run?" << std::endl;
	int simcount = 0;
	std::cin >> simcount;
	system("cls");
	return simcount;
}

// prints the stats of each player
void printStats(Player p1, Player p2, Game g) {
	/**/

	std::cout << "Matches Simulated: " << g.getMatchesSimulated() << std::endl;
	std::cout << p1.getName() << " won: " << p1.getMatchesWon() << std::endl;
	std::cout << p2.getName() << " won: " << p2.getMatchesWon() << std::endl << std::endl;
	std::cout << "J" << "-" << "S" << std::endl;	
	float setsWonRatio = 0;
	float totalPercent = 0;
	for (int i = 0; i < 7; i++) {
		setsWonRatio = float(p1.setsWonDuringLoss[i]) / float(g.getMatchesSimulated()) * 100;
		totalPercent += setsWonRatio;
		std::cout << i << ":7 -- " << setsWonRatio << "%"<< std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < 7; i++) {
		setsWonRatio = float(p2.setsWonDuringLoss[i]) / float(g.getMatchesSimulated()) * 100;
		totalPercent += setsWonRatio;
		std::cout << "7:" << i << " -- " << setsWonRatio << "%" << std::endl;;
	}

	std::cout << totalPercent << "%";
}

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

	for (game.getMatchesSimulated(); game.getMatchesSimulated() < sims; game.incMatchesSimulated()) {
		game.simulateMatch();
	}	
		
	printStats(Joe, Sid, game);
	//printStats(Sid);
}



