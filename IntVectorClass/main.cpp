// This is a test harness for the IntVector class
// Author: John Palacios

#include "IntVector.h"
#include <vector>
#include <iostream>
using namespace std;

void printElements(const IntVector);

int main() {
	IntVector defaultTest;						//Testing default constructur
	IntVector param1Test(3);					//Testing paramaratized constructor with predef
	IntVector param2Test(5, 5);					//Testing paramaratized constructor without predef

	////Test member fxn resize
	//defaultTest.resize(49, 4);
	//defaultTest.assign(100, 5);

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

	//Testing member fctn insert and private member fctn expand
	param1Test.insert(2, 4);
	cout << "param1Test now contains:\n";
	printElements(param1Test);
	cout << endl;

	param1Test.insert(0, 3);
	cout << "param1Test now contains:\n";
	printElements(param1Test);
	cout << endl;

	param1Test.insert(4, 2);
	cout << "param1Test now contains:\n";
	printElements(param1Test);
	cout << endl;

	//Testing member fctn delete
	param1Test.erase(2);
	cout << "After erasing element at index 2;\n";
	printElements(param1Test);
	cout << endl;

	//Testing member fxn assign
	param1Test.assign(10, -4);
	cout << "After assigning the value -4 to 10 elements of param1Test, we have:\n";
	printElements(param1Test);
	cout << endl;

	//Testing member fxn push_back
	for (int i = 0; i < 6; i++) { defaultTest.push_back(i); }
	cout << "DefaultTest now contains:\n";
	printElements(defaultTest);
	cout << endl;

	//Testing member fxn resize
	cout << "Resizeing defaultTest to 3 elements\n";
	defaultTest.resize(3);
	printElements(defaultTest);
	cout << endl;

	cout << "Now to resize defaultTest to ten elements, additional elements set to 4\n";
	defaultTest.resize(100, 4);
	printElements(defaultTest);
	cout << endl;

	//Testing member fxn reserve
	param1Test.reserve(15);

	/*******************************End Tests*******************************/
	return 0;
}

void printElements(const IntVector vect) {
	int length = static_cast<int>(vect.size());

	for (int i = 0; i < length; i++) {
		cout << vect.at(i) << endl;
	}
}