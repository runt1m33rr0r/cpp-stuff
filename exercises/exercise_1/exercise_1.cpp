// exercise_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	/*int a = 0, b = 0, q = 0, r = 0;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	if (b == 0)
	{
		cerr << "Can't divide by zero." << endl;
		return 1;
	}

	q = a / b;
	r = a % b;

	cout << "a = " << b << " * " << q << " + " << r << endl;*/


	/*int number = 0, initial_number = 0, remainder = 0;
	string result = "";
	cin >> number;
	initial_number = number;

	if (number == 0)
	{
		result = "0";
	}

	while (number > 0)
	{
		remainder = number % 3;
		number /= 3;
		if (remainder == 0)
			result = "0" + result;
		else if (remainder == 1)
			result = "1" + result;
		else if (remainder == 2)
			result = "2" + result;
	}

	cout << initial_number << "(10)=" << result << "(3)" << endl;*/


	int a = 0, b = 0, min = 0, max = 0;
	cin >> a >> b;

	if (a == 0 && b == 0)
	{
		cout << "Invalid input!" << endl;
		return 1;
	}
	else if (a == 0 || b == 0)
	{
		cout << abs(a - b) << endl;
		return 0;
	}

	if (a > b)
	{
		max = a;
		min = b;
	}
	else
	{
		max = b;
		min = a;
	}

	int temp = max - min;
	while (temp > 0)
	{
		max = (temp > min) ? temp : min;
		min = (temp < min) ? temp : min;
		temp = max - min;
	}

	cout << min << endl;

    return 0;
}