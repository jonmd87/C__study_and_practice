// write the program that ask how much miles you have gone
// then program ask quantity of fuel
// in the end program display 


#include <iostream>
using namespace std;

const double gallon = 2;

int				main(void)
{
	double		way;
	double		fuel;
	
	cout << "Please enter lenth of way:\n";
	cin >> way;
	cout << "Now enter quantity of fuel:\n";
	cin >> fuel;
	cout << " your расход is " << way / fuel << "\n";
	return (0);
}