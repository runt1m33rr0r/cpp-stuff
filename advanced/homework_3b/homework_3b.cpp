#include "pch.h"

// Александър Янков F87134
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int GCD(int a, int b)
{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}

	return a;
}

class Fraction
{
private:
	int numerator;
	int denominator;

	void Simplify()
	{
		int divider = GCD(this->numerator, this->denominator);
		this->numerator /= divider;
		this->denominator /= divider;
	}
public:
	Fraction() : numerator{ 0 }, denominator{ 1 }
	{};

	Fraction(int numerator, int denominator) :
		numerator{ numerator }, denominator{ denominator }
	{};

	Fraction& operator+=(const Fraction& other)
	{
		this->numerator = this->numerator * other.denominator + other.numerator * this->denominator;
		this->denominator = this->denominator * other.denominator;

		this->Simplify();

		return *this;
	}

	Fraction& operator-=(const Fraction& other)
	{
		this->numerator = this->numerator * other.denominator - other.numerator * this->denominator;
		this->denominator = this->denominator * other.denominator;

		this->Simplify();

		return *this;
	}

	friend ostream& operator<<(std::ostream& stream, const Fraction& number)
	{
		if (number.denominator == 1)
		{
			return stream << number.numerator;
		}

		if (number.numerator < 0 || number.denominator < 0)
		{
			return stream << '-' << abs(number.numerator) << '/' << abs(number.denominator);
		}

		return stream << number.numerator << '/' << number.denominator;
	}
};

int main()
{
	string line;
	while (getline(cin, line))
	{
		istringstream is{ line };
		int a = 0;
		char slash = '/';
		int b = 0;
		char sign = '+';

		Fraction currentFraction{};

		while (is >> a >> slash >> b)
		{
			Fraction nextFraction{ a, b };
			
			if (sign == '+')
			{
				currentFraction += nextFraction;
			}
			else if (sign == '-')
			{
				currentFraction -= nextFraction;
			}

			if (!(is >> sign))
			{
				break;
			}
		}

		cout << currentFraction << endl;
	}

	return 0;
}