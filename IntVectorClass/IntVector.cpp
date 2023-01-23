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

IntVector::IntVector(const IntVector& OrigVec) {
	cap = OrigVec.capacity();				//Local object's copy of cap member
	sz = OrigVec.size();					//Local object's copy of sz member

	//alocate memory for data private member in copied obj
	data = new int[cap];
	if (data == nullptr) { throw "Error allocating memory! \n"; }

	//Copy data member values
	for (unsigned i = 0; i < sz; i++) { data[i] = OrigVec.at(i); }
}

IntVector& IntVector::operator=(const IntVector& assignObj) {
	if (this != &assignObj) {					//Prevent needless self assignment

		cap = assignObj.capacity();				//copy assignObj's cap member
		sz = assignObj.size();					//copy assignObj's sz member

		//Free this data's dynamically alocated data if need be
		if (data != nullptr) { delete[] data; }

		//alocate memory for data private member in copied obj
		data = new int[cap];
		if (data == nullptr) { throw "Error allocating memory! \n"; }

		//Copy data member values
		for (unsigned i = 0; i < sz; i++) { data[i] = assignObj.at(i); }
	}

	return *this;
}

const int & IntVector::at(unsigned index) const {
	if (index < sz) { return data[index]; }															//Perform bounds checking, then return data at valad address
	else { throw std::out_of_range("IntVector::at_range_check"); }
}

int & IntVector::at(unsigned index) {
	if (index < sz) { return data[index]; }															//Perform bounds checking, then return data at valad address
	else { throw std::out_of_range("IntVector::at_range_check"); }
}

const int & IntVector::front() const {
	if (data != nullptr) { return data[0]; }														//Only works if data has been allocated
	else { throw std::out_of_range("IntVector::bad_weak_ptr"); }
}

int & IntVector::front() {
	if (data != nullptr) { return data[0]; }														//Only works if data has been allocated
	else { throw std::out_of_range("IntVector::bad_weak_ptr"); }
}

const int & IntVector::back() const {
	if (data != nullptr) { return data[sz - 1]; }													//Only works if data has been allocated
	else { throw std::out_of_range("IntVector::bad_weak_ptr"); }
}

int & IntVector::back() {
	if (data != nullptr) { return data[sz - 1]; }													//Only works if data has been allocated
	else { throw std::out_of_range("IntVector::bad_weak_ptr"); }
}

bool IntVector::empty() const {
	bool isEmpty;
	sz == 0 ? isEmpty = true : isEmpty = false;														//Returns true when sz = 0, else returns false
	return isEmpty;
}

void IntVector::expand() {

	//Exclude those vectors with unitialized data members
	if (cap == 0) {
		data = new int[1];
		cap = 1;
	}
	else {
		//allocate memory for the expanded data member
		int *temp = new int[2 * cap];

		//Copy data values into temp pointer
		for (unsigned i = 0; i < sz; i++) { temp[i] = data[i]; }

		//Return data memory to free store
		delete[] data;
		data = nullptr;

		//point data to temp's memory location
		data = temp;

		//update other members
		cap *= 2;
	}
	
}

void IntVector::expand(unsigned amount) {
	//Exclude those vectors with unitialized data members
	if (cap == 0) {
		data = new int[amount];
		cap = amount;
	}
	else {
		//allocate memory for the expanded data member
		int *temp = new int[cap + amount];

		//Copy data values into temp pointer
		for (unsigned i = 0; i < sz; i++) {
			temp[i] = data[i];
		}

		//Return data memory to free store and ground data before assigning
		//address to data
		delete[] data;
		data = nullptr;

		//point data to temp's memory location
		data = temp;

		//update other members
		cap += amount;
	}
}

void IntVector::insert(unsigned index, int value) {
	if (index > sz) { throw std::out_of_range("IntVector::insert_range_check"); }					//Perform bounds checking before attempting to insert
	if (sz == cap) { this->expand(); }																//Expand data member if necessary

	//Declare loop variables of type int
	int begin = static_cast<int>(sz) - 1;
	int end = static_cast<int>(index) - 1;

	//Shuffle elements at and above index to one index up
	for (int i = begin; i > end; i--) { data[i + 1] = data[i]; }

	//assign value to data[index]
	data[index] = value;

	//Update size
	sz += 1;
}

void IntVector::erase(unsigned index) {
	if (index >= sz) { throw std::out_of_range("IntVector::erase_range_check"); }						//Perform bounds checking before attempting to erase

	//Shuffle elements down from index + 1 to index and i to i - 1
	for (unsigned i = index + 1; i < sz + 1; i++) { data[i - 1] = data[i]; }

	//Reduce sz by one. No need to actually erase last element
	sz -= 1;
}

void IntVector::assign(unsigned n, int value) {
	//Handle case when requested size is greater than current capacity
	//If so, and 2 * cap > n - cap then expand this obj, else expand by n - cap
	if (n > cap) { 2 * cap > n ? this->expand() : this->expand(n - cap); }

	//update size
	sz = n;

	//write value to first n elements of data
	for (unsigned i = 0; i < sz; i++) { data[i] = value; }
}

void IntVector::push_back(int value) {
	if (sz + 1 > cap) { this->expand(); }															//Check new size against cap, expanding data as necessary

	//Update size
	sz += 1;

	//write to end of data member
	data[sz - 1] = value;
}

void IntVector::resize(unsigned size, int value) {
	if (size > cap) { 2 * cap > size ? this->expand() : this->expand(size - cap); }			//If size > cap, expand data memer by max{2*cap, size-cap};

	//should size be less than sz
	if (size < sz) { sz = size; }

	//should size be greater than sz
	else { 
		for (unsigned i = sz; i < size; i++) { data[i] = value; }
		sz = size;
	}
}

void IntVector::reserve(unsigned n) { 
	if (n > cap) { this->expand(n - cap); }															//If n > cap, then reserve exactly n*size_of_Int memory locations
}

IntVector::~IntVector() {
	delete[] data;																					//Dealocate dynamically allocated memroy
	data = NULL;																					//Ground pointer
}