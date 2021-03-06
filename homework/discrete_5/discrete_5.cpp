#include "stdafx.h"

#include <iostream>

using namespace std;


void first_task();
void second_task();
void third_task();
void fourth_task();
void fifth_task();


bool is_set(int *, const unsigned);

void create_mask(int *, const unsigned, int *, const unsigned, bool *);
void print_subset(int *, unsigned const, bool *);

void print_int_arr(int *, const unsigned);
void print_bool_arr(bool *, const unsigned);
bool has_element(int *, const unsigned, int);

unsigned get_mask_power(bool *, const unsigned);
void subtract(bool *, bool *, bool *, const unsigned);
bool second_has_first(int *, const unsigned, int *, const unsigned);
bool is_subset(bool *, bool *, const unsigned);
void unite(int *, const unsigned, int *, const unsigned, int *, const unsigned);
void intersect(int *, const unsigned, int *, const unsigned, int *, const unsigned);
void differ(int *, const unsigned, int *, const unsigned, int *, const unsigned);
void complement(int *, const unsigned, int *, const unsigned, int *, const unsigned);


int main()
{
	first_task();
	cout << endl;

	second_task();
	cout << endl;

	third_task();
	cout << endl;

	fourth_task();
	cout << endl;

	fifth_task();
	cout << endl;

	return 0;
}

void fifth_task()
{
	const unsigned first_len = 5;
	int first[first_len] = { 1, 2, 3, 4, 5 };
	const unsigned second_len = 3;
	int second[second_len] = { 1, 2, 6 };

	// union
	const unsigned union_len = first_len + second_len;
	int union_set[union_len] = { 0 };
	unite(first, first_len, second, second_len, union_set, union_len);
	cout << "union(ignore trailing zeroes): ";
	print_int_arr(union_set, union_len);

	// intersection
	int intersection[first_len] = { 0 };
	intersect(first, first_len, second, second_len, intersection, first_len);
	cout << "intersection(ignore trailing zeroes): ";
	print_int_arr(intersection, first_len);

	// difference
	const unsigned difference_len = first_len + second_len;
	int difference[difference_len] = { 0 };
	differ(first, first_len, second, second_len, difference, difference_len);
	cout << "difference(ignore trailing zeroes): ";
	print_int_arr(difference, difference_len);

	// complemention
	const unsigned universal_len = 6;
	int universal[universal_len] = { 1, 2, 3, 4, 5, 6 };
	const unsigned sec_len = 3;
	int sec[sec_len] = { 1, 2, 3 };
	int comp[universal_len] = { 0 };
	complement(universal, universal_len, sec, sec_len, comp, universal_len);
	cout << "complement(ignore trailing zeroes): ";
	print_int_arr(comp, universal_len);
}

void fourth_task()
{
	const unsigned universal_len = 10;
	int universal[universal_len] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	const unsigned first_len = 5;
	int first[first_len] = { 1, 2, 3, 4, 5 };
	const unsigned second_len = 3;
	int second[second_len] = { 1, 2, 6 };

	bool first_mask[universal_len] = { false };
	bool second_mask[universal_len] = { false };

	create_mask(universal, universal_len, first, first_len, first_mask);
	create_mask(universal, universal_len, second, second_len, second_mask);

	bool result = is_subset(first_mask, second_mask, universal_len);
	cout << "second set is subset of the first set: " << (result ? "true" : "false") << endl;
}

void third_task()
{
	const unsigned first_len = 5;
	int first[first_len] = { 1, 2, 3, 4, 5 };
	const unsigned second_len = 6;
	int second[second_len] = { 2, 4, 1, 5, 3, 7 };

	cout << "the second set has all the elements of the first set: "
		<< (second_has_first(first, first_len, second, second_len) ? "true" : "false") << endl;
}

void second_task()
{
	const unsigned first_len = 5;
	int first[first_len] = { 1, 2, 3, 4, 5 };
	const unsigned second_len = 2;
	int second[second_len] = { 2, 4 };

	bool first_mask[first_len];
	for (int i = 0; i < first_len; i++)
		first_mask[i] = true;

	bool second_mask[first_len] = { false };
	create_mask(first, first_len, second, second_len, second_mask);

	bool result_mask[first_len] = { false };
	subtract(first_mask, second_mask, result_mask, first_len);

	cout << "first - second: ";
	print_subset(first, first_len, result_mask);
}

void first_task()
{
	const unsigned universal_len = 10;
	int universal[universal_len] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	const unsigned set_len = 3;
	int set[set_len] = { 1, 3, 5 };

	if (!is_set(set, set_len) || !is_set(universal, universal_len))
	{
		cout << "invalid set" << endl;
		return;
	}

	bool * mask = new bool[universal_len];
	create_mask(universal, universal_len, set, set_len, mask);

	print_int_arr(universal, universal_len);
	print_bool_arr(mask, universal_len);

	unsigned power = get_mask_power(mask, universal_len);
	cout << "set power: " << power << endl;

	delete[] mask;
	mask = nullptr;
}

void unite(
	int * first_set,
	const unsigned first_len,
	int * second_set,
	const unsigned second_len,
	int * result_set,
	const unsigned result_len)
{
	if (result_len < first_len + second_len)
	{
		cout << "invalid result set length" << endl;
		return;
	}

	for (unsigned i = 0; i < first_len; i++)
	{
		result_set[i] = first_set[i];
	}

	unsigned flag = first_len;
	for (unsigned i = 0; i < second_len; i++)
	{
		if (has_element(first_set, first_len, second_set[i]) == false)
		{
			result_set[flag] = second_set[i];
			flag++;
		}
	}
}

void intersect(
	int * first_set,
	const unsigned first_len,
	int * second_set,
	const unsigned second_len,
	int * result_set,
	const unsigned result_len)
{
	if (result_len < first_len && result_len < second_len)
	{
		cout << "invalid result array length" << endl;
		return;
	}

	for (unsigned i = 0; i < first_len; i++)
	{
		bool b_has_a = has_element(second_set, second_len, first_set[i]);
		if (b_has_a)
			result_set[i] = first_set[i];
	}
}

void differ(
	int * first_set,
	const unsigned first_len,
	int * second_set,
	const unsigned second_len,
	int * result_set,
	const unsigned result_len)
{
	if (result_len < first_len + second_len)
	{
		cout << "invalid result array length" << endl;
		return;
	}

	int flag = 0;
	for (unsigned i = 0; i < first_len; i++)
	{
		bool b_has_a = has_element(second_set, second_len, first_set[i]);
		if (b_has_a == false)
		{
			result_set[flag] = first_set[i];
			flag++;
		}
	}

	for (unsigned i = 0; i < second_len; i++)
	{
		bool a_has_b = has_element(first_set, first_len, second_set[i]);
		if (a_has_b == false)
		{
			result_set[flag] = second_set[i];
		}
	}
}

void complement(
	int * universal_set,
	const unsigned universal_len,
	int * second_set,
	const unsigned second_len,
	int * result_set,
	const unsigned result_len)
{
	if (result_len < universal_len)
	{
		cout << "invalid result array length" << endl;
		return;
	}

	int flag = 0;
	for (unsigned i = 0; i < universal_len; i++)
	{
		bool a_has_uni = has_element(second_set, second_len, universal_set[i]);
		if (a_has_uni == false)
		{
			result_set[flag] = universal_set[i];
			flag++;
		}
	}
}

bool is_subset(bool * first_mask, bool * second_mask, const unsigned len)
{
	for (unsigned i = 0; i < len; i++)
	{
		if (first_mask[i] == false && second_mask[i] == true)
			return false;
	}
	return true;
}

bool has_element(int * arr, const unsigned len, int el)
{
	for (unsigned i = 0; i < len; i++)
		if (arr[i] == el)
			return true;
	return false;
}

bool second_has_first(int * first, const unsigned first_len, int * second, const unsigned second_len)
{
	if (second_len < first_len)
		return false;

	for (unsigned i = 0; i < first_len; i++)
	{
		if (has_element(second, second_len, first[i]) == false)
			return false;
	}
	return true;
}

void subtract(bool * first_mask, bool * second_mask, bool * result_mask, const unsigned len)
{
	for (unsigned i = 0; i < len; i++)
	{
		result_mask[i] = first_mask[i] ^ second_mask[i];
	}
}

void create_mask(int * set, const unsigned set_len, int * subset, const unsigned subset_len, bool * mask)
{
	for (unsigned i = 0; i < set_len; i++)
		mask[i] = false;

	for (unsigned i = 0; i < subset_len; i++)
	{
		const int subset_el = subset[i];
		for (unsigned j = 0; j < set_len; j++)
		{
			const int set_el = set[j];

			if (set_el == subset_el)
			{
				mask[j] = true;
			}
		}
	}
}

void print_int_arr(int * arr, const unsigned len)
{
	for (unsigned i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void print_bool_arr(bool * arr, const unsigned len)
{
	for (unsigned i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;
}

bool is_set(int * set, unsigned const set_len)
{
	for (unsigned i = 0; i < set_len; i++)
	{
		for (unsigned j = 0; j < i; j++)
		{
			if (set[i] == set[j])
				return false;
		}
	}

	return true;
}

unsigned get_mask_power(bool * mask, unsigned const len)
{
	unsigned count = 0;
	for (unsigned i = 0; i < len; i++)
		if (mask[i] == true)
			count++;
	return count;
}

void print_subset(int * set, unsigned const set_len, bool * mask)
{
	for (unsigned i = 0; i < set_len; ++i)
	{
		if (mask[i] == true)
			cout << set[i] << " ";
	}
	cout << endl;
}