// write program that take temperature in celsius
// then program call function <celsius_to_fahrenheit>
// 	- function take value in celsius
// 	- function return value in farheiheit

#include <iostream>
using namespace std;

double	celsius_to_fahrenheit(const int celsius);

int			main(void)
{
	int		celsius;
	
	celsius = 0;
	cout << "Please enter the celsius value\n";
	cin >> celsius;
	cout << celsius << " degrees Celsius is ";
	cout << celsius_to_fahrenheit(celsius);
	cout << " degrees Fahrenheit\n";
	return (0);
}

double	celsius_to_fahrenheit(const int celsius)
{
	return ((double)celsius * 1.8 + 32.0);
}
