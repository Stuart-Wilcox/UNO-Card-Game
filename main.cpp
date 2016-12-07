//Created by S Wilcox
#include <iostream>
#include "Bag.h"
#include "OL.h"
#include "Q.h"
#include "Stack.h"
#include "Board.h"
using namespace std;

int main() {
	//created by S wilcox
	cout << "*************************************************\n";
	cout << "*************************************************\n";
	cout << "*** * * * * * *  Welcome to UNO!  * * * * * * ***\n";
	cout << "*************************************************\n";
	cout << "*************************************************\n\n\n";

	cout << "\nPlease enter the number of players: ";
	int num_players(0);
	cin >> num_players;
	while (num_players < 2 || num_players>19) {
		cout << "\nMust have between 2 and 19 players. Please enter number of players: ";
		cin >> num_players;
	}
	cout << "\nPlease enter the number of cards each player starts with: ";
	int num_cards(0);
	cin >> num_cards;
	while (num_cards < 2 || num_cards>12) {
		cout << "\nMust have between 2 and 10 cards. Please enter number of cards each player starts with: ";
		cin >> num_cards;
	}
	cout << "\nPlease enter the maximum denomination of the cards: ";
	int max_denom(0);
	cin >> max_denom;
	cout << endl;
	while (max_denom < 5 || max_denom >25 || max_denom * 8 < num_cards*num_players+2) {
		cout << "Must have a denomination between 5 and 25 and at least enough cards to deal to all players.\n"
			"Please enter the maximum denomination of cards: ";
		cin >> max_denom;

		cout << endl;
	}


	cout << "\n\n..........Game is starting..........\n\n";
	uno_board a(num_players, num_cards, max_denom);
	int p_index = 0; int br = 0;
	
	while(1){
		for (int j(1); j < num_players+1; j++) {
			p_index = j;
			if (a.take_turn(j - 1)) {
				br = 1;
				break;
			}
		}
		if (br) {
			break;
		}
	}
	cout << "..........Game has ended..........\n";
	cout << endl << "Player " << p_index<< " won.\n\n";


	return 0;
}