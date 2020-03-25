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

void printStats(Player player) {
	std::cout << player.getName() << ":" << std::endl;
	std::cout << player.getSetsWon() << std::endl;
	std::cout << player.getBullsHit() << std::endl;
}

int main() {
	srand(time(NULL));
	Player Joe(70, "Joe"); // accuracy, name
	Player Sid(75, "Sid");	

	int sims = 1; //simCount();
	Game game(Joe, Sid);
	for (int i = 0; i < sims; i++) {		
		game.simulateMatch();
	}

	//printStats(Joe);
	//printStats(Sid);
}



