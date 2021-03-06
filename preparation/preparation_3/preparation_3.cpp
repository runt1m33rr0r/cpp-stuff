// preparation_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>

using namespace std;

int rec_sum(int start, int end, int sum)
{
	if (start > end)
		return sum;
	else
	{
		sum += start;
		rec_sum(start + 1, end, sum);
	}
}

int rec_mul(int n, int m, int current, int mul)
{
	if (current == m)
		return mul;
	else
	{
		mul += n;
		rec_mul(n, m, current + 1, mul);
	}
}

void histogram(char * str, unsigned * histo)
{
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			histo[(int)(*str - '0')]++;
		}
		str++;
	}
}

void gentext(char * str, char * alpha, bool space = true)
{
	unsigned i = 0, len = rand() % 991 + 10;
	while (i < len)
	{
		if (space)
			str[i++] = alpha[rand() % 53];
		else
			str[i++] = alpha[rand() % 52];
	}
	str[i] = '\0';
}



typedef bool(*pf)(int);

bool div_by_3(int val)
{
	return (val % 3 == 0);
}

bool prime(int val) {
	for (unsigned i = 2; i <= sqrt(val); i++)
		if (val % i == 0) return false;
	return true;
}

bool even(int val)
{
	return (val % 2 == 0);
}

int sum_array(int ** arr, unsigned sz, pf fun)
{
	int sum = 0;
	for (unsigned i = 0; i < sz; i++)
		for (unsigned j = 0; j < sz; j++)
			if ((*fun)(arr[i][j]))
				sum += arr[i][j];
	return sum;
}



typedef bool(*pred)(int, int, int);
typedef int(*pf2)(int, int);

bool inMainDiagonal(int i, int j, int = 0)
{
	return (i == j);
}

bool inInterval(int i, int j, int val)
{
	return (val >= i && val <= j);
}

int factorial(int i, int j)
{
	int mul = 1;
	for (unsigned n = 2; n <= i * j; n++)
		mul *= i;
	return mul;
}

int multiplication(int i, int j)
{
	return i * j;
}

int power(int i, int j)
{
	return pow(i, j);
}

int changeArray(int ** arr, unsigned sz, pf2 fun, pred predicate)
{
	int sum = 0;
	for (unsigned i = 0; i < sz; i++)
		for (unsigned j = 0; j < sz; j++)
			if ((*predicate)(i, j, arr[i][j]))
				arr[i][j] = (*fun)(i, j);
	return sum;
}

int printArray(int ** arr, unsigned sz)
{
	for (unsigned i = 0; i < sz; i++)
	{
		for (unsigned j = 0; j < sz; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
	return 0;
}

int main()
{
	/*cout << rec_sum(1, 10, 0) << endl;
	cout << rec_mul(2, 3, 0, 0) << endl;*/

	/*char str[1000];
	unsigned histo[10] = { 0 };
	cout << "Please enter a text: ";
	cin.getline(str, 999);
	cout << str << endl;
	histogram(str, histo);
	for (unsigned i = 0; i < 10; i++)
	{
	cout << i << "=" << histo[i] << endl;
	}*/

	/*srand(time(NULL));
	char text[1000];
	char alphabet[54] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ";
	gentext(text, alphabet);
	cout << text << endl;*/

	/*unsigned sz = 3;
	int ** arr = new int *[sz];
	for (unsigned i = 0; i < sz; i++)
	arr[i] = new int[sz];
	int val = 0;
	for (unsigned i = 0; i < sz; i++)
	for (unsigned j = 0; j < sz; j++)
	arr[i][j] = ++val;
	for (unsigned i = 0; i < sz; i++)
	{
	for (unsigned j = 0; j < sz; j++)
	cout << arr[i][j] << "\t";
	cout << endl;
	}
	cout << "Sum of all even numbers is: " << sum_array(arr, 3, even) << endl;
	cout << "Sum of all numbers that can be diveded by 3 is: " << sum_array(arr, 3, div_by_3) << endl;
	cout << "Sum of all prime numbers is: " << sum_array(arr, 3, prime) << endl;
	for (unsigned i = 0; i < sz; i++)
	delete[] arr[i];
	delete[] arr;
	arr = NULL;*/

	unsigned sz = 3;
	int ** arr = new int *[sz];
	for (unsigned i = 0; i < sz; i++)
		arr[i] = new int[sz];
	int val = 0;
	for (unsigned i = 0; i < sz; i++)
		for (unsigned j = 0; j < sz; j++)
			arr[i][j] = ++val;
	printArray(arr, sz);
	changeArray(arr, sz, power, inMainDiagonal);
	cout << endl << endl;
	printArray(arr, sz);
	changeArray(arr, sz, factorial, inInterval);
	cout << endl << endl;
	printArray(arr, sz);
	for (unsigned i = 0; i<sz; i++)
		delete[] arr[i];
	delete[] arr;
	arr = NULL;

	char str[101] = "deez", destination[1001] = "deez nutz deezdeez";
	unsigned short num = 0;
	char* pos = destination;
	while (pos = strstr(pos, str)) {
		num++;
		pos++;
	}
	cout << "Matchings of " << str << " in " << destination << ": " << num << " times." << endl;
	
	float min = 1;
	float max = 2;
	srand(time(NULL));
	for (int i = 0; i < 100; i++)
		cout << min + (float)(rand()) / (float)(RAND_MAX / (max - min)) << " ";
	cout << endl;

	return 0;
}