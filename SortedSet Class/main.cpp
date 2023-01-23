//This main file serves as a test harness for the SortedSet class file main.cpp
//Author: John Palacios

#include "SortedSet.h"
#include <iostream>
using namespace std;

int main() {
	//Test default constructor
	SortedSet theEmptySet;

	theEmptySet.empty() ? cout << "The empty set is empty\n" : cout << "The empty set is not so empty after all...\n";

	//Testing member function add
	SortedSet setA;

	setA.empty() ? cout << "The setA is empty\n" : cout << "The setA is not so empty after all...\n";
	setA.add(4);
	setA.empty() ? cout << "The setA is empty\n" : cout << "The setA is not so empty after all...\n";
	cout << setA << endl;

	//Testing member function in
	setA.in(4) ? cout << "The setA contains 4\n" : cout << "The setA does not contain 4. Something went wrong...\n";

	//Testing the copy constructor
	SortedSet setB(setA);
	setB.in(4) ? cout << "The setB contains 4\n" : cout << "The setB does not contain 4. Something went wrong...\n";

	//Testing intList to SortedSet copy constructor
	IntList list1;
	
	list1.push_back(5);
	list1.push_back(7);
	list1.push_back(-4);
	setB = list1;
	cout << "List1 contains: " << list1 << endl;
	cout << "SetB contains: " << setB << endl;
	SortedSet setC(list1);
	cout << "SetC contains: " << setC << endl;

	//Testing Union and intersection operators
	SortedSet setD;
	SortedSet setE;
	setD = setA | setB;
	cout << "SetD contains: " << setD << endl;

	setE = setA & setD;
	cout << "SetE contains: " << setE << endl;

	//Testing union assignment operator
	setE |= setD;
	cout << "SetE contains: " << setE << endl;

	//Testing intersection assignment operator
	setE &= setA;
	cout << "SetE contains: " << setE << endl;

	return 0;
}