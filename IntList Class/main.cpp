//This is a test harness for the IntList class
//Author: John Palacios

#include "IntList.h"

#include <iostream>
using namespace std;

int main() {
	cout << "Enter a test number(1-5): ";
	int test;
	cin >> test;
	cout << endl;
	//tests constructor, destructor, push_front, pop_front, display
	if (test == 1) {
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
		cout << endl;
	}
	if (test == 1) {
		cout << "list1 destructor called" << endl;
	}

	//tests push_back
	if (test == 2) {
		cout << "\nlist2 constructor called" << flush;
		IntList list2;
		cout << "\npushback 10" << flush;
		list2.push_back(10);
		cout << "\npushback 20" << flush;
		list2.push_back(20);
		cout << "\npushback 30" << flush;
		list2.push_back(30);
		cout << "\nlist2: " << flush;
		list2.display();
		cout << "\npop" << flush;
		list2.pop_front();
		cout << "\nlist2: " << flush;
		list2.display();
		cout << "\npop" << flush;
		list2.pop_front();
		cout << "\nlist2: " << flush;
		list2.display();
		cout << "\npop" << flush;
		list2.pop_front();
		cout << "\nlist2: " << flush;
		list2.display();
		cout << endl;
	}
	if (test == 2) {
		cout << "list2 destructor called" << endl;
	}

	//tests selection_sort
	if (test == 3) {
		cout << "\nlist3 constructor called" << flush;
		IntList list3;
		cout << "\npushfront 10" << flush;
		list3.push_front(10);
		cout << "\npushfront 20" << flush;
		list3.push_front(20);
		cout << "\npushfront 30" << flush;
		list3.push_front(30);
		cout << "\nlist3: " << flush;
		list3.display();
		cout << "\nselection_sort()" << flush;
		list3.selection_sort();
		cout << "\nlist3: " << flush;
		list3.display();
		cout << "\npop" << flush;
		list3.pop_front();
		cout << "\npop" << flush;
		list3.pop_front();
		cout << "\npop" << flush;
		list3.pop_front();
		cout << "\nlist3: " << flush;
		list3.display();
		cout << "\nselection_sort()" << flush;
		list3.selection_sort();
		cout << "\nlist3: " << flush;
		list3.display();
		cout << "\npushfront 10" << flush;
		list3.push_front(10);
		cout << "\nselection_sort()" << flush;
		list3.selection_sort();
		cout << "\nlist3: " << flush;
		list3.display();
		cout << "\npushfront 20" << flush;
		list3.push_front(20);
		cout << "\nlist3: " << flush;
		list3.display();
		cout << "\nselection_sort()" << flush;
		list3.selection_sort();
		cout << "\nlist3: " << flush;
		list3.display();
		cout << endl;
	}
	if (test == 3) {
		cout << "list3 destructor called" << endl;
	}

	//tests insert_sorted
	if (test == 4) {
		cout << "\nlist4 constructor called" << flush;
		IntList list4;
		cout << "\ninsert 20" << flush;
		list4.insert_ordered(20);
		cout << "\ninsert 10" << flush;
		list4.insert_ordered(10);
		cout << "\ninsert 30" << flush;
		list4.insert_ordered(30);
		cout << "\nlist4: " << flush;
		list4.display();
		cout << "\ninsert 50" << flush;
		list4.insert_ordered(50);
		cout << "\nlist4: " << flush;
		list4.display();
		cout << "\ninsert 40" << flush;
		list4.insert_ordered(40);
		cout << "\nlist4: " << flush;
		list4.display();
		cout << "\ninsert 11" << flush;
		list4.insert_ordered(11);
		cout << "\nlist4: " << flush;
		list4.display();
		cout << "\ninsert 10" << flush;
		list4.insert_ordered(10);
		cout << "\nlist4: " << flush;
		list4.display();
		cout << "\ninsert 11" << flush;
		list4.insert_ordered(11);
		cout << "\nlist4: " << flush;
		list4.display();
		cout << "\ninsert 9" << flush;
		list4.insert_ordered(9);
		cout << "\nlist4: " << flush;
		list4.display();
		cout << "\ninsert 50" << flush;
		list4.insert_ordered(50);
		cout << "\nlist4: " << flush;
		list4.display();
		cout << "\ninsert 51" << flush;
		list4.insert_ordered(51);
		cout << "\nlist4: " << flush;
		list4.display();
		cout << endl;
	}
	if (test == 4) {
		cout << "list4 destructor called" << endl;
	}

	//tests remove_duplicates
	if (test == 5) {
		cout << "\nlist5 constructor called" << flush;
		IntList list5;
		cout << "\npushfront 10" << flush;
		list5.push_front(10);
		cout << "\npushfront 20" << flush;
		list5.push_front(20);
		cout << "\npushfront 10" << flush;
		list5.push_front(10);
		cout << "\npushfront 30" << flush;
		list5.push_front(30);
		cout << "\nlist5: " << flush;
		list5.display();
		cout << "\nremove_duplicates()" << flush;
		list5.remove_duplicates();
		cout << "\nlist5: " << flush;
		list5.display();
		cout << "\npushfront 10" << flush;
		list5.push_front(10);
		cout << "\nlist5: " << flush;
		list5.display();
		cout << "\nremove_duplicates()" << flush;
		list5.remove_duplicates();
		cout << "\nlist5: " << flush;
		list5.display();
		cout << "\npushfront 20" << flush;
		list5.push_front(20);
		cout << "\nlist5: " << flush;
		list5.display();
		cout << "\nremove_duplicates()" << flush;
		list5.remove_duplicates();
		cout << "\nlist5: " << flush;
		list5.display();
		cout << "\npushfront 20" << flush;
		list5.push_front(20);
		cout << "\nlist5: " << flush;
		list5.display();
		cout << "\nremove_duplicates()" << flush;
		list5.remove_duplicates();
		cout << "\nlist5: " << flush;
		list5.display();
		cout << "\npushfront 20" << flush;
		list5.push_front(20);
		cout << "\npushfront 20" << flush;
		list5.push_front(20);
		cout << "\nlist5: " << flush;
		list5.display();
		cout << "\nremove_duplicates()" << flush;
		list5.remove_duplicates();
		cout << "\nlist5: " << flush;
		list5.display();
		cout << "\nremove_duplicates()" << flush;
		list5.remove_duplicates();
		cout << "\nlist5: " << flush;
		list5.display();
		cout << "\npop" << flush;
		list5.pop_front();
		cout << "\npop" << flush;
		list5.pop_front();
		cout << "\npush_front(30)" << flush;
		list5.push_front(30);
		cout << "\nlist5: " << flush;
		list5.display();
		cout << "\nremove_duplicates()" << flush;
		list5.remove_duplicates();
		cout << "\nlist5: " << flush;
		list5.display();
		cout << "\npush_front(30)" << flush;
		list5.push_front(30);
		cout << "\npush_front(30)" << flush;
		list5.push_front(30);
		cout << "\nlist5: " << flush;
		list5.display();
		cout << "\nremove_duplicates()" << flush;
		list5.remove_duplicates();
		cout << "\nlist5: " << flush;
		list5.display();
		cout << "\nremove_duplicates()" << flush;
		list5.remove_duplicates();
		cout << "\nlist5: " << flush;
		list5.display();
		cout << "\npop" << flush;
		list5.pop_front();
		cout << "\nlist5: " << flush;
		list5.display();
		cout << "\nremove_duplicates()" << flush;
		list5.remove_duplicates();
		cout << "\nlist5: " << flush;
		list5.display();
		cout << endl;
	}
	if (test == 5) {
		cout << "list5 destructor called" << endl;
	}

	/*
	* Destructor will be tested by looking at code. There is no run-time
	* test for it. Make sure your destructor actually deletes ALL nodes, not
	* just the head and/or tail.
	*/

	return 0;
}