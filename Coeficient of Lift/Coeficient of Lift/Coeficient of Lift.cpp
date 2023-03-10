// Coeficient of Lift.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// accomplishes basic file handling, extracts data to populate parallel vectors
void readData(const string &, vector<double> &, vector<double> &);

// interpolates a coeficient of lift given a desired flight angle
double interpolation(double, const vector<double> &, const vector<double> &);

//pairwise comparison of elements, returns (list.at(i) < list.at(i+1) for all 0<=i<=list.size - 1
bool isOrdered(const vector<double> &);

// utilizes parallel selection sort algorithm
void reorder(vector<double> &, vector<double> &);

int main()
{
	vector<double> flghtAngl;
	vector<double> coefLift;
	string filename;
	string repeat = "yes";
	bool badInput = true;
	double lwrBound;
	double uprBound;
	double angle;

    cout << "Enter name of input data file:\n"; 
	cin >> filename;
	cout << endl;


	// open file, read in data
	readData(filename, flghtAngl, coefLift);

	// check order of values
	if (!isOrdered(flghtAngl)) { reorder(flghtAngl, coefLift); }

	// angle data bounds
	lwrBound = flghtAngl.at(0);
	uprBound = flghtAngl.at(flghtAngl.size() - 1);

	// begin user inquiry loop
	while (repeat == "yes") {

		while (badInput) {
			badInput = false;
			cout << "Please enter flight-path angle:\n";
			cin >> angle;
			if ((angle < lwrBound) || (angle > uprBound)) { badInput = true; }
		}
		cout << interpolation(angle, flghtAngl, coefLift) << endl;
		cout << "enter \"yes\" if you would like to enter another angle:\n";
		cin >> repeat;
	}

	
	//double angles[17] = { -2, -4, 0, 1};
	//double coefic[17] = { -0.18, -0.05, 0.09, 0.23};
	//flghtAngl.assign(angles, angles + 4);
	//coefLift.assign(coefic, coefic + 4);
	//
	////testing reorder fxn
	//reorder(flghtAngl, coefLift);

	////testing interpolate fxn
	//cout << interpolation(-1.0, flghtAngl, coefLift) << endl;

	return 0;
}

void readData(const string &filename, vector<double> &flghtAngl, vector<double> &coefLift) {
	ifstream inFS;                  // Input file stream
	double angle;					// Input file flight path angle
	double coefL;					// Input file coeficient of lift corresponding to flight path angle

	//opening file stream
	inFS.open(filename);
	if (!inFS.is_open()) {
		cout << "Error opening " << filename << endl;
		exit(1);
	}

	//reading data into vectors
	while (!inFS.fail()) {
		inFS >> angle;
		inFS >> coefL;
		flghtAngl.push_back(angle);
		coefLift.push_back(coefL);
	}

	//Closing file
	inFS.close();
}


double interpolation(double angle, const vector<double> &flghtAngl, const vector<double> &coefLift) {
	//f(b) = f(a) + ((b - a)/(c - a))(f(c) - f(a)) angle = b, f(b) is coeficient of lift "at" b in flghtAngle
	int inf;							// index of a above
	int sup;							// index of c above
	int length = static_cast<int>(flghtAngl.size());

	// search flightAngl for angle
	for (int i = 0; i < length; i++) {
		if (flghtAngl.at(i) == angle) { return coefLift.at(i); }
	}

	// find angle below and then above given angle
	for (int i = 0; i < length; i++) {
		if ((flghtAngl.at(i) < angle) && (angle < coefLift.at(i+1))) { inf = i; }
	}
	sup = inf + 1;

	// return f(b) as formulated above
	return (coefLift.at(inf) + (angle - flghtAngl.at(inf)) / (flghtAngl.at(sup) - flghtAngl.at(inf)) * (coefLift.at(sup) - coefLift.at(inf)));
}

bool isOrdered(const vector<double> &list) {
	int length = static_cast<int>(list.size());

	for (int i = 0; i < length - 1; i++) {
		if (list.at(i) > list.at(i + 1)) { return false; }
	}

	return true;
}

void reorder(vector<double> &flghtAngl, vector<double> &coefLift) {
	double smlstAngl;
	double smlstCoef;
	int length = static_cast<int>(flghtAngl.size());
	int minIndex;

	for (int i = 0; i < length; i++) {
		minIndex = i;
		smlstAngl = flghtAngl.at(i);
		smlstCoef = coefLift.at(i);
		for (int j = i + 1; j < length; j++) {
			if (flghtAngl.at(j) < smlstAngl) {
				smlstAngl = flghtAngl.at(j);
				smlstCoef = coefLift.at(j);
				minIndex = j;
			}
		}
		flghtAngl.at(minIndex) = flghtAngl.at(i);
		coefLift.at(minIndex) = coefLift.at(i);
		flghtAngl.at(i) = smlstAngl;
		coefLift.at(i) = smlstCoef;
	}
}