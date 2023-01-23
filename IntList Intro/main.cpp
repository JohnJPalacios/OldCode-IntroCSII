//This is a test harness for the IntList class
//Author: John Palacios

#include <iostream>
#include "IntList.h"
using namespace std;



int main() {

	//tests constructor, destructor, push_front, pop_front, display

	{/*		Test destructor by going out of scope 	 */
		cout << "\nlist1 constructor called" << flush;
		IntList list1;
		cout << "\npushfront 10" << flush;
		list1.push_front(10);
		cout << "\npushfront 20" << flush;
		list1.push_front(20);
		cout << "\npushfront 30" << flush;
		list1.push_front(30);
		cout << "\nlist1: " << flush;
		list1.display();
		cout << "\npop" << flush;
		list1.pop_front();
		cout << "\nlist1: " << flush;
		list1.display();
		cout << "\npop" << flush;
		list1.pop_front();
		cout << "\nlist1: " << flush;
		list1.display();
		cout << "\npop" << flush;
		list1.pop_front();
		cout << "\nlist1: " << flush;
		list1.display();
		cout << "\nlist1 is ";
		list1.empty() ? cout << "empty\n" : cout << "Non-empty\n SOMETHING WENT WRONG!\n";
		cout << "\npushfront 100" << flush;
		list1.push_front(100);
		cout << "\npushfront 200" << flush;
		list1.push_front(200);
		cout << "\npushfront 300" << flush;
		list1.push_front(300);
		cout << "\nlist1: " << flush;
		list1.display();
		cout << endl;
		cout << "\nthe front of the list contains: " << list1.front() << endl;
		cout << "\nthe back of the list contains: " << list1.back() << endl;
	}
	cout << "list1 destructor called" << endl;

	return 0;
}