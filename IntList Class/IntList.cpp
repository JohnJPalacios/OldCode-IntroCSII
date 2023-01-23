//Implementation file for class IntList. file IntList.cpp
//Author: John Palacios

#include "IntList.h"
#include <map>
using namespace std;

IntList::IntList(const IntList &cpy) {
	IntNode *temp = nullptr;								//Holds address of next node
	if (head != nullptr) {									//Need to delete current nodes, then while currNode != nullptr,
															//push cpy's node's value onto the list.
		while (head != nullptr) {							//Loop through list deleting items until end is reached
			temp = head->next;
			delete head;
			head = temp;
		}
	}

	temp = cpy.head;
	while (temp != nullptr) {								//Push each of cpy's values onto the list
		this->push_back(temp->data);
		temp = temp->next;
	}

}

IntList & IntList::operator=(const IntList &rhs) {
	IntNode *temp = nullptr;								//Holds address of next node

	if (rhs.head != this->head) {							//protect against self copying

		if (head != nullptr) {								//Need to delete current nodes
			while (head != nullptr) {						//Loop through list deleting items until end is reached
				temp = head->next;
				delete head;
				head = temp;
			}
		}

		temp = rhs.head;
		while (temp != nullptr) {							//Push each of rhs's values onto the list
			this->push_back(temp->data);
			temp = temp->next;
		}
	}
	return *this;
}

void IntList::push_back(int value) {
	IntNode *temp = nullptr;								//Node to be pushed into the tail end of the linked list
	temp = new IntNode(value);								//Alocate memory for IntNode to be pushed onto tail end of linked list

															//handle case when list is not empty
	if (head != nullptr) {									//Push temp into tail end of linked list
		tail->next = temp;
		tail = temp;
	}

	//Handle case when list was empty
	else {
		head = temp;
		tail = temp;
	}
}

void IntList::selection_sort() {
	IntNode *index = nullptr;								//Node which we want to be smallest value of remaining nodes
	IntNode *runer = nullptr;								//Pointer used to examine remaining nodes to determine which is smallest
	IntNode *minnd = nullptr;								//Points to node with smallest value
	int temp;												//Used to store index->value to facilitate swap between index->value and minnd->value
	int minval;

	if (head != nullptr) {									//calling selection_sort on an empty list does nothing
		index = head;
		minnd = head;
		minval = head->data;
		while (index->next != nullptr) {
			runer = index->next;
			while (runer != nullptr) {
				if (runer->data < minval) {					//Find node with smallest value
					minnd = runer;
					minval = runer->data;
				}
				runer = runer->next;
			}
			if (minnd != index) {							//Swap values if minnd != index
				temp = index->data;
				index->data = minnd->data;
				minnd->data = temp;
			}
			index = index->next;
			minnd = index;
			minval = index->data;
		}
	}
}

void IntList::insert_ordered(int value) {
	IntNode *runer = nullptr;
	IntNode *temp = nullptr;

	runer = head;
	while (runer != nullptr && temp == nullptr) {			//Search list for data > value. Short circuit with assignment of temp.
		if (runer->data > value && temp == nullptr) {		//Once found, create a new IntNode, point this temp to runer's next and temp's data becomes runner's data
			temp = new IntNode(runer->data);
			temp->next = runer->next;
			runer->data = value;							//Copy value into runer's data, then point runer to temp.
			runer->next = temp;
			if (temp->next == nullptr) { tail = temp; }		//Handle case when the new node should be the tail
		}													//The new value has been added to the list
		runer = runer->next;								//Check next value. No short circuiting, so this search always
	}

	if (temp == nullptr) { this->push_back(value); }		//Now to handle case when value is the suprimum of the list values
}

void IntList::remove_duplicates() {
	IntNode *runer = nullptr;								//Pointer which runs through all but last element of list
	IntNode *temp = nullptr;								//Used to point to duplicate node which is to be deleted
	map<int, int> vals;										//map used to track occurance of values
	bool duplicate = false;									//Marks the removal of a duplicate item

	runer = head;											//Point runer to first element in list
	if (runer != nullptr) {
		vals.insert(pair<int, int>(runer->data, 1));		//Add value of first element to map

		while (runer->next != nullptr) {					//Search list for duplicate values
															//If value isn't in vals, add it.
			duplicate = false;
			if (vals.find(runer->next->data) == vals.end()) { vals.insert(pair<int, int>(runer->next->data, 1)); }
			else {
				if (runer->next == tail) { tail = runer; }	//If the node to be deleted is tail, update tail
				temp = runer->next;							//Save node to be deleted
				runer->next = runer->next->next;			//point runner next to next value
				delete temp;								//Now that node is isolated, return it's memory to free store
				temp = nullptr;								//gound temp.
				duplicate = true;							//Flag the removal of a duplicate. No need to progress pointer
			}
			if (runer->next != nullptr && duplicate == false) { runer = runer->next; }
		}
	}
}

IntList::~IntList() {										//I am the omega
	IntNode *temp = nullptr;								//Holds address of next node

	while (head != nullptr) {								//Loop through list deleting items until end is reached
		temp = head->next;
		delete head;
		head = temp;
	}

	tail = nullptr;											//Ground tail
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

ostream & operator<<(ostream &out, const IntList &rhs) {
	IntList copy(rhs);										//Duplicate of rhs

	while (!copy.empty()) {									//insert rhs values into out stream
		out << copy.front();
		copy.pop_front();
		if (!copy.empty()) { out << " "; }					//Add space only if mirr is not empty
	}
	return out;
}

void IntList::pop_front() {
	IntNode *temp = nullptr;								//Will point to head

	if (head != nullptr) {									//Only operate on populated list
		temp = head;										//Remember where this alocated memory is located
		head = head->next;									//Point head to the element after first

		delete temp;										//Return alocated memory to free store
		temp = nullptr;										//Ground pointe
	}
}

void IntList::clear() {
	IntNode *temp = nullptr;								//Holds address of next node

	while (head != nullptr) {								//Loop through list deleting items until end is reached
		temp = head->next;
		delete head;
		head = temp;
	}

	tail = nullptr;											//Ground tail
}