//Implementation file for Distance class
//Author: John Palacios
#include "Distance.h"

/* Constructs a default Distance of 0 (0 feet and 0.0 inches)
	*/
Distance::Distance() {
	feet = 0;
	inches = 0;
	
}

/* Constructs a distance of ft feet and in inches,
	unless in >= 12, in which case the values of feet and inches
	are adjusted accordingly. A Distance will always be positive.
*/
Distance::Distance(unsigned ft, double in) {
	feet = ft;
	inches = in;
	init();
}

/* Constructs a distance of 0 ft and in inches,
	unless in >= 12, in which case the values of feet and inches
	are adjusted accordingly. A Distance will always be positive.
*/
Distance::Distance(double in) {
	feet = 0;
	inches = in;
	init();
}

/* Returns just the feet portion of the Distance
*/
unsigned Distance::getFeet() const {
	return feet;
}

/* Returns just the inches portion of the Distance
*/
double Distance::getInches() const {
	return inches;
}

/* Returns the entire distance as the equivalent amount of inches.
	(e.g., 4 feet 3.5 inches would be returned as 51.5 inches)
*/
double Distance::distanceInInches() const { 
	return (static_cast<double>(feet) * 12 + inches); 
}

/* Returns the entire distance as the equivalent amount of feet.
	(e.g., 3 feet 6 inches would be returned as 3.5 feet)
*/
double Distance::distanceInFeet() const {
	return (static_cast<double>(feet) + inches / 12.0);
}

/* Returns the entire distance as the equivalent amount of meters.
	1 inch equals 0.0254 meters.
	(e.g., 2 feet 8.12 inches would be returned as 0.815848 meters)
*/
double Distance::distanceInMeters() const {
	return distanceInInches()*0.0254;
}

/* Returns the sum of 2 Distances.
*/
const Distance Distance::operator+(const Distance &rhs) const {
	unsigned newFeet = feet + rhs.getFeet();
	double newInches = inches + rhs.getInches();
	Distance result(newFeet, newInches);
	return result;
}


/* Returns the difference between 2 Distances.
*/
const Distance Distance::operator-(const Distance &rhs) const {
	double loperand = this->distanceInInches();
	double roperand = rhs.distanceInInches();
	double difference = loperand - roperand;
	Distance result(difference);
	return result;
}


/* Outputs to the stream out the Distance in the format:
	feet' inches'' (i.e. 3' 3.41'')
*/
ostream & operator<<(ostream &out, const Distance &rhs) {
	out << rhs.getFeet() << "' " << rhs.getInches() << "\"";
	return out;
}

/* Used by the 2 parameterized constructors to convert any negative values to positive and
	inches >= 12 to the appropriate number of feet and inches.
*/
void Distance::init() {
	double inches = this->inches;
	unsigned feet = this->feet;
	unsigned count = 0;

	if (inches < 0) {				//Deal with negative inches
		inches = -1 * inches;
	}
	if (inches >= 12.0) {			//convert excess inches to feet
		while (inches >= 12.0) {
			inches -= 12.0;
			count++;
		}
		feet += count;
	}
	
	this->inches = inches;
	this->feet = feet;
}