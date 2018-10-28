#include "pch.h"
#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull Factorial(ull number)
{
	/*if (number != 0)
	{
		cout << number << (number == 1 ? "" : "*");
	}*/

	ull result = number == 0 ? 1 : Factorial(number - 1) * number;

	if (number != 0)
	{
		cout << (number == 1 ? "" : "*") << number;
	}

	return result;
}

int BinarySearch(int arr[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;

		// If the element is present at the middle  
		// itself 
		if (arr[mid] == x)
		{
			return mid;
		}

		// If element is smaller than mid, then  
		// it can only be present in left subarray 
		if (arr[mid] > x)
		{
			return BinarySearch(arr, l, mid - 1, x);
		}

		// Else the element can only be present 
		// in right subarray 
		return BinarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not  
	// present in array 
	return -1;
}

int main()
{
	ull number = 9;

	cout << number << " faktoriel e: ";
	ull result = Factorial(number);
	cout << " i tova pravi " << result << endl;

	return 0;
}