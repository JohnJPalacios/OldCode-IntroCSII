//Header file for both IntList Class and IntNode Struct file IntList.h
/*	 Class IntList provides an object which maintains a linked list abstract data structur	 */
//Author: John Palacios

#ifndef INTLIST_H	
#define INTLIST_H
#include <cstdlib>
#include <iostream>
using namespace std;

//IntNode data structue
struct IntNode {
	int data;
	IntNode *next;
	IntNode(int data) : data(data), next(0) {}
};

//IntList Class declaration
class IntList
{
public:
	IntList() {}													//Initializes and empty list.
	IntList(const IntList &cpy);									//Copy constructor.
	IntList & operator=(const IntList &rhs);						//Overloaded assignment operator. Performs deep copy.
	~IntList();														//Dealocates dynamically alocated IntNotdes.
	void display() const;											//Prints values stored in list to single, non-new line terminated line seperated by spaces.
	friend ostream & operator<<(ostream &out, const IntList &rhs);	//Overloads ostream operator to properly display list.
	void push_front(int);											//Inserts new node with value at the front of the list.
	void push_back(int);											//Inserts new node with value at the tail end of the list.
	void pop_front();												//Removes the node at the front end of the list.
	void clear();													//Removes all Nodes in the list.
	void selection_sort();											//Arranges list values into ascending order. Nodes not moved.
	void insert_ordered(int);										//Pushes new IntNode into position assuming list is in ascending order.
	void remove_duplicates();										//Removes the second instance of any duplicate values found in the list.
	bool empty() const { return head == nullptr; }					//Retuns true if the list is empty
	const int & front() const { return head->data; }				//Returns a reference to the first value in the list. Need not check for empty list.
	const int & back() const { return tail->data; }					//Returns a reference to the last value in the list. Need not check for empty list.

protected:
	IntNode *head = nullptr;										//Points to first node in linked list.
	IntNode *tail = nullptr;										//Points to last node in linked list.
};

#endif /*INTLIST_H*/