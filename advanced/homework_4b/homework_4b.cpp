#include "pch.h"

// Александър Янков F87134
#include <iostream>
#include <set>

using namespace std;

#define NUMBERS_COUNT 10000
#define MAX_RAND 100000
#define MAX_ELEMENTS 10

struct CustomComparator
{
	bool operator() (const unsigned& first, const unsigned& second) const
	{
		return first > second;
	}
};

int main()
{
	unsigned input = 0;
	while (cin >> input)
	{
		srand(input);

		set<unsigned, CustomComparator> numbers;
		for (unsigned i = 0; i < NUMBERS_COUNT; i++)
		{
			numbers.emplace(rand() % MAX_RAND);

			if (numbers.size() > MAX_ELEMENTS)
			{
				numbers.erase(--numbers.end());
			}
		}

		unsigned numberIdx = 1;
		for (unsigned number : numbers)
		{
			cout << number << (numberIdx == MAX_ELEMENTS ? '\0' : ' ');
			numberIdx++;
		}
		cout << endl;
	}

	return 0;
}