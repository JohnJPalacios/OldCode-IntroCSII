//Header file for SortedSet class file IntList.h
/*	 Class SortedSet provides an object which emulates an integer version of the Set abstract data structur	 */
//Author: John Palacios

#ifndef SORTEDSET_H
#define SORTEDSET_H
#include "IntList.h"

class SortedSet : public IntList {
public:
	SortedSet() {}																		//Default constructor
	SortedSet(const SortedSet &set) : IntList(set) {}									//Copy constructor
	SortedSet(const IntList &list) : IntList(list) {									//Copy constructor for use with IntList objects. Deletes duplicates then sorts remaining elements
		this->remove_duplicates();
		this->selection_sort();
	}														
	~SortedSet() {}																		//Destructor for base class already deletes dynamically allocated objects
	bool in(int data);																	//Returns true if data is in Set
	SortedSet & operator|(const SortedSet &rhs);										//Returns the union of left and right hand operands. x in AUB => x in A or x in B
	SortedSet & operator&(const SortedSet &rhs);										//Returns the intersection of left and right operands. x in AnB => x in A and x in B
	void add(int data) { if (!in(data)) { this->IntList::insert_ordered(data); } }		//Adds data to set in order if data not in set.
	void push_front(int data) { add(data); }											//Overides Base class's member function so that order is maintained and no duplicate values are added
	void push_back(int data) { add(data); }												//Overides Base class's member function so that order is maintained and no duplicate values are added
	void insert_ordered(int data) { add(data); }										//Overides Base class's member function so that duplicate values are not added.
	SortedSet & operator|=(const SortedSet &rhs);										//Union-assign operator. Returns a union of the left and right operands, but also sets the left operand's elements to be the union of lhs and rhs
	SortedSet & operator&=(const SortedSet &rhs);										//Intersection-assign operator. Returns a Intersection of the left and right operands, but also sets the left operand's elements to be the intersection of lhs and rhs
};


#endif /* SORTEDSET_H */