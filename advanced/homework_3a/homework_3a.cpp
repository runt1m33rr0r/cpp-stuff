#include "pch.h"

// Александър Янков F87134
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

const int elementsLen = 2;
int elements[elementsLen] = { '+', '-' };

vector<char> currentVariation;
vector<unsigned> expression;
vector<vector<char>> variations;

void PrintExpression(size_t variationIdx)
{
	for (size_t i = 0; i < expression.size() - 2; i++)
	{
		cout << expression[i] << variations[variationIdx][i];
	}
	cout << expression[expression.size() - 2] << '=' << expression[expression.size() - 1] << endl;
}

bool IsExpressionValid(size_t variationIdx)
{
	int numberToCompare = expression[expression.size() - 1];
	int currentNumber = expression[0];

	for (size_t i = 0; i < expression.size() - 2; i++)
	{
		if (variations[variationIdx][i] == '+')
		{
			currentNumber += expression[i + 1];
		}
		else
		{
			currentNumber -= expression[i + 1];
		}
	}

	if (currentNumber == numberToCompare)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CheckVariations()
{
	for (size_t varIdx = 0; varIdx < variations.size(); varIdx++)
	{
		if (IsExpressionValid(varIdx))
		{
			PrintExpression(varIdx);
			return;
		}
	}

	cout << endl;
}

void CalculateVariations(size_t index)
{
	if (index >= currentVariation.size())
	{
		variations.emplace_back(currentVariation);
	}
	else
	{
		for (size_t i = 0; i < elementsLen; i++)
		{
			currentVariation[index] = elements[i];
			CalculateVariations(index + 1);
		}
	}
}

void SetUpData()
{
	currentVariation.resize(expression.size() - 2);
}

void ResetData()
{
	expression.clear();
	variations.clear();
}

int main()
{
	string line;
	while (getline(cin, line))
	{
		istringstream is{ line };
		int number = 0;
		while (is >> number)
		{
			expression.emplace_back(number);
		}

		SetUpData();
		CalculateVariations(0);
		CheckVariations();
		ResetData();
	}

	return 0;
}