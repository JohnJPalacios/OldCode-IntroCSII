// Implementation file for class IntVector IntVector.cpp
// Author John Palacios

#include "IntVector.h"

IntVector::IntVector(unsigned size, int value) {

	//alocate memory for data private member
	data = new int[size];
	if (data == nullptr) { throw "Error allocating memory! \n"; }

	//Initialize values of data member with passed in value
	for (unsigned i = 0; i < size; i++) {
		data[i] = value;
	}

	//Initialize size and capacity members
	sz = size;
	cap = size;
}

const int & IntVector::at(unsigned index) const {
	if (index < sz) { return data[index]; }								//Perform bounds checking, then return data at valad address
	else { throw std::out_of_range("IntVector::at_range_check"); }
}

const int & IntVector::front() const {
	if (data != nullptr) { return data[0]; }							//Only works if data has been allocated
	else { throw std::out_of_range("IntVector::bad_weak_ptr"); }
}

const int & IntVector::back() const {
	if (data != nullptr) { return data[sz - 1]; }						//Only works if data has been allocated
	else { throw std::out_of_range("IntVector::bad_weak_ptr"); }
}

bool IntVector::empty() const {
	bool isEmpty;
	sz == 0 ? isEmpty = true : isEmpty = false;							//Returns true when sz = 0, else returns false
	return isEmpty;
}

IntVector::~IntVector() {
	delete[] data;														//Dealocate dynamically allocated memroy
	data = NULL;														//Ground pointer
}