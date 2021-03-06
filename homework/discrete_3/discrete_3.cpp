// discrete_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	while (true)
	{
		if (a == 0)
			return b;
		b %= a;
		if (b == 0)
			return a;
		a %= b;
	}
}

int egcd(int a, int b, int &x, int &y) 
{
	if (b == 0) 
	{
		x = 1;
		y = 0;
		return a;
	}

	int x1, y1, gcd = egcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return gcd;
}

void first_task()
{
	int a = 0, b = 0, c = 0, x = 0, y = 0;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;

	if (b % gcd(a, c) != 0)
	{
		cout << "no soultion" << endl;
		return;
	}

	cout << egcd(a, b, x, y) % c << endl;
	cout << "x=" << x << endl << "y=" << y << endl;
}

int main()
{
	first_task();
	return 0;
}