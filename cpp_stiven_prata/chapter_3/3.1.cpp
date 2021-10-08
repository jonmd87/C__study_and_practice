// write a program that ask your height in inches
// then program display your height in foots and inch
// let the program show place to enter height with underlined symbol
// 

#include <iostream>
using namespace std;

const double foot = 12;

double			convert(const int cm);
void				foot_inch(const double val);

int				main(void)
{
	double	 	inch;
	unsigned int	foots;
	
	cout << "Please enter your height in inches\n________\b\b\b\b\b\b\b\b";
	cin >> inch;
	foots = (unsigned int)(inch / foot);
	cout << "Your height is\n\t[";
	cout << foots << "] foots\n\t[";
	inch -= (foots * foot);
	cout << inch << "] inches\n";
	cout << "Good bye\n";
}
