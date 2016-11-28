//created by S Wilcox
#pragma once
#include <vector>
#include "OL.h"
#include "Card.h"
#include "Board.h"
#include <string>
#define _SCL_SECURE_NO_WARNINGS

using namespace std;


//created by S Wilcox
class uno_player{
private:
	OrderedList<uno_card> _hand;
	string _name;
	int num_players;
public:
	uno_player();
	uno_player(string);
	void card_match(uno_card&, uno_card&);
	void set_name(string);
	void add_card_to_hand(uno_card);
	bool play_card(Stack<uno_card> &b, Queue<uno_card> &d);
	void print_hand();
	bool empty_hand();
};

uno_player::uno_player() {
	num_players = 0;
	_name = "Player";

}

uno_player::uno_player(string x) {
	_name = x;
}

void uno_player::card_match(uno_card &a, uno_card &b) {
	//stuff
}

void uno_player::set_name(string x) {
	_name = x;
}

void uno_player::add_card_to_hand(uno_card x) {
	_hand.insert(x);
}

bool uno_player::play_card(Stack<uno_card> &b, Queue<uno_card> &d) {

	//does the deck need to be repopulated?
	if (d.isEmpty()) {
		Bag<uno_card> bag(b.getSize());
		uno_card top = b.pop();
		for (unsigned short int i(0); i < b.getSize();i++) {
			bag.add(b.pop());
		}
		for (unsigned short int i(0); i < bag.currentSize(); i++) {
			d.enqueue(bag.getOne());
		}
		b.push(top);
		cout << "\n***** Deck has been repopulated *****\n\n";
	}

	for (unsigned int i(1); i < _hand.getLength() + 1; i++) {
		if ((b.peek()).same_value(_hand.retrieve(i))) {
			b.push(_hand.retrieve(i));
			cout << _name << " found a match! They played: "; (_hand.remove(i)).print_card(); cout << endl;
			//yell UNO
			if (_hand.getLength() == 1) {
				cout << _name << " yelled UNO!\n";
			}
			cout << "They have " << _hand.getLength() << " cards left.\n\n";
			return (_hand.getLength() == 0);
		}
	}
	//match number?

	for (unsigned int i(1); i < _hand.getLength() + 1; i++) {
		if ((b.peek()).same_colour(_hand.retrieve(i))) {
			b.push(_hand.retrieve(i));
			cout << _name << " found a match! They played: "; (_hand.remove(i)).print_card(); cout << endl;
			//yell UNO
			if (_hand.getLength() == 1) {
				cout << _name << " yelled UNO!\n";
			}
			cout << "They have " << _hand.getLength() << " cards left.\n\n";
			return (_hand.getLength() == 0);
		}
	}
	//match colour?

	cout << _name << " did not find a match. They drew a card.\n";
	_hand.insert(d.dequeue());
	cout << "They have " << _hand.getLength() << " cards left.\n\n";
	return 0;
	//pick up a card

	

}

void uno_player::print_hand() {
	cout << "Player Name: " << _name << endl;
	cout << "Number of Cards: " << _hand.getLength() << endl;
	for (unsigned int i(1); i < _hand.getLength()+1; i++) {
		(_hand.retrieve(i)).print_card();
		cout << endl;
	}
	cout << endl;
}

bool uno_player::empty_hand() {
	return _hand.getLength() == 0;
}