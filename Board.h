//created by S Wilcox
#pragma once
#include <vector>
#include "Stack.h"
#include "Q.h"
#include "Bag.h"
#include "Card.h"
#include "Player.h"
#define DEFAULT_NUM_PLAYERS 3
#define DEFAULT_MAX_DENOMINATION_CARDS 9
#define DEFAULT_NUM_PLAYER_CARDS 5

using namespace std;
//created by S Wilcox
class uno_board {
private:
	unsigned short int _num_players;
	unsigned int _num_player_cards;
	unsigned int _max_denomination_cards;
	Bag<uno_card> _deck;
	Stack<uno_card> _face_up_cards;
	Queue<uno_card> _face_down_cards;
	uno_player* player;
public:
	uno_board();
	uno_board(unsigned short int, unsigned int, unsigned int);
	~uno_board() { /*delete[] player; */}
	void print_hands();
	bool game_over(unsigned int);
	bool take_turn(unsigned int);
};

uno_board::uno_board() {
	_num_players = DEFAULT_NUM_PLAYERS;
	_num_player_cards = DEFAULT_NUM_PLAYER_CARDS;
	_max_denomination_cards = DEFAULT_MAX_DENOMINATION_CARDS;
	player = new uno_player[DEFAULT_NUM_PLAYERS];
	//create all cards and place them in a bag
	Bag<uno_card> deck(_max_denomination_cards*8);
	for (unsigned short int i(0); i < _max_denomination_cards; i++) {
		for (int j(0); j < 4; j++) {
			uno_card temp(i + 1, j);
			//adding two of each card (value i+1, colours 0-3
			deck.add(temp);
			deck.add(temp);
		}
	}
	//there are 4 colours of cards (red, yellow, blue, green)
	//user defined denomination of cards

	for (unsigned short int i(0); i < _max_denomination_cards*8; i++) {
		uno_card temp = deck.getOne();
		_face_down_cards.enqueue(temp);
	}
	//now remove the cards from the bag and place them into the deck

	for (unsigned int i(0); i < _num_players; i++) {
		//char n[7];
		//n[0] = 'p'; n[1] = 'l'; n[2] = 'a'; n[3] = 'y'; n[4] = 'e'; n[5] = 'r'; n[6] = char(i);
		//player[i].set_name(n);
	}

	for (unsigned int i(0); i < _num_player_cards; i++) {
		for (int j(0); j < _num_players; j++) {
			player[j].add_card_to_hand(_face_down_cards.dequeue());
		}
	}
	player[0].set_name("Player 1");
	player[1].set_name("Player 2");
	player[2].set_name("Player 3");
	//create players (and give them a hand)


	uno_card temp = _face_down_cards.dequeue();
	_face_up_cards.push(temp);
	//draw a starting card for the face up pile
}

uno_board::uno_board(unsigned short int num_players_, unsigned int num_cards_, unsigned int max_denomination_) {
	_num_players = num_players_;//set number of players
	_num_player_cards = num_cards_;//set number of cards in each player's hands
	_max_denomination_cards = max_denomination_;//set max denomiation;
	player = new uno_player[num_players_];
	
	//create all cards and put them in a bag
	Bag<uno_card> deck(_max_denomination_cards * 8);
	for (unsigned short int i(0); i < _max_denomination_cards; i++) {
		for (int j(0); j < 4; j++) {
			uno_card temp(i + 1, j);
			//adding two of each card (value i+1, colours 0-3)
			deck.add(temp);
			deck.add(temp);
		}
	}
	//there are 4 colours of cards (red, yellow, blue, green)
	//user defined denomination of cards
	
	for (unsigned short int i(0); i < _max_denomination_cards * 8; i++) {
		uno_card temp = deck.getOne();
		_face_down_cards.enqueue(temp);
	}
	//now remove the cards from the bag and place them into the deck

	for (unsigned int i(0); i < _num_player_cards; i++) {
		for (int j(0); j < _num_players; j++) {
			player[j].add_card_to_hand(_face_down_cards.dequeue());
		}
	}//give them some cards
	//player[0].set_name("Heng Weng");
	for (unsigned int i(0); i < _num_players; i++) {
		string name = "Player";
		name.push_back(i+49);
		player[i].set_name(name);
		name.pop_back();
	}

	uno_card temp = _face_down_cards.dequeue();
	_face_up_cards.push(temp);
	//draw a starting card for the face up pile
}

void uno_board::print_hands() {
	for (int i(0); i < _num_players; i++) {
		player[i].print_hand();
	}
	cout << endl << "Face Up Card: ";
	_face_up_cards.push(_face_down_cards.dequeue());
	(_face_up_cards.peek()).print_card();
	cout << endl;
}

bool uno_board::game_over(unsigned int x) {
	return player[x].empty_hand();
}

bool uno_board::take_turn(unsigned int x) {
	if (x<0 || x>_num_players - 1) {
		return 0;
	}
	return player[x].play_card(_face_up_cards, _face_down_cards);
}