#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string Convert(unsigned number, unsigned base)
{
	char symbols[] { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	unsigned remainder = 0;
	string output = "";

	do
	{
		remainder = number % base;
		output = symbols[remainder] + output;
		number /= base;
	} while (number > 0);

	return output;
}

int main()
{
	vector<unsigned> inputNumbers;

	unsigned input = 0;
	while (cin >> input)
	{
		inputNumbers.emplace_back(input);
	}

	for (auto el : inputNumbers)
	{
		cout << Convert(el, 2) << " "
			<< Convert(el, 8) << " "
			<< Convert(el, 16) << endl;
	}

	return 0;
}