//Implementation file for class SortedSet. file SortedSet.cpp
//Author: John Palacios

#include "SortedSet.h"
using namespace std;

bool SortedSet::in(int data) {
	IntNode *temp = head;
	while (temp != nullptr) {													//Traverse the list looking for the data value
		if (temp->data == data) { return true; }
		temp = temp->next;
	}
	return false;
}

//SortedSet::SortedSet(const SortedSet &set) {									//Uses base class copy constructor
//	this->IntList::IntList(set);
//}

//SortedSet::SortedSet(const IntList &list) {									//Uses base class copy constructor, remove_duplicates, and selection sort methods
//	this->IntList::IntList(list);
//	this->remove_duplicates();
//	this->selection_sort();
//}

SortedSet & SortedSet::operator|(const SortedSet &rhs) {						//A union B = A | B
	SortedSet *temp = new SortedSet(*this);
	IntNode *runner = rhs.head;
	
	while (runner != nullptr) {
		temp->add(runner->data);
		runner = runner->next;
	}
	return *temp;
}

SortedSet & SortedSet::operator&(const SortedSet &rhs) {						//A intersection B = A & B
	SortedSet *temp = new SortedSet;
	IntNode *runner = rhs.head;

	while (runner != nullptr) {
		if (this->in(runner->data)) { temp->add(runner->data); }
		runner = runner->next;
	}
	return *temp;
}

SortedSet & SortedSet::operator|=(const SortedSet &rhs) {								//Does this NEED to return anything?
	IntNode *runner = nullptr;

	runner = rhs.head;
	while (runner != nullptr) {
		this->add(runner->data);
		runner = runner->next;
	}
	return *this;
}

SortedSet & SortedSet::operator&=(const SortedSet &rhs) {						//Returning only because requested
	SortedSet *temp = new SortedSet;
	IntNode *runner = rhs.head;

	while (runner != nullptr) {
		if (this->in(runner->data)) { temp->add(runner->data); }
		runner = runner->next;
	}
	this->operator=(*temp);
	return *temp;
}