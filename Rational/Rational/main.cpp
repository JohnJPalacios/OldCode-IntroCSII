//
//

#include <iostream>
#include <string>
using namespace std;

class Rational {
private:
	int numerator;
	int denominator;
public:
	Rational() : numerator(0), denominator(1) {}
	explicit Rational(int num) : numerator(num), denominator(1) {}
	Rational(int num, int den) : numerator(num), denominator(den) {}
	const Rational add(const Rational &) const;
	const Rational subtract(const Rational &) const;
	const Rational multiply(const Rational &) const;
	const Rational divide(const Rational &) const;
	const int getNum() const { return numerator; }
	const int getDen() const { return denominator; }
	void simplify();
	void display() const;
private:
	int gcd(int, int) const;
};

const Rational Rational::add(const Rational &frac) const {
	int a = this->numerator;
	int b = this->denominator;
	int c = frac.getNum();
	int d = frac.getDen();
	Rational sum((a * d + b * c), (b*d));

	return sum;
}

const Rational Rational::subtract(const Rational &frac) const {
	int a = this->numerator;
	int b = this->denominator;
	int c = frac.getNum();
	int d = frac.getDen();
	Rational dif((a * d - b * c), (b*d));

	return dif;
}

const Rational Rational::multiply(const Rational &frac) const {
	int a = this->numerator;
	int b = this->denominator;
	int c = frac.getNum();
	int d = frac.getDen();
	Rational prd((a * c), (b * d));

	return prd;
}

const Rational Rational::divide(const Rational &frac) const {
	int a = this->numerator;
	int b = this->denominator;
	int c = frac.getNum();
	int d = frac.getDen();
	Rational qot((a * d), (b * c));

	return qot;
}

void Rational::simplify() {
	int gcd = 1;
	if (numerator >= denominator) { gcd = this->gcd(denominator, numerator); }
	gcd = this->gcd(numerator, denominator);
	numerator = numerator / gcd;
	denominator = denominator / gcd;
}

int Rational::gcd(int a, int b) const {
	int x = a;
	int y = b;
	int remainder = 0;

	while (y != 0) {
		remainder = x % y;
		x = y;
		y = remainder;
	}
	
	return x;
}

void Rational::display() const {
	cout << numerator << " / " << denominator;
}

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
	Rational A, B, result;
	int choice;

	cout << "Enter Rational A:" << endl;
	A = getRational();
	cout << endl;

	cout << "Enter Rational B:" << endl;
	B = getRational();
	cout << endl;

	cout << "Enter Operation (1 - 4):" << endl
		<< "1 - Addition (A + B)" << endl
		<< "2 - Subtraction (A - B)" << endl
		<< "3 - Multiplication (A * B)" << endl
		<< "4 - Division (A / B)" << endl
		<< "5 - Simplify A" << endl;
	cin >> choice;
	cout << endl;

	if (choice == 1) {
		result = A.add(B);
		displayResult("+", A, B, result);
	}
	else if (choice == 2) {
		result = A.subtract(B);
		displayResult("-", A, B, result);
	}
	else if (choice == 3) {
		result = A.multiply(B);
		displayResult("*", A, B, result);
	}
	else if (choice == 4) {
		result = A.divide(B);
		displayResult("/", A, B, result);
	}
	else if (choice == 5) {
		A.simplify();
		A.display();
	}
	else {
		cout << "Unknown Operation";
	}
	cout << endl;

	return 0;
}

Rational getRational() {
	int choice;
	int numer, denom;

	cout << "Which Rational constructor? (Enter 1, 2, or 3)" << endl
		<< "1 - 2 parameters (numerator & denominator)" << endl
		<< "2 - 1 parameter (numerator)" << endl
		<< "3 - 0 parameters (default)" << endl;
	cin >> choice;
	cout << endl;

	if (choice == 1) {
		cout << "numerator? ";
		cin >> numer;
		cout << endl;
		cout << "denominator? ";
		cin >> denom;
		cout << endl;
		return Rational(numer, denom);
	}
	else if (choice == 2) {
		cout << "numerator? ";
		cin >> numer;
		cout << endl;
		return Rational(numer);
	}
	else {
		return Rational();
	}
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
	cout << "(";
	lhs.display();
	cout << ") " << op << " (";
	rhs.display();
	cout << ") = (";
	result.display();
	cout << ")";
}