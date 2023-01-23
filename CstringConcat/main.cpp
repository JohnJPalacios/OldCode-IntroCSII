// main.cpp the entry point to a simple demonstration of an implementation of the C string libraries string concatination function
// Author: John Palacios

#include <iostream>
using namespace std;

/* Concatenate strings
   Appends a copy of the source string to the destination string.
   The terminating null character in destination is overwritten by the
   first character of source, and a null-character is included at the
   end of the new string formed by the concatenation of both in destination.

   returns destination.*/
char * mystrcat(char * destination, const char * source);

int main() {

	//char foo[15] = "Hello ";			//Test destination
	//char bar[10] = " World";			//Test source

	////Test of function
	//mystrcat(foo, bar);

	////Varifying results
	//cout << foo << endl;

	char cstr1[80];
	char cstr2[80];

	cstr1[0] = 'L';
	cstr1[1] = 'i';
	cstr1[2] = 'o';
	cstr1[3] = 'n';
	cstr1[4] = 'e';
	cstr1[5] = 'l';
	cstr1[6] = '\0';

	cstr2[0] = 'M';
	cstr2[1] = 'e';
	cstr2[2] = 's';
	cstr2[3] = 's';
	cstr2[4] = 'i';
	cstr2[5] = '\0';

	cout << cstr1 << endl;
	cout << cstr2 << endl;

	mystrcat(cstr1, " ");
	mystrcat(cstr1, cstr2);

	cout << cstr1 << endl;

	return 0;
}

char * mystrcat(char * destination, const char * source) {
	int i = 0;						//Index of null termination in distination C-string.
	int j = 0;						//Current index of source C-string

	//Deterimine termination of destination C-string
	while (destination[i] != '\0') {
		i++;
	}

	//Begin concatination process
	while (source[j] != '\0') {
		destination[i + j] = source[j];
		j++;
	}
	destination[i + j] = '\0';

	return destination;
}