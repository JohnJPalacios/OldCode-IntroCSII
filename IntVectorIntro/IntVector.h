// IntVector class header file IntVector.h
// Author: John Palacios

#ifndef INTVECTOR_H
#define INTVECTOR_H
#include <stdexcept>
class IntVector {
public:
	IntVector() : sz(0), cap(0) {}							//Standard constructor
	IntVector(unsigned size, int value = 0);				//Parameratized constructor
	~IntVector();											//destructor; deletes pointer data member
	unsigned size() const { return sz; }					//returns size of vector
	unsigned capacity() const { return cap; }				//returns total capacity of vector
	bool empty() const;										//returns true if vector is empty
	const int & at(unsigned index) const;					//returns data[i] for this->at(i)
	const int & front() const;								//returns value of data[0]
	const int & back() const;								//returns value of data[size -1]
private:
	unsigned sz;											// stores the size of the IntVector(the number of elements currently being used).
	unsigned cap;											// stores the size of the array
	int *data = nullptr;									// stores the address of the dynamically - allocated array of integers
};

#endif // !INTVECTOR_H
