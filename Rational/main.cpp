//
//
#include<iostream>
#include<string>
#include<cctype>
using namespace std;


class Date {
private:
	unsigned day;
	unsigned month;
	string monthName;
	unsigned year;
public:
	// creates the date January 1st, 2000.
	Date() : day(1), month(1), monthName("January"), year(2000) {}


	/* parameterized constructor: month number, day, year
		- e.g. (3, 1, 2010) will construct the date March 1st, 2010

		If any of the arguments are invalid (e.g. 15 for month or 32 for day)
		then the constructor will construct instead a valid Date as close
		as possible to the arguments provided - e.g. in above example,
		Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
		In case of such invalid input, the constructor will issue a console error message:

		Invalid date values: Date corrected to 12/31/2010.
		(with a newline at the end).
	*/
	Date(unsigned m, unsigned d, unsigned y);


	/* parameterized constructor: month name, day, year
  ­      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

		If the constructor is unable to recognize the string argument as a valid month name,
		then it will issue a console error message:

		Invalid month name: the Date was set to 1/1/2000.
		(with a newline at the end).

		If the day argument is invalid for the given month (but the month name was valid),
		then the constructor will handle this error in the same manner as the other
		parameterized constructor.

		This constructor will recognize both "december" and "December"
		as month name.
	*/
	Date(const string &mn, unsigned d, unsigned y);


	/* Outputs to the console (cout) a Date exactly in the format "3/1/2012".
	   Does not output a newline at the end.
	*/
	void printNumeric() const;


	/* Outputs to the console (cout) a Date exactly in the format "March 1, 2012".
	   The first letter of the month name is upper case, and the month name is
	   printed in full - January, not Jan, jan, or january.
	   Does not output a newline at the end.
	*/
	void printAlpha() const;

private:

	/* Returns true if the year passed in is a leap year, otherwise returns false.
	*/
	bool isLeap(unsigned y) const;


	/* Returns number of days allowed in a given month
	   -  e.g. daysPerMonth(9, 2000) returns 30.
	   Calculates February's days for leap and non-­leap years,
	   thus, the reason year is also a parameter.
	*/
	unsigned daysPerMonth(unsigned m, unsigned y) const;

	/* Returns the name of a given month
	   - e.g. name(12) returns the string "December"
	*/
	string name(unsigned m) const;

	/* Returns the number of a given named month
	   - e.g. number("March") returns 3
	*/
	unsigned number(const string &mn) const;
};

Date::Date(unsigned m, unsigned d, unsigned y) {
	unsigned maxDays;
	month = m;
	year = y;
	bool badDate = false;

	if (month > 12) {											//User input month out of range
		month = 12;
		monthName = name(month);
		day = 31;
		year = y;
		badDate = true;
	}
	else if (month < 1) {
		month = 1;
		monthName = name(month);
		day = 1;
		year = y;
		badDate = true;
	}
	
	maxDays = daysPerMonth(month, y);
	if (d > maxDays) {											//user input days out of range
		monthName = name(month);
		day = maxDays;
		year = y;
		badDate = true;
	}
	else if (d < 1) {
		monthName = name(month);
		day = 1;
		year = y;
		badDate = true;
	}
	else {														//all is well
		monthName = name(month);
		day = d;
		year = y;
	}
	if (badDate) {
		cout << "Invalid date values: Date corrected to ";
		printNumeric();
		cout << ".\n";
	}
}

Date::Date(const string &mn, unsigned d, unsigned y) {
	unsigned days;
	unsigned m = number(mn);
	bool badDate = false;

	if (m == static_cast<unsigned>(0)) {					//user month incorrect
		day = 1;
		month = 1;
		m = 1;
		monthName = name(month);
		year = 2000;
		badDate = true;
		cout << "Invalid month name: the Date was set to ";
	}


	days = daysPerMonth(m, y);
	if (d > days && !badDate ) {											//user input days out of range
		month = m;
		monthName = name(m);
		day = days;
		year = y;
		badDate = true;
		cout << "Invalid date values: Date corrected to ";
	}
	else if (d < 1 && !badDate) {
		month = m;
		monthName = name(m);
		day = 1;
		year = y;
		badDate = true;
		cout << "Invalid date values: Date corrected to ";
	}
	if (!badDate) {													//all is well
		month = m;
		monthName = name(month);
		day = d;
		year = y;
	}
	if (badDate) {
		printNumeric();
		cout << ".\n";
	}
}

void Date::printNumeric() const {
	cout << month << "/" << day << "/" << year;
}

void Date::printAlpha() const {
	cout << monthName << " " << day << ", " << year;
}

bool Date::isLeap(unsigned y) const {
	bool leap = false;
	if (y % 4 == 0) { leap = true; }

	if (y % 100 == 0) { leap = false; }

	if (y % 400 == 0) { leap = true; }

	return leap;
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const {
	unsigned days = 30;

	switch (m) {
	case 1: days++;
		break;
	case 2: isLeap(y) ? days-- : days -= 2;
		break;
	case 3: days++;
		break;
	case 4: break;
	case 5: days++;
		break;
	case 6: break;
	case 7: days++;
		break;
	case 8: days++;
		break;
	case 9: break;
	case 10: days++;
		break;
	case 11: break;
	case 12: days++;
		break;
	default:
		cout << "Something went wrong in daysPerMonth\n";
		break;
	}

	return days;
}

string Date::name(unsigned m) const {

	switch (m) {
	case 1: return "January";
		break;
	case 2: return "February";
		break;
	case 3: return "March";
		break;
	case 4: return "April";
		break;
	case 5: return "May";
		break;
	case 6: return "June";
		break;
	case 7: return "July";
		break;
	case 8: return "August";
		break;
	case 9: return "September";
		break;
	case 10: return "October";
		break;
	case 11: return "November";
		break;
	case 12: return "December";
		break;
	default:
		return "Not a month";
		break;
	}
}

unsigned Date::number(const string &mn) const {
		string capMonth[] = { "NAM", "January", "February", "March", "April", "May", 
			"June", "July", "August", "September", "October", "November", "December" };
		string lowMonth[] = { "NAM", "january", "february", "march", "april", "may",
			"june", "july", "august", "september", "october", "november", "december" };
		string target = mn;

		for (int i = 1; i < 13; i++) {
			if (target == capMonth[i] || target == lowMonth[i] ) { return static_cast<unsigned>(i); }
		}

		return static_cast<unsigned>(0);
}


Date getDate();

int main() {

	Date testDate;
	testDate = getDate();
	cout << endl;
	cout << "Numeric: ";
	testDate.printNumeric();
	cout << endl;
	cout << "Alpha:   ";
	testDate.printAlpha();
	cout << endl;

	return 0;
}

Date getDate() {
	int choice;
	unsigned monthNumber, day, year;
	string monthName;

	cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
		<< "1 - Month Number" << endl
		<< "2 - Month Name" << endl
		<< "3 - default" << endl;
	cin >> choice;
	cout << endl;

	if (choice == 1) {
		cout << "month number? ";
		cin >> monthNumber;
		cout << endl;
		cout << "day? ";
		cin >> day;
		cout << endl;
		cout << "year? ";
		cin >> year;
		cout << endl;
		return Date(monthNumber, day, year);
	}
	else if (choice == 2) {
		cout << "month name? ";
		cin >> monthName;
		cout << endl;
		cout << "day? ";
		cin >> day;
		cout << endl;
		cout << "year? ";
		cin >> year;
		cout << endl;
		return Date(monthName, day, year);
	}
	else {
		return Date();
	}
}