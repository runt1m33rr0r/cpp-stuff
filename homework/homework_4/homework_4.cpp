#include "stdafx.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <ctime>

using namespace std;

void first_task()
{
	int digits_count = 0, input = 0;

	cout << "number: ";
	cin >> input;

	input = abs(input);

	while (input > 0)
	{
		digits_count++;
		input /= 10;
	}

	cout << "digits_count: " << digits_count << endl;
}

void second_task()
{
	int digits_sum = 0, input = 0;

	cout << "number: ";
	cin >> input;

	input = abs(input);

	while (input > 0)
	{
		digits_sum += input % 10;
		input /= 10;
	}

	cout << "digits_sum: " << digits_sum << endl;
}

void third_task()
{
	int input = 0;
	string output = "";

	cout << "number: ";
	cin >> input;

	input = abs(input);

	while (input > 0)
	{
		output += to_string(input % 10);
		input /= 10;
	}

	cout << output << endl;
}

void fourth_task()
{
	int occurences_0 = 0;
	int occurences_1 = 0;
	int occurences_2 = 0;
	int occurences_3 = 0;
	int occurences_4 = 0;
	int occurences_5 = 0;
	int occurences_6 = 0;
	int occurences_7 = 0;
	int occurences_8 = 0;
	int occurences_9 = 0;

	int input = 0;
	cout << "number: ";
	cin >> input;

	input = abs(input);

	while (input > 0)
	{
		switch (input % 10)
		{
			case 0: occurences_0++; break;
			case 1: occurences_1++; break;
			case 2: occurences_2++; break;
			case 3: occurences_3++; break;
			case 4: occurences_4++; break;
			case 5: occurences_5++; break;
			case 6: occurences_6++; break;
			case 7: occurences_7++; break;
			case 8: occurences_8++; break;
			case 9: occurences_9++; break;
		}

		input /= 10;
	}

	cout << "0/" << occurences_0 << ", ";
	cout << "1/" << occurences_1 << ", ";
	cout << "2/" << occurences_2 << ", ";
	cout << "3/" << occurences_3 << ", ";
	cout << "4/" << occurences_4 << ", ";
	cout << "5/" << occurences_5 << ", ";
	cout << "6/" << occurences_6 << ", ";
	cout << "7/" << occurences_7 << ", ";
	cout << "8/" << occurences_8 << ", ";
	cout << "9/" << occurences_9 << endl;
}

void add_symbols(string& input_str, int& number_of_times, char symbol)
{
	for (int i = 1; i <= number_of_times; ++i)
	{
		input_str += symbol;
	}
}

void fifth_task()
{
	int side = 0;
	char symbol = '-';
	cout << "side: ";
	cin >> side;
	cout << "symbol: ";
	cin >> symbol;

	for (int i = 1, symbols = 1; i <= side; ++i, symbols += 2)
	{
		int spaces = side - i;

		string output = "";

		add_symbols(output, spaces, ' ');
		add_symbols(output, symbols, symbol);

		cout << output << endl;
	}
}

void sixth_task()
{
	int input = 0;
	cout << "digit: ";
	cin >> input;

	if (input < 0 || input > 9)
	{
		cout << input << " is not a digit" << endl;
		return;
	}

	for (int i = 0; i < input * 2; ++i)
	{
		cout << 0;
	}
	cout << endl;

	for (int i = 1; i <= input; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cout << j;
		}

		for (int j = 0; j < (input - i) * 2; ++j)
		{
			cout << 0;
		}

		for (int j = i; j > 0; --j)
		{
			cout << j;
		}

		cout << endl;	
	}
}

void seventh_task()
{
	int input = 0;
	cout << "digit: ";
	cin >> input;

	if (input < 0 || input > 9)
	{
		cout << input << " is not a digit" << endl;
		return;
	}

	for (int i = 0; i < input * 2 - 1; ++i)
	{
		cout << 0;
	}
	cout << endl;

	for (int i = 1; i <= input; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cout << j;
		}

		for (int j = 0; j < (input - i) * 2 - 1; ++j)
		{
			cout << 0;
		}

		if (i == input)
		{
			for (int j = i - 1; j > 0; --j)
			{
				cout << j;
			}
		}
		else
		{
			for (int j = i; j > 0; --j)
			{
				cout << j;
			}
		}

		cout << endl;
	}
}

void book_task_62()
{
	int from_base = 10, to_base = 10, remainder = 0;
	char symbols[]{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	string input = "", output = "";

	cout << "from base: ";
	cin >> from_base;
	cout << "to base: ";
	cin >> to_base;
	cout << "number: ";
	cin >> input;
	
	if (from_base < 2)
	{
		cout << "Invalid from base!" << endl;
		return;
	}

	if (to_base > 16 || to_base < 2)
	{
		cout << "Invalid to base!" << endl;
		return;
	}

	// converts to base of 10
	unsigned long long converted = stoull(input, nullptr, from_base);

	// converts from base 10 to specified
	do
	{
		remainder = converted % to_base;
		output = symbols[remainder] + output;
		converted /= to_base;
	} while (converted > 0);

	cout << input << " in base " << from_base << " is " 
		 << output << " in base " << to_base << endl;
}

int rdn(int d, int m, int y) {
	if (m < 3)
		y--, m += 12;
	return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}


void book_task_63()
{
	string first_date = "", second_date = "";
	int first_day, first_month, first_year;
	int second_day, second_month, second_year;

	cout << "first date: ";
	cin >> first_date;
	cout << "second date: ";
	cin >> second_date;

	sscanf_s(first_date.c_str(), "%d-%d-%d", &first_day, &first_month, &first_year);
	sscanf_s(second_date.c_str(), "%d-%d-%d", &second_day, &second_month, &second_year);

	int days = rdn(first_day, first_month, first_year) - rdn(second_day, second_month, second_year);

	cout << "result: " << days << endl;
}

void book_task_64()
{
	int year, month, day, hour, minute, second;
	int seconds_to_add;
	string input;

	cout << "time: ";
	cin >> input;
	cout << "seconds to add: ";
	cin >> seconds_to_add;

	struct tm time = { 0 };

	sscanf_s(
		input.c_str(),
		"%d-%d-%d-%d-%d-%d",
		&year,
		&month,
		&day,
		&hour,
		&minute,
		&second);
	time.tm_year = year - 1900;
	time.tm_mon = month - 1;
	time.tm_mday = day;
	time.tm_hour = hour;
	time.tm_min = minute;
	time.tm_sec = second;

	time_t rawtime = mktime(&time);
	rawtime += seconds_to_add;

	localtime_s(&time, &rawtime);

	char buff[100];
	strftime(buff, sizeof buff, "%Y-%m-%d-%H-%M-%S", &time);
	cout << buff << endl;
}

// used for task 65
bool is_correct(int number)
{
	int first_last, second_last;

	first_last = number % 10;
	number /= 10;

	second_last = number % 10;

	if ((first_last == 1 || first_last == 2) &&
		(second_last == 1 || second_last == 2))
	{
		return true;
	}
	
	return false;
}

void book_task_65()
{
	int n = 0, current_power = 0, current_result = 0;
	cout << "n: ";
	cin >> n;

	do
	{
		current_power++;
		current_result = pow(n, current_power);
	} while (!is_correct(current_result));

	cout << current_power << endl;
}

int transform(int number)
{
	string number_str = to_string(number);
	char first_digit_chr = number_str[0];
	number_str = number_str.substr(1, number_str.length() - 1);
	number_str += first_digit_chr;
	return stoi(number_str);
}

int get_first_digit(int number)
{
	int last_digit = 0;

	while (number > 0)
	{
		last_digit = number % 10;
		number /= 10;
	}

	return last_digit;
}

void book_task_66()
{
	int number = 1;
	int transformed = 0;

	do
	{
		transformed = transform(number);
		if (get_first_digit(number) == 1 && 
			transformed / 3 == number &&
			transformed % 3 == 0)
		{
			break;
		}

		number++;
	} while (true);
	cout << number << endl;
}

int get_num_length(int number)
{
	return to_string(number).length();
}

bool get_bit_at_pos(int number, int position)
{
	return (number >> position) & 1;
}

void book_task_81()
{
	int first_number = 0, second_number = 0, first_pos = 0, second_pos = 0;
	cout << "first number: ";
	cin >> first_number;
	cout << "first number bit pos: ";
	cin >> first_pos;
	cout << "second number: ";
	cin >> second_number;
	cout << "second number bit pos: ";
	cin >> second_pos;

	if (get_bit_at_pos(first_number, first_pos) == get_bit_at_pos(second_number, second_pos))
		cout << "true" << endl;
	else
		cout << "false" << endl;
}

int swap_bits(int num, int nPosition, int mPosition)
{
	int k = ((num >> nPosition) & 1) - (num >> mPosition) & 1;

	return num + k*(1 << mPosition) - k*(1 << nPosition);
}

void book_task_82()
{
	unsigned int n = 0, first_bit = 0, second_bit = 0;
	cout << "number: ";
	cin >> n;
	cout << "first bit: ";
	cin >> first_bit;
	cout << "second bit: ";
	cin >> second_bit;

	cout << swap_bits(n, first_bit, second_bit) << endl;
}

int main()
{
	first_task();
	second_task();
	third_task();
	fourth_task();
	fifth_task();
	sixth_task();
	seventh_task();

	book_task_62();
	book_task_63();
	book_task_64();
	book_task_65();
	book_task_66();
	book_task_81();
	book_task_82();

	return 0;
}