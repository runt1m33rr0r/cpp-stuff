#include "pch.h"

// Александър Янков F87134
#include <iostream>
#include <cmath>

using namespace std;

// 2001 is the maximum number we can calculate with ((1 + sin(0.1*i))*k) + 1
const unsigned maxPrimes = 2001;
bool primes[maxPrimes + 1];

void GeneratePrimes()
{
	fill(begin(primes), end(primes), true);
	primes[0] = false;
	primes[1] = false;

	unsigned current = 0;
	unsigned multiple = 0;
	for (current = 2; current * current <= maxPrimes; current++)
	{
		if (primes[current] == true)
		{
			for (multiple = current * 2; multiple <= maxPrimes; multiple += current)
			{
				primes[multiple] = false;
			}
		}
	}
}

unsigned CountPrimes(unsigned k, unsigned n)
{
	unsigned count = 0;
	unsigned number = 0;
	unsigned i = 0;
	
	for (i = 1; i <= n; i++)
	{
		number = static_cast<unsigned>(((1 + sin(0.1 * i)) * k) + 1);
		if (primes[number])
		{
			count++;
		}
	}

	return count;
}

int main()
{
	GeneratePrimes();

	unsigned k = 0;
	unsigned n = 0;

	while (cin >> k >> n)
	{
		cout << CountPrimes(k, n) << endl;
	}

	return 0;
}