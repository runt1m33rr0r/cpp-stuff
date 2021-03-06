// homework_5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

int main()
{
	int rows = 1, cols = 1;
	const int min = -12, max = 122;
	cout << "rows: ";
	cin >> rows;
	cout << "cols: ";
	cin >> cols;
	int ** arr = new int *[rows];
	for (int i = 0; i < rows; i++)
		arr[i] = new int[cols];

	// task 1
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			arr[row][col] = min + rand() % (max - min + 1);
			cout << arr[row][col] << " ";
		}
		cout << endl;
	}
	cout << endl;

	// task 2
	int len = rows > cols ? cols : rows;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (i + j < len - 1)
				arr[i][j] = 0;
		}
	}

	// task 3
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (i >= j)
				arr[i][j] = pow(i + j, i);
		}
	}

	// task 4
	// first print the array in normal way
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			cout << arr[row][col] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	// then print it in spiral
	int i, k = 0, l = 0, n = cols, m = rows;
	while (k < m && l < n)
	{
		for (i = l; i < n; ++i)
		{
			cout << arr[k][i] << " ";
		}
		k++;

		for (i = k; i < m; ++i)
		{
			cout << arr[i][n - 1] << " ";
		}
		n--;

		if (k < m)
		{
			for (i = n - 1; i >= l; --i)
			{
				cout << arr[m - 1][i] << " ";
			}
			m--;
		}

		if (l < n)
		{
			for (i = m - 1; i >= k; --i)
			{
				cout << arr[i][l] << " ";
			}
			l++;
		}
	}
	cout << endl;

	// clean memory
	for (int i = 0; i < rows; i++)
		delete[] arr[i];
	delete[] arr;

    return 0;
}