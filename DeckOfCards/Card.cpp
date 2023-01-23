//Card implementation file
//Author: John Palacios

#include "Card.h"
#include <string>
#include <cstring>

/* Assigns the Card the suit and rank provided.
	   suits: c = Clubs, d = Diamonds, h = Hearts, s = Spades
	   If an invalid suit is provided, sets the suit to Clubs
	   ranks: 1 - 13 (1 = Ace, 11 = Jack, 12 = Queen, 13 = King)
	   If an invalid rank is provided, sets the rank to 2
	   Accepts lower or upper case characters for suit*/
Card::Card(char suit, int rank) {
	char suits[8] = { 'c', 'd', 'h', 's', 'C', 'D', 'H', 'S' };
	bool valid = false;

	//Validate suit initializer
	for (int i = 0; i < 8; i++) {
		if (suit == suits[i])	{
			valid = true;
			this->suit = suits[i % 4];
		}
	}
	if (!valid) {
		this->suit = 'c';
	}

	//Validate rank initializer
	if (rank < 1 or rank > 13) {
		this->rank = 2;
	}
	else
	{
		this->rank = rank;
	}
}

/* Outputs a Card in the following format: Rank of Suit
	   For example, if the rank is 3 and the suit is h: 3 of Hearts
	   Or, if the rank is 1 and the suit is d: Ace of Diamonds
	   Or, if the rank is 12 and the suit is c: Queen of Clubs
	   etc.*/
ostream & operator<<(ostream &out, const Card &card) {
	string Suits[4] = { "Clubs", "Diamonds", "Hearts", "Spades"};
	char suits[8] = { 'c', 'd', 'h', 's', 'C', 'D', 'H', 'S' };

	//Load rank and " of " into output stream
	switch (card.getRank()) {
	case 1: out << "Ace of ";
		break;
	case 11: out << "Jack of ";
		break;
	case 12: out << "Queen of ";
		break;
	case 13: out << "King of ";
		break;
	default: out << card.getRank() << " of ";
	}

	//determine and load suit into output stream
	for (int i = 0; i < 8; i++) {
		if (card.getSuit() == suits[i] ) {
			out << Suits[i % 4].c_str();
		}
	}

	return out;
}