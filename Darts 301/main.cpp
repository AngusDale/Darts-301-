#include "Game.h"
#include "Player.h"
#include <iostream>
#include <time.h> 
#include <windows.h>
#include <string> 
#include <sstream>

// for controling cursor position
HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

#pragma region Prototypes
int getValidInt();
int simCount();
void printStats(Player, Player, Game);
void printPlayerStats(Player);
bool simulateAgain();
#pragma endregion

int main() {
	srand(time(NULL));

	Player Joe(77, "Joe"); // accuracy, name
	Player Sid(75, "Sid");	
	Game game(Joe, Sid);

	bool again = false;

	do {
		game.reset();
		Joe.reset();
		Sid.reset();

		int sims = simCount();
		// simulates requested amount of matches
		for (game.getMatchesSimulated(); game.getMatchesSimulated() < sims; game.incMatchesSimulated()) {
			game.simulateMatch();
		}

		printStats(Joe, Sid, game);
		again = simulateAgain();
	} while (again);	
}

// gets a valid integer from the user
int getValidInt()
{
	int newInt = 0;
	float roundedInt = 0;
	do {
		std::string tempString = " ";
		// recieving input using getline
		getline(std::cin, tempString);
		// converts the string to an int
		std::stringstream geek(tempString);
		geek >> newInt;

		roundedInt = roundf(newInt);

		std::cout << roundedInt << std::endl;

		// input validation
		if (roundedInt <= 0) {
			std::cout << std::endl << "Please enter a number above 0: ";
		}
		else if (roundedInt >= 100000) {
			std::cout << "Enter a number lower than 100'000.\n";
		}
		else { return roundedInt; }
	} while (roundedInt <= 0 || roundedInt >= 100000);
	system("cls");
}

// asks how many simulations to execute
int simCount() {
	std::cout << "How many simulations would you like to run? ";
	int simcount = getValidInt();
	system("cls");
	return simcount;
}

// prints the stats of each player
void printStats(Player p1, Player p2, Game g) {
	// keeps track of the cursor's y position
	SHORT line = 1;

	float setsWonRatio = 0;

	// prints ratio headers
	std::cout << p1.getName() << ":" << p2.getName();
	SetConsoleCursorPosition(hconsole, { 9, 0 });
	std::cout << "Frequency:" << std::endl;

	// prints player one's stats
	for (int i = 6; i >= 0; i--) {
		setsWonRatio = float(p1.setsWonDuringLoss[i]) / float(g.getMatchesSimulated()) * 100;

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

// simulate again
bool simulateAgain() {
	std::cout << "Would you like to simulate more? (y/n) ";
	std::string response;
	getline(std::cin, response);
	std::cout << std::endl;
	return (response[0] == 'y' || response[0] == 'Y');
}


