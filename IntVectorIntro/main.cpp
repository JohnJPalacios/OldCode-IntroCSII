// This is a test function for the IntVector class
// Author: John Palacios

#include "IntVector.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
	IntVector defaultTest;						//Testing default constructur
	IntVector param1Test(3);					//Testing paramaratized constructor with predef
	IntVector param2Test(5, 5);					//Testing paramaratized constructor without predef
	vector<int> sample(5, 5);

	//testing .at member fnctn with valid input
	cout << param2Test.at(2) << endl;

	//Testing .at member fnctn with invalid input, expect out of bounds error thrown
	//cout << param2Test.at(5) << endl;			error as expected

	//tsting size member fnctn
	cout << "Expect 0. Size of default constructed IntVector: " << defaultTest.size() << endl;
	cout << "Expect 5. Size of paramet constructed IntVector: " << param2Test.size() << endl;

	//Testing capacity member fnctn
	cout << "Expect 0. capacity of default constructed IntVector: " << defaultTest.capacity() << endl;
	cout << "Expect 5. capacity of paramet constructed IntVector: " << param2Test.capacity() << endl;

	//Testing empty member fnctn
	if (defaultTest.empty()) { cout << "default constructed IntVector is empty\n"; }
	if (param1Test.empty()) { cout << "Unexpected execution; param1Test is empty\n"; }

	//Testing member fctn front()
	cout << "The front of param2Test is: " << param2Test.front() << ". Expecting 5.\n";

	//Testing member fctn back()
	cout << "The back of param1Test is: " << param1Test.back() << ". Expecting 0.\n";
	
	return 0;
}