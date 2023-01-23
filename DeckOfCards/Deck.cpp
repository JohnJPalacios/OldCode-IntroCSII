//Deck Implementation file
//Author: John Palacios

#include "Deck.h"

/* Constructs a Deck of 52 cards:
	   Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King of each suit.
	   Cards should start off in this order with the order of suits being:
	   Clubs, Diamonds, Hearts, Spades.
	   For efficiency reasons, the "top" of the deck should be the back of the vector.*/
Deck::Deck() {
	char suits[4] = { 'c', 'd', 'h', 's'};

	for (int i = 0; i < 52; i++) {
		Card newCard(suits[i / 13], (i % 13) + 1 );
		theDeck.push_back(newCard);
		newCard.~Card();
	}

	reverse(theDeck.begin(), theDeck.end());
}

/* Deals (returns) the top card on the deck.
	   Removes this card from theDeck and places it in the dealtCards.
	   For efficiency reasons, cards should be dealt from the back of the vector.*/
Card Deck::dealCard() {
	Card dealt = theDeck.at(theDeck.size() - 1);
	dealtCards.push_back(dealt);
	theDeck.pop_back();
	return dealt;
}

/* Places all cards back into theDeck and shuffles them into random order.
	   Uses random_shuffle function from algorithm standard library.*/
void Deck::shuffleDeck() {
	//Add the elements of dealtCards to the end of theDeck.
	theDeck.insert(theDeck.end(), dealtCards.begin(), dealtCards.end());

	//Delete the elements contained in dealtCards
	dealtCards.clear();
	
	//Shuffle theDeck using <algorithm> random_shuffle fxn.
	random_shuffle(theDeck.begin(), theDeck.end());
}