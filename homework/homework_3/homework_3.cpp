// homework_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int get_biggest_divisable(int comparable, int roman_nums[], int nums_length) {
	int biggest = 0;

	for (int i = 0; i < nums_length; ++i) {
		int current_num = roman_nums[i];

		if (current_num <= comparable && current_num > biggest) {
			biggest = current_num;
		}
	}

	return biggest;
}

void first_task() {
	int number = 0;

	cout << "integer: ";
	cin >> number;

	while (number < 1 || number > 3999) {
		cout << "The number must be between 1 and 3999!" << endl;
		cout << "integer: ";
		cin >> number;
	}

	const int numbers_count = 13;
	int roman_numbers[numbers_count] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };

	while (number > 0) {
		int biggest = get_biggest_divisable(number, roman_numbers, numbers_count);

		switch (biggest) {
		case 1: cout << "I"; break;
		case 4: cout << "IV"; break;
		case 5: cout << "V"; break;
		case 9: cout << "IX"; break;
		case 10: cout << "X"; break;
		case 40: cout << "XL"; break;
		case 50: cout << "L"; break;
		case 90: cout << "XC"; break;
		case 100: cout << "C"; break;
		case 400: cout << "CD"; break;
		case 500: cout << "D"; break;
		case 900: cout << "CM"; break;
		default: cout << "M"; break;
		}

		number -= biggest;
	}
}

void second_task() {
	string digit = "";
	int result = 0;

	cout << "Enter the digits of the number. Each digit must be entered one after another, each followed by press of ENTER."
		<< endl << "To finish entering digits just pass a dot." << endl;
	do {
		cout << "roman digit: ";
		cin >> digit;

		if (digit == "I")
			result += 1;
		else if (digit == "IV")
			result += 4;
		else if (digit == "V")
			result += 5;
		else if (digit == "IX")
			result += 9;
		else if (digit == "X")
			result += 10;
		else if (digit == "XL")
			result += 40;
		else if (digit == "L")
			result += 50;
		else if (digit == "XC")
			result += 90;
		else if (digit == "C")
			result += 100;
		else if (digit == "CD")
			result += 400;
		else if (digit == "D")
			result += 500;
		else if (digit == "CM")
			result += 900;
		else if (digit == "M")
			result += 1000;
		else if (digit != ".")
			cout << "Invalid digit!" << endl;

	} while (digit != ".");

	if (result > 3999) {
		cout << "Your number is invalid!" << endl;
		return;
	}

	cout << "result = " << result << endl;
}

#define MIN 1.
#define MAX 10.
void third_task() {
	double input = 0.;

	cout << "real number: ";
	cin >> input;

	if (input < MIN || input > MAX) {
		cout << "your number is not in the interval" << endl;
	}
	else {
		cout << "your number is in the interval" << endl;
	}
}

void fourth_task() {
	int input = 0;
	cout << "integer: ";
	cin >> input;

	if (input == 0) {
		cout << 0 << endl;
	}

	input = abs(input);

	while (input > 0) {
		cout << input % 10 << endl;
		input /= 10;
	}
}

void fifth_task() {
	int min, max;
	cout << "min=";
	cin >> min;
	cout << "max=";
	cin >> max;

	if (min > max) {
		cout << "min can not be greater than max!" << endl;
		return;
	}

	srand(time(NULL));
	int random = rand() % (max - min + 1) + min;
	int test_number = random;

	int number_of_digits = 0;
	while (test_number > 0) {
		test_number /= 10;
		number_of_digits++;
	}

	if (number_of_digits <= 3) {
		cout << random << endl;
	}
	else {
		cout << "the generated number has more than 3 digits" << endl;
	}
}

void sixth_task() {
	int min, max;
	cout << "min=";
	cin >> min;
	cout << "max=";
	cin >> max;

	if (min > max) {
		cout << "min can not be greater than max!" << endl;
		return;
	}

	srand(time(NULL));
	double number = min + ((double)rand() / RAND_MAX) * (max - min);
	cout << number << endl;
}

void book_task_1() {
	double ax, bx, cx, ay, by, cy;
	cout << "Ax=";
	cin >> ax;
	cout << "Ay=";
	cin >> ay;
	cout << "Bx=";
	cin >> bx;
	cout << "By=";
	cin >> by;
	cout << "Cx=";
	cin >> cx;
	cout << "Cy=";
	cin >> cy;

	double area = abs((ax * (by - cy) + bx * (cy - ay) + cx * (ay - by)) / 2);

	double ab = sqrt(pow(abs(ax - bx), 2) + pow(abs(ay - by), 2));
	double ac = sqrt(pow(abs(ax - cx), 2) + pow(abs(ay - cy), 2));
	double bc = sqrt(pow(abs(bx - cx), 2) + pow(abs(by - cy), 2));

	cout << "area=" << area << endl;
	cout << "perimiter=" << ab + ac + bc << endl;
}

void book_task_2() {
	double ax, bx, cx, ay, by, cy;
	cout << "Ax=";
	cin >> ax;
	cout << "Ay=";
	cin >> ay;
	cout << "Bx=";
	cin >> bx;
	cout << "By=";
	cin >> by;
	cout << "Cx=";
	cin >> cx;
	cout << "Cy=";
	cin >> cy;

	double ox = (ax + bx + cx) / 3.0;
	double oy = (ay + by + cy) / 3.0;
	cout << "Ox=" << ox << endl;
	cout << "Oy=" << oy << endl;
}

double calc_distance(double x1, double y1, double x2, double y2, double x0, double y0) {
	return abs(abs(y2 - y1) * x0 - abs(x2 - x1) * y0 + x2 * x1 - y2 * x1) / sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2));
}

void book_task_3() {
	double ax, bx, cx, dx, ay, by, cy, dy, x0, y0;
	cout << "Ax=";
	cin >> ax;
	cout << "Ay=";
	cin >> ay;
	cout << "Bx=";
	cin >> bx;
	cout << "By=";
	cin >> by;
	cout << "Cx=";
	cin >> cx;
	cout << "Cy=";
	cin >> cy;
	cout << "Dx=";
	cin >> dx;
	cout << "Dy=";
	cin >> dy;
	cout << "x0=";
	cin >> x0;
	cout << "y0=";
	cin >> y0;

	double distance_ab = calc_distance(ax, ay, bx, by, x0, y0);
	double distance_bc = calc_distance(bx, by, cx, cy, x0, y0);
	double distance_cd = calc_distance(cx, cy, dx, dy, x0, y0);
	double distance_da = calc_distance(dx, dy, ax, ay, x0, y0);

	cout << "distance to AB: " << distance_ab << endl;
	cout << "distance to BC: " << distance_bc << endl;
	cout << "distance to CD: " << distance_cd << endl;
	cout << "distance to DA: " << distance_da << endl;
}

void book_task_4() {
	double ax, bx, cx, ay, by, cy, x0, y0;
	cout << "Ax=";
	cin >> ax;
	cout << "Ay=";
	cin >> ay;
	cout << "Bx=";
	cin >> bx;
	cout << "By=";
	cin >> by;
	cout << "Cx=";
	cin >> cx;
	cout << "Cy=";
	cin >> cy;
	cout << "x0=";
	cin >> x0;
	cout << "y0=";
	cin >> y0;

	double distance_ab = calc_distance(ax, ay, bx, by, x0, y0);
	double distance_bc = calc_distance(bx, by, cx, cy, x0, y0);
	double distance_ca = calc_distance(cx, cy, ax, ay, x0, y0);

	cout << "distance to AB: " << distance_ab << endl;
	cout << "distance to BC: " << distance_bc << endl;
	cout << "distance to CA: " << distance_ca << endl;
}

void book_task_8() {
	double a, b, c;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "c=";
	cin >> c;

	cout << "resultA = " << min(a + b + c, a * b * c) + 1.5 << endl;

	double res1 = pow(a, 2) - pow(b, 3) + c;
	double res2 = a - 4.5 * b;
	double res3 = 1.5 * a + 3.5 * b - 8 * c;
	double max = 0;
	if (res1 >= res2 && res1 >= res3)
		max = res1;
	else if (res2 >= res1 && res2 >= res3)
		max = res2;
	else
		max = res3;
	cout << "resultB = " << max - 7.5 << endl;
}

void book_task_9() {
	int a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	if (a == b) {
		cout << "invalid input" << endl;
		return;
	}

	if (a > b) {
		a -= 5;
		b += 3;
	}
	else {
		b -= 5;
		a += 3;
	}

	cout << "a : " << a << endl;
	cout << "b : " << b << endl;
}

void book_task_10() {
	int a, b, c;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;

	if (a <= b && b <= c) {
		a = abs(a);
		b = abs(b);
		c = abs(c);
	}
	else {
		a *= 2;
		b *= 2;
		c *= 2;
	}

	cout << "a : " << a << endl;
	cout << "b : " << b << endl;
	cout << "c : " << c << endl;
}

void book_task_13() {
	int a, b, c, d, x1, x2;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;

	d = b * b - 4 * a * c;

	if (a == 0 || b == 0 || c == 0) {
		cout << "no soultion" << endl;
		return;
	}

	if (d > 0) {
		x1 = (-b + sqrt(d)) / 2 * a;
		x2 = (-b - sqrt(d)) / 2 * a;

		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}
	else if (d == 0) {
		x1 = -b / 2 * a;
		cout << "x = " << x1 << endl;
	}
	else {
		cout << "no solution" << endl;
	}
}

double get_abs(double input) {
	if (input < 0) {
		return -1 * input;
	}

	return input;
}

void book_task_14() {
	double x;
	cout << "x=";
	cin >> x;

	cout << "result : " << get_abs(get_abs(2 * x - 3.6) - get_abs(2.5 * x - 10)) - 2.5 << endl;
}

void book_task_17() {
	int a, b, c, d, x1, x2;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;

	if (a == 0 || b == 0 || c == 0) {
		cout << "no soultion" << endl;
		return;
	}

	d = b * b - 4 * a * c;

	if (d > 0) {
		x1 = (-b + sqrt(d)) / 2 * a;
		x2 = (-b - sqrt(d)) / 2 * a;

		if (x1 > 0) {
			cout << "x1-1 = " << sqrt(x1) << endl;
			cout << "x1-2 = " << -sqrt(x1) << endl;
		}

		if (x2 > 0) {
			cout << "x2-1 = " << sqrt(x2) << endl;
			cout << "x2-2 = " << -sqrt(x2) << endl;
		}

		if (x1 == 0) {
			cout << "x1=0" << endl;
		}

		if (x2 == 0) {
			cout << "x2=0" << endl;
		}

		if (x1 < 0) {
			cout << "no solution for x1" << endl;
		}

		if (x2 < 0) {
			cout << "no solution for x2" << endl;
		}
	}
	else if (d == 0) {
		x1 = -b / 2 * a;

		if (x1 > 0) {
			cout << "x1 = " << sqrt(x1) << endl;
			cout << "x2 = " << -sqrt(x1) << endl;
		}

		if (x1 == 0) {
			cout << "x1=0" << endl;
		}

		if (x1 < 0) {
			cout << "no solution" << endl;
		}
	}
	else {
		cout << "no solution" << endl;
	}
}

void book_task_20() {
	int n;
	cout << "n = ";
	cin >> n;

	unsigned long long int product = 1;
	for (int i = 1; i <= n; ++i) {
		int current_num = pow(i, 3) + 8 * i * n + pow(n, 2);

		if (current_num % 3 == 0 || current_num % 8 == 0) {
			product *= current_num;
			cout << current_num << endl;
		}
	}

	cout << "result : " << product << endl;
}

int main() {
	first_task();
	second_task();
	third_task();
	fourth_task();
	fifth_task();
	sixth_task();
	book_task_1();
	book_task_2();
	book_task_3();
	book_task_4();
	book_task_8();
	book_task_9();
	book_task_10();
	book_task_13();
	book_task_14();
	book_task_17();
	book_task_20();

	return 0;
}