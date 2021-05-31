#include <iostream>
#include <cctype>

using namespace				std;

int 							get_data(int *first, int *second);
int 							get_answer(int min, int max);
double						harmonic(double fir, double sec);

int							main(void)
{
	int 						first;
	int						second;
	
	while (get_data(&first, &second) == 0)
	{
		cout << "average harmonic value of [" << first << "] and [";
		cout << second << "] = [";
		cout << harmonic((double)first, (double) second) << "]" << endl;
	}
	cout << "Goodbye" << endl;
	return (0);
}


double						harmonic(double x, double y)
{
	return (2.0 * x * y / (x + y));
}

int 							get_answer(int min, int max)
{
	ssize_t					num;
	
	while (1)
	{
		cin >> num;
		if ((cin.fail() == false ) && num >= min && num <= max)
			return ((int)num);
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Only numbers in this limit " << min << " to " << max << endl;
	}
	return (1);
}

int 							get_data(int *first, int *second)
{
	cout << "enter first number:" << endl;
	*first = get_answer(INT_MIN, INT_MAX);
	if (*first == 0)
		return (1);
	cout << "enter second number:" << endl;
	*second = get_answer(INT_MIN, INT_MAX);
	if (*second == 0)
		return (1);
	return (0);
}
