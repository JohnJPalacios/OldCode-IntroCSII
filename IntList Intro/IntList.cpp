//Implementation file for class IntList. file IntList.cpp
//Author: John Palacios

#include "IntList.h"
#include <iostream>
using namespace std;


IntList::~IntList() {
	IntNode *temp = nullptr;								//Holds address of next node

	while (head != nullptr) {								//Loop through list deleting items until end is reached
		temp = head->next;
		delete head;
		head = temp;
		}
}

void IntList::push_front(int value) {
	IntNode *temp = nullptr;								//Node to be pushed into the front of the linked list
	temp = new IntNode(value);								//Alocate memory for IntNode to be pushed onto front of linked list

	//Push temp into front of linked list
	temp->next = head;
	head = temp;

	//Handle case when list was empty
	if (tail == nullptr) { tail = temp; }
}

void IntList::display() const {
	IntNode *temp = nullptr;								//Points to current element in linked list

	temp = head;											//Point current pointer to start of list
	while (temp != nullptr) {								//print contents of non-null nodes 
		cout << temp->data;									//followed by space if not at end
		temp = temp->next;

		if (temp != nullptr) { cout << " "; }
	}
}

void IntList::pop_front() {
	IntNode *temp = nullptr;								//Will point to head

	//Delete node pointed to by head
	temp = head;											//Remember where this alocated memory is located
	head = head->next;										//Point head to the element after first

	delete temp;											//Return alocated memory to free store
	temp = nullptr;											//Ground pointer
}