//Deck prototype file
//Author: John Palacios

#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>
#include <cstdlib>
#include <algorithm>

class Deck {
public:
	/* Constructs a Deck of 52 cards:
	   Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King of each suit.
	   Cards should start off in this order with the order of suits being:
	   Clubs, Diamonds, Hearts, Spades.
	   For efficiency reasons, the "top" of the deck should be the back of the vector.*/
	Deck ();

	/* Deals (returns) the top card on the deck.
	   Removes this card from theDeck and places it in the dealtCards.
	   For efficiency reasons, cards should be dealt from the back of the vector. */
	Card dealCard();

	/* Places all cards back into theDeck and shuffles them into random order.
	   Uses random_shuffle function from algorithm standard library.*/
	void shuffleDeck();

	/* returns the size of the Deck (how many cards have not yet been dealt).*/
	unsigned deckSize() const { return theDeck.size(); }

	~Deck () { /*No native pointers = no memory leaks*/ }

private:
	vector<Card> theDeck;
	vector<Card> dealtCards;
};

#endif // !DECK_H

