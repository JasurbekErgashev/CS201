#include <iostream>
#include <vector>

using namespace std;

class Rational {
public:
	Rational() {
		numerator = 0;
		denominator = 1;
	}
	Rational(const int& numerator, const int& denominator) {
		this->numerator = numerator;
		this->denominator = denominator;
	}

	vector<int> add(const int& num, const int& den) {
		int a = numerator * den + num * denominator;
		int b = denominator * den;
		int gcdNum = gcd(a, b);
		return {a / gcdNum, b / gcdNum};
	}

	vector<int> subtract(const int& num, const int& den) {
		int a = numerator * den - num * denominator;
		int b = denominator * den;
		int gcdNum = gcd(a, b);
		return {a / gcdNum, b / gcdNum};
	}

	vector<int> multiplication(const int& num, const int& den) {
		int a = numerator * num;
		int b = denominator * den;
		int gcdNum = gcd(a, b);
		return {a / gcdNum, b / gcdNum};
	}

	vector<int> division(const int& num, const int& den) {
		int a = numerator * den;
		int b = denominator * num;
		int gcdNum = gcd(a, b);
		return {a / gcdNum, b / gcdNum};
	}

	void printRationalNumber(const vector<int>& ratNum) {
		cout << ratNum[0] << "/" << ratNum[1];
	}

	void printAsFloatingFormat(const vector<int>& ratNum) {
		cout << static_cast<double>(ratNum[0]) / ratNum[1];
	}

	int gcd(const int& a, const int& b) {
		int gcdAns{0};
		int upperBound{ 0 };
		if (a >= b)
			upperBound = a;
		else
			upperBound = b;
		for (int i{ 1 }; i <= upperBound; i++) {
			if (a % i == 0 && b % i == 0)
				gcdAns = i;
		}
		return gcdAns;
	}

private:
	int numerator;
	int denominator;
};

int main() {
	Rational ratObj(2, 3);
	cout << "Rational numbers are: 2/3 and 14/7: \n";

	cout << "Addition: ";
	ratObj.printRationalNumber(ratObj.add(14, 7));
	cout << endl;
	ratObj.printAsFloatingFormat(ratObj.add(14, 7));

	cout << "\n\nSubtraction: ";
	ratObj.printRationalNumber(ratObj.subtract(14, 7));
	cout << endl;
	ratObj.printAsFloatingFormat(ratObj.subtract(14, 7));

	cout << "\n\nMultiplication: ";
	ratObj.printRationalNumber(ratObj.multiplication(14, 7));
	cout << endl;
	ratObj.printAsFloatingFormat(ratObj.multiplication(14, 7));

	cout << "\n\nDivision: ";
	ratObj.printRationalNumber(ratObj.division(14, 7));
	cout << endl;
	ratObj.printAsFloatingFormat(ratObj.division(14, 7));
	return 0;
}
