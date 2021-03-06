#include "pch.h"

// Александър Янков F87134
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

bool CompareElements(const string& first, const string& second)
{
	if (first.length() < second.length())
	{
		return true;
	}

	if (first.length() > second.length())
	{
		return false;
	}

	return first <= second;
}

int main()
{
	unsigned elementsCount = 0;
	unsigned searchedElementsCount = 0;
	unsigned currentSearchedElement = 0;
	unsigned numberOfExamples = 0;

	string currentElement;

	cin >> numberOfExamples;

	for (unsigned i = 0; i < numberOfExamples; i++)
	{
		vector<size_t> searchedElements;
		vector<string> allElements;

		cin >> elementsCount >> searchedElementsCount;
		
		for (size_t j = 1; j <= searchedElementsCount; j++)
		{
			cin >> currentSearchedElement;
			searchedElements.push_back(currentSearchedElement);
		}
		
		for (size_t j = 1; j <= elementsCount; j++)
		{
			cin >> currentElement;
			allElements.push_back(currentElement);
		}

		sort(allElements.begin(), allElements.end(), CompareElements);

		for (size_t el : searchedElements)
		{
			cout << allElements[el - 1] << endl;
		}
	}

	return 0;
}