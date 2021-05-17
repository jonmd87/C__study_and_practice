// write a program that take 10 double numers
// if was entered not a number, getting end.
// then the program show average result.
// and program show how much numbers are more then average
#include <iostream>

using namespace 		std;
const unsigned int		M = 10;

int				get_data(double *donate, unsigned int num)
{
	cout << "enter " << num << "of donate:\n";
	if (cin >> *donate)
		return (0);
	return (1);
}

double				make_average(double donat[], int max)
{
	double			average;
	int 				ind;
	
	ind = 0;
	while (ind < max)
	{
		average += donat[ind];
		ind++;
	}
	return (average / (double)max);
}

void 				show_data(double donat[], double num, int max)
{
	int				ind;
	
	ind = 0;
	cout << "The bigger numbers then " << num << " in array" << endl; 
	while (ind < max && donat[ind])
	{
		if (donat[ind] > num)
			cout << donat[ind] << endl;
		ind++;
	}
}

int					main(void)
{
	double 			donat[10];
	double			average;
	unsigned  int		ind;
	
	ind = 0;
	cout << "Let's start\n";
	while (ind < M && get_data(&donat[ind], ind + 1) == 0)
		ind++;
	if (ind < M)
		cout <<"etered not double number/nwas entered" << ind << "numbers\n";
	average = make_average(donat, ind);
	cout << "average = " << average << endl;
	show_data(donat, average, M);
	cout << "\ngood bye!!!" << endl;
	return (0);
}
