//Main function file
//Author: John Palacios

#include "Deck.h"
//#include "Card.h"
#include <string>
#include <fstream>
using namespace std;

/* Passes in a vector Cards and returns true if any 2 Cards have the same rank.
   Otherwise returns false.*/
bool hasPair(const vector<Card> &);

//Runns Monte Carlo simulation. Draws numCards from Deck numHands times.
//Counts the number of hands with a pair in it, divides by numHands,
//Returns quotient.
double runSimulation(int, int);

//As runSimulation except will save each hand to a designated file.
double runSimulation(int, int, const string &);

/* Passes in a vector of Cards and outputs to the stream each Card
   separated by a comma and a space,
   with no comma, space, or newline at the end.*/
ostream & operator<<(ostream &, const vector<Card> &);

int main() {
	srand(2222);
	////Test default constructor
	//Card card1;
	//cout << "card1 " << card1 << endl;
	////Test two param constructor
	//Card card2('h', 5);
	//cout << "Card2 " << card2 << endl;

	////Test invalid suit
	//Card card3('p', 3);
	//cout << "Card3 " << card3 << endl;

	////test rank < 2
	//Card card4('d', 1);
	//cout << "Card4 " << card4 << endl;

	////Test rank > 13, 42 because it is the meaning of life, the universe, and everything XD
	//Card card5('S', 42);
	//cout << "Card5 " << card5 << endl;

	////Testing Deck constructor
	//Deck deck;

	////Testing fxn deal card
	//Card test1 = deck.dealCard();
	//cout << "Test card 1: " << test1 << endl;
	//test1.~Card();

	////Testing fxn shuffle
	//deck.shuffleDeck();
	//Card test2 = deck.dealCard();
	//cout << "Test card 2: " << test2 << endl;

	////testing of global functions
	////testing has pair: true
	//Card card6('c', 11);
	//Card card7('h', 11);
	//vector<Card> hand;
	//hand.push_back(card6);
	//hand.push_back(card7);
	//hand.push_back(card1);
	//hand.push_back(card2);
	//hand.push_back(card3);

	////Testing oustream overloading of <<
	//cout << "This hand contains:\n" << hand << endl;

	//hasPair(hand) ? cout << "True, has pair\n" : cout << "False, each distinct\n";

	////testing has pair: false
	//hand.clear();
	//hand.push_back(card6);
	//hand.push_back(card4);
	//hand.push_back(card1);
	//hand.push_back(card2);
	//hand.push_back(card3);

	////Testing oustream overloading of <<
	//cout << "This hand contains:\n" << hand << endl;

	//hasPair(hand) ? cout << "True, has pair\n" : cout << "False, each distinct\n";

	////Test equality overloading
	//card6 = card4;
	//cout << card6;

	string choice;								//User indicates if the data is to be saved to a file
	string fileName;							//Name of file to be created
	int numCards;								//Number of cards per hand
	int numHands;								//Number of hands to test
	double Prob = 0;
	bool file = false;

	cout << "Do you want to output all hands to a file?(Yes/No) ";
	cin >> choice;
	cout << endl;

	if (choice == "Yes" || choice == "yes" || choice == "y") {
		cout << "Enter name of output file: ";
		cin >> fileName;
		file = true;
		cout << endl;
	}

	cout << "Enter number of cards per hand: ";
	cin >> numCards;
	cout << endl;

	cout << "Enter number of deals (simulations): ";
	cin >> numHands;
	cout << endl;

	//Compute odds of recieving a pair in a hand of numCards
	file ? Prob = 100.0 * runSimulation(numCards, numHands, fileName) : Prob = 100.0 * runSimulation(numCards, numHands);

	cout << "Chances of receiving a pair in a hand of " << numCards << " cards is: " << Prob << "%" << endl;

	return 0;
}

/* Passes in a vector Cards and returns true if any 2 Cards have the same rank.
   Otherwise returns false.*/
bool hasPair(const vector<Card> &hand) {
	int length = static_cast<int>(hand.size());
	bool pair = false;
	for (int i = 0; i < length; i++) {
		for (int j = i + 1; j < length; j++) {
			if (hand.at(i).getRank() == hand.at(j).getRank()) {
				pair = true;
			}
		}
	}
	return pair;
}

//Runns Monte Carlo simulation. Draws numCards from Deck numHands times.
//Counts the number of hands with a pair in it, divides by numHands,
//Returns quotient.
double runSimulation(int numCards, int numHands) {
	Deck simDeck;
	vector<Card> hand;
	int count = 0;

	//Shuffle Deck before use
	simDeck.shuffleDeck();
	simDeck.shuffleDeck();
	simDeck.shuffleDeck();
	simDeck.shuffleDeck();
	simDeck.shuffleDeck();
	simDeck.shuffleDeck();
	simDeck.shuffleDeck();
	
	//Count hands with pairs
	for (int i = 0; i < numHands; i++) {

		//Populate hand from Deck
		for (int j = 0; j < numCards; j++) {
			if (static_cast<int>(simDeck.deckSize()) < numCards) { simDeck.shuffleDeck(); }
			hand.push_back(simDeck.dealCard());
		}

		//Check for pair, increment count if so.
		if (hasPair(hand)) { count++; }
		
		//Empty hand
		hand.clear();
		
		//Shuffle Deck between each use
		simDeck.shuffleDeck();
	}
	
	return static_cast<double>(count) / static_cast<double>(numHands);
}

double runSimulation(int numCards, int numHands, const string &fileName) {
	Deck simDeck;
	vector<Card> hand;
	ofstream dataFile;
	int count = 0;

	//Open specified file
	dataFile.open(fileName, std::ofstream::out);
	if (!dataFile.is_open()) {
		cout << "Error opening " << fileName << endl;
		exit(1);
	}

	//Shuffle Deck before use
	simDeck.shuffleDeck();
	simDeck.shuffleDeck();
	simDeck.shuffleDeck();
	//simDeck.shuffleDeck();
	//simDeck.shuffleDeck();
	//simDeck.shuffleDeck();
	//simDeck.shuffleDeck();

	//Count hands with pairs
	for (int i = 0; i < numHands; i++) {

		//Populate hand from Deck
		for (int j = 0; j < numCards; j++) {
			if (static_cast<int>(simDeck.deckSize()) < numCards) { simDeck.shuffleDeck(); }
			hand.push_back(simDeck.dealCard());
		}

		//Check for pair, increment count if so.
		if (hasPair(hand)) { count++; }

		//Save hand to file
		hasPair(hand) ? dataFile << "Found Pair!! " << hand << endl : dataFile << "             " << hand << endl;

		//Empty hand
		hand.clear();
	}

	//Close file stream object
	dataFile.close();

	return static_cast<double>(count) / static_cast<double>(numHands);
}

/* Passes in a vector of Cards and outputs to the stream each Card
   separated by a comma and a space,
   with no comma, space, or newline at the end.*/
ostream & operator<<(ostream &out, const vector<Card> &hand) {
	int length = static_cast<int>(hand.size());

	//insert cards in stream
	for (int i = 0; i < length - 1; i++) {
		out << hand.at(i) << ", ";
	}
	out << hand.at(length - 1);

	return out;
}