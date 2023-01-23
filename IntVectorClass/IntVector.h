// IntVector class header file IntVector.h
// Author: John Palacios

#ifndef INTVECTOR_H
#define INTVECTOR_H
#include <stdexcept>
class IntVector {
public:
	IntVector() : sz(0), cap(0) {}							//Standard constructor
	IntVector(unsigned size, int value = 0);				//Parameratized constructor
	IntVector(const IntVector& OrigVec);					//Copy constructor
	IntVector& operator=(const IntVector& assignObj);		//Overloading the asignment operator to handle data*
	~IntVector();											//destructor; deletes pointer data member
	unsigned size() const { return sz; }					//returns size of vector
	unsigned capacity() const { return cap; }				//returns total capacity of vector
	bool empty() const;										//returns true if vector is empty
	const int & at(unsigned index) const;					//returns data[i] for this->at(i)
	int & at(unsigned index);								//mutator function for data[index]
	void insert(unsigned index, int value);					//Insert value at index in data
	void erase(unsigned index);								//Erasses data stored at index, moves elements at indicis greater than index down one index
	const int & front() const;								//returns value of data[0]
	int & front();											//Mutator for data at first element
	const int & back() const;								//returns value of data[size -1]
	int & back();											//Mutator for data at last element
	void assign(unsigned n, int value);						//Erases all data, then stores n elements of value value in data. expand as necessary
	void push_back(int value);								//Increase sz by one, storing value at new last element. expand as necessary
	void pop_back() { if (sz > 0) { sz -= 1; } }			//Delete last element. Decrement sz
	void clear() { sz = 0; }								//Delete all values from data and set sz to zero
	void resize(unsigned size, int value = 0);				//Resize vector to contain size elements. If sz < size, decrement sz. If size > sz, insert (size - sz) elements,
															//initializing each new element to value
	void reserve(unsigned n);								//Request capacity be set to at least n. If n > cap, expand data to n, each element uninitialized

private:
	unsigned sz;											//stores the size of the IntVector(the number of elements currently being used).
	unsigned cap;											//stores the size of the array
	int *data = nullptr;									//stores the address of the dynamically - allocated array of integers
	void expand();											//Doubles capacity of vector.
	void expand(unsigned amount);							//Expands the capacity of vector by amount
};

#endif // !INTVECTOR_H