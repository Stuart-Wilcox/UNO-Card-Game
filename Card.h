//created by S Wilcox
#pragma once
#include <iostream>
using namespace std;
//***VERY IMPORTANT**
//colours as follows:
//red = 0
//yellow = 1
//blue = 2
//green = 3



//created by S Wilcox
class uno_card {
	//there are 4 colours of cards (red, yellow, blue, green)
	//user defined denomination of cards
private:
	int _value;
	int _colour;
public:
	uno_card();
	uno_card(int val, int col);
	bool same_colour(uno_card);
	bool same_value(uno_card);
	int getVal() { return _value; }
	int getCol() { return _colour; }
	bool isNULL();
	void print_card();
};

uno_card::uno_card(){
	//default constructor
}

uno_card::uno_card(int val, int col) {
	_value = val;
	_colour = col;
}

bool uno_card::same_colour(uno_card card1) {
	return (card1._colour == _colour);
}

bool uno_card::same_value(uno_card card1) {
	return (card1._value == _value);
}

bool operator<(uno_card a, uno_card b) {
	if (a.getVal() < b.getVal()) {
		return 1;
	}
	else if (a.getVal() > b.getVal()) {
		return 0;
	}
	else if(a.getCol()<b.getCol()){
		return 1;
	}
	return 0;
}

bool uno_card::isNULL() {
	if (getCol() == NULL && getVal() == NULL) {
		return 1;
	}
	return 0;
}

void uno_card::print_card() {
	switch (_colour) {
	case 0: {
		cout << "Red";
		break;
	}
	case 1: {
		cout << "Yellow";
		break;
	}
	case 2: {
		cout << "Green";
		break;
	}
	case 3: {
		cout << "Blue";
		break;
	}
	default: {
		cout << "";
		break;
	}
	}
	cout << " " << _value;
}