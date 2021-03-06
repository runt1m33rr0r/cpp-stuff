#include "pch.h"
#include <iostream>

using namespace std;

const int len = 5;
int numbers[len] = { 5, 4, 3, 2, 1 };

void Partition(int left, int right, int& newLeft, int& newRight)
{
	do
	{
		int picked = numbers[(right + left) / 2];

		newLeft = left;
		while (numbers[newLeft] < picked)
		{
			newLeft++;
		}

		newRight = right;
		while (numbers[newRight] > picked)
		{
			newRight--;
		}

		if (newLeft <= newRight)
		{
			int tmp = numbers[newLeft];
			numbers[newLeft] = numbers[newRight];
			numbers[newRight] = tmp;

			newLeft++;
			newRight--;
		}
	} while (newLeft <= newRight);
}

void QuickSort(int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int newLeft = 0;
	int newRight = 0;
	Partition(left, right, newLeft, newRight);

	// left part
	cout << "left subtree sinking: " << endl 
		<< "    left: " << left << endl
		<< "    right: " << right << endl;
	QuickSort(left, newRight);
	cout << "left subtree emerging: " << endl
		<< "    left: " << left << endl
		<< "    right: " << right << endl;

	// right part
	cout << "right subtree sinking: " << endl
		<< "    left: " << left << endl
		<< "    right: " << right << endl;
	QuickSort(newLeft, right);
	cout << "right subtree emerging: " << endl
		<< "    left: " << left << endl
		<< "    right: " << right << endl;
}

void PrintData()
{
	for (auto el : numbers)
	{
		cout << el << " ";
	}
	cout << endl;
}

int main()
{
	cout << "starting data: ";
	PrintData();
	cout << endl;

	QuickSort(0, len - 1);

	cout << endl;
	cout << "processed data: ";
	PrintData();
	
	return 0;
}