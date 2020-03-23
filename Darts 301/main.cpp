#include "Game.h"
#include "Player.h"
#include <iostream>
#include <time.h> 

int simCount() {
	std::cout << "How many simulations would you like to run?" << std::endl;
	int simcount = 0;
	std::cin >> simcount;
	return simcount;
}

void printStats(Player player) {
	std::cout << player.getName() << ":" << std::endl;
	std::cout << player.getGamesWon() << std::endl;
	std::cout << player.getBullsHit() << std::endl;
}

int main() {
	srand(time(NULL));
	Player Joe(70, "Joe");
	Player Sid(70, "Sid");	

	int sims = 1; //simCount();

	for (int i = 0; i < sims; i++) {
		Game game(Joe, Sid);
		game.simulateGame();
	}

	//printStats(Joe);
	//printStats(Sid);
}



