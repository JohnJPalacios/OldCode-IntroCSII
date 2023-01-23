//Card class prototype file
//Author: John Palacios

#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;

class Card {
public:
	/* Assigns a default value of 2 of Clubs*/
	Card() : suit('c'), rank(2) {}

	/* Assigns the Card the suit and rank provided.
	   suits: c = Clubs, d = Diamonds, h = Hearts, s = Spades
	   If an invalid suit is provided, sets the suit to Clubs
	   ranks: 1 - 13 (1 = Ace, 11 = Jack, 12 = Queen, 13 = King)
	   If an invalid rank is provided, sets the rank to 2
	   Accepts lower or upper case characters for suit*/
	Card(char, int);

	/* Returns the Card's suit*/
	char getSuit() const { return suit; }

	/* Returns the Card's rank as an integer*/
	int getRank() const { return rank; }

	/* Overloading equality opperator */
	void operator=(const Card &rhs)  {
		this->rank = rhs.getRank();
		this->suit = rhs.getSuit();
	}

	/* Outputs a Card in the following format: Rank of Suit
	   For example, if the rank is 3 and the suit is h: 3 of Hearts
	   Or, if the rank is 1 and the suit is d: Ace of Diamonds
	   Or, if the rank is 12 and the suit is c: Queen of Clubs
	   etc.*/
	friend ostream & operator<<(ostream &, const Card &);

	~Card () { /* No pointers => no memory leaks */ }

private:
	char suit;
	int rank;
};

#endif // !CARD_H

