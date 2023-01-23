//Header file for both IntList Class and IntNode Struct file IntList.h
/*	 Class IntList provides an object which maintains a linked list abstract data structur	 */
//Author: John Palacios

#ifndef INTLIST_H	
#define INTLIST_H
#include <cstdlib>
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
	IntList() {}												//Initializes and empty list
	~IntList();													//Dealocates dynamically alocated IntNotdes
	void display() const;										//Prints values stored in list to single, non-new line terminated line seperated by spaces
	void push_front(int);										//Inserts new node with value at the front of the list
	void pop_front();											//Removes the node at the front end of the list
	bool empty() const {return head == nullptr; }				//Retuns true if the list is empty
	const int & front() const { return head->data; }			//Returns a reference to the first value in the list. Need not check for empty list
	const int & back() const { return tail->data; }				//Returns a reference to the last value in the list. Need not check for empty list

private:
	IntNode *head = nullptr;									//Points to first node in linked list
	IntNode *tail = nullptr;									//Points to last node in linked list
};

#endif /*INTLIST_H*/